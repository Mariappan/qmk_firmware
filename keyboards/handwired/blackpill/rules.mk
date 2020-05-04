BOOTMAGIC_ENABLE = no	# Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes	    # USB Nkey Rollover
MOUSEKEY_ENABLE = no

DEFAULT_FOLDER = handwired/blackpill/atreus50

DFU_ARGS = -d 1eaf:0003 -a2 -R
DFU_SUFFIX_ARGS = -v 1eaf -p 0003

MCU_LDSCRIPT = STM32F103x8_stm32duino_bootloader
BOARD = STM32_F103_STM32DUINO
