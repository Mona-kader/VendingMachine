################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include HAL/keypad/subdir.mk
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
VendingMachine-tx.lss \

FLASH_IMAGE += \
VendingMachine-tx.hex \

EEPROM_IMAGE += \
VendingMachine-tx.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: VendingMachine-tx.elf secondary-outputs

# Tool invocations
VendingMachine-tx.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,VendingMachine-tx.map -mmcu=atmega16 -o "VendingMachine-tx.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

VendingMachine-tx.lss: VendingMachine-tx.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S VendingMachine-tx.elf  >"VendingMachine-tx.lss"
	@echo 'Finished building: $@'
	@echo ' '

VendingMachine-tx.hex: VendingMachine-tx.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex VendingMachine-tx.elf  "VendingMachine-tx.hex"
	@echo 'Finished building: $@'
	@echo ' '

VendingMachine-tx.eep: VendingMachine-tx.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex VendingMachine-tx.elf  "VendingMachine-tx.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: VendingMachine-tx.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 VendingMachine-tx.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) VendingMachine-tx.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
