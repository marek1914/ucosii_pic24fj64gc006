/*
 * File:   debug.c
 * Author: sunixy
 *
 * Created on December 3, 2015, 10:20 AM
 */
#include "debug.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <mcc.h>

#define DOUBLE_BUFFER_FULL                  (0x0003U)
#define DOUBLE_BUFFER_EMPTY                 (0x0000U)

#define DOUBLE_BUFFER_1                     (0X0001U)
#define DOUBLE_BUFFER_2                     (0X0001U)

#define DOUBLE_BUFFER_LOAD_BIT              (4)
#define DOUBLE_BUFFER_PROCESS_BIT           (8)

#define DOUBLE_BUFFER_USED_MASK             (0x0003U)
#define DOUBLE_BUFFER_LOAD_MASK             (0x0030U)
#define DOUBLE_BUFFER_PROCESS_MASK          (0x0300U)

#define get_double_buffer_process(a)    \
    a = (g_double_buffer.bit_map & DOUBLE_BUFFER_PROCESS_MASK)>>DOUBLE_BUFFER_PROCESS_BIT


#define dma_channel0_start_transfer(item)    \
            DMA_SourceAddressSet(DMA_CHANNEL0, (uint16_t)((item)->buffer));   \
            DMA_TransferCountSet(DMA_CHANNEL0, (item)->size);   \
            DMACH0bits.CHEN = 1;  \
            DMA_SoftwareTriggerEnable(DMA_CHANNEL0)    


typedef struct tagDoubleBufferItem
{
    uint8_t buffer[MAX_DEBUG_INFO_SIZE];
    uint16_t size;
} DoubleBufferItem;

typedef struct tagDoubleBuffer
{
    DoubleBufferItem item[2];
    volatile uint16_t bit_map;
} DoubleBuffer;

static DoubleBuffer g_double_buffer;

static void dma_complete_notify(void);




static DoubleBufferItem *double_buffer_alloc(void)
{
    DoubleBufferItem *item = NULL;
    uint16_t used = 0;

    do {
        disable_irq();
        used = g_double_buffer.bit_map & DOUBLE_BUFFER_USED_MASK;
        enable_irq();
    } while (DOUBLE_BUFFER_FULL == used);
    
    disable_irq();
    if (DOUBLE_BUFFER_EMPTY == 
            (g_double_buffer.bit_map & DOUBLE_BUFFER_USED_MASK))
    {
        g_double_buffer.bit_map |= DOUBLE_BUFFER_1;
        item = &(g_double_buffer.item[0]);
    }
    else
    {
        used = (g_double_buffer.bit_map & DOUBLE_BUFFER_USED_MASK)
                ^ DOUBLE_BUFFER_USED_MASK;
        g_double_buffer.bit_map |= used;
        item = &(g_double_buffer.item[used-1]);
    }
    enable_irq();
    
    return item;
}

static void usart_dma_write(DoubleBufferItem *item)
{
    uint16_t load = 0;
    
    if (item == &(g_double_buffer.item[0]))
    {
        load = DOUBLE_BUFFER_1;
    }
    else
    {
        load = DOUBLE_BUFFER_2;
    }
    
    disable_irq();
    g_double_buffer.bit_map |= load<<DOUBLE_BUFFER_LOAD_BIT;
    if (DOUBLE_BUFFER_EMPTY == 
            (g_double_buffer.bit_map & DOUBLE_BUFFER_PROCESS_MASK))
    {
        g_double_buffer.bit_map |= load<<DOUBLE_BUFFER_PROCESS_BIT;
        enable_irq();
        dma_channel0_start_transfer(item);
    }
    else
    {
        enable_irq();
    }
}

static void dma_complete_notify(void)
{
    uint16_t used = 0;
    
    get_double_buffer_process(used);
    g_double_buffer.bit_map &= ~DOUBLE_BUFFER_PROCESS_MASK; //clear process bit
    g_double_buffer.bit_map &= ~used; //clear used bit
    g_double_buffer.bit_map &= ~(used<<DOUBLE_BUFFER_LOAD_BIT); //clear load bit
    used = g_double_buffer.bit_map & DOUBLE_BUFFER_LOAD_MASK;
    if (DOUBLE_BUFFER_EMPTY != used)
    {
        g_double_buffer.bit_map |= used << DOUBLE_BUFFER_LOAD_BIT;
        dma_channel0_start_transfer(&(g_double_buffer.item[(used>>DOUBLE_BUFFER_LOAD_BIT)-1]));
    }
}

void debug_init(void)
{
    memset(&g_double_buffer, 0x00U, sizeof(DoubleBuffer));
    DMA_Initialize();
    DMA_DestinationAddressSet(DMA_CHANNEL0, (uint16_t)&U2TXREG);
    DMA_RegisterNotify(dma_complete_notify);
    UART2_Initialize();
}


void _log_print(int level, char *fmt, ...)
{
    va_list args;
    DoubleBufferItem *item = NULL;

    item = double_buffer_alloc();
    if (NULL != item)
    {
        memset(item, 0, sizeof(DoubleBufferItem));
        va_start(args, fmt);
        item->size = vsnprintf((char *)item->buffer, MAX_DEBUG_INFO_SIZE, fmt, args);
        va_end(args);
#if 1
        usart_dma_write(item);
#else
        UART2_Transfer((uint8_t *)item->buffer, item->size);
#endif        
    }

    return;
}


