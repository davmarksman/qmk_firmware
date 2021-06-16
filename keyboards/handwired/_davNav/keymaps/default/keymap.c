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

// Apps
#define KA_RENAME KC_F2
#define KA_FIREFX KC_F17
#define KA_VSCODE KC_F18
#define KA_CHROME KC_F15
#define KA_VS19 KC_F16
#define KA_APP1 KC_F13
#define KA_APP2 KC_F14
#define KA_VOL KC_F20
#define KA_EXPLR G(KC_E)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KA_FIREFX  ,KA_CHROME    ,KA_APP1   , 
    KA_VSCODE    ,KA_VS19  ,KA_APP2   ,LSYS
  ),
  [SYS] = LAYOUT(
    RESET     ,KC_NO     ,RESET     ,
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

