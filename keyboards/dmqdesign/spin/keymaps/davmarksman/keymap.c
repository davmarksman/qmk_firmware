// Spinpad
// qmk compile -kb dmqdesign/spin -km davmarksman
#include QMK_KEYBOARD_H

enum layers {
    _APPS,
    _FNPAD,
    _NAV,
    _RGB,
    _LYRICS,
};
// Window organisation layer (or put on fn pad)

enum custom_keycodes {
    DAVMARKSMAN = SAFE_RANGE,
    K_WINMOVE,
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
#define LNAV TO(_NAV)
#define LRGB TO(_RGB)
#define LLYR TO(_LYRICS)

// Window layout
#define K_RDESK G(KC_RGHT)
#define K_LDESK G(KC_LEFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_APPS] = LAYOUT(/* Base */
                KA_FIREFX,  KA_CHROME,  KA_NOTE,    LLYR,
                KA_VSCODE,  KA_VS19,    KA_SQL,     LFN,
                KA_EXPLR,   K_LDESK,    K_RDESK,    LNAV,
                K_SAVE,     K_WINMOVE,  KA_SPOT
                ),
    [_FNPAD] = LAYOUT(
                KC_F1,      KC_F2,      KC_F3,      LAPP,
                KC_F4,      KC_F5,      KC_F6,      LFN,
                KC_F7,      KC_F8,      KC_F9,      LNAV,
                KC_F10,     KC_F11,     KC_F12
                ),
    [_NAV] = LAYOUT(
                K_WINMOVE,  XXXXXXX,    KC_PGUP,    LAPP,
                K_LDESK,    K_RDESK,    KC_PGDN,    LFN,
                KC_HOME,    KC_UP,      KC_END,     LNAV,
                KC_LEFT,    KC_DOWN,    KC_RGHT
                ),
    [_RGB] = LAYOUT(
                RGB_HUI,  RGB_SAI, RGB_VAI, LAPP,
                RGB_HUD,  RGB_SAD, RGB_VAD, LFN,
                RGB_M_P,  XXXXXXX, XXXXXXX, LNAV,
                RGB_RMOD, RGB_TOG, RGB_MOD
                ),
    [_LYRICS] = LAYOUT(
                KC_UP,  XXXXXXX, C(KC_INS), LAPP,
                KC_DOWN,  XXXXXXX, XXXXXXX, LFN,
                C(A(KC_LEFT)), C(KC_ENT), C(A(KC_RGHT)), LNAV,
                A(KC_LEFT),  C(KC_SPC), XXXXXXX
                )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DAVMARKSMAN:
            if (record->event.pressed) {
                SEND_STRING("davmarksman");
            }
            break;
        case K_WINMOVE:
            if (record->event.pressed) {
                tap_code16(G(S(KC_LEFT)));
                tap_code16(G(KC_UP));
                tap_code16(G(KC_UP));
            }
            break;  
    }

    return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        // switch (get_highest_layer(layer_state)) {     //break each encoder update into a switch statement for the current layer           
        //     // change layers
        //     default:
        //         if (clockwise) {
        //             layer_move(_RGB);
        //         } else {
        //             layer_move(_LYRICS);
        //         }
        //         break;
        //     // 
        //     case _RGB:
        //         if (clockwise) {
        //             layer_move(_LYRICS);
        //         } else {
        //             layer_move(_APPS);
        //         }
        //         break;
        //     case _LYRICS:
        //         if (clockwise) {
        //             layer_move(_APPS);
        //         } else {
        //             layer_move(_RGB);
        //         }
        //         break;
        // }
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
        if (clockwise) {
           tap_code16(C(KC_Y));
        } else {
            tap_code16(C(KC_Z));
        }
        // switch (get_highest_layer(layer_state)) {
        //     case _NAV:
        //         if (clockwise) {
        //             tap_code(KC_PGDN);
        //         } else {
        //             tap_code(KC_PGUP);
        //         }
        //         break;
        //     case _RGB:
        //         if (clockwise) {
        //             rgblight_increase_sat();
        //         } else {
        //             rgblight_decrease_sat();
        //         }
        //         break;
        //     default:
        //         // Scroll tabs
        //         if (clockwise) {
        //             tap_code16(C(KC_TAB));
        //         } else {
        //             tap_code16(S(C(KC_TAB)));
        //         }
        //         break;
        // }
    } else if (index == 2) { /* Third encoder */
        switch (get_highest_layer(layer_state)) {
            case _RGB:
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
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
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) { //This will run every time the layer is updated
    switch (get_highest_layer(state)) {
        case _APPS:
            rgblight_mode(RGBLIGHT_MODE_BREATHING);
            break;
        case _FNPAD:
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
            break;
        case _NAV:
            rgblight_mode(RGBLIGHT_MODE_KNIGHT);
            break;
        case _RGB:
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            setrgb(RGB_RED, &led[0]);
            setrgb(RGB_SPRINGGREEN, &led[1]);
            setrgb(RGB_BLUE, &led[2]);
            // setrgb(0, 0, 0, &led[2]); - no colour
            break;
        case _LYRICS:
            rgblight_mode(RGBLIGHT_MODE_SNAKE);
            // setrgb(0, 0, 0, &led[2]); - no colour
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
        case _FNPAD:
            oled_write_P(PSTR("FUNCTIONS\n"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        case _APPS:
            oled_write_P(PSTR("APPS - PROGRAM\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAVIGATION\n"), false);
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

