// Kimiko
// qmk compile -kb keycapsss/kimiko -km davmarksman
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

 [_BASE] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_NUBS,
    KC_TAB,   KC_J,   KC_C,    KC_L,    KC_H,    KC_EQL,                      TD(TD_MINS),KC_K,    KC_U,    KC_W,    KC_Z,    KC_RPRN,
    KC_LPRN,  KC_F,   KC_R,    KH_C_S,  KC_T,    KC_B,                        KC_Y,       KC_I,    KC_E,    KC_O,    KC_A,    KC_QUOT,
    KC_LCBR,  KC_X,   KC_G,    KC_M,    KC_D,    KC_V,    K_CLIP,  K_AHK,     TD(TD_SCLN),KC_P,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCBR,
                      KC_LEFT, KC_RGHT, KC_TAB,  K_OSFT,  KT_C_BK, L1_SPC,    LSYN_N,     KC_ENT,  KC_LALT, KC_RGUI
),

[_GAME] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_NUBS,
    KC_EQL,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    LBASE,  LQ,         KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LEFT, KC_RGHT, XXXXXXX, KC_LSFT, KT_C_BK, KC_ENT,    KC_SPC,  XXXXXXX, KC_LALT, KC_RGUI
),
[_L1] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K_UNDOTB,                    XXXXXXX, XXXXXXX, A(KC_LEFT),A(KC_RGHT),KC_NO,KC_F12,
    XXXXXXX, KC_BSLS, KC_LBRC, KC_LCBR, KC_LPRN, K_GLOBAL,                    XXXXXXX, KC_AT,   KC_UNDS, KC_BSLS, XXXXXXX, XXXXXXX,
    KC_CAPS, KS_X2X,  KC_RBRC, KC_RCBR, KC_RPRN, XXXXXXX,   LBASE,  LQ,       XXXXXXX, K_SNIP,  XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,
                      KC_HOME, KC_END,  XXXXXXX, KC_PPLS,   KC_DEL, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX
),

[_SYNAV] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                     XXXXXXX, K_AND,   K_GRV3,  K_OR,    XXXXXXX, KC_F12,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                     KC_DLR,  KC_AMPR, KC_ASTR, K_PIPE,  KC_BSLS, XXXXXXX,
    _______, KS_X2X,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  LBASE, LQ,         XXXXXXX, K_AT,    KC_GRV,  K_EQ_GR, K_TILDE, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX,KT_S_EXLM, KT_C_BK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        if (record->event.pressed) {
            bool isShift = (get_mods() & MOD_MASK_SHIFT) | (get_oneshot_mods() & MOD_MASK_SHIFT);
            bool isCtrl = (get_mods() & MOD_MASK_CTRL) | (get_oneshot_mods() & MOD_MASK_CTRL);
            uprintf("0x%04X,%u,%u,%u,%s\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state), isShift ? "Shift": "", isCtrl? "Ctrl": "");
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

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
    oled_write_P(corne_logo, false);
    // oled_write_P(PSTR("Kimiko"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM sym_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM l1_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_L1)) {
        oled_write_P(l1_layer, false);
    } else if(layer_state_is(_SYNAV)) {
        oled_write_P(sym_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_styker(void) {
    static const char PROGMEM styker_logo[] = {
        255, 31, 15,135, 55,123, 91,237,237,245,253,249, 59, 51,119,247,239,239,159,191, 63,127,127,255,255,255,255,255,255,255,255,255,253,240,231,239, 15,111, 30, 30, 60,189, 57,251,243,231,239,207,223,159, 63,127,247,239,231,242,253,249,231,199,223, 63,255,255,
    };
    oled_write_raw_P(styker_logo, sizeof(styker_logo));
}

void render_chip(void) {
    static const char PROGMEM doc_logo[] = {
        0,  0,  0,  0,  0,128,224,160,224,128,224,160,224,128,224,160,224,128,224,160,224,128,224,160,224,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,254, 17, 16, 16,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,254,  0,  0,  0,  0,  0,  0,  0,127,145,161,225, 32,224,160,224, 32,224,160,224, 32,224,160,224, 32,224,160,224, 32,224,160, 80, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  2,  3,  0,  3,  2,  3,  0,  3,  2,  3,  0,  3,  2,  3,  0,  3,  2,  3,  0,  0,  0,  0,  0,  0,  0,
    };

    oled_write_raw_P(doc_logo, sizeof(doc_logo));
}

void render_apc(void) {
    static const char PROGMEM apc_logo[] = {
        255, 31,  7, 15, 15, 15, 15,  7, 15, 15, 15, 13,  1,  1,  1, 13, 13, 13, 13, 13, 13, 15, 15, 31, 31, 63, 63, 63,127,255,255,255,
    };
    oled_write_raw_P(apc_logo, sizeof(apc_logo));
}

// static void render_imgshift(){
//        // if(modifiers & MOD_MASK_SHIFT) {
//     //     oled_write_raw_P(arrow_logo, sizeof(arrow_logo));
//     // }else{
//     //     oled_write_raw_P(doc_logo, sizeof(arrow_logo));
//     // }
// }

static void render_shift(uint8_t modifiers){
    oled_write_P(PSTR("     "), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("SHIFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("     "), (modifiers & MOD_MASK_SHIFT));
}

void render_status_main(void) {
    render_space();
    render_space();
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    render_space();
    render_space();
    render_logo();
    render_space();
    render_shift(get_mods()|get_oneshot_mods());
    render_styker();
    render_space();
    render_apc();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}


#endif


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
