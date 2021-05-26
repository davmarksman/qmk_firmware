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
  OR_FOR, 
  DM_DAV, 
  BR_BROK, 
  BO_BROK,

  // Shortcuts
  BM_COPY,//xc qwerty
  BD_PASTE, //cv qwerty
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
const uint16_t PROGMEM or_combo[] = {KC_O, KC_R, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM br_combo[] = {KC_B, HOME_C_R, COMBO_END};
const uint16_t PROGMEM bo_combo[] = {KC_B, KC_O, COMBO_END};

const uint16_t PROGMEM bm_combo[] = {KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM bd_combo[] = {KC_B, KC_D, COMBO_END};
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
  [OR_FOR] = COMBO_ACTION(or_combo), // maybe remove
  [DM_DAV] = COMBO_ACTION(dv_combo),
  [BR_BROK] = COMBO_ACTION(br_combo),
  [BO_BROK] = COMBO_ACTION(bo_combo),
  [BM_COPY] = COMBO_ACTION(bm_combo),
  [BD_PASTE] = COMBO_ACTION(bd_combo),
  [CL_ALL] = COMBO_ACTION(cl_combo),
  [LF_FIND] = COMBO_ACTION(lf_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  mod_state = get_mods();

  switch(combo_index) {
    case KU_QU:
      if (pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            send_string("Qu");
            set_mods(mod_state);
        }
        else {
            send_string("qu");
        }
      }
      break;
    case FO_FOR:
      if (pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            send_string("For");
            set_mods(mod_state);
        }
        else {
            send_string("for");
        }
      }
      break;
    case TD_THE:
      if (pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            send_string("The");
            set_mods(mod_state);
        }
        else {
            send_string("the");
        }
      }
      break;
    case TF_TH:
      if (pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            send_string("Th");
            set_mods(mod_state);
        }
        else {
            send_string("th");
        }
      }
      break;
    case TN_ENT:
      if (pressed) {
        SEND_STRING("ent");
      }
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
      if (pressed) {
          if (mod_state & MOD_MASK_SHIFT) {
              del_mods(MOD_MASK_SHIFT);
              send_string("And");
              set_mods(mod_state);
          }
          else {
              send_string("and");
          }
        }
        break;
    case OR_FOR:
      if (pressed) {
          if (mod_state & MOD_MASK_SHIFT) {
              del_mods(MOD_MASK_SHIFT);
              send_string("For");
              set_mods(mod_state);
          }
          else {
              send_string("for");
          }
        }
        break;
    case DM_DAV:
      if (pressed) {
          if (mod_state & MOD_MASK_SHIFT) {
              del_mods(MOD_MASK_SHIFT);
              send_string("David");
              set_mods(mod_state);
          }
          else {
              send_string("david");
          }
        }
        break;
    case BR_BROK:
      if (pressed) {
          if (mod_state & MOD_MASK_SHIFT) {
              del_mods(MOD_MASK_SHIFT);
              send_string("Broker");
              set_mods(mod_state);
          }
          else {
              send_string("broker");
          }
        }
        break;
    case BO_BROK:
      if (pressed) {
          if (mod_state & MOD_MASK_SHIFT) {
              del_mods(MOD_MASK_SHIFT);
              send_string("Broker");
              set_mods(mod_state);
          }
          else {
              send_string("broker");
          }
        }
        break;
    case BM_COPY:
      if (pressed) {
        register_code(KC_LCTRL);
        tap_code(KC_C);
        unregister_code(KC_LCTRL);
      }
      break;
    case BD_PASTE:
      if (pressed) {
        register_code(KC_LCTRL);
        tap_code(KC_V);
        unregister_code(KC_LCTRL);
      }
      break;
    case CL_ALL:
      if (pressed) {
        register_code(KC_LCTRL);
        tap_code(KC_A);
        unregister_code(KC_LCTRL);
      }
      break;
    case LF_FIND:
      if (pressed) {
        register_code(KC_LCTRL);
        tap_code(KC_F);
        unregister_code(KC_LCTRL);
      }
      break;
  }
}
