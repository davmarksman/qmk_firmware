#include QMK_KEYBOARD_H

// layers
enum layer_names {
    BASE,
    GAME,
    L1,
    NAV,
    SYM
};


// layer keys
#define LBASE TO(BASE)
#define LQ TO(GAME)
#define LL1 OSL(L1)
#define LNAV TO(NAV)
#define LSYM OSL(SYM) // or MO
#define LNAV_Q LT(NAV,KC_QUOT) 

// Userful defines
#define K_UNDO LCTL(KC_Z)
#define K_REDO LCTL(KC_Y)
#define K_CLIP C(A(KC_C))  // Paste Clipboard
#define K_AHK MEH(KC_NO) // autohotkey 

#define KT_ALTESC LALT_T(KC_ESC)
#define KT_C_BK LCTL_T(KC_BSPC)
#define KT_C_DEL LCTL_T(KC_DEL)

// Custom codes
enum custom_keycodes {
    K_EQ_GR = SAFE_RANGE,
    K_AND,
    K_OR
};


// Tap dance
enum {
    TD_MINS,
    TD_1,
    TD_2,
    TD_3,
    TD_4,
    TD_5,
    TD_6,
    TD_7,
    TD_8,
    TD_LB,
    TD_RB,
    TD_X_UNDO,
    TD_QUOT,
    // TD_EQ,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_EXCLAIM),
    [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_AT),
    [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_HASH),
    [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_DLR),
    [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PERC),
    [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CIRC),
    [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_AMPR),
    [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR),
    [TD_LB] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_RB] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_X_UNDO] = ACTION_TAP_DANCE_DOUBLE(KC_X, K_UNDO),
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_AT),
    // [TD_EQ] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
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

         //KC_BSPC ,LSFT_T(KC_SPC) ,KC_LCTL , // disable to make learning shift easier
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT( 
          KC_NO       ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_EQL      ,TD(TD_1)    ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_W        ,KC_E        ,KC_R        ,KC_T        ,
          LNAV        ,KC_A        ,LT(L1,KC_S) ,LCTL_T(KC_D),LSFT_T(KC_F),KC_G        ,
          TD(TD_LB)   ,KC_Z        ,TD(TD_X_UNDO),KC_C        ,KC_V        ,KC_B        ,
                       K_UNDO      ,KC_LEFT     ,KC_RGHT     ,LL1         ,
          // Thumb
                       KT_ALTESC   ,K_CLIP      ,
                                    KC_DEL      ,
          KT_C_BK     ,KC_LSFT     ,LSYM        ,
          // Right Hand
          KC_F9       ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,KC_F13      ,LQ          ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,TD(TD_MINS) ,
          KC_Y        ,KC_U        ,KC_I        ,KC_O        ,KC_P        ,KC_NUBS     ,
          KC_H        ,RSFT_T(KC_J),RCTL_T(KC_K),LT(L1,KC_L) ,KC_SCLN     ,TD(TD_QUOT) ,
          KC_N        ,KC_M        ,KC_COMM     ,KC_DOT      ,KC_SLSH     ,TD(TD_RB)   ,
                       KC_LALT     ,KC_RGUI     ,KC_BSLS     ,KC_GRV      ,
          // Thumb
          K_AHK       ,KC_RGUI     ,
          KC_UP       ,
          KC_DOWN     ,LT(L1, KC_SPC),KC_ENT      
    ),
[GAME] = LAYOUT(
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_EQL      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_W        ,KC_E        ,KC_R        ,KC_T        ,
          LNAV        ,KC_A        ,KC_S        ,KC_D        ,KC_F        ,KC_G        ,
          KC_LSFT     ,KC_Z        ,KC_X        ,KC_C        ,KC_V        ,KC_B        ,
                       KC_NO       ,KC_LEFT     ,KC_RGHT     ,LL1         ,
          // Thumb
                       KT_ALTESC   ,K_CLIP      ,
                                    KC_DEL      ,
          KT_C_BK     ,KC_LSFT     ,LSYM        ,
          // Right Hand
          KC_F9       ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,KC_F13      ,LBASE       ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,KC_MINS     ,
          KC_Y        ,KC_U        ,KC_I        ,KC_O        ,KC_P        ,KC_NUBS     ,
          KC_H        ,KC_J        ,KC_K        ,KC_L        ,KC_SCLN     ,KC_QUOT     ,
          KC_N        ,KC_M        ,KC_COMM     ,KC_DOT      ,KC_SLSH     ,KC_RSFT     ,
                       KC_BSLS     ,KC_LBRC     ,KC_RBRC     ,KC_GRV      ,
          // Thumb
          K_AHK       ,KC_RGUI     ,
          KC_UP       ,
          KC_DOWN     ,KC_SPC      ,KC_ENT      
    ),
