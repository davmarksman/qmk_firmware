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
  KU_Q,
  FO_FOR,
  TD_THE,
  TH_TH,
  TN_ENT,
  IN_ING,
  ON_ION,
  DN_AND, 

  // This must be the last item in the enum.
  // This is used to automatically update the combo count.
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;


const uint16_t PROGMEM ku_combo[] = {KC_K, KC_U, COMBO_END};
const uint16_t PROGMEM fo_combo[] = {KC_F, KC_O, COMBO_END};
const uint16_t PROGMEM td_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM th_combo[] = {KC_T, KC_H, COMBO_END};
const uint16_t PROGMEM tn_combo[] = {KC_T, LNAV_N, COMBO_END};
const uint16_t PROGMEM in_combo[] = {KC_I, LNAV_N, COMBO_END};
const uint16_t PROGMEM on_combo[] = {KC_O, LNAV_N, COMBO_END};
const uint16_t PROGMEM dn_combo[] = {KC_D, LNAV_N, COMBO_END};



combo_t key_combos[] = {
  [KU_Q] = COMBO_ACTION(ku_combo),
  [FO_FOR] = COMBO_ACTION(fo_combo),
  [TD_THE] = COMBO_ACTION(td_combo),
  [TH_TH] = COMBO_ACTION(th_combo),
  [TN_ENT] = COMBO_ACTION(tn_combo),
  [IN_ING] = COMBO_ACTION(in_combo),
  [ON_ION] = COMBO_ACTION(on_combo),
  [DN_AND] = COMBO_ACTION(dn_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  mod_state = get_mods();

  switch(combo_index) {
    case KU_Q:
      if (pressed) {
        tap_code16(KC_Q);
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
    case TH_TH:
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
  }
}
