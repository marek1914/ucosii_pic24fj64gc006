#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ucosii.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ucosii.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/mcc.c app/main.c ucosii/port/os_cpu_a.s ucosii/port/os_cpu_c.c ucosii/port/os_cpu_util_a.s ucosii/port/os_dbg.c ucosii/source/os_core.c ucosii/source/os_flag.c ucosii/source/os_mbox.c ucosii/source/os_mem.c ucosii/source/os_mutex.c ucosii/source/os_q.c ucosii/source/os_sem.c ucosii/source/os_task.c ucosii/source/os_time.c ucosii/source/os_tmr.c mcc_generated_files/pin_manager.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/app/main.o ${OBJECTDIR}/ucosii/port/os_cpu_a.o ${OBJECTDIR}/ucosii/port/os_cpu_c.o ${OBJECTDIR}/ucosii/port/os_cpu_util_a.o ${OBJECTDIR}/ucosii/port/os_dbg.o ${OBJECTDIR}/ucosii/source/os_core.o ${OBJECTDIR}/ucosii/source/os_flag.o ${OBJECTDIR}/ucosii/source/os_mbox.o ${OBJECTDIR}/ucosii/source/os_mem.o ${OBJECTDIR}/ucosii/source/os_mutex.o ${OBJECTDIR}/ucosii/source/os_q.o ${OBJECTDIR}/ucosii/source/os_sem.o ${OBJECTDIR}/ucosii/source/os_task.o ${OBJECTDIR}/ucosii/source/os_time.o ${OBJECTDIR}/ucosii/source/os_tmr.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/app/main.o.d ${OBJECTDIR}/ucosii/port/os_cpu_a.o.d ${OBJECTDIR}/ucosii/port/os_cpu_c.o.d ${OBJECTDIR}/ucosii/port/os_cpu_util_a.o.d ${OBJECTDIR}/ucosii/port/os_dbg.o.d ${OBJECTDIR}/ucosii/source/os_core.o.d ${OBJECTDIR}/ucosii/source/os_flag.o.d ${OBJECTDIR}/ucosii/source/os_mbox.o.d ${OBJECTDIR}/ucosii/source/os_mem.o.d ${OBJECTDIR}/ucosii/source/os_mutex.o.d ${OBJECTDIR}/ucosii/source/os_q.o.d ${OBJECTDIR}/ucosii/source/os_sem.o.d ${OBJECTDIR}/ucosii/source/os_task.o.d ${OBJECTDIR}/ucosii/source/os_time.o.d ${OBJECTDIR}/ucosii/source/os_tmr.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/app/main.o ${OBJECTDIR}/ucosii/port/os_cpu_a.o ${OBJECTDIR}/ucosii/port/os_cpu_c.o ${OBJECTDIR}/ucosii/port/os_cpu_util_a.o ${OBJECTDIR}/ucosii/port/os_dbg.o ${OBJECTDIR}/ucosii/source/os_core.o ${OBJECTDIR}/ucosii/source/os_flag.o ${OBJECTDIR}/ucosii/source/os_mbox.o ${OBJECTDIR}/ucosii/source/os_mem.o ${OBJECTDIR}/ucosii/source/os_mutex.o ${OBJECTDIR}/ucosii/source/os_q.o ${OBJECTDIR}/ucosii/source/os_sem.o ${OBJECTDIR}/ucosii/source/os_task.o ${OBJECTDIR}/ucosii/source/os_time.o ${OBJECTDIR}/ucosii/source/os_tmr.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o

