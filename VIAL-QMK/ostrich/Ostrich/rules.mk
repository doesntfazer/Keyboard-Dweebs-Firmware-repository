# MCU name
MCU = RP2040
BOOTLOADER = rp2040
BOARD = GENERIC_RP_RP2040

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes

ENCODER_ENABLE = yes

SRC += mcp23017.c
SRC += matrix.c
CUSTOM_MATRIX = lite

SEND_STRING_ENABLE = yes


EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = rp2040_flash
