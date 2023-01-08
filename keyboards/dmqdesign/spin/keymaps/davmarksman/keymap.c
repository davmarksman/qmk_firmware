// Spinpad
// qmk compile -kb dmqdesign/spin -km davmarksman
#include QMK_KEYBOARD_H

enum layers {
    _APPS,
    // _RGB,
    _LYRICS,
    _CODE
};
// Window organisation layer (or put on fn pad)

enum custom_keycodes {
    DAVMARKSMAN = SAFE_RANGE,
    K_WINMOVE,
    K_TEST_R,
    K_TEST_D,
    K_TEST_L
};

// Apps
#define K_CLIP C(A(KC_C))  // Paste Clipboard
#define KA_FIREFX KC_F17
#define KA_VSCODE KC_F18
#define KA_CHROME KC_F15
#define KA_VS19 KC_F16
#define K_SAVE C(KC_S)
#define KA_APP2 KC_F14
#define KA_VOL KC_F20
#define KA_EXPLR G(KC_1)
#define KA_NEXPLR G(KC_E)
#define KA_SPOT G(KC_2) // 2nd icon
#define KA_NOTE G(KC_3) // 3rd icon
#define KA_SQL G(KC_4) // 4th icon


#define LFN TO(_FNPAD)
#define LAPP TO(_APPS)
// #define LRGB TO(_RGB)
#define LLYR TO(_LYRICS)
#define LCODE OSL(_CODE)

// Window layout
#define K_RDESK G(KC_RGHT)
#define K_LDESK G(KC_LEFT)

