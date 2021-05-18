//Kinesis
#include QMK_KEYBOARD_H
#include "sendstring_uk.h"
#include "keymap.h"

// This will import the uprintf function
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
};


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
[_BASE] = LAYOUT( 
          XXXXXXX     ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_ESC      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_J        ,KC_G        ,KC_M        ,KC_F        ,KC_EQL      ,
          KC_LPRN     ,KC_H        ,KC_R        ,LCTL_T(KC_S),KC_T        ,KC_B        ,
          KC_LCBR     ,KC_X        ,KC_C        ,KC_L        ,KC_D        ,KC_V        ,
                       LL1         ,KC_LEFT     ,KC_RGHT     ,KC_DOWN         ,
          // Thumb{}
                       KT_ALTESC   ,K_CLIP      ,
                                    KC_DEL      ,
          K_OSFT      ,KT_C_BK     ,LSYM_TB     ,
          // Right Hand
          KC_F9       ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,LQM      ,LQ          ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,KC_NUBS     ,
          TD(TD_MINS) ,KC_K        ,KC_U        ,KC_W        ,KC_Z        ,KC_RPRN     ,
          KC_Y        ,KC_I        ,KC_E        ,KC_O        ,KC_A        ,KC_QUOT     ,
          TD(TD_SCLN) ,KC_P        ,KC_COMM     ,KC_DOT      ,KC_SLSH     ,KC_RCBR     ,
                       KC_LALT     ,KC_RGUI     ,KC_BSLS     ,KC_GRV      ,
          // Thumb
          K_AHK       ,KC_RGUI     ,
          KC_DOWN     ,
          LNAV_ENT    ,L1_SPC      ,KC_N      
    ),
    [_QWERTY] = LAYOUT( 
          XXXXXXX     ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_EQL      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_W        ,KC_E        ,KC_R        ,KC_T       ,
          LNAV        ,KC_A        ,KC_S        ,LCTL_T(KC_D),KC_F        ,KC_G        ,
          KC_LCBR     ,KC_Z        ,KC_X        ,KC_C        ,KC_V        ,KC_B        ,
                       LL1         ,KC_LEFT     ,KC_RGHT     ,KC_DOWN         ,
          // Thumb
                       KT_ALTESC   ,K_CLIP      ,
                                    KC_DEL      ,
          K_OSFT      ,KT_C_BK,LSYM_TB    ,
          // Right Hand
          KC_F9       ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,KC_F13      ,LBASE          ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,TD(TD_MINS) ,
          KC_Y        ,KC_U        ,KC_I        ,KC_O        ,KC_P        ,KC_NUBS     ,
          KC_H        ,RSFT_T(KC_J),RCTL_T(KC_K),KC_L        ,KC_SCLN     ,KC_QUOT     ,
          KC_N        ,KC_M        ,KC_COMM     ,KC_DOT      ,KC_SLSH     ,KC_RCBR     ,
                       KC_LALT     ,KC_RGUI     ,KC_BSLS     ,KC_GRV      ,
          // Thumb
          K_AHK       ,KC_RGUI     ,
          KC_DOWN     ,
          LNAV_ENT    ,L1_SPC      ,KC_N      
    ),
[_GAME] = LAYOUT(
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_EQL      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_W        ,KC_E        ,KC_R        ,KC_T        ,
          LNAV        ,KC_A        ,KC_S        ,KC_D        ,KC_F        ,KC_G        ,
          KC_LSFT     ,KC_Z        ,KC_X        ,KC_C        ,KC_V        ,KC_B        ,
                       LL1         ,KC_LEFT     ,KC_RGHT     ,K_UNDO      ,
          // Thumb
                       KT_ALTESC   ,K_CLIP      ,
                                    KC_DEL      ,
         KC_LSFT     , KT_C_BK     ,LSYM_TB     ,
          // Right Hand
          KC_F9       ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,KC_F13      ,LBASE       ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,KC_MINS     ,
          KC_Y        ,KC_U        ,KC_I        ,KC_O        ,KC_P        ,KC_NUBS     ,
          KC_H        ,KC_J        ,KC_K        ,KC_L        ,KC_SCLN     ,KC_QUOT     ,
          KC_N        ,KC_M        ,KC_COMM     ,KC_DOT      ,KC_SLSH     ,KC_RSFT     ,
                       KC_LALT     ,KC_RGUI     ,KC_RBRC     ,KC_GRV      ,
          // Thumb
          K_AHK       ,KC_RGUI     ,
          KC_UP       ,
          KC_DOWN     ,KC_SPC      ,KC_ENT      
    ),
