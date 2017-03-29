#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-DEBUG_LED.mk)" "nbproject/Makefile-local-DEBUG_LED.mk"
include nbproject/Makefile-local-DEBUG_LED.mk
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=DEBUG_LED
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/HID.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/HID.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/GetFeatureReport.o ${OBJECTDIR}/src/GetInputReport.o ${OBJECTDIR}/src/ProcessIO.o ${OBJECTDIR}/src/SetFeatureReport.o ${OBJECTDIR}/src/SetOutputReport.o ${OBJECTDIR}/src/SetupFeatureReport.o ${OBJECTDIR}/src/SetupOutputReport.o ${OBJECTDIR}/src/USBEcho.o ${OBJECTDIR}/src/UserDefs.o ${OBJECTDIR}/src/UserInit.o ${OBJECTDIR}/src/checkEcho.o ${OBJECTDIR}/src/hid_defs.o ${OBJECTDIR}/src/init_usart.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/usb.o ${OBJECTDIR}/src/usb_remoto.o ${OBJECTDIR}/src/wait.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/GetFeatureReport.o.d ${OBJECTDIR}/src/GetInputReport.o.d ${OBJECTDIR}/src/ProcessIO.o.d ${OBJECTDIR}/src/SetFeatureReport.o.d ${OBJECTDIR}/src/SetOutputReport.o.d ${OBJECTDIR}/src/SetupFeatureReport.o.d ${OBJECTDIR}/src/SetupOutputReport.o.d ${OBJECTDIR}/src/USBEcho.o.d ${OBJECTDIR}/src/UserDefs.o.d ${OBJECTDIR}/src/UserInit.o.d ${OBJECTDIR}/src/checkEcho.o.d ${OBJECTDIR}/src/hid_defs.o.d ${OBJECTDIR}/src/init_usart.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/usb.o.d ${OBJECTDIR}/src/usb_remoto.o.d ${OBJECTDIR}/src/wait.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/GetFeatureReport.o ${OBJECTDIR}/src/GetInputReport.o ${OBJECTDIR}/src/ProcessIO.o ${OBJECTDIR}/src/SetFeatureReport.o ${OBJECTDIR}/src/SetOutputReport.o ${OBJECTDIR}/src/SetupFeatureReport.o ${OBJECTDIR}/src/SetupOutputReport.o ${OBJECTDIR}/src/USBEcho.o ${OBJECTDIR}/src/UserDefs.o ${OBJECTDIR}/src/UserInit.o ${OBJECTDIR}/src/checkEcho.o ${OBJECTDIR}/src/hid_defs.o ${OBJECTDIR}/src/init_usart.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/usb.o ${OBJECTDIR}/src/usb_remoto.o ${OBJECTDIR}/src/wait.o


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
	${MAKE}  -f nbproject/Makefile-DEBUG_LED.mk dist/${CND_CONF}/${IMAGE_TYPE}/HID.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/GetFeatureReport.o: src/GetFeatureReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/GetFeatureReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/GetFeatureReport.c  -o${OBJECTDIR}/src/GetFeatureReport.o
	
${OBJECTDIR}/src/GetInputReport.o: src/GetInputReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/GetInputReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/GetInputReport.c  -o${OBJECTDIR}/src/GetInputReport.o
	
${OBJECTDIR}/src/ProcessIO.o: src/ProcessIO.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/ProcessIO.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/ProcessIO.c  -o${OBJECTDIR}/src/ProcessIO.o
	
${OBJECTDIR}/src/SetFeatureReport.o: src/SetFeatureReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/SetFeatureReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/SetFeatureReport.c  -o${OBJECTDIR}/src/SetFeatureReport.o
	
${OBJECTDIR}/src/SetOutputReport.o: src/SetOutputReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/SetOutputReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/SetOutputReport.c  -o${OBJECTDIR}/src/SetOutputReport.o
	
${OBJECTDIR}/src/SetupFeatureReport.o: src/SetupFeatureReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/SetupFeatureReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/SetupFeatureReport.c  -o${OBJECTDIR}/src/SetupFeatureReport.o
	
${OBJECTDIR}/src/SetupOutputReport.o: src/SetupOutputReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/SetupOutputReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/SetupOutputReport.c  -o${OBJECTDIR}/src/SetupOutputReport.o
	
${OBJECTDIR}/src/USBEcho.o: src/USBEcho.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/USBEcho.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/USBEcho.c  -o${OBJECTDIR}/src/USBEcho.o
	
${OBJECTDIR}/src/UserDefs.o: src/UserDefs.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/UserDefs.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/UserDefs.c  -o${OBJECTDIR}/src/UserDefs.o
	
${OBJECTDIR}/src/UserInit.o: src/UserInit.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/UserInit.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/UserInit.c  -o${OBJECTDIR}/src/UserInit.o
	
${OBJECTDIR}/src/checkEcho.o: src/checkEcho.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/checkEcho.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/checkEcho.c  -o${OBJECTDIR}/src/checkEcho.o
	
