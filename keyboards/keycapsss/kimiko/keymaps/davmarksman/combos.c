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
  ALL,
  QU,
  DM_DAV,
  OBRACK,
  CBRACK,
  SB_BROK,
  OA, 
  ING,
  AK,
  // PY,
  // PI,
  FOR,
  OBRACKR,
  CBRACKR,
  INSU,
  FIND2,
  FIND3,
  // // This must be the last item in the enum.
  // This is used to automatically update the combo count.
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// combo changes  10/10/21
// fd - for
// in - insur
// ok - oa
// k= - Find
// 



const uint16_t PROGMEM qu_combo[] = {KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM sb_combo[] = {KC_S, KC_B, COMBO_END};
const uint16_t PROGMEM obrack_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM cbrack_combo[] = {KC_COMM, KC_E, COMBO_END};
//const uint16_t PROGMEM py_combo[] = {KC_P, KC_EQL, COMBO_END};
const uint16_t PROGMEM oa_combo[] = {KC_O, KC_Z, COMBO_END};
const uint16_t PROGMEM ing_combo[] = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM ak_combo[] = {HOME_CT_A, KC_K, COMBO_END};
const uint16_t PROGMEM for_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM ins_combo[] = {KC_I, KC_B, COMBO_END};


const uint16_t PROGMEM all_combo[] = {KC_Q, KC_Y, COMBO_END};
const uint16_t PROGMEM find2_combo[] = {KC_O, KC_MINS, COMBO_END};
const uint16_t PROGMEM find3_combo[] = {KC_Y, KC_MINS, COMBO_END};


const uint16_t PROGMEM obrackr_combo[] = {KC_P, KC_I, COMBO_END};
const uint16_t PROGMEM cbrackr_combo[] = {KC_O, KC_E, COMBO_END};


combo_t key_combos[] = {
  //[REPLACE] = COMBO_ACTION(rep_combo),
  [QU] = COMBO_ACTION(qu_combo),
  [DM_DAV] = COMBO_ACTION(dv_combo),
  [OBRACK] = COMBO_ACTION(obrack_combo),
  [CBRACK] = COMBO_ACTION(cbrack_combo),
  [SB_BROK] = COMBO_ACTION(sb_combo),
  [OA] = COMBO_ACTION(oa_combo),
  [ING] = COMBO_ACTION(ing_combo),
  [AK] = COMBO_ACTION(ak_combo),
  [FOR] = COMBO_ACTION(for_combo),
  //[PY] = COMBO_ACTION(py_combo),
  [OBRACKR] = COMBO_ACTION(obrackr_combo),
  [CBRACKR] = COMBO_ACTION(cbrackr_combo),
  [INSU] = COMBO_ACTION(ins_combo),
  [ALL] = COMBO_ACTION(all_combo),

  [FIND2] = COMBO_ACTION(find2_combo),
  [FIND3] = COMBO_ACTION(find3_combo),
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

    case FOR:
      word_combo(pressed,mod_state, "For");
      break;
    case ING:
      if (pressed) {
        SEND_STRING("ing");
      }
      break;
    case INSU:
      word_combo(pressed,mod_state, "Insur");
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
    case OBRACKR:
        if (pressed) {
          tap_code16(KC_LCBR);
        }
        break;
    case CBRACKR:
        if (pressed) {
          tap_code16(KC_RCBR);
        }
        break; 
    case QU:
      word_combo(pressed,mod_state, "Qu");
      break; 
    case FIND2:
      if (pressed) {
        tap_code16(C(KC_F));
      }
      break;
    case FIND3:
      if (pressed) {
        tap_code16(C(KC_F));
      }
      break;
    case ALL:
      if (pressed) {
        tap_code16(C(KC_A));
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
    // case PY:
    //   if (pressed) {
    //     SEND_STRING("py");
    //   }
    //   break;
    // case PI:
    //   if (pressed) {
    //     SEND_STRING("py");
    //   }
    //   break;
    case AK:
      if (pressed) {
        SEND_STRING("ak");
      }
      break;
  }
}