[_L1] = LAYOUT(
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,K_UNDOTB    ,
          XXXXXXX     ,KC_BSLS     ,KC_LBRC     ,KC_LCBR     ,KC_LPRN     ,K_GLOBAL    ,
          KC_CAPS     ,KS_X2X      ,KC_RBRC     ,KC_RCBR     ,KC_RPRN     ,XXXXXXX     ,
                       XXXXXXX     ,KC_HOME     ,KC_END      ,K_UNDO      ,
          // Thumb
                       KT_ALTESC   ,XXXXXXX     ,
                                    XXXXXXX     ,
          KC_PPLS     ,KT_C_DEL    ,XXXXXXX     ,
          // Right Hand
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11      ,
          XXXXXXX     ,XXXXXXX     ,A(KC_LEFT)  ,A(KC_RGHT)  ,XXXXXXX     ,KC_F12      ,
          XXXXXXX     ,KC_AT       ,KC_UNDS     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,K_SNIP      ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,KC_INS      ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
          XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     
    ),
[_SYM] = LAYOUT(
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,K_AT        ,KC_HASH     ,KC_DLR      ,KC_PERC     ,
          XXXXXXX     ,KS_X2X      ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,K_UNDO      ,
          // Thumb
                       XXXXXXX     ,XXXXXXX     ,
                                    XXXXXXX     ,
          XXXXXXX     ,KT_C_DEL    ,XXXXXXX     ,
          // Right Hand
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,K_AND       ,K_GRV3      ,K_OR        ,XXXXXXX     ,XXXXXXX     ,
          KC_CIRC     ,KC_AMPR     ,KC_ASTR     ,K_PIPE      ,KC_BSLS     ,XXXXXXX  ,
          XXXXXXX     ,K_AT        ,KC_GRV      ,K_EQ_GR     ,KC_TILD     ,XXXXXXX     ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
          XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,
          XXXXXXX     ,KC_EXLM     ,XXXXXXX     
    ),
[_NAV] = LAYOUT(
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_ESC      ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_TAB      ,XXXXXXX     ,KC_HOME     ,KC_UP       ,KC_END      ,KC_PGUP     ,
          XXXXXXX     ,XXXXXXX     ,KC_LEFT     ,KC_DOWN     ,KC_RGHT     ,KC_PGDN     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,LBASE       ,
          // Thumb
                       KT_ALTESC   ,XXXXXXX     ,
                                    XXXXXXX     ,
          KC_LSFT,     KC_LCTL     ,XXXXXXX     ,
          // Right Hand
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX    ,XXXXXXX    ,
          KC_PGUP     ,KC_HOME     ,KC_UP       ,KC_END      ,XXXXXXX     ,KC_F12      ,
          KC_PGDN     ,KC_LEFT     ,KC_DOWN     ,KC_RGHT     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,KC_CAPS     ,
                       KC_LALT     ,KC_RGUI     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
          XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,
          XXXXXXX     ,KC_ENT      ,KC_SPC      
    ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        if (record->event.pressed) {
            bool isShift = (get_mods() & MOD_MASK_SHIFT) | (get_oneshot_mods() & MOD_MASK_SHIFT);
            bool isCtrl = (get_mods() & MOD_MASK_CTRL) | (get_oneshot_mods() & MOD_MASK_CTRL);
            uprintf("0x%04X,%u,%u,%u,%s,%s\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state), isShift ? "Shift": "", isCtrl? "Ctrl": "");
        }
    #endif

    switch (keycode) {
        case OSM(MOD_LSFT):
            if (record->event.pressed && get_oneshot_mods()) {
                clear_oneshot_mods ();
                return false;
            }
            break;
        case K_EQ_GR:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        case K_AND:
            if (record->event.pressed) {
                SEND_STRING("&&");
            }
            break;
        case K_OR:
            if (record->event.pressed) {
                SEND_STRING("||");
            }
            break;
        case KS_X2X:
            if (record->event.pressed) {
                SEND_STRING("x => x");
            }
            break;
        case K_GRV3:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            break;
    }
    return true;
}

void led_set_user(uint8_t usb_led) {

}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t hi_state = get_highest_layer(state);
    writePin(LED_COMPOSE_PIN, !((hi_state == _GAME) | (hi_state == _SYM)));
    writePin(LED_SCROLL_LOCK_PIN, !((hi_state == _NAV) | (hi_state == _BASE)));
    writePin(LED_NUM_LOCK_PIN, !((hi_state == _L1)| (hi_state == _BASE)| (hi_state == _GAME)));    

    return state;
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) { 
    writePin(LED_CAPS_LOCK_PIN, 0);
  }
  if (!mods) { 
    writePin(LED_CAPS_LOCK_PIN, 1);
  }
}
       
bool led_update_user(led_t led_state) {

    // you need to implement this method and return false otherwise it will overwrite what happened in layer_state_set_user
    return false; 
}
