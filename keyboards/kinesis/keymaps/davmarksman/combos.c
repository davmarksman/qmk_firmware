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
  YU_THE,
  UI_ING,
  FN_FN,
  Y7_AND
};

const uint16_t PROGMEM the_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM ing_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM func_combo[] = {KC_F, KC_M, COMBO_END};
const uint16_t PROGMEM and_combo[] = {KC_7, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [YU_THE] = COMBO_ACTION(the_combo),
  [UI_ING] = COMBO_ACTION(ing_combo),
  [FN_FN] = COMBO_ACTION(func_combo),
  [Y7_AND] = COMBO_ACTION(and_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  mod_state = get_mods();
  oneshot_mod_state = get_oneshot_mods();

  switch(combo_index) {
    case YU_THE:
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
    case Y7_AND:
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
    case FN_FN:
      if (pressed) {
        SEND_STRING("function[]{}"); // as i've got that () change. Don't think its necessary anymore
      }
      break;
  }
}
