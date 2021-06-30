################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/timer/subdir.mk
-include MCAL/UART/subdir.mk
-include LIB/string/subdir.mk
-include HAL/LCD/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
VendingMachine-rx.lss \

FLASH_IMAGE += \
VendingMachine-rx.hex \

EEPROM_IMAGE += \
VendingMachine-rx.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: VendingMachine-rx.elf secondary-outputs

# Tool invocations
VendingMachine-rx.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,VendingMachine-rx.map -mmcu=atmega16 -o "VendingMachine-rx.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

VendingMachine-rx.lss: VendingMachine-rx.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S VendingMachine-rx.elf  >"VendingMachine-rx.lss"
	@echo 'Finished building: $@'
	@echo ' '

VendingMachine-rx.hex: VendingMachine-rx.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex VendingMachine-rx.elf  "VendingMachine-rx.hex"
	@echo 'Finished building: $@'
	@echo ' '

VendingMachine-rx.eep: VendingMachine-rx.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex VendingMachine-rx.elf  "VendingMachine-rx.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: VendingMachine-rx.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 VendingMachine-rx.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) VendingMachine-rx.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