[L1] = LAYOUT(
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,
          A(KC_TAB)   ,KC_NO       ,KC_NO       ,KC_LCBR     ,KC_RCBR     ,C(S(KC_T))  ,
          LBASE       ,KC_LCBR     ,KC_RCBR     ,KC_LBRC     ,KC_RBRC     ,C(S(KC_F))  ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_LPRN     ,KC_RPRN     ,KC_NO       ,
                       KC_INS      ,KC_HOME     ,KC_END      ,LBASE       ,
          // Thumb
                       KT_ALTESC   ,KC_NO       ,
                                    K_REDO      ,
          KT_C_DEL    ,KC_LSFT     ,K_UNDO      ,
          // Right Hand
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11      ,
          K_REDO      ,K_UNDO      ,A(KC_LEFT)  ,A(KC_RGHT)  ,G(S(KC_S))  ,KC_F12      ,
          KC_NO       ,KC_AT       ,KC_PLUS     ,KC_UNDS     ,KC_NO       ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_CAPS     ,
                       LBASE       ,KC_NO       ,KC_NO       ,KC_NO       ,
          // Thumb
          KC_NO       ,KC_NO       ,
          KC_PGUP     ,
          KC_PGDN     ,KC_NO       ,KC_NO       
    ),
[NAV] = LAYOUT(
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,
          KC_TAB      ,KC_HOME     ,KC_UP       ,KC_END      ,KC_PGUP     ,KC_NO       ,
          LBASE       ,KC_LEFT     ,KC_DOWN     ,KC_RGHT     ,KC_PGDN     ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
                       KC_NO       ,KC_NO       ,KC_NO       ,LBASE       ,
          // Thumb
                       KT_ALTESC   ,KC_NO       ,
                                    KC_NO       ,
          KC_LCTL     ,KC_LSFT     ,KC_NO       ,
          // Right Hand
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11      ,
          KC_PGUP     ,KC_HOME     ,KC_UP       ,KC_END      ,KC_NO       ,KC_F12      ,
          KC_PGDN     ,KC_LEFT     ,KC_DOWN     ,KC_RGHT     ,KC_NO       ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_CAPS     ,
                       LBASE       ,KC_NO       ,KC_NO       ,KC_NO       ,
          // Thumb
          KC_NO       ,KC_NO       ,
          KC_NO       ,
          KC_NO       ,KC_ENT      ,KC_SPC      
    ),
[SYM] = LAYOUT(
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,K_EQ_GR     ,KC_NO       ,KC_NO       ,
          LBASE       ,KC_EXCLAIM  ,KC_AT       ,KC_HASH     ,KC_DLR      ,KC_PERC     ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
                       KC_NO       ,KC_NO       ,KC_NO       ,K_UNDO      ,
          // Thumb
                       KC_NO       ,KC_NO       ,
                                    KC_NO       ,
          KT_C_DEL    ,KC_LSFT     ,KC_NO       ,
          // Right Hand
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_NO       ,K_AND       ,KC_NO       ,K_OR        ,KC_NO       ,KC_NO       ,
          KC_CIRC     ,KC_AMPR     ,KC_ASTR     ,S(KC_NUBS)  ,S(KC_QUOT)  ,KC_DQUO     ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
                       KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          // Thumb
          KC_NO       ,KC_NO       ,
          KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       
    ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K_EQ_GR:
            if (record->event.pressed) {
                SEND_STRING("=>");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case K_AND:
            if (record->event.pressed) {
                SEND_STRING("&&");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case K_OR:
            if (record->event.pressed) {
                SEND_STRING("¬¬");
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
}

void led_set_user(uint8_t usb_led) {

}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t hi_state = get_highest_layer(state);
    writePin(LED_COMPOSE_PIN, !((hi_state == GAME) | (hi_state == SYM)));
    writePin(LED_SCROLL_LOCK_PIN, !(hi_state == NAV));
    writePin(LED_NUM_LOCK_PIN, !(hi_state == L1));    

    return state;
}
       
bool led_update_user(led_t led_state) {
    // we want caps lock to keep working as is:
    writePin(LED_CAPS_LOCK_PIN, !led_state.caps_lock);

    // you need to implement this method and return false otherwise it will overwrite what happened in layer_state_set_user
    return false;
}

