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
  FIND,
  REPLACE,
  QU,
  YOU,
  DM_DAV,
  OBRACK,
  CBRACK,
  SB_BROK,
  OA, 
  ING,
  AY,
  // // This must be the last item in the enum.
  // This is used to automatically update the combo count.
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM find_combo[] = {KC_O, KC_K, COMBO_END};
const uint16_t PROGMEM rep_combo[] = {KC_K, KC_EQL, COMBO_END};
const uint16_t PROGMEM qu_combo[] = {KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM sb_combo[] = {KC_S, KC_B, COMBO_END};
const uint16_t PROGMEM obrack_combo[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM cbrack_combo[] = {KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM u_combo[] = {KC_P, KC_O, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM ing_combo[] = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM ay_combo[] = {HOME_CT_A, KC_Y, COMBO_END};


combo_t key_combos[] = {
  [FIND] = COMBO_ACTION(find_combo),
  [REPLACE] = COMBO_ACTION(rep_combo),
  [QU] = COMBO_ACTION(qu_combo),
  [YOU] = COMBO_ACTION(u_combo),
  [DM_DAV] = COMBO_ACTION(dv_combo),
  [OBRACK] = COMBO_ACTION(obrack_combo),
  [CBRACK] = COMBO_ACTION(cbrack_combo),
  [SB_BROK] = COMBO_ACTION(sb_combo),
  [OA] = COMBO_ACTION(oe_combo),
  [ING] = COMBO_ACTION(ing_combo),
  [AY] = COMBO_ACTION(ay_combo),
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

    // case FO_FOR:
    //   word_combo(pressed,mod_state, "For");
    //   break;
    case ING:
      if (pressed) {
        SEND_STRING("ing");
      }
      break;
    // case IO_ION:
    //   if (pressed) {
    //     SEND_STRING("ion");
    //   }
    //   break;
    // case EO_ION:
    //   if (pressed) {
    //     SEND_STRING("ion");
    //   }
    //   break;
    //case IY_INSU:
    //  word_combo(pressed,mod_state, "Insurance");
    //  break;
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
    case YOU:
      word_combo(pressed,mod_state, "You");
      break;    
    case QU:
      word_combo(pressed,mod_state, "Qu");
      break; 
    case FIND:
      if (pressed) {
        tap_code16(C(KC_F));
      }
      break;
    case REPLACE:
      if (pressed) {
        tap_code16(C(KC_H));
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
    case OA:
      if (pressed) {
        SEND_STRING("oa");
      }
      break;
    case AY:
      if (pressed) {
        SEND_STRING("ay");
      }
      break;
  }
}
