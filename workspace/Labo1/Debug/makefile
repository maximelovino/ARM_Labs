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
all: Labo1.axf

# Tool invocations
Labo1.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"Z:\PROC\workspace\CMSIS_CORE_LPC17xx\Debug" -L"Z:\PROC\workspace\MyLab_lib\Debug" -L"Z:\PROC\workspace\MyLab_lib\Debug\src" -Xlinker -Map="Labo1.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "Labo1_Debug.ld" -o "Labo1.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Labo1.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Labo1.axf"; # arm-none-eabi-objcopy -v -O binary "Labo1.axf" "Labo1.bin" ; # checksum -p LPC1769 -d "Labo1.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
