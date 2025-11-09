################################################################################
# MAKEFILE COMPATIBLE CON XPACK BUILD TOOLS (LINUX STYLE)
################################################################################

TARGET = Stepper
BUILD_DIR = build

CC = arm-none-eabi-gcc
AS = arm-none-eabi-gcc -x assembler-with-cpp
CP = arm-none-eabi-objcopy
SZ = arm-none-eabi-size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

C_SOURCES = $(wildcard Core/Src/*.c) $(wildcard Drivers/STM32F1xx_HAL_Driver/Src/*.c)
ASM_SOURCES = Core/Startup/startup_stm32f103c8tx.s

C_INCLUDES = -ICore/Inc -ICore/Src -IDrivers/STM32F1xx_HAL_Driver/Inc \
             -IDrivers/STM32F1xx_HAL_Driver/Inc/Legacy \
             -IDrivers/CMSIS/Device/ST/STM32F1xx/Include -IDrivers/CMSIS/Include

C_DEFS = -DUSE_HAL_DRIVER -DSTM32F103xB
MCU = -mcpu=cortex-m3 -mthumb
OPT = -Og -g -Wall -fdata-sections -ffunction-sections
CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -std=c99
LDSCRIPT = STM32F103C8TX_FLASH.ld
LIBS = -lc -lm -lnosys
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--gc-sections

OBJECTS = $(addprefix $(BUILD_DIR)/,$(C_SOURCES:.c=.o))
OBJECTS += $(addprefix $(BUILD_DIR)/,$(ASM_SOURCES:.s=.o))

all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@echo Compilando $<
	@$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@echo Ensamblando $<
	@$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	@echo Ligando $@
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	@$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@$(HEX) $< $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@$(BIN) $< $@

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all clean