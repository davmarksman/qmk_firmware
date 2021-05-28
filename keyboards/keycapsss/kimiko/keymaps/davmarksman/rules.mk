BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = no 
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
ENCODER_ENABLE = yes       # ENables the use of one or more encoders
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
SLEEP_LED_ENABLE = no

TAP_DANCE_ENABLE = yes      # Enable tap dance
COMBO_ENABLE = yes

OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
WPM_ENABLE = yes

# LTO: Link Time Optimizations.
# Reduce compiled size, but will automatically disable the legacy TMK Macros and Functions features.
# This does not affect QMK Macros and Layers
LTO_ENABLE = yes

ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += combos.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    SRC += oled.c
endif
