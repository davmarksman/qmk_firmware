#include QMK_KEYBOARD_H
#include "sendstring_uk.h"
#include "keymap.h"

// This will import the uprintf function
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif


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
    K_OR,
    KS_X2X,
    KS_THE,
    KS_ING,
    KS_FN,
};

/*
* TAP DANCE
*/
enum {
    TD_MINS,
};


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
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
[BASE] = LAYOUT( 
          KC_NO       ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_EQL      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_W        ,KC_NO        ,KC_R        ,KC_T       ,
          LNAV        ,KC_A        ,KC_S        ,LCTL_T(KC_D),KC_F         ,KC_G        ,
          KC_LCBR     ,KC_Z        ,KC_X        ,KC_C        ,KC_V        ,KC_B        ,
                       LL1         ,KC_LEFT     ,KC_RGHT     ,KC_DOWN         ,
          // Thumb
                       KT_ALTESC   ,K_CLIP      ,
                                    KC_DEL      ,
          KT_C_BK     ,OSM(MOD_LSFT),LSYM        ,
          // Right Hand
          KC_F9       ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,KC_F13      ,LQ          ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,TD(TD_MINS) ,
          KC_Y        ,KC_U        ,KC_I        ,KC_O        ,KC_P        ,KC_NUBS     ,
          KC_H        ,RSFT_T(KC_J),RCTL_T(KC_K),KC_L        ,KC_SCLN     ,KC_QUOT     ,
          KC_N        ,KC_M        ,KC_COMM     ,KC_DOT      ,KC_SLSH     ,KC_RCBR     ,
                       KC_LALT     ,KC_RGUI     ,KC_BSLS     ,KC_GRV       ,
          // Thumb
          K_AHK       ,KC_RGUI     ,
          KC_NO     ,
          //KC_DOWN     ,LT(L1, KC_SPC),KC_ENT  
          KC_ENT     ,LT(L1, KC_SPC),KC_E      
    ),
[GAME] = LAYOUT(
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_EQL      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_W        ,KC_E        ,KC_R        ,KC_T        ,
          LNAV        ,KC_A        ,KC_S        ,KC_D        ,KC_F        ,KC_G        ,
          KC_LSFT     ,KC_Z        ,KC_X        ,KC_C        ,KC_V        ,KC_B        ,
                       LL1       ,KC_LEFT     ,KC_RGHT     ,K_UNDO         ,
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
                       KC_LALT     ,KC_RGUI     ,KC_RBRC     ,KC_GRV      ,
          // Thumb
          K_AHK       ,KC_RGUI     ,
          KC_UP       ,
          KC_DOWN     ,KC_SPC      ,KC_ENT      
    ),
[L1] = LAYOUT(
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,
          KC_TAB      ,KC_NO       ,KC_NO       ,KC_LCBR     ,KC_RCBR     ,C(S(KC_T))  ,
          LBASE       ,KC_LCBR     ,KC_RCBR     ,KC_LBRC     ,KC_RBRC     ,C(S(KC_F))  ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_LPRN     ,KC_RPRN     ,KC_NO       ,
                       KC_INS      ,KC_HOME     ,KC_END      ,K_UNDO       ,
          // Thumb
                       KT_ALTESC   ,KC_NO       ,
                                    KC_NO       ,
          KT_C_DEL    ,KC_KP_PLUS  ,KC_NO       ,
          // Right Hand
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11      ,
          K_REDO      ,K_UNDO      ,A(KC_LEFT)  ,A(KC_RGHT)  ,G(S(KC_S))  ,KC_F12      ,
          KC_NO       ,KC_AT       ,KC_UNDS     ,KC_LPRN     ,KC_RPRN     ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_CAPS     ,
                       KC_LALT     ,KC_RGUI     ,KC_NO       ,KC_NO       ,
          // Thumb
          KC_NO       ,KC_NO       ,
          KC_PGUP     ,
          KC_PGDN     ,KC_NO       ,KC_NO       
    ),
[NAV] = LAYOUT(
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_ESC      ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
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
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO      ,KC_NO      ,
          KC_PGUP     ,KC_HOME     ,KC_UP       ,KC_END      ,KC_NO       ,KC_F12      ,
          KC_PGDN     ,KC_LEFT     ,KC_DOWN     ,KC_RGHT     ,KC_NO       ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_CAPS     ,
                       KC_LALT     ,KC_RGUI     ,KC_NO       ,KC_NO       ,
          // Thumb
          KC_NO       ,KC_NO       ,
          KC_NO       ,
          KC_NO       ,KC_ENT      ,KC_SPC      
    ),
[SYM] = LAYOUT(
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,K_EQ_GR     ,KC_NO       ,KC_NO       ,
          LBASE       ,KC_EXCLAIM  ,S(KC_QUOT)  ,KC_HASH     ,KC_DLR      ,KC_PERC     ,
          KC_NO       ,KC_NO       ,KS_X2X      ,KC_NO       ,KC_NO       ,KC_NO       ,
                       KC_NO       ,KC_NO       ,KC_NO       ,K_UNDO      ,
          // Thumb
                       KC_NO       ,KC_NO       ,
                                    KC_NO       ,
          KT_C_DEL    ,KC_EXCLAIM  ,KC_NO       ,
          // Right Hand
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,KC_NO       ,
          KC_NO       ,K_AND       ,KC_NO       ,K_OR        ,KC_NO       ,KC_NO       ,
          KC_CIRC     ,KC_AMPR     ,KC_ASTR     ,S(KC_NUBS)  ,S(KC_QUOT)  ,KC_DQUO     ,
          KC_NO       ,KS_FN       ,KC_NO       ,KC_NO       ,KC_NUBS      ,KC_NO       ,
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
    #ifdef CONSOLE_ENABLE
        if (record->event.pressed) {
            uprintf("0x%04X,%u,%u,%u\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state));
        }
    #endif

    switch (keycode) {
        case KT_C_BK:
        {
            static bool delkey_registered;
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    delkey_registered = true;
                    set_mods(get_mods());
                    return false;
                }
                if (get_oneshot_mods() & MOD_MASK_SHIFT) {
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    delkey_registered = true;
                    return false;
                }
            } else {
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            return true;
        }
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
        case KS_THE:
            if (record->event.pressed) {
                SEND_STRING("the");
            }
            break;
        case KS_ING:
            if (record->event.pressed) {
                SEND_STRING("ing");
            }
            break;
        case KS_FN:
            if (record->event.pressed) {
                SEND_STRING("function");
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
