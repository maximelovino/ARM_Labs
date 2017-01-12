################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: labo5_Interruptions_GPIO-TIMER.axf

# Tool invocations
labo5_Interruptions_GPIO-TIMER.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/Users/maximelovino/Google Drive/HEPIA/2016-2017/IT_231 - Processeurs/LABS/workspace/MyLab_lib/Debug" -L"/Users/maximelovino/Google Drive/HEPIA/2016-2017/IT_231 - Processeurs/LABS/workspace/CMSIS_CORE_LPC17xx/Debug" -Xlinker -Map="labo5_Interruptions_GPIO-TIMER.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "labo5_Interruptions_GPIO-TIMER_Debug.ld" -o "labo5_Interruptions_GPIO-TIMER.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) labo5_Interruptions_GPIO-TIMER.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "labo5_Interruptions_GPIO-TIMER.axf"; # arm-none-eabi-objcopy -v -O binary "labo5_Interruptions_GPIO-TIMER.axf" "labo5_Interruptions_GPIO-TIMER.bin" ; # checksum -p LPC1769 -d "labo5_Interruptions_GPIO-TIMER.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