// Useful defines
#define K_GLOBAL C(S(KC_F))
#define K_ZOOM_RST C(KC_KP_0)
#define K_ZOOM_RST2 C(KC_0)
// #define K_ZOOM_IN LCTL(KC_WH_D)
// #define K_ZOOM_OUT LCTL(KC_WH_U)
#define K_ZOOM_IN LCTL(KC_PPLS)
#define K_ZOOM_OUT LCTL(KC_PMNS)
// KC_KP_0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_APPS] = LAYOUT(/* Base */
                KA_FIREFX,  KA_CHROME,  KA_NOTE,    LCODE,
                KA_VSCODE,  KA_VS19,    KA_SQL,     K_ZOOM_RST,
                KA_EXPLR,   K_LDESK,    K_RDESK,    LLYR,
                K_SAVE,     K_WINMOVE,  KA_SPOT
                ),
    // [_RGB] = LAYOUT(
    //             RGB_HUI,  RGB_SAI, RGB_VAI, LAPP,
    //             RGB_HUD,  RGB_SAD, RGB_VAD, LFN,
    //             RGB_M_P,  XXXXXXX, XXXXXXX, LNAV,
    //             RGB_RMOD, RGB_TOG, RGB_MOD
    //             ),=
    [_LYRICS] = LAYOUT(
                KC_UP,         XXXXXXX,   C(KC_INS),     LAPP,
                KC_DOWN,       XXXXXXX,   XXXXXXX,       ,
                C(A(KC_LEFT)), C(KC_ENT), C(A(KC_RGHT)), LLYR,
                A(KC_LEFT),    C(KC_SPC), XXXXXXX
                ),
    [_CODE] = LAYOUT(
                K_TEST_L,  K_TEST_R,  K_TEST_D,      LAPP,
                C(KC_A),  XXXXXXX,    XXXXXXX,       ,
                A(KC_E),  K_GLOBAL,  XXXXXXX,        LLYR,
                XXXXXXX,  XXXXXXX,  XXXXXXX      
                )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K_WINMOVE:
            if (record->event.pressed) {
                tap_code16(G(S(KC_LEFT)));
                tap_code16(G(KC_UP));
                tap_code16(G(KC_UP));
            }
            break;  
        case K_TEST_R:
            if (record->event.pressed) {
                tap_code16(C(KC_R));
                _delay_ms(100);
                tap_code16(KC_T);
            }
            break;
        case K_TEST_D:
            if (record->event.pressed) {
                tap_code16(C(KC_R));
                _delay_ms(100);
                tap_code16(C(KC_T));
            }
            break;
        case K_TEST_L:
            if (record->event.pressed) {
                tap_code16(C(KC_R));
                _delay_ms(100);
                tap_code16(KC_L);
            }
            break;
    }

    return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        // Rotate tabs
        switch (get_highest_layer(layer_state)) {     //break each encoder update into a switch statement for the current layer           
            case _APPS:
                if (clockwise) {
                    tap_code16(C(KC_TAB));
                } else {
                    tap_code16(S(C(KC_TAB)));
                }
                break;
            default:
                if (clockwise) {
                    tap_code16(C(KC_Y));
                } else {
                    tap_code16(C(KC_Z));
                }
                break;
        }
    } else if (index == 1) { /* Second encoder */
        // Zoom in out
        // register_code(KC_LCTL);
        // _delay_ms(60);
        // if (clockwise) {
        //    tap_code(KC_WH_D);
        // } else {
        //     tap_code16(KC_WH_U);
        // }  
        // _delay_ms(60);
        // unregister_code(KC_LCTL);
        if (clockwise) {
           tap_code16(LCTL(KC_PPLS));
        } else {
            tap_code16(LCTL(KC_PMNS));
        } 
    } else if (index == 2) { /* Third encoder */
        // Undo redo
        if (clockwise) {
            tap_code16(C(KC_Y));
        } else {
            tap_code16(C(KC_Z));
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) { //This will run every time the layer is updated
    switch (get_highest_layer(state)) {
        case _APPS:
            rgblight_mode(RGBLIGHT_MODE_BREATHING);
            break;
        // case _FNPAD:
        //     rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
        //     break;
        // case _GAME:
        //     rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        //     rgblight_setrgb_at(RGB_SPRINGGREEN, 0);
        //     rgblight_setrgb_at(RGB_YELLOW, 1);
        //     rgblight_setrgb_at(RGB_BLUE, 2);
        //     break;
        case _CODE:
            rgblight_setrgb(RGB_GOLD);
            break;
        case _LYRICS:
            rgblight_setrgb(RGB_RED);
            break;
    }
    rgblight_set();
    return state;
}

#ifdef OLED_ENABLE

static const char *ANIMATION_NAMES[] = {
	"unknown",
	"static",
	"breathing I",
	"breathing II",
	"breathing III",
	"breathing IV",
	"rainbow mood I",
	"rainbow mood II",
	"rainbow mood III",
	"rainbow swirl I",
	"rainbow swirl II",
	"rainbow swirl III",
	"rainbow swirl IV",
	"rainbow swirl V",
	"rainbow swirl VI",
	"snake I",
	"snake II",
	"snake III",
	"snake IV",
	"snake V",
	"snake VI",
	"knight I",
	"knight II",
	"knight III",
	"christmas",
	"static gradient I",
	"static gradient II",
	"static gradient III",
	"static gradient IV",
	"static gradient V",
	"static gradient VI",
	"static gradient VII",
	"static gradient VIII",
	"static gradient IX",
	"static gradient X",
	"rgb test",
	"alternating",
	"twinkle I",
	"twinkle II",
	"twinkle III",
	"twinkle IV",
	"twinkle V",
	"twinkle VI"
};

void rgblight_get_mode_name(uint8_t mode, size_t bufsize, char *buf) {
    snprintf(buf, bufsize, "%-25s", ANIMATION_NAMES[mode]);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#ifdef LEFT_HAND
    return OLED_ROTATION_180;
#else
    return OLED_ROTATION_0;
#endif
}

void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _APPS:
            oled_write_P(PSTR("APPS - PROGRAM\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    static char rgb_mode_name[30];
    rgblight_get_mode_name(rgblight_get_mode(), sizeof(rgb_mode_name), rgb_mode_name);

    oled_write_P(PSTR("Mode: "), false);
    oled_write_ln(rgb_mode_name, false);
}
#endif