# Source Files
SOURCEFILES=mcc_generated_files/mcc.c app/main.c ucosii/port/os_cpu_a.s ucosii/port/os_cpu_c.c ucosii/port/os_cpu_util_a.s ucosii/port/os_dbg.c ucosii/source/os_core.c ucosii/source/os_flag.c ucosii/source/os_mbox.c ucosii/source/os_mem.c ucosii/source/os_mutex.c ucosii/source/os_q.c ucosii/source/os_sem.c ucosii/source/os_task.c ucosii/source/os_time.c ucosii/source/os_tmr.c mcc_generated_files/pin_manager.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ucosii.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GC006
MP_LINKER_FILE_OPTION=,--script=p24FJ64GC006.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/mcc_generated_files/mcc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/app/main.o: app/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/app" 
	@${RM} ${OBJECTDIR}/app/main.o.d 
	@${RM} ${OBJECTDIR}/app/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  app/main.c  -o ${OBJECTDIR}/app/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/app/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/app/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/port/os_cpu_c.o: ucosii/port/os_cpu_c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/port" 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_c.o.d 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/port/os_cpu_c.c  -o ${OBJECTDIR}/ucosii/port/os_cpu_c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/port/os_cpu_c.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/port/os_cpu_c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/port/os_dbg.o: ucosii/port/os_dbg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/port" 
	@${RM} ${OBJECTDIR}/ucosii/port/os_dbg.o.d 
	@${RM} ${OBJECTDIR}/ucosii/port/os_dbg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/port/os_dbg.c  -o ${OBJECTDIR}/ucosii/port/os_dbg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/port/os_dbg.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/port/os_dbg.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_core.o: ucosii/source/os_core.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_core.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_core.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_core.c  -o ${OBJECTDIR}/ucosii/source/os_core.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_core.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_core.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_flag.o: ucosii/source/os_flag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_flag.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_flag.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_flag.c  -o ${OBJECTDIR}/ucosii/source/os_flag.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_flag.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_flag.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_mbox.o: ucosii/source/os_mbox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mbox.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mbox.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_mbox.c  -o ${OBJECTDIR}/ucosii/source/os_mbox.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_mbox.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_mbox.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_mem.o: ucosii/source/os_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mem.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_mem.c  -o ${OBJECTDIR}/ucosii/source/os_mem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_mem.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_mem.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_mutex.o: ucosii/source/os_mutex.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mutex.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mutex.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_mutex.c  -o ${OBJECTDIR}/ucosii/source/os_mutex.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_mutex.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_mutex.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_q.o: ucosii/source/os_q.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_q.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_q.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_q.c  -o ${OBJECTDIR}/ucosii/source/os_q.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_q.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_q.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_sem.o: ucosii/source/os_sem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_sem.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_sem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_sem.c  -o ${OBJECTDIR}/ucosii/source/os_sem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_sem.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_sem.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_task.o: ucosii/source/os_task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_task.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_task.c  -o ${OBJECTDIR}/ucosii/source/os_task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_task.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_task.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_time.o: ucosii/source/os_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_time.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_time.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_time.c  -o ${OBJECTDIR}/ucosii/source/os_time.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_time.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_time.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_tmr.o: ucosii/source/os_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_tmr.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_tmr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_tmr.c  -o ${OBJECTDIR}/ucosii/source/os_tmr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_tmr.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_tmr.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/mcc_generated_files/mcc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/app/main.o: app/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/app" 
	@${RM} ${OBJECTDIR}/app/main.o.d 
	@${RM} ${OBJECTDIR}/app/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  app/main.c  -o ${OBJECTDIR}/app/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/app/main.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/app/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/port/os_cpu_c.o: ucosii/port/os_cpu_c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/port" 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_c.o.d 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/port/os_cpu_c.c  -o ${OBJECTDIR}/ucosii/port/os_cpu_c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/port/os_cpu_c.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/port/os_cpu_c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/port/os_dbg.o: ucosii/port/os_dbg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/port" 
	@${RM} ${OBJECTDIR}/ucosii/port/os_dbg.o.d 
	@${RM} ${OBJECTDIR}/ucosii/port/os_dbg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/port/os_dbg.c  -o ${OBJECTDIR}/ucosii/port/os_dbg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/port/os_dbg.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/port/os_dbg.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_core.o: ucosii/source/os_core.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_core.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_core.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_core.c  -o ${OBJECTDIR}/ucosii/source/os_core.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_core.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_core.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_flag.o: ucosii/source/os_flag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_flag.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_flag.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_flag.c  -o ${OBJECTDIR}/ucosii/source/os_flag.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_flag.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_flag.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_mbox.o: ucosii/source/os_mbox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mbox.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mbox.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_mbox.c  -o ${OBJECTDIR}/ucosii/source/os_mbox.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_mbox.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_mbox.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_mem.o: ucosii/source/os_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mem.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_mem.c  -o ${OBJECTDIR}/ucosii/source/os_mem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_mem.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_mem.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_mutex.o: ucosii/source/os_mutex.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mutex.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_mutex.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_mutex.c  -o ${OBJECTDIR}/ucosii/source/os_mutex.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_mutex.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_mutex.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_q.o: ucosii/source/os_q.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_q.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_q.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_q.c  -o ${OBJECTDIR}/ucosii/source/os_q.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_q.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_q.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_sem.o: ucosii/source/os_sem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_sem.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_sem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_sem.c  -o ${OBJECTDIR}/ucosii/source/os_sem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_sem.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_sem.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_task.o: ucosii/source/os_task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_task.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_task.c  -o ${OBJECTDIR}/ucosii/source/os_task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_task.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_task.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_time.o: ucosii/source/os_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_time.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_time.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_time.c  -o ${OBJECTDIR}/ucosii/source/os_time.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_time.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_time.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ucosii/source/os_tmr.o: ucosii/source/os_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/source" 
	@${RM} ${OBJECTDIR}/ucosii/source/os_tmr.o.d 
	@${RM} ${OBJECTDIR}/ucosii/source/os_tmr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ucosii/source/os_tmr.c  -o ${OBJECTDIR}/ucosii/source/os_tmr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ucosii/source/os_tmr.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ucosii/source/os_tmr.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -mno-eds-warn  -g -omf=elf -legacy-libc  -O2 -I"mcc_generated_files" -I"ucosii/cfg" -I"ucosii/port" -I"ucosii/source" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ucosii/port/os_cpu_a.o: ucosii/port/os_cpu_a.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/port" 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_a.o.d 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_a.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ucosii/port/os_cpu_a.s  -o ${OBJECTDIR}/ucosii/port/os_cpu_a.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -legacy-libc  -I"ucosii/port" -Wa,-MD,"${OBJECTDIR}/ucosii/port/os_cpu_a.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/ucosii/port/os_cpu_a.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ucosii/port/os_cpu_util_a.o: ucosii/port/os_cpu_util_a.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/port" 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_util_a.o.d 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_util_a.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ucosii/port/os_cpu_util_a.s  -o ${OBJECTDIR}/ucosii/port/os_cpu_util_a.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -legacy-libc  -I"ucosii/port" -Wa,-MD,"${OBJECTDIR}/ucosii/port/os_cpu_util_a.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/ucosii/port/os_cpu_util_a.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ucosii/port/os_cpu_a.o: ucosii/port/os_cpu_a.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/port" 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_a.o.d 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_a.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ucosii/port/os_cpu_a.s  -o ${OBJECTDIR}/ucosii/port/os_cpu_a.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -legacy-libc  -I"ucosii/port" -Wa,-MD,"${OBJECTDIR}/ucosii/port/os_cpu_a.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/ucosii/port/os_cpu_a.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ucosii/port/os_cpu_util_a.o: ucosii/port/os_cpu_util_a.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ucosii/port" 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_util_a.o.d 
	@${RM} ${OBJECTDIR}/ucosii/port/os_cpu_util_a.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ucosii/port/os_cpu_util_a.s  -o ${OBJECTDIR}/ucosii/port/os_cpu_util_a.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -legacy-libc  -I"ucosii/port" -Wa,-MD,"${OBJECTDIR}/ucosii/port/os_cpu_util_a.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/ucosii/port/os_cpu_util_a.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ucosii.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ucosii.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG   -omf=elf -legacy-libc      -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/ucosii.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ucosii.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -legacy-libc  -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/ucosii.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
