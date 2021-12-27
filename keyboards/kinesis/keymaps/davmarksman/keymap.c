//Kinesis
#include "sendstring_uk.h"
#include "keymap.h"

// This will import the uprintf function
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

/* Changes for recording
- new tap dances - ,; & dot,:ellipses
- new combos
*/

void dance_dot_finished(qk_tap_dance_state_t *state, void *user_data) {
    #ifdef CONSOLE_ENABLE
        uprintf("0x%04X,%u,%u,%u,%s,%s,%s\n", state->count, 0, 0, 0, "", "", "TD_DOT");
    #endif

    switch (state->count) {
        case 1:
            register_code(KC_DOT);
            break;
        case 2:
            register_code16(KC_COLN);
            break;
        case 3:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            register_code(KC_DOT);
            break;
    }
}

void dance_dot_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        unregister_code16(KC_COLN);
    } else {  
        unregister_code(KC_DOT);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_CMSC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_COLN),
    [TD_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dot_finished, dance_dot_reset),
};



// Adaptive keys
uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(    
          KA_EXPLR    ,K_SAVE      ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_ESC      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_Y        ,KC_O        ,KC_MINS     ,KC_EQL      ,
          KC_NO        ,KC_H        ,KC_I        ,KC_E        ,HOME_CT_A   ,KC_K        ,
          KC_NUBS     ,KC_Z        ,KC_DOT      ,TD(TD_CMSC) ,KC_U        ,TD(TD_SCLN) ,
                       KC_CAPS     ,KC_GRV      ,KC_PLUS     ,KC_SLSH     ,
          // Thumb
                       KT_A_ESC    ,K_CLIP      ,
                                    KC_BSLS     , // for gaming
          K_OSFT      ,LSYN_BK     ,KC_DEL      ,
          // Right Hand
          KA_APP2     ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,LPLAY      ,LGAME       ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,KA_RENAME   ,
          KC_B        ,KC_F        ,KC_L        ,KC_P        ,KC_J        ,KC_BSLS     ,
          KC_W        ,KC_D        ,KC_T        ,KC_S        ,KC_R        ,KC_QUOT     ,
          KC_V        ,KC_C        ,KC_M        ,KC_G        ,KC_X        ,KC_SLSH     ,
                       KC_LALT     ,KC_RGUI     ,KC_RCTL     ,KC_GRV      ,
          // Thumb
          KC_RCTL     ,K_AHK       ,
          KC_NO       ,
          KC_ENT      ,L1_SPC      ,KC_N       
    ),
[_GAME] = LAYOUT(
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_EQL      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_W        ,KC_E        ,KC_R        ,KC_T        ,
          XXXXXXX     ,KC_A        ,KC_S        ,KC_D        ,KC_F        ,KC_G        ,
          KC_LSFT     ,KC_Z        ,KC_X        ,KC_C        ,KC_V        ,KC_B        ,
                       XXXXXXX     ,KC_LEFT     ,KC_RGHT     ,XXXXXXX     ,
          // Thumb
                       KT_A_ESC    ,K_CLIP      ,
                                    K_SAVE      ,
          KC_LSFT     ,KT_C_BK     ,LNAV        ,
          // Right Hand
          KC_F9       ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,KA_VOL       ,LBASE     ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,KC_MINS     ,
          KC_Y        ,KC_U        ,KC_I        ,KC_O        ,KC_P        ,KC_NUBS     ,
          KC_H        ,KC_J        ,KC_K        ,KC_L        ,KC_SCLN     ,KC_QUOT     ,
          KC_N        ,KC_M        ,KC_COMM     ,KC_DOT      ,KC_SLSH     ,KC_RSFT     ,
                       KC_LALT     ,KC_RGUI     ,KC_RBRC     ,KC_GRV      ,
          // Thumb
          KC_UP       ,K_AHK       ,
          KC_DOWN     ,
          KC_ENT      ,KC_SPC      ,LL1         
    ),
