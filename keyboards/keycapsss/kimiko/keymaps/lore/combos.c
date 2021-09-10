#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process


/*
* Combos
*/
enum combos {
  E_UM, 
  A_ACC,
  E_GRAVE,
  A_GRAVE
};

const uint16_t PROGMEM eum_combo[] = {KC_E, KC_SCLN, COMBO_END};
const uint16_t PROGMEM acc_combo[] = {KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM egrave_combo[] = {KC_E, KC_QUOT, COMBO_END};
const uint16_t PROGMEM agrave_combo[] = {KC_A, KC_QUOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [E_UM] = COMBO_ACTION(eum_combo),
  [A_ACC] = COMBO_ACTION(acc_combo),
  [E_GRAVE] = COMBO_ACTION(egrave_combo),
  [A_GRAVE] = COMBO_ACTION(agrave_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  uint8_t mod_state = get_mods();
  switch(combo_index) {
    case E_UM:
      if (pressed) {
        clear_mods();
        register_code(KC_LALT);
        if (mod_state & MOD_MASK_SHIFT) {
          tap_code(KC_KP_2);
          tap_code(KC_KP_0);
          tap_code(KC_KP_3);
        }
        else {
          tap_code(KC_KP_1);
          tap_code(KC_KP_3);
          tap_code(KC_KP_7);
        }
        unregister_code(KC_LALT);
        clear_mods();
        set_mods(mod_state);
      }
      break;

    case A_ACC:
      if (pressed) {
        clear_mods();
        register_code(KC_LALT);
        if (mod_state & MOD_MASK_SHIFT) {
          tap_code(KC_KP_0);
          tap_code(KC_KP_1);
          tap_code(KC_KP_9);
          tap_code(KC_KP_2);
        }
        else {
          tap_code(KC_KP_1);
          tap_code(KC_KP_3);
          tap_code(KC_KP_3);
        }
        unregister_code(KC_LALT);
        clear_mods();
        set_mods(mod_state);

      }
      break;
    case E_GRAVE:
      if (pressed) {
        clear_mods();
        register_code(KC_LALT);
        if (mod_state & MOD_MASK_SHIFT) {
          tap_code(KC_KP_1);
          tap_code(KC_KP_4);
          tap_code(KC_KP_4);
        }
        else {
          tap_code(KC_KP_1);
          tap_code(KC_KP_3);
          tap_code(KC_KP_0);
        }
        unregister_code(KC_LALT);
        clear_mods();
        set_mods(mod_state);
      }
      break;   
    case A_GRAVE:
      if (pressed) {
        clear_mods();
        register_code(KC_LALT);
        if (mod_state & MOD_MASK_SHIFT) {
          tap_code(KC_KP_0);
          tap_code(KC_KP_1);
          tap_code(KC_KP_9);
          tap_code(KC_KP_3);
        }
        else {
          tap_code(KC_KP_1);
          tap_code(KC_KP_6);
          tap_code(KC_KP_0);
        }
        unregister_code(KC_LALT);
        clear_mods();
        set_mods(mod_state);
      }
  }
}
