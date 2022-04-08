#pragma once

#include QMK_KEYBOARD_H

uint8_t mod_state;
uint8_t oneshot_mod_state;

// layers
enum layer_names {
    _BASE,
    _GAME,
    _L1,
    _SYNAV,
    _PLAYL,
    _PLAYR
};

// layer keys
#define LBASE TO(_BASE)
#define LGAME TO(_GAME)
#define LL1 OSL(_L1)
#define LNAV MO(_SYNAV)
#define LPLAY TO(_PLAYL)

#define L1_SPC LT(_L1, KC_SPC)
#define LSYN_N LT(_SYNAV,KC_N) 


// Mods
#define KT_A_ESC LALT_T(KC_ESC)
#define KT_A_TAB LALT_T(KC_TAB)
#define KT_C_BK LCTL_T(KC_BSPC)
#define KT_C_DEL LCTL_T(KC_DEL)
#define HOME_CT_E LCTL_T(KC_E)
#define HOME_CT_A LCTL_T(KC_A)
#define KT_A_DEL LALT_T(KC_DEL)

// expriment symbol nav layer
#define LSYN_BK LT(_SYNAV,KC_BSPC) 



// Userful defines
#define K_OSFT OSM(MOD_LSFT)
#define K_UNDO LCTL(KC_Z)
#define K_REDO LCTL(KC_Y)
#define K_CLIP C(A(KC_C))  // Paste Clipboard
#define K_AHK MEH(KC_NO) // autohotkey 
#define K_AT S(KC_QUOT) 
#define K_TILDE S(KC_BSLS)
#define K_PIPE S(KC_NUBS)
#define K_DQUOT S(KC_2)
#define K_GLOBAL C(S(KC_F))
#define K_UNDOTB C(S(KC_T))
#define K_SNIP G(S(KC_S))
#define K_CUR_BK A(KC_LEFT)
#define K_CUR_FW A(KC_RGHT)
#define K_ED_LF A(KC_I)
#define K_ED_RG A(KC_A)
#define K_SAVE C(KC_S)
#define K_RDESK G(C(KC_RGHT))
#define K_LDESK G(C(KC_LEFT))
#define K_RSNAP G(KC_RGHT)
#define K_LSNAP G(KC_LEFT)



// Apps
#define KA_RENAME KC_F2
#define KA_FIREFX KC_F17
#define KA_VSCODE KC_F18
#define KA_CHROME KC_F15
#define KA_VS19 KC_F16
#define KA_APP1 KC_F13
#define KA_APP2 KC_F14
#define KA_VOL KC_F20
#define KA_EXPLR G(KC_1)



// Custom codes
enum custom_keycodes {
    K_EQ_GR = SAFE_RANGE,
    K_AND,
    K_OR,
    KS_X2X,
    K_GRV3,
    K_WINDR,
    K_WINDL,
    KS_X2,
    K_TH,
    K_DTCOL,
    K_WINR,
    K_WINL,
    K_AK,
    K_RESET
   // K_COMSC
};

/*
* TAP DANCE
*/
enum {
    TD_MINS,
    TD_SCLN,
    TD_CMSC,
    TD_DOT
};


