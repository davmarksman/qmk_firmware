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
  YU_AND,
  UI_ING, 
  SF_THE
};

const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [YU_AND] = COMBO_ACTION(yu_combo),
  [UI_ING] = COMBO_ACTION(ui_combo),
  [SF_THE] = COMBO_ACTION(sf_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  mod_state = get_mods();
  oneshot_mod_state = get_oneshot_mods();

  switch(combo_index) {
    case SF_THE:
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
    case UI_ING:
      if (pressed) {
        SEND_STRING("ing");
      }
      break;
    case YU_AND:
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
