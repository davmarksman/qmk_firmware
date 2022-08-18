#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

/*
* Combos
*/
enum combos {
  REPLACE,
  ALL,
  COPY,
  PASTE,

  QU,
  DM_DAV,
  OBRACK,
  CBRACK,
  SB_BROK,
  ING,
  BL,
  OU,
  CL,
  // // This must be the last item in the enum.
  // This is used to automatically update the combo count.
  COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM qu_combo[] = {KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM gx_combo[] = {KC_G, KC_X, COMBO_END};
const uint16_t PROGMEM ps_combo[] = {KC_P, KC_S, COMBO_END};
const uint16_t PROGMEM cm_combo[] = {KC_C, KC_M, COMBO_END};

const uint16_t PROGMEM ing_combo[] = {KC_I, KC_E, COMBO_END};

const uint16_t PROGMEM fb_combo[] = {KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM ou_combo[] = { KC_MINS, KC_O, COMBO_END};


const uint16_t PROGMEM obrack_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM cbrack_combo[] = {KC_O, KC_E, COMBO_END};

const uint16_t PROGMEM all_combo[] = {KC_Q, KC_Y, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_K, KC_DOT, COMBO_END}; 
const uint16_t PROGMEM paste_combo[] = {KC_U, KC_DOT, COMBO_END}; 


combo_t key_combos[] = {
  [QU] = COMBO_ACTION(qu_combo),
  [DM_DAV] = COMBO_ACTION(gx_combo),
  [OBRACK] = COMBO_ACTION(obrack_combo),
  [CBRACK] = COMBO_ACTION(cbrack_combo),
  [SB_BROK] = COMBO_ACTION(ps_combo),
  [ING] = COMBO_ACTION(ing_combo),
  [BL] = COMBO_ACTION(fb_combo),
  [OU] = COMBO_ACTION(ou_combo),
  [CL] = COMBO_ACTION(cm_combo),

  [ALL] = COMBO_ACTION(all_combo),
  [COPY] = COMBO_ACTION(copy_combo),
  [PASTE] = COMBO_ACTION(paste_combo),
};

void word_combo(bool pressed, uint8_t mod_state, char* word) {
  if (pressed) {
    if (mod_state & MOD_MASK_SHIFT) {
      del_mods(MOD_MASK_SHIFT);
      send_string(word);
      set_mods(mod_state);
    }
    else {
      word[0] = word[0] + 32; // make first char lower
      send_string(word);
      word[0] = word[0] - 32; // reset
    }
  }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
#ifdef CONSOLE_ENABLE
    if (pressed) {
        combo_t *combo = &key_combos[combo_index];
        uint8_t idx = 0;
        uint16_t combo_keycode;
        while ((combo_keycode = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
            uprintf("0x%04X,NA,NA,%u\n", combo_keycode, get_highest_layer(layer_state));
            idx++;
        }
    }
#endif

  mod_state = get_mods();
  switch(combo_index) {
    case ING:
      if (pressed) {
        SEND_STRING("ing");
      }
      break;
    case OBRACK:
        if (pressed) {
          tap_code16(KC_LCBR);
        }
        break;
    case CBRACK:
        if (pressed) {
          tap_code16(KC_RCBR);
        }
        break; 
    case QU:
      word_combo(pressed,mod_state, "Qu");
      break; 
    case BL:
      word_combo(pressed,mod_state, "Bl");
      break; 
    case OU:
      word_combo(pressed,mod_state, "Ou");
      break; 
    case ALL:
      if (pressed) {
        tap_code16(C(KC_A));
      }
      break;
    case COPY:
      if (pressed) {
        tap_code16(C(KC_C));
      }
      break;
    case PASTE:
      if (pressed) {
        tap_code16(C(KC_V));
      }
      break;

    case DM_DAV:
      if (pressed) {
      word_combo(pressed,mod_state, "David");
      }
      break;
    case SB_BROK:
      word_combo(pressed,mod_state, "Brok");
      break;
    case CL:
      if (pressed) {
        SEND_STRING("cl");
      }
      break;
  }
}


