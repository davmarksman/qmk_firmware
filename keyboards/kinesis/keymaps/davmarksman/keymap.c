//Kinesis
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
          KA_FIREFX   ,KA_EXPLR    ,KC_F2       ,KA_VSCODE   ,KA_VS19     ,KA_CHROME   ,KA_APP1     ,KC_F7       ,KC_F8       ,
          KC_ESC      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Z        ,KC_C        ,KC_L        ,KC_F        ,KC_EQL      ,
          KC_Q        ,KC_W        ,KC_S        ,HOME_C_R    ,KC_T        ,KC_G        ,
          K_WINDL     ,KC_X        ,KC_B        ,KC_M        ,KC_D        ,KC_V        ,
                       K_WINDR     ,KC_LEFT     ,KC_RGHT      ,KC_LGUI     ,
          // Thumb
                       KT_A_ESC    ,K_CLIP      ,
                                    KC_DEL      ,
          K_OSFT      ,LSYN_BK     ,KC_TAB      ,
          // Right Hand
          KA_APP2     ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,KA_VOL      ,LGAME       ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,KA_RENAME   ,
          TD(TD_MINS) ,KC_K        ,KC_U        ,KC_H        ,KC_J        ,KC_BSLS     ,
          KC_Y        ,KC_I        ,KC_E        ,KC_O        ,KC_A        ,KC_QUOT     ,
          TD(TD_SCLN) ,KC_P        ,KC_COMM     ,KC_DOT      ,KC_SLSH     ,KC_NUBS     ,
                       KC_RALT     ,KC_RGUI     ,XXXXXXX     ,KC_GRV      ,
          // Thumb
          KC_UP       ,K_AHK       ,
          KC_DOWN     ,
          KC_ENT      ,L1_SPC      ,KC_N      
    ),
[_GAME] = LAYOUT(
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_EQL      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_W        ,KC_E        ,KC_R        ,KC_T        ,
          XXXXXXX     ,KC_A        ,KC_S        ,KC_D        ,KC_F        ,KC_G        ,
          KC_LSFT     ,KC_Z        ,KC_X        ,KC_C        ,KC_V        ,KC_B        ,
                       XXXXXXX     ,KC_LEFT     ,KC_RGHT     ,XXXXXXX     ,
          // Thumb
                       KT_A_ESC    ,K_CLIP      ,
                                    KC_DEL      ,
          KC_LSFT     ,KT_C_BK     ,LNAV        ,
          // Right Hand
          KC_F9       ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,KA_VOL       ,LBASE     ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,KC_MINS     ,
          KC_Y        ,KC_U        ,KC_I        ,KC_O        ,KC_P        ,KC_NUBS     ,
          KC_H        ,KC_J        ,KC_K        ,KC_L        ,KC_SCLN     ,KC_QUOT     ,
          KC_N        ,KC_M        ,KC_COMM     ,KC_DOT      ,KC_SLSH     ,KC_RSFT     ,
                       KC_LALT     ,KC_RGUI     ,KC_RBRC     ,KC_GRV      ,
          // Thumb
          KC_UP       ,K_AHK       ,
          KC_DOWN     ,
          KC_ENT      ,KC_SPC      ,LL1         
    ),
[_L1] = LAYOUT(
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,
          XXXXXXX     ,K_UNDO      ,C(KC_X)     ,C(KC_C)     ,C(KC_V)     ,K_UNDOTB    ,
          XXXXXXX     ,K_EQ_GR     ,KC_LBRC     ,KC_LCBR     ,KC_LPRN     ,K_GLOBAL    ,
          KC_CAPS     ,KS_X2X      ,KC_RBRC     ,KC_RCBR     ,KC_RPRN     ,XXXXXXX     ,
                       XXXXXXX     ,KC_HOME     ,KC_END      ,XXXXXXX     ,
          // Thumb
                       XXXXXXX     ,XXXXXXX     ,
                                    XXXXXXX     ,
          KC_EXLM     ,KC_DEL      ,XXXXXXX     ,
          // Right Hand
          RESET       ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11      ,
          XXXXXXX     ,K_AND       ,K_GRV3      ,K_OR        ,XXXXXXX     ,KC_F12      ,
          XXXXXXX     ,KC_AT       ,KC_UNDS     ,K_PIPE      ,XXXXXXX     ,XXXXXXX     ,
          K_SNIP      ,K_SNIP      ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,KC_INS      ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
          XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     
    ),
[_SYNAV] = LAYOUT(
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,K_CUR_BK    ,K_CUR_FW    ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,KC_LALT     ,KC_LCTL     ,KC_LSFT     ,KC_LGUI     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,RCS(KC_NO)  ,XXXXXXX     ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
                       XXXXXXX     ,XXXXXXX     ,
                                    XXXXXXX     ,
          KC_LSFT     ,KT_C_DEL    ,RCS(KC_NO)  ,
          // Right Hand
          RESET       ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11      ,
          KC_PGUP     ,KC_HOME     ,KC_UP       ,KC_END      ,XXXXXXX     ,KC_F12      ,
          KC_PGDN     ,KC_LEFT     ,KC_DOWN     ,KC_RGHT     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
          XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,
          XXXXXXX     ,KT_C_DEL     ,XXXXXXX     
    )
};

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
        case K_WINDR:
            if (record->event.pressed) {
                tap_code16(C(KC_L));
                tap_code16(C(KC_C));
                tap_code16(C(KC_W));
                register_code(KC_LCTL);
                tap_code_delay(KC_N, 100);
                tap_code_delay(KC_V, 200);
                unregister_code(KC_LCTL);
                tap_code16(KC_ENT);
                tap_code16(G(KC_LEFT));
                tap_code16(G(KC_LEFT));
                tap_code16(G(KC_LEFT));
            }
            break;
        case K_WINDL:
            if (record->event.pressed) {
                tap_code16(C(KC_L));
                tap_code16(C(KC_C));
                tap_code16(C(KC_W));
                register_code(KC_LCTL);
                tap_code_delay(KC_N, 100);
                tap_code_delay(KC_V, 200);
                unregister_code(KC_LCTL);
                tap_code16(KC_ENT);
                tap_code16(G(KC_LEFT));
                tap_code16(G(KC_LEFT));
                tap_code16(G(KC_LEFT));
                tap_code16(G(KC_LEFT));
            }
            break;
    }
    return true;
}

void led_set_user(uint8_t usb_led) {

}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t hi_state = get_highest_layer(state);
    writePin(LED_COMPOSE_PIN, !(hi_state == _GAME));
    writePin(LED_SCROLL_LOCK_PIN, !(hi_state == _SYNAV));
    writePin(LED_NUM_LOCK_PIN, !(hi_state == _L1));    


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
