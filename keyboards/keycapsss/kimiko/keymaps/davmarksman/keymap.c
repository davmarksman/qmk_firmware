// Kimiko
// qmk compile -kb keycapsss/kimiko -km davmarksman
#include "keymap.h"
#include "sendstring_uk.h"

// This will import the uprintf function
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,--------------------------------------------.                    ,----------------------------------------------.
 * |   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `        |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -        |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |  LShift |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '        |
 * |---------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift/Enter|
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

//  TODO: replace a tab with Del
 [_BASE] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_NUBS,
    KC_TAB,   KC_Z,   KC_C,    KC_L,    KC_F,    KC_EQL,                      TD(TD_MINS),KC_K,    KC_U,    KC_H,    KC_J,    KC_BSLS,
    KC_Q,     KC_W,   KC_S,    HOME_C_R,KC_T,    KC_G,                        KC_Y,       KC_I,    KC_E,    KC_O,    KC_A,    KC_QUOT,
    KC_DEL,   KC_X,   KC_B,    KC_M,    KC_D,    KC_V,    K_CLIP,  K_AHK,     TD(TD_SCLN),KC_P,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
                      KC_LEFT, KC_RGHT, KT_A_TAB,K_OSFT,  KT_C_BK, L1_SPC,    LSYN_N,     KC_ENT,  KC_RALT, KC_RGUI
),

[_GAME] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_NUBS,
    KC_EQL,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    LBASE,  LGAME,      KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LEFT, KC_RGHT, LNAV,    K_OSFT, KT_C_BK, KC_SPC,     LL1,     KC_ENT,   KC_LALT, KC_RGUI
),
[_L1] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, XXXXXXX, XXXXXXX ,XXXXXXX, XXXXXXX, K_UNDOTB,                    XXXXXXX, K_AND,   K_GRV3,  K_OR,    XXXXXXX, KC_F12,
    XXXXXXX, K_EQ_GR, KC_LBRC, KC_LCBR, KC_LPRN, K_GLOBAL,                    XXXXXXX, KC_AT,   KC_UNDS, K_PIPE,  XXXXXXX, XXXXXXX,
    KC_CAPS, KS_X2X,  KC_RBRC, KC_RCBR, KC_RPRN, XXXXXXX,   LBASE,  LGAME,    K_SNIP,  K_SNIP,  XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,
                      KC_HOME, KC_END,  KC_EXLM, KC_PPLS,   KC_DEL, XXXXXXX,  XXXXXXX, XXXXXXX, KC_LALT, KC_RGUI
),

[_SYNAV] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, XXXXXXX, XXXXXXX ,K_CUR_BK,K_CUR_FW,XXXXXXX,                     KC_PGUP,  KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_F12,
    XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, KC_RGUI,                     KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    KC_DEL,  KS_X2X,  K_AT,    XXXXXXX, XXXXXXX, XXXXXXX,  LBASE, LGAME,      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_RGUI, KC_LALT, RCS(KC_NO),KC_LSFT, KT_C_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

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
    }
    return true;
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    #ifdef CONSOLE_ENABLE
        uprintf("%s,%u,%u,%u\n", "encoder"+index+clockwise, 0, 0, get_highest_layer(layer_state));
    #endif

    // Encoder on master side
    if (index == 0) {
        if (clockwise) {
            tap_code16(KC_DOWN);
        } else {
            tap_code16(KC_UP);
        }
    }
    // Encoder on slave side
    else if (index == 1) {
        // Undo /Redo
        if (clockwise) {
            tap_code16(K_REDO);
        } else {
            tap_code16(K_UNDO);
        }
    }
}
#endif // ENCODER_ENABLE
