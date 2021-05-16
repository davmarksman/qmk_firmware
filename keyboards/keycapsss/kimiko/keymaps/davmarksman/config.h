
#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define OLED_FONT_H "keyboards/keycapsss/kimiko/keymaps/default/glcdfont.c"
// #define OLED_FONT_WIDTH 5
// #define OLED_FONT_HEIGHT 7

#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_HUE_STEP 8
#   define RGBLIGHT_SAT_STEP 8
#   define RGBLIGHT_VAL_STEP 8
#   define RGBLIGHT_SLEEP       /* the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
#   define RGBLIGHT_ANIMATIONS
/*== or choose animations to save space ==*/
// #   define RGBLIGHT_EFFECT_BREATHING
// #   define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #   define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #   define RGBLIGHT_EFFECT_SNAKE
// #   define RGBLIGHT_EFFECT_KNIGHT
// #   define RGBLIGHT_EFFECT_CHRISTMAS
// #   define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #   define RGBLIGHT_EFFECT_RGB_TEST
// #   define RGBLIGHT_EFFECT_ALTERNATING
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

// Home row mods settings //
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 220
#define COMBO_TERM 70

// Limits the max. amount of layers to 8 to save firmware memory.
#define LAYER_STATE_8BIT

#define ONESHOT_TIMEOUT 1500  /* Time (in ms) before the one shot key is released */

#define COMBO_COUNT 8

/* Change encoder resolution to lower value*/
#define ENCODER_RESOLUTION 2


/* State on both hands */
#define SPLIT_MODS_ENABLE