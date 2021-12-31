// Plaid
// qmk compile -kb keycapsss/plaid_pad -km davmarksman

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _FNPAD,
    _APPS,
    _NAV,
    _MEDIA
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
#define LMEDIA TO(_MEDIA)

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
        LAPP,      KC_LSFT,     KC_LCTL,  LNAV,
        KC_F1,     KC_F2,       KC_F3,    KC_F4,
        KC_F5,     KC_F6,       KC_F7,    KC_F8,
        KC_F9,     KC_F10,      KC_F11,   KC_F12
    ),
    [_APPS] = LAYOUT_ortho_4x4(
        LFN,       K_SAVE,      K_SAVE,     LNAV,
        G(KC_6),   G(KC_7),     G(KC_8),    G(KC_9),
        KA_FIREFX, KA_CHROME,   KA_NOTE,    G(KC_0),
        KA_VSCODE, KA_VS19,     KA_EXPLR,   XXXXXXX
    ),
    /* Navigation/MEDIA layer
    */
    [_NAV] = LAYOUT_ortho_4x4(
        LAPP,      XXXXXXX,     KC_UP,      LFN,
        KC_LSFT,   KC_LEFT,     KC_DOWN,    KC_RGHT,
        KC_LCTL,   KC_HOME,     KC_UP,      KC_END,             
        XXXXXXX,   KC_LEFT,     KC_DOWN,    KC_RGHT             
    ),
    [_MEDIA] = LAYOUT_ortho_4x4(
        LFN,      XXXXXXX,      XXXXXXX,    LFN,
        XXXXXXX,   XXXXXXX,     XXXXXXX,    XXXXXXX,
        XXXXXXX,   KC_MPRV     ,KC_MPLY,    KC_MNXT,             
        XXXXXXX,   XXXXXXX,     XXXXXXX,    XXXXXXX             
    )
};

// Combos for switching layers
// const uint16_t PROGMEM zeroDot_combo[] = {KC_P0, KC_PDOT, COMBO_END};
// const uint16_t PROGMEM leftDown_combo[] = {KC_LEFT, KC_DOWN, COMBO_END};
// const uint16_t PROGMEM prevPlay_combo[] = {KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, COMBO_END};
const uint16_t PROGMEM layer_combo[] = {LAPP, LNAV, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO1] = COMBO_ACTION(layer_combo),
  // [COMBO2] = COMBO_ACTION(leftDown_combo),
  // [COMBO3] = COMBO_ACTION(prevPlay_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO1:
      if (pressed) {
        layer_move(_MEDIA);
      }
      break;
    // case COMBO2:
    //   if (pressed) {
    //     layer_move(_MEDIA);
    //   }
    //   break;
    // case COMBO3:
    //   if (pressed) {
    //     layer_move(_NUMPAD);
    //   }
    //   break;
  }
}

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
    if (clockwise) {
        tap_code16(KC_DOWN);
    } else {
        tap_code16(KC_UP);
    }
  // Second encoder (E2)
  } else if (index == 1) {
    if (clockwise) {
        tap_code16(KC_AUDIO_VOL_UP);
    } else {
        tap_code16(KC_AUDIO_VOL_DOWN);
    }
  // Third encoder (E3)
  } else if (index == 2) {
    if (clockwise) {
        tap_code16(KC_AUDIO_VOL_UP);
    } else {
        tap_code16(KC_AUDIO_VOL_DOWN);
    }
  // Forth encoder (E4)
  } else if (index == 3) {
    if (clockwise) {
        tap_code16(KC_DOWN);
    } else {
        tap_code16(KC_UP);
    }
  }
    return true;
}
#endif