[_L1] = LAYOUT(
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,
          S(KC_TAB)   ,XXXXXXX     ,KC_LT       ,KC_GT       ,K_EQ_GR     ,K_UNDOTB    ,
          XXXXXXX     ,KS_X2X      ,KC_PPLS     ,KC_LPRN     ,KC_RPRN     ,K_GLOBAL    ,
          KC_CAPS     ,KS_X2       ,XXXXXXX     ,KC_LBRC     ,KC_RBRC     ,XXXXXXX     ,
                       XXXXXXX     ,K_LDESK     ,K_RDESK     ,XXXXXXX     ,
          // Thumb
                       XXXXXXX     ,XXXXXXX     ,
                                    XXXXXXX     ,
          KC_EXLM     ,KC_QUES     , S(KC_TAB)  ,
          // Right Hand
          RESET       ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11      ,
          XXXXXXX     ,K_AND       ,K_GRV3      ,K_OR        ,XXXXXXX     ,KC_F12      ,
          XXXXXXX     ,K_DQUOT     ,KC_UNDS     ,K_PIPE      ,XXXXXXX     ,XXXXXXX     ,
          K_SNIP      ,K_SNIP      ,KC_LT       ,KC_GT       ,XXXXXXX     ,KC_INS      ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
          XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     
    ),
    [_SYNAV] = LAYOUT(
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,
          S(KC_TAB)   ,XXXXXXX     ,K_CUR_BK    ,K_CUR_FW   ,XXXXXXX      ,S(KC_TAB)    ,
          XXXXXXX     ,KC_LALT     ,RCS(KC_NO)  ,KC_LCTL     ,KC_LSFT     ,KC_LGUI     ,
          KC_CAPS     ,K_UNDO      ,C(KC_X)     ,C(KC_C)     ,C(KC_V)     ,XXXXXXX     ,
                       XXXXXXX     ,K_WINL      ,K_WINR     ,XXXXXXX     ,
          // Thumb
                       XXXXXXX     ,XXXXXXX     ,
                                    XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX  ,
          // Right Hand
          RESET       ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11      ,
          KC_PGUP     ,KC_HOME     ,KC_UP       ,KC_END      ,XXXXXXX     ,KC_F12      ,
          KC_PGDN     ,KC_LEFT     ,KC_DOWN     ,KC_RGHT     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,K_ED_LF     ,XXXXXXX     ,K_ED_RG     ,XXXXXXX     ,KC_INS      ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
          XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,
          XXXXXXX     ,C(KC_BSPC)     ,KC_CAPS     
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
        case K_TH:
        {
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT || get_oneshot_mods() & MOD_MASK_SHIFT) {
                    SEND_STRING("Th");
                } else{
                    SEND_STRING("th");
                }
            }
            break;
        }
        case KC_D:
        {
            // adaptive D to H
            if (record->event.pressed) {
                if ((prior_keycode == KC_T || prior_keycode == KC_S || prior_keycode == KC_G) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_H); 
                    record_code = KC_H;
                    return_state = false; 
                }
                break;   
            }
        }
        case KC_M:
        {
            // adaptive CM to CL
            if (record->event.pressed) {
                if ((prior_keycode == KC_C) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_L); 
                    record_code = KC_L;
                    return_state = false; 
                }
                break;   
            }
        }
        case KC_G:
        {
            // adaptive MG to MB
            if (record->event.pressed) {
                if ((prior_keycode == KC_M) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_B); 
                    record_code = KC_B;
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

void led_set_user(uint8_t usb_led) {

}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t hi_state = get_highest_layer(state);
    writePin(LED_COMPOSE_PIN, !(hi_state == _GAME || hi_state == _PLAYL));
    writePin(LED_SCROLL_LOCK_PIN, !(hi_state == _SYNAV || hi_state == _PLAYL));
    writePin(LED_NUM_LOCK_PIN, !(hi_state == _L1));    


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
