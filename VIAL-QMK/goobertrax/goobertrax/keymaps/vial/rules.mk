# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

ENCODER_ENABLE = no

AUDIO_SUPPORTED = no        # Audio is not supported
RGB_MATRIX_SUPPORTED = yes  # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = no     # RGB underglow is supported, but not enabled by default
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360

# RP2040-specific options
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.
TRI_LAYER_ENABLE = yes
SEND_STRING_ENABLE = yes
COMBO_ENABLE = yes
#CONSOLE_ENABLE = yes
VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes
EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = rp2040_flash
