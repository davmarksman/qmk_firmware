// DavNav
// keyboards\handwired\6davkey\keymaps\default\keymap.c

// qmk compile -kb handwired/_davNav -km default
#include QMK_KEYBOARD_H


// layers
enum layer_names {
    BASE,
    SYS,
};


// layer keys
#define LSYS_HOME LT(SYS,KC_HOME)
#define KT_C_END LCTL_T(KC_END)
#define LSYS LT(SYS,KC_NO)
#define K_UNDO LCTL(KC_Z)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    LSYS_HOME  ,KC_UP    ,KT_C_END   , 
    KC_LEFT    ,KC_DOWN  ,KC_RGHT   ,K_UNDO
  ),
  [SYS] = LAYOUT(
    KC_NO     ,KC_NO     ,RESET     ,
    KC_NO     ,KC_NO     ,KC_NO     ,KC_NO   
  )
};


void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code16(C(KC_Y));
  } else {
    tap_code16(C(KC_Z));
  }
}

