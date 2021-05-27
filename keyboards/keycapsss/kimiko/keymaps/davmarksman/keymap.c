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

bool is_alt_tab_active = false; 
uint16_t alt_tab_timer = 0;     


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
                      KC_LEFT, KC_RGHT, LNAV, K_OSFT, KT_C_BK, KC_SPC,     LL1,  KC_ENT,   KC_LALT, KC_RGUI
),
[_L1] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K_UNDOTB,                    XXXXXXX, XXXXXXX, A(KC_LEFT),A(KC_RGHT),KC_NO,KC_F12,
    XXXXXXX, XXXXXXX, KC_LBRC, KC_LCBR, KC_LPRN, K_GLOBAL,                    XXXXXXX, KC_AT,   KC_UNDS, KC_ASTR, XXXXXXX, XXXXXXX,
    KC_CAPS, KS_X2X,  KC_RBRC, KC_RCBR, KC_RPRN, XXXXXXX,   LBASE,  LGAME,    K_SNIP,  K_SNIP,  XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,
                      KC_HOME, KC_END,  XXXXXXX, KC_PPLS,   KC_DEL, XXXXXXX,  XXXXXXX, XXXXXXX, KC_LALT, KC_RGUI
),

[_SYNAV] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, XXXXXXX, K_GRV3,  K_AND,   K_OR,    XXXXXXX,                     KC_PGUP,  KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_F12,
    XXXXXXX, K_EQ_GR, KC_EXLM, KC_AMPR, K_PIPE,  KC_DLR,                      KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    _______, KS_X2X,  K_AT,    XXXXXXX, XXXXXXX, XXXXXXX,  LBASE, LGAME,      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, RCS(KC_NO),KC_LSFT, KT_C_DEL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, KC_RGUI
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
        case KC_R:
        {
            // remap ctr-r to ctr-f.
            static bool f_registered;
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_CTRL) {
                    register_code(KC_F);
                    f_registered = true;
                    return false;
                }
            } else {
                if (f_registered) {
                    unregister_code(KC_F);
                    f_registered = false;
                    return false;
                }
            }
            return true;
        }
        case K_ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case K_SA_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_LSFT);
                register_code(KC_TAB);
                unregister_code(KC_LSFT);
            } else {
                unregister_code(KC_TAB);
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

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
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
}

void render_inf(void) {
    static const char PROGMEM inf_logo[] = {
// '4535c364c6507eda6e11498a8cf7736a - Copy', 32x32px
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x37, 0x0b, 0x23, 
0x43, 0x83, 0x63, 0x0b, 0x03, 0x27, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xef, 0xef, 0xc3, 0xc7, 0x83, 0x23, 0x17, 0x07, 0x07, 0x03, 0x05, 0x04, 0x00, 0x00, 0x1b, 0x00, 
0x10, 0x10, 0x04, 0x10, 0x80, 0x84, 0x00, 0x00, 0x23, 0x07, 0xe7, 0x1f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xe0, 0x00, 0x40, 0x10, 0x02, 
0x40, 0x60, 0x20, 0x81, 0x00, 0x01, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xf1, 0xf1, 0xf5, 0xe4, 0xe0, 0xe1, 
0xc0, 0xc0, 0xc0, 0xc0, 0xc2, 0xd1, 0xc8, 0xd0, 0xc1, 0xc1, 0xe3, 0xf7, 0xff, 0xff, 0xff, 0xff    
};
    oled_write_raw_P(inf_logo, sizeof(inf_logo));
}

void render_apc(void) {
    static const char PROGMEM apc_logo[] = {
// 'gtk_wolf_1b_he_stinger_by_schwarzweiler-d9nkny2', 32x15px
0xbf, 0x1f, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x0f, 0x0f, 0x0f, 0x09, 0x01, 0x01, 0x01, 0x05, 
0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0xff, 
0x6f, 0x6e, 0x6c, 0x68, 0x68, 0x60, 0x60, 0x60, 0x60, 0x68, 0x68, 0x68, 0x60, 0x60, 0x60, 0x68, 
0x68, 0x68, 0x60, 0x60, 0x60, 0x68, 0x68, 0x68, 0x60, 0x60, 0x60, 0x68, 0x68, 0x6c, 0x6e, 0x6f 
};
    oled_write_raw_P(apc_logo, sizeof(apc_logo));
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
    if(layer_state_is(_L1)) {
        oled_write_P(l1_layer, false);
    } else if(layer_state_is(_SYNAV)) {
        oled_write_P(sym_layer, false);
    } else if(layer_state_is(_GAME)) {
        oled_write_P(adjust_layer, false);
    } else {
        oled_write_P(default_layer, false);
    } 
}

static void render_shift(uint8_t modifiers){
    oled_write_P(PSTR("     "), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("SHIFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("     "), (modifiers & MOD_MASK_SHIFT));
}

static void render_layer_text(void){
    static const char PROGMEM nav_arr[] = {
        0x20, 0x20, 0x18, 0x20, 0x20,
        0x20, 0x1b, 0x19, 0x1a, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0};

    if(layer_state_is(_L1)) {
        oled_write_P(PSTR("     "), true);
        oled_write_P(PSTR("[{(_*"), true);
        oled_write_P(PSTR("     "), true);
    } else if(layer_state_is(_SYNAV)) {
        oled_write_P(nav_arr, false);
    } else if(layer_state_is(_GAME)) {
        render_apc();
    }  else {
    oled_write_P(PSTR("      "), false);
    oled_write_P(PSTR("      "), false);
    oled_write_P(PSTR("      "), false);
    } 
}


void render_status_main(void) {
    render_space();
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    render_space();
    render_layer_text();
}

void render_status_secondary(void) {
    render_space();
    render_logo();
    render_space();
    render_shift(get_mods()|get_oneshot_mods());
    render_space();
    render_space();
    render_inf();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();
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