${OBJECTDIR}/src/hid_defs.o: src/hid_defs.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/hid_defs.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/hid_defs.c  -o${OBJECTDIR}/src/hid_defs.o
	
${OBJECTDIR}/src/init_usart.o: src/init_usart.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/init_usart.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/init_usart.c  -o${OBJECTDIR}/src/init_usart.o
	
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/main.c  -o${OBJECTDIR}/src/main.o
	
${OBJECTDIR}/src/usb.o: src/usb.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/usb.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/usb.c  -o${OBJECTDIR}/src/usb.o
	
${OBJECTDIR}/src/usb_remoto.o: src/usb_remoto.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/usb_remoto.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/usb_remoto.c  -o${OBJECTDIR}/src/usb_remoto.o
	
${OBJECTDIR}/src/wait.o: src/wait.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/wait.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/wait.c  -o${OBJECTDIR}/src/wait.o
	
else
${OBJECTDIR}/src/GetFeatureReport.o: src/GetFeatureReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/GetFeatureReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/GetFeatureReport.c  -o${OBJECTDIR}/src/GetFeatureReport.o
	
${OBJECTDIR}/src/GetInputReport.o: src/GetInputReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/GetInputReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/GetInputReport.c  -o${OBJECTDIR}/src/GetInputReport.o
	
${OBJECTDIR}/src/ProcessIO.o: src/ProcessIO.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/ProcessIO.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/ProcessIO.c  -o${OBJECTDIR}/src/ProcessIO.o
	
${OBJECTDIR}/src/SetFeatureReport.o: src/SetFeatureReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/SetFeatureReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/SetFeatureReport.c  -o${OBJECTDIR}/src/SetFeatureReport.o
	
${OBJECTDIR}/src/SetOutputReport.o: src/SetOutputReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/SetOutputReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/SetOutputReport.c  -o${OBJECTDIR}/src/SetOutputReport.o
	
${OBJECTDIR}/src/SetupFeatureReport.o: src/SetupFeatureReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/SetupFeatureReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/SetupFeatureReport.c  -o${OBJECTDIR}/src/SetupFeatureReport.o
	
${OBJECTDIR}/src/SetupOutputReport.o: src/SetupOutputReport.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/SetupOutputReport.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/SetupOutputReport.c  -o${OBJECTDIR}/src/SetupOutputReport.o
	
${OBJECTDIR}/src/USBEcho.o: src/USBEcho.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/USBEcho.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/USBEcho.c  -o${OBJECTDIR}/src/USBEcho.o
	
${OBJECTDIR}/src/UserDefs.o: src/UserDefs.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/UserDefs.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/UserDefs.c  -o${OBJECTDIR}/src/UserDefs.o
	
${OBJECTDIR}/src/UserInit.o: src/UserInit.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/UserInit.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/UserInit.c  -o${OBJECTDIR}/src/UserInit.o
	
${OBJECTDIR}/src/checkEcho.o: src/checkEcho.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/checkEcho.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/checkEcho.c  -o${OBJECTDIR}/src/checkEcho.o
	
${OBJECTDIR}/src/hid_defs.o: src/hid_defs.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/hid_defs.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/hid_defs.c  -o${OBJECTDIR}/src/hid_defs.o
	
${OBJECTDIR}/src/init_usart.o: src/init_usart.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/init_usart.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/init_usart.c  -o${OBJECTDIR}/src/init_usart.o
	
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/main.c  -o${OBJECTDIR}/src/main.o
	
${OBJECTDIR}/src/usb.o: src/usb.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/usb.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/usb.c  -o${OBJECTDIR}/src/usb.o
	
${OBJECTDIR}/src/usb_remoto.o: src/usb_remoto.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/usb_remoto.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/usb_remoto.c  -o${OBJECTDIR}/src/usb_remoto.o
	
${OBJECTDIR}/src/wait.o: src/wait.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/src 
	${RM} ${OBJECTDIR}/src/wait.o 
	${MP_CC} --debug-ralloc --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -c -mpic16 -p18f4550 src/wait.c  -o${OBJECTDIR}/src/wait.o
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/HID.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC}  --debug-ralloc -Wl-c -Wl-m --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -mpic16 -p18f4550 ${OBJECTFILES}  -odist/${CND_CONF}/${IMAGE_TYPE}/HID.${IMAGE_TYPE}.${OUTPUT_SUFFIX} 
else
dist/${CND_CONF}/${IMAGE_TYPE}/HID.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC}  --debug-ralloc -Wl-c -Wl-m --pstack-model=small "-Wl,-m,-s 18f4550.lkr" -I include/ libc18f.lib libio18f4550.lib -DDEBUG_USB  -DDEBUG_USB_REMOTO -DDEBUG_LED -mpic16 -p18f4550 ${OBJECTFILES}  -odist/${CND_CONF}/${IMAGE_TYPE}/HID.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/DEBUG_LED
	${RM} -r dist/DEBUG_LED

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
