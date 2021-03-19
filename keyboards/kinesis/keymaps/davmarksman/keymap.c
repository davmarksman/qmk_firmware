#include QMK_KEYBOARD_H

#define QWERTY_MOD 0 // qwerty with mods
#define QWERTY 1 // qwerty
#define L1 2 // qwerty

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY_MOD] = LAYOUT(
          KC_ESC  ,KC_F1   ,KC_COPY ,KC_PSTE ,C(A(KC_C))   ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,
          KC_EQL  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,
          KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,
          KC_CAPS   ,LGUI_T(KC_A),LALT_T(KC_S),LSFT_T(KC_D),LCTL_T(KC_F),KC_G    ,
          KC_LSPO ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,
                  KC_NUHS ,KC_LEFT ,KC_RGHT ,OSL(2)  ,
        // Thumb
                  LALT_T(KC_ESC),KC_DEL  ,
                            MEH_T(KC_NO),
          KC_BSPC ,LCTL_T(KC_SPC),KC_LSFT ,
        // Right Hand
          KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,KC_MPRV ,KC_MPLY ,KC_MNXT ,KC_NO   ,TO(1)   ,
          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
          KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
          KC_H    ,RCTL(KC_J),RSFT_T(KC_K),LT(2,KC_L),RGUI_T(KC_SCLN),KC_QUOT ,
          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSPC ,
                   OSL(2)  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,
          C(A(KC_C))   ,KC_RGUI ,
          KC_UP   ,
          KC_DOWN ,KC_ENT  ,KC_SPC
    ),
[QWERTY] = LAYOUT(
          KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,
          KC_EQL  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,
          KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,
          KC_NO   ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,
          KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,
                  KC_NUHS ,KC_LEFT ,KC_RGHT ,OSL(2)  ,
          // Thumb
                  LALT_T(KC_ESC),KC_DEL ,
                            MEH(KC_NO),
          KC_BSPC ,KC_LCTL,KC_LSFT ,
          // Right Hand size
          KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,KC_MPRV ,KC_MPLY ,KC_MNXT ,KC_NO   ,TO(0) ,
          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
          KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
          KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
                  OSL(2)  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,
          C(A(KC_C))   ,KC_RGUI ,
          KC_UP   ,
          KC_DOWN ,KC_ENT  ,KC_SPC
    ),
[L1] = LAYOUT(
          KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
          KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,
          A(KC_TAB),KC_NO  ,KC_NO   ,KC_LCBR ,KC_RCBR ,KC_NO   ,
          KC_TRNS ,KC_NO   ,C(S(KC_F)),KC_NO   ,KC_NO   ,KC_NO   ,
          KC_NO   ,KC_NO    ,KC_NO   ,KC_LPRN ,KC_RPRN ,KC_NO   ,
                  KC_INS  ,A(KC_LEFT),A(KC_RGHT),KC_TRNS ,
          KC_NO   ,KC_NO   ,
          KC_NO   ,
          KC_NO   ,KC_NO   ,KC_NO   ,
          // Right Hand size
          KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
          KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
          KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,G(S(KC_S))   ,KC_F12  ,
          KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_NO   ,KC_NO   ,
          KC_NO   ,KC_NO   ,KC_UNDO ,LCTL(KC_Y),KC_NO   ,KC_CAPS ,
                  KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,
          KC_NO   ,KC_NO   ,
          KC_NO   ,
          KC_NO   ,KC_NO   ,KC_NO
    ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
      case QWERTY:
          writePin(LED_COMPOSE_PIN, 0);    
          writePin(LED_SCROLL_LOCK_PIN, 1);
          break;
      case L1:
          writePin(LED_SCROLL_LOCK_PIN, 0);
          writePin(LED_COMPOSE_PIN, 1);
          break;
      default:
          writePin(LED_COMPOSE_PIN, 1);
          writePin(LED_SCROLL_LOCK_PIN, 1);
    }
  return state;
}
       
bool led_update_user(led_t led_state) {
    writePin(LED_NUM_LOCK_PIN, !led_state.num_lock);
    writePin(LED_CAPS_LOCK_PIN, !led_state.caps_lock);

    return false;
}

