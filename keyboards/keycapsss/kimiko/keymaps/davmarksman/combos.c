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
  KU_QU,
  FO_FOR,
  TD_THE,
  TF_TH,
  TN_ENT,
  IN_ING,
  ON_ION,
  DN_AND, 
  DM_DAV, 
  BK_BROK, 
  MV_MARK,
  VA_VAR,
  
  // Shortcuts
  BM_COPY,//xc qwertymd
  MD_PASTE, //cv qwerty
  BX_UNDO, // xz qwerty
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
const uint16_t PROGMEM tn_combo[] = {KC_T, LSYN_N, COMBO_END};
const uint16_t PROGMEM in_combo[] = {KC_I, LSYN_N, COMBO_END};
const uint16_t PROGMEM on_combo[] = {KC_O, LSYN_N, COMBO_END};
const uint16_t PROGMEM dn_combo[] = {KC_D, LSYN_N, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM bk_combo[] = {KC_B, KC_K, COMBO_END};
const uint16_t PROGMEM mv_combo[] = {KC_M, KC_V, COMBO_END};
const uint16_t PROGMEM va_combo[] = {KC_V, KC_A, COMBO_END};

  // Shortcuts
const uint16_t PROGMEM bm_combo[] = {KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM md_combo[] = {KC_M, KC_D, COMBO_END};
const uint16_t PROGMEM bx_combo[] = {KC_B, KC_X, COMBO_END};
const uint16_t PROGMEM cl_combo[] = {KC_C, KC_L, COMBO_END};
const uint16_t PROGMEM lf_combo[] = {KC_F, KC_L, COMBO_END};


combo_t key_combos[] = {
  [KU_QU] = COMBO_ACTION(ku_combo),
  [FO_FOR] = COMBO_ACTION(fo_combo),
  [TD_THE] = COMBO_ACTION(td_combo),
  [TF_TH] = COMBO_ACTION(tf_combo),
  [TN_ENT] = COMBO_ACTION(tn_combo),
  [IN_ING] = COMBO_ACTION(in_combo),
  [ON_ION] = COMBO_ACTION(on_combo),
  [DN_AND] = COMBO_ACTION(dn_combo),
  [DM_DAV] = COMBO_ACTION(dv_combo),
  [BK_BROK] = COMBO_ACTION(bk_combo),
  [MV_MARK] = COMBO_ACTION(mv_combo),
  [VA_VAR] = COMBO_ACTION(va_combo),

  // Shortcuts
  [BM_COPY] = COMBO_ACTION(bm_combo),
  [MD_PASTE] = COMBO_ACTION(md_combo),
  [BX_UNDO] = COMBO_ACTION(bx_combo),
  [CL_ALL] = COMBO_ACTION(cl_combo),
  [LF_FIND] = COMBO_ACTION(lf_combo),
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
    case TN_ENT:
      word_combo(pressed,mod_state, "Ent");
      break;
    case IN_ING:
      if (pressed) {
        SEND_STRING("ing");
      }
      break;
    case ON_ION:
      if (pressed) {
        SEND_STRING("ion");
      }
      break;
    case DN_AND:
      word_combo(pressed,mod_state, "And");
      break;
    case DM_DAV:
      word_combo(pressed,mod_state, "David");
      break;
    case BK_BROK:
      word_combo(pressed,mod_state, "Broker");
      break;
    case MV_MARK:
      word_combo(pressed,mod_state, "Mark");
      break;
    case VA_VAR:
      word_combo(pressed,mod_state, "Var");
      break;

    // Shortcuts
    case BM_COPY:
      if (pressed) {
        tap_code16(C(KC_C));
      }
      break;
    case MD_PASTE:
      if (pressed) {
        tap_code16(C(KC_V));
      }
      break;
    case BX_UNDO:
      if (pressed) {
        tap_code16(C(KC_Z));
      }
      break;
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
  }
}