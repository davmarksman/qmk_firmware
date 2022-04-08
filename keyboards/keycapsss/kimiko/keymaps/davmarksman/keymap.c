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
    [TD_CMSC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_COLN)
};



// Adaptive keys
uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0;


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
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,      KC_5,                          KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KA_RENAME,
    KC_TAB,   KC_Q,   KC_Y,    KC_O,    KC_MINS,   KC_EQL,                        KC_B,       KC_F,    KC_L,    KC_P,    KC_J,    KC_BSLS,
    KC_CAPS,  KC_H,   KC_I,    KC_E,    HOME_CT_A, KC_K,                          KC_W,       KC_D,    KC_T,    KC_S,    KC_R,    KC_QUOT,
    KC_NUBS,  KC_Z,   KC_DOT,  TD(TD_CMSC), KC_U,  TD(TD_SCLN), K_CLIP,  K_AHK,   KC_V,       KC_C,    KC_M,    KC_G,    KC_X,    KC_SLSH,
                      KC_GRV,  KC_SLSH, KT_A_DEL,  K_OSFT,  LSYN_BK, L1_SPC,      KC_N,       KC_ENT,  KC_QUOT, KC_RGUI
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
   S(KC_TAB),XXXXXXX, KC_LT,   KC_GT,   K_EQ_GR, K_UNDOTB,                    XXXXXXX, K_AND,   K_GRV3,    K_OR,  XXXXXXX, KC_F12,
    KC_CAPS, KS_X2X,  KC_PPLS, KC_LPRN, KC_RPRN, K_GLOBAL,                    XXXXXXX, K_DQUOT, KC_UNDS, K_PIPE,  XXXXXXX, XXXXXXX,
    KC_CAPS, KS_X2,   XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,   LBASE,  LGAME,    K_SNIP,  K_SNIP,  KC_LT,   KC_GT,   XXXXXXX, KC_INS,
                      K_LDESK, K_RDESK, S(KC_TAB),KC_EXLM,  KC_QUES,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_SYNAV] = LAYOUT(
    KC_ESC,   KC_F1,   KC_F2,     KC_F3,   KC_F4,   KC_F5,                       KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
   S(KC_TAB), XXXXXXX, S(C(KC_TAB)),C(KC_TAB),XXXXXXX,K_UNDOTB,                   KC_PGUP,  KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_F12,
    KC_CAPS,  KC_LALT, RCS(KC_NO),KC_LCTL, KC_LSFT, KC_LGUI,                     KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    KC_CAPS,  K_UNDO,  C(KC_X),   C(KC_C), C(KC_V), XXXXXXX,  LBASE, LGAME,      XXXXXXX,  K_ED_LF, K_CUR_BK, K_ED_RG, K_CUR_FW, KC_INS,
                       K_LSNAP,   K_WINL,  K_WINR,  K_RSNAP, XXXXXXX, C(KC_BSPC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool return_state = true;
    uint16_t record_code = keycode;

    switch (keycode) {
        case OSM(MOD_LSFT):
            if (record->event.pressed && get_oneshot_mods()) {
                clear_oneshot_mods ();
                return_state = false;
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
        case KS_X2:
            if (record->event.pressed) {
                SEND_STRING("x => ");
            }
            break;
        case K_GRV3:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            break;
        case K_WINL:
            if (record->event.pressed) {
                tap_code16(G(S(KC_LEFT)));
                tap_code16(G(KC_UP));
                tap_code16(G(KC_UP));
            }
            break;
            
        case K_WINR:
            if (record->event.pressed) {
                tap_code16(G(S(KC_RGHT)));
                tap_code16(G(KC_UP));
                tap_code16(G(KC_UP));
            }
            break;
        case KC_D:
        {
            // adaptive D to H
            if (record->event.pressed) {
                if ((prior_keycode == KC_T || prior_keycode == KC_S || prior_keycode == KC_G || prior_keycode == KC_W
                        || prior_keycode == KC_P) 
                     && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) 
                {
                    tap_code(KC_H); 
                    record_code = KC_H;
                    return_state = false; 
                }
                break;   
            }
        }
        case KC_M:
        {
            if (record->event.pressed) {
                // adaptive CM to CH
                if ((prior_keycode == KC_C) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_H); 
                    record_code = KC_H;
                    return_state = false; 
                  // adaptive GM to GH
                } else if((prior_keycode == KC_G) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)){
                    tap_code(KC_H); 
                    record_code = KC_H;
                    return_state = false; 
                }
                break;
            }
        }
        case KC_MINS:
        {
            // adaptive OU  
            if (record->event.pressed) {
                if ((prior_keycode == KC_O) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_U); 
                    record_code = KC_U;
                    return_state = false; 
                }
                break;   
            }
        }
        case KC_F:
        {
            // adaptive bf to BL 
            if (record->event.pressed) {
                if ((prior_keycode == KC_B) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_L); 
                    record_code = KC_L;
                    return_state = false; 
                }
                break;   
            }
        }
        case KC_V:
        {
            // adaptive MV to MB
            if (record->event.pressed) {
                if ((prior_keycode == KC_M) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_B); 
                    record_code = KC_B;
                    return_state = false; 
                } 
                // adaptive CV to CL
                else if ((prior_keycode == KC_C) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_L); 
                    record_code = KC_L;
                    return_state = false; 
                }
                break;
            } 
        }
        case KC_L:
        {
            // adaptive BL to BM
            if (record->event.pressed) {
                if ((prior_keycode == KC_B) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_M); 
                    record_code = KC_M;
                    return_state = false; 
                }
                break;   
            }
        }
    }

    if (record->event.pressed) {
        prior_keycode = keycode;
        prior_keydown = timer_read(); 
    }

    #ifdef CONSOLE_ENABLE
        if (record->event.pressed) {
            bool isShift = (get_mods() & MOD_MASK_SHIFT) | (get_oneshot_mods() & MOD_MASK_SHIFT);
            bool isCtrl = (get_mods() & MOD_MASK_CTRL) | (get_oneshot_mods() & MOD_MASK_CTRL);
            uprintf("0x%04X,%u,%u,%u,%s,%s\n", record_code, record->event.key.row, record->event.key.col, get_highest_layer(layer_state), isShift ? "Shift": "", isCtrl? "Ctrl": "");
        }
    #endif

    return return_state;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    #ifdef CONSOLE_ENABLE
        uprintf("%s,%u,%u,%u\n", "encoder"+index+clockwise, 0, 0, get_highest_layer(layer_state));
    #endif

    // Encoder on main side
    if (index == 0) {
        // Undo /Redo
        if (clockwise) {
            tap_code16(K_REDO);
        } else {
            tap_code16(K_UNDO);
        }
    }
    // Encoder on other side
    else if (index == 1) {
        if (clockwise) {
            tap_code16(KC_DOWN);
        } else {
            tap_code16(KC_UP);
        }
    }
      return false;
}
#endif // ENCODER_ENABLE
