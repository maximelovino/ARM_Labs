################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPIO.c \
../src/cr_startup_lpc175x_6x.c \
../src/lcd.c 

OBJS += \
./src/GPIO.o \
./src/cr_startup_lpc175x_6x.o \
./src/lcd.o 

C_DEPS += \
./src/GPIO.d \
./src/cr_startup_lpc175x_6x.d \
./src/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSIS_CORE_LPC17xx -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM3 -D__LPC17XX__ -I"/Users/maximelovino/Google Drive/HEPIA/2016-2017/IT_231 - Processeurs/LABS/workspace/MyLab_lib/inc" -I"/Users/maximelovino/Google Drive/HEPIA/2016-2017/IT_231 - Processeurs/LABS/workspace/CMSIS_CORE_LPC17xx/inc" -I"/Users/maximelovino/Google Drive/HEPIA/2016-2017/IT_231 - Processeurs/LABS/workspace/MyLab_lib/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


