#pragma once

#include QMK_KEYBOARD_H

uint8_t mod_state;
uint8_t oneshot_mod_state;

// layers
enum layers {
    _BASE,
    // _QWERTY,
    _GAME,
    _L1,
    _SYNAV
};

// layer keys
#define LBASE TO(_BASE)
#define LGAME TO(_GAME)
#define LL1 OSL(_L1)
#define LNAV MO(_SYNAV)

// #define LQM TO(_QWERTY)
#define L1_SPC LT(_L1, KC_SPC)
#define LSYN_N LT(_SYNAV,KC_N) 

// Userful defines
#define K_OSFT OSM(MOD_LSFT)
#define K_UNDO LCTL(KC_Z)
#define K_REDO LCTL(KC_Y)
#define K_CLIP C(A(KC_C))  // Paste Clipboard
#define K_AHK MEH(KC_NO) // autohotkey 


#define KT_A_ESC LALT_T(KC_ESC)
#define KT_A_TAB LALT_T(KC_TAB)
#define KT_C_BK LCTL_T(KC_BSPC)
#define KT_C_DEL LCTL_T(KC_DEL)
#define KT_S_EXLM LSFT_T(KC_EXLM)

#define K_AT S(KC_QUOT) 
#define K_TILDE S(KC_BSLS)
#define K_PIPE S(KC_NUBS)
#define K_GLOBAL C(S(KC_F))
#define K_UNDOTB C(S(KC_T))
#define K_SNIP G(S(KC_S))

#define HOME_C_S LCTL_T(KC_S)
#define HOME_C_R LCTL_T(KC_R)

// Custom codes
enum custom_keycodes {
    K_EQ_GR = SAFE_RANGE,
    K_AND,
    K_OR,
    KS_X2X,
    K_GRV3,
};

/*
* TAP DANCE
*/
enum {
    TD_MINS,
    TD_SCLN
};

