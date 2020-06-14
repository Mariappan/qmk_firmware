## chip/board settings
# the next two should match the directories in
#  <chibios>/os/hal/ports/$(MCU_FAMILY)/$(MCU_SERIES)
MCU_FAMILY = STM32
MCU_SERIES = STM32F1xx
# linker script to use
# it should exist either in <chibios>/os/common/ports/ARMCMx/compilers/GCC/ld/
#  or <this_dir>/ld/
MCU_LDSCRIPT = STM32F103x8_stm32duino_bootloader
# startup code to use
# is should exist in <chibios>/os/common/startup/ARMCMx/compilers/GCC
MCU_STARTUP = stm32f1xx
# it should exist either in <chibios>/os/hal/boards/
#  or <this_dir>/boards
BOARD = STM32_F103_STM32DUINO
# Cortex version
MCU  = cortex-m3
# ARM version, CORTEX-M0/M1 are 6, CORTEX-M3/M4/M7 are 7
ARMV = 7
USE_FPU = no

# Address of the booloader in system memory
STM32_BOOTLOADER_ADDRESS ?= 0x08000000

# Options to pass to dfu-util when flashing
DFU_ARGS = -d 1eaf:0003 -a 2
DFU_SUFFIX_ARGS = -v 1eaf -p 0003

# Build Options
#   change yes to no to disable
#
KEYBOARD_SHARED_EP       = yes

# To enable onboard LED
OLED_DRIVER_ENABLE = yes
