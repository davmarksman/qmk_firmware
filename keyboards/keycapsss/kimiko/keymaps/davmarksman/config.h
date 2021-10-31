
#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define OLED_FONT_H "keyboards/keycapsss/kimiko/keymaps/default/glcdfont.c"
 

// Home row mods settings //
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200
#define COMBO_TERM 40
#define ADAPTIVE_TERM 200

// Limits the max. amount of layers to 8 to save firmware memory.
#define LAYER_STATE_8BIT

#define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is released */



/* State on both hands */
#define SPLIT_MODS_ENABLE


#define ENCODER_RESOLUTIONS { 2, 4 }