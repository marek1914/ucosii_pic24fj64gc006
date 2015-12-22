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
#include <dma.h>
#include <uart2.h>

#define DOUBLE_BUFFER_FULL                  (0x0003U)
#define DOUBLE_BUFFER_EMPTY                 (0x0000U)
#define DOUBLE_BUFFER_NEW                   (0x0101U)

#define DOUBLE_BUFFER_USED_MASK             (0x0003U)
#define DOUBLE_BUFFER_PROCESS_MASK          (0x0300U)

#define get_double_buffer_process(a)    \
    a = (g_double_buffer.bit_map & DOUBLE_BUFFER_PROCESS_MASK)>>8


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
    uint16_t bit_map;
} DoubleBuffer;

static DoubleBuffer g_double_buffer;

static void dma_complete_notify(void);




static DoubleBufferItem *double_buffer_alloc(void)
{
    DoubleBufferItem *item = NULL;
    uint16_t used = 0;

    while (DOUBLE_BUFFER_FULL == 
            (g_double_buffer.bit_map & DOUBLE_BUFFER_USED_MASK))
    {
        //wait dma interrupt to free double buffer
        __builtin_nop();
    }

    __builtin_disi(0x3FFF);
    if (DOUBLE_BUFFER_EMPTY == 
            (g_double_buffer.bit_map & DOUBLE_BUFFER_USED_MASK))
    {
        g_double_buffer.bit_map |= DOUBLE_BUFFER_NEW;
        item = &g_double_buffer.item[0];
    }
    else
    {
        get_double_buffer_process(used);
        if (0 != used)
        {
            used = ((~used) & DOUBLE_BUFFER_USED_MASK);
            __builtin_disi(0x3FFF);
            g_double_buffer.bit_map |= used;
            __builtin_disi(0x0000);
            item = &g_double_buffer.item[used-1];
        }
    }
    __builtin_disi(0x0000);

    return item;
}

static void usart_dma_write(uint8_t *data, uint16_t len)
{
    DoubleBufferItem *item = NULL;

    item = double_buffer_alloc();
    if (NULL != item)
    {
        memset(item, 0, sizeof(DoubleBufferItem));
        memcpy(item->buffer, data, len);
        item->size = len;
        if (0 == DMA_TransferCountGet(DMA_CHANNEL0))
        //if (0 == DMA_IsSoftwareRequestPending(DMA_CHANNEL0))
        {
            dma_channel0_start_transfer(item);
        }
    }
}

static void dma_complete_notify(void)
{
    uint16_t used = 0;
    get_double_buffer_process(used);
    g_double_buffer.bit_map &= (~DOUBLE_BUFFER_PROCESS_MASK);
    g_double_buffer.bit_map &= (~used);
    used = g_double_buffer.bit_map & DOUBLE_BUFFER_USED_MASK;
    if (DOUBLE_BUFFER_EMPTY != used)
    {
        g_double_buffer.bit_map |= used << 8;
        dma_channel0_start_transfer(&(g_double_buffer.item[used-1]));
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


void log_print(int level, char *fmt, ...)
{
    va_list args;
    char buffer[MAX_DEBUG_INFO_SIZE] = {0};
    int len = 0;

    va_start(args, fmt);
    len = vsnprintf(buffer, MAX_DEBUG_INFO_SIZE, fmt, args);
    va_end(args);
#if 1
    usart_dma_write((uint8_t *)buffer, (uint16_t)len);
#else
    UART2_Transfer((uint8_t *)buffer, (uint16_t)len);
#endif

    return;
}


