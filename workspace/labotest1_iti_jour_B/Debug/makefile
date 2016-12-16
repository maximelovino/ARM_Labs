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
all: labotest1_iti_jour_B.axf

# Tool invocations
labotest1_iti_jour_B.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"Z:\PROC\workspace\CMSIS_CORE_LPC17xx\Debug" -Xlinker -Map="labotest1_iti_jour_B.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "labotest1_iti_jour_B_Debug.ld" -o "labotest1_iti_jour_B.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) labotest1_iti_jour_B.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "labotest1_iti_jour_B.axf"; # arm-none-eabi-objcopy -v -O binary "labotest1_iti_jour_B.axf" "labotest1_iti_jour_B.bin" ; # checksum -p LPC1769 -d "labotest1_iti_jour_B.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
