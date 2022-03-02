// Plaid
// qmk compile -kb keycapsss/plaid_pad -km davmarksman

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _FNPAD,
    _APPS,
    _NAV,
    // _MEDIA
};

enum combos {
  COMBO1,
  //COMBO2,
  //COMBO3
};

// layer keys
#define LFN TO(_FNPAD)
#define LAPP TO(_APPS)
#define LNAV TO(_NAV)
// #define LMEDIA TO(_MEDIA)

// Apps
#define K_CLIP C(A(KC_C))  // Paste Clipboard
#define KA_FIREFX KC_F17
#define KA_VSCODE KC_F18
#define KA_CHROME KC_F15
#define KA_VS19 KC_F16
#define K_SAVE C(KC_S)
#define KA_NOTE KC_F13
#define KA_APP2 KC_F14
#define KA_VOL KC_F20
#define KA_EXPLR G(KC_1)
#define KA_NEXPLR G(S(KC_1))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_FNPAD] = LAYOUT_ortho_4x4(
        LAPP,      K_SAVE,      XXXXXXX,  LNAV,
        KC_F1,     KC_F2,       KC_F3,    KC_F4,
        KC_F5,     KC_F6,       KC_F7,    KC_F8,
        KC_F9,     KC_F10,      KC_F11,   KC_F12
    ),
    [_APPS] = LAYOUT_ortho_4x4(
        LFN,       K_SAVE,      XXXXXXX,     XXXXXXX,
        KA_FIREFX, KA_CHROME,   KA_VSCODE,   KA_VS19, 
        KA_NOTE,   G(KC_6),     G(KC_7),     G(KC_8),    
        G(KC_9),   G(KC_0),     XXXXXXX,    XXXXXXX
    ),
    [_NAV] = LAYOUT_ortho_4x4(
        LFN,       KC_HOME,     KC_PGUP,    XXXXXXX,
        KC_LSFT,   KC_END,      KC_PGDN,    XXXXXXX,
        KC_LCTL,   XXXXXXX,     KC_UP,      XXXXXXX,             
        XXXXXXX,   KC_LEFT,     KC_DOWN,    KC_RGHT             
    ),
    // Add game pad layer
};

#ifdef OLED_ENABLE

void render_space(void) {
  oled_write_P(PSTR("     "), false);
}


void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer: "), false);
  if(layer_state_is(_FNPAD)) {
    oled_write_ln_P(PSTR("FUNCTIONS"), false);
  } else if(layer_state_is(_APPS)) {
    oled_write_ln_P(PSTR("APPS - PROGRAM"), false);
  } else if(layer_state_is(_NAV)) {
    oled_write_ln_P(PSTR("NAVIGATION"), false);
  } else {
    oled_write_ln_P(PSTR("MEDIA"), false);
  }
}


void oled_task_user(void) {
  oled_write_ln_P(PSTR("Plaid-Pad ///////////"), false);
  oled_render_layer_state();
}

#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
/*
    ,-----------------------,
    |  E1 |  E2 |  E3 |  E4 |
    |-----+-----+-----+-----|
    |     |     |     |  E3 |
    |-----+-----+-----+-----|
    |     |     |     |  E2 |
    |-----+-----+-----+-----|
    |     |     |     |  E1 |
    `-----------------------'
 */

  // First encoder (E1)
  if (index == 0) {
    switch (get_highest_layer(layer_state)) {
      // change layers
      case _FNPAD:
        if (clockwise) {
          layer_move(_APPS);
        } else {
          layer_move(_NAV);
        }
        break;
      case _APPS:
        if (clockwise) {
          layer_move(_NAV);
        } else {
          layer_move(_FNPAD);
        }
        break;
      case _NAV:
        if (clockwise) {
          layer_move(_FNPAD);
        } else {
          layer_move(_APPS);
        }
        break;
    }

  // Forth encoder (E4)
  } else if (index == 3) {
    // brower tabing
    if (clockwise) {
      tap_code16(C(KC_TAB));
    } else {
      tap_code16(S(C(KC_TAB)));
    }
  }
    return true;
}
#endif
