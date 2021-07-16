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
  // words
  TD_THE, // vertical
  TF_TH, 
  IP_AND,  
  UH_YOU, // horizontal 
  DM_DAV,  
  FO_FOR, // 2 hands
  BK_BROK,
  IY_INSU,

  // horizontal letters
  KU_QU,
  BM_BL, 
  OBRACK,
  CBRACK,

  // Horizontal endings
  IE_ING,
  IO_ION,
  EO_ION,

  // Common words


  // Shortcuts
  CL_ALL, // we qwerty
  LF_FIND, // er qwerty

  // This must be the last item in the enum.
  // This is used to automatically update the combo count.
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;


const uint16_t PROGMEM ku_combo[] = {KC_K, KC_U, COMBO_END};
const uint16_t PROGMEM fo_combo[] = {KC_F, KC_O, COMBO_END};  
const uint16_t PROGMEM td_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM tf_combo[] = {KC_T, KC_F, COMBO_END};
const uint16_t PROGMEM tn_combo[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM en_combo[] = {KC_E, KC_N, COMBO_END};

const uint16_t PROGMEM ip_combo[] = {KC_I, KC_P, COMBO_END};

const uint16_t PROGMEM ie_combo[] = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};

const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM bk_combo[] = {KC_B, KC_K, COMBO_END};
const uint16_t PROGMEM bm_combo[] = {KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM mn_combo[] = {KC_M, KC_N, COMBO_END};
const uint16_t PROGMEM iy_combo[] = {KC_I, KC_Y, COMBO_END};
const uint16_t PROGMEM uh_combo[] = {KC_U, KC_H, COMBO_END};


// Shortcuts
const uint16_t PROGMEM cl_combo[] = {KC_C, KC_L, COMBO_END};
const uint16_t PROGMEM lf_combo[] = {KC_F, KC_L, COMBO_END};

const uint16_t PROGMEM pcom_combo[] = {KC_P, KC_COMM, COMBO_END};
const uint16_t PROGMEM md_combo[] = {KC_M, KC_D, COMBO_END};


combo_t key_combos[] = {
  [KU_QU] = COMBO_ACTION(ku_combo),
  [FO_FOR] = COMBO_ACTION(fo_combo),
  [TD_THE] = COMBO_ACTION(td_combo),
  [TF_TH] = COMBO_ACTION(tf_combo),
  [IP_AND] = COMBO_ACTION(ip_combo),

  [IE_ING] = COMBO_ACTION(ie_combo),
  [IO_ION] = COMBO_ACTION(io_combo),
  [EO_ION] = COMBO_ACTION(oe_combo),

  [DM_DAV] = COMBO_ACTION(dv_combo),
  [BK_BROK] = COMBO_ACTION(bk_combo),
  [BM_BL] = COMBO_ACTION(bm_combo),
  [IY_INSU] = COMBO_ACTION(iy_combo),
  [UH_YOU] = COMBO_ACTION(uh_combo),

  // Shortcuts
  [CL_ALL] = COMBO_ACTION(cl_combo),
  [LF_FIND] = COMBO_ACTION(lf_combo),

  // Symbols
  [OBRACK] = COMBO_ACTION(md_combo),
  [CBRACK] = COMBO_ACTION(pcom_combo),
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
    case KU_QU:
      word_combo(pressed,mod_state, "Qu");
      break;
    case FO_FOR:
      word_combo(pressed,mod_state, "For");
      break;
    case TD_THE:
      word_combo(pressed,mod_state, "The");
      break;
    case TF_TH:
      word_combo(pressed,mod_state, "Th");
      break;
    case IP_AND:
      word_combo(pressed,mod_state, "And");
      break;

    case IE_ING:
      if (pressed) {
        SEND_STRING("ing");
      }
      break;
    case IO_ION:
      if (pressed) {
        SEND_STRING("ion");
      }
      break;
    case EO_ION:
      if (pressed) {
        SEND_STRING("ion");
      }
      break;


    case DM_DAV:
      if (pressed) {
        SEND_STRING("David");
      }
      break;
    case BK_BROK:
      word_combo(pressed,mod_state, "Brok");
      break;
    case BM_BL:
      word_combo(pressed,mod_state, "Bl");
      break;
    case IY_INSU:
      word_combo(pressed,mod_state, "Insurance");
      break;
    case UH_YOU:
      word_combo(pressed,mod_state, "You");
      break;
    // Shortcuts
    case CL_ALL:
      if (pressed) {
        tap_code16(C(KC_A));
      }
      break;
    case LF_FIND:
      if (pressed) {
        tap_code16(C(KC_F));
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
  }
}
