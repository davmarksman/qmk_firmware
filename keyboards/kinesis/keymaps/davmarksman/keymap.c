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

void td_open_parentesis(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && (state->interrupted || !state->pressed)){
        tap_code16(KC_LPRN);
    } else if(state->pressed){
        tap_code16(KC_END);
        tap_code16(KC_LPRN);
    }
}

void td_close_parentesis(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && (state->interrupted || !state->pressed)){
        tap_code16(KC_RPRN);
    } else if(state->pressed){
        tap_code16(KC_END);
        tap_code16(KC_RPRN);
    }
}
void td_open_curly(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && (state->interrupted || !state->pressed)){
        tap_code16(KC_LCBR);
    } else if(state->pressed){
        tap_code16(KC_END);
        tap_code16(KC_LCBR);
    }
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_CMSC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_COLN),
    [TD_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dot_finished, dance_dot_reset),
    [TD_FIND] = ACTION_TAP_DANCE_DOUBLE(C(KC_F), C(KC_A)),
    [TD_LPRN] = ACTION_TAP_DANCE_FN(td_open_parentesis),
    [TD_RPRN] = ACTION_TAP_DANCE_FN(td_close_parentesis),
    [TD_LCBR] = ACTION_TAP_DANCE_FN(td_open_curly),
};


// Adaptive keys
uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(    
          KA_EXPLR    ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_ESC      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_Y        ,KC_O        ,KC_MINS     ,KC_EQL      ,
          C(KC_F)     ,KC_H        ,KC_I        ,KC_E        ,HOME_CT_A   ,TD(TD_CMSC) ,
          C(KC_A)     ,KC_Z        ,KC_K        ,KC_DOT      ,KC_U        ,TD(TD_SCLN) ,
                       KC_GRV      ,KC_BSLS     ,KC_NUBS     ,KC_SLSH     ,
          // Thumb
                       KT_A_ESC    ,K_CLIP      ,
                                    KC_LEAD     , 
          K_OSFT      ,LSYN_BK     ,KC_DEL      ,
          // Right Hand
          KC_F9       ,KC_F10      ,KC_F11      ,KC_F12      ,KC_MPRV     ,KC_MPLY     ,KC_MNXT     ,KA_VOL      ,LGAME       ,
          KC_6        ,KC_7        ,KC_8        ,KC_9        ,KC_0        ,KA_RENAME   ,
          KC_V        ,KC_F        ,KC_L        ,KC_P        ,KC_J        ,KC_BSLS     ,
          KC_W        ,KC_D        ,KC_T        ,KC_S        ,KC_R        ,KC_LEAD     ,
          KC_B        ,KC_C        ,KC_M        ,KC_G        ,KC_X        ,K_AT        ,
                       KC_QUOT     ,KC_RGUI     ,KC_RCTL     ,KC_GRV      ,
          // Thumb
          KC_CAPS     ,K_AHK       ,
          KC_LEAD     ,
          KC_ENT      ,L1_SPC      ,KC_N       
    ),
[_GAME] = LAYOUT(
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,KC_F6       ,KC_F7       ,KC_F8       ,
          KC_EQL      ,KC_1        ,KC_2        ,KC_3        ,KC_4        ,KC_5        ,
          KC_TAB      ,KC_Q        ,KC_W        ,KC_E        ,KC_R        ,KC_T        ,
          KC_CAPS     ,KC_A        ,KC_S        ,KC_D        ,KC_F        ,KC_G        ,
          KC_LSFT     ,KC_Z        ,KC_X        ,KC_C        ,KC_V        ,KC_B        ,
                       XXXXXXX     ,KC_LEFT     ,KC_RGHT     ,KC_SLSH     ,
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
          S(KC_TAB)   ,XXXXXXX     ,K_EQ_GR     ,KC_LCBR     ,KC_RCBR     ,K_UNDOTB    ,
          XXXXXXX     ,KC_LT       ,KC_EXLM     ,KC_LPRN     ,KC_RPRN     ,K_GLOBAL    ,
          KC_CAPS     ,XXXXXXX     ,KC_GT       ,KC_LBRC     ,KC_RBRC     ,XXXXXXX     ,
                       XXXXXXX     ,K_LDESK     ,K_RDESK     ,XXXXXXX     ,
          // Thumb
                       XXXXXXX     ,KC_ESC     ,
                                    XXXXXXX     ,
          KC_EXLM     ,KC_QUES     , S(KC_TAB)  ,
          // Right Hand
          K_RESET     ,RESET       ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11      ,
          XXXXXXX     ,KC_AMPR     ,K_GRV3      ,K_OR        ,XXXXXXX     ,KC_F12      ,
          K_SNIP      ,K_DQUOT     ,KC_UNDS     ,KC_COLN     ,KC_GT       ,XXXXXXX     ,
          K_SNIP      ,K_SNIP      ,XXXXXXX      ,K_PIPE      ,XXXXXXX     ,KC_INS      ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
          XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     
    ),
[_SYNAV] = LAYOUT(
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_ESC      ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,
          XXXXXXX     ,XXXXXXX     ,S(C(KC_TAB)),C(KC_TAB)   ,LSYNR       ,K_UNDOTB    ,
          XXXXXXX     ,KC_LALT     ,RCS(KC_NO)  ,KC_LCTL     ,KC_LSFT     ,KC_LGUI     ,
          XXXXXXX     ,K_UNDO      ,C(KC_X)     ,C(KC_C)     ,C(KC_V)     ,XXXXXXX     ,
                       K_LSNAP     ,K_WINL      ,K_WINR      ,LSYNR        ,
          // Thumb
                       XXXXXXX     ,XXXXXXX     ,
                                    XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX  ,
          // Right Hand
          K_RESET     ,RESET       ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11      ,
          KC_PGUP     ,KC_HOME     ,KC_UP       ,KC_END      ,XXXXXXX     ,KC_F12      ,
          KC_PGDN     ,KC_LEFT     ,KC_DOWN     ,KC_RGHT     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,K_ED_LF     ,K_CUR_BK    ,K_ED_RG    ,K_CUR_FW     ,KC_INS      ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
          XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,
          XXXXXXX     ,C(KC_BSPC)     ,XXXXXXX     
    ),
[_WASD] = LAYOUT(
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          KC_ESC      ,KC_0        ,KC_9        ,KC_8        ,KC_7        ,KC_6        ,
          S(KC_TAB)   ,KC_HOME     ,KC_UP       ,KC_END      ,KC_PGUP     ,XXXXXXX     ,
          XXXXXXX     ,KC_LEFT     ,KC_DOWN     ,KC_RGHT     ,KC_PGDN     ,KC_LALT     ,
          XXXXXXX     ,K_UNDO      ,C(KC_X)     ,C(KC_C)     ,C(KC_V)     ,XXXXXXX     ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,LBASE     ,
          // Thumb
                       XXXXXXX     ,XXXXXXX     ,
                                    XXXXXXX     ,
          XXXXXXX     ,LBASE       ,XXXXXXX  ,
          // Right Hand
          K_RESET     ,RESET       ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
                       XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
          // Thumb
          XXXXXXX     ,XXXXXXX     ,
          XXXXXXX     ,
          XXXXXXX     ,C(KC_BSPC)     ,XXXXXXX     
    ),

// [_CODE] = LAYOUT(
//           XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
//           KC_ESC      ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
//           S(KC_TAB)   ,XXXXXXX     ,XXXXXXX     ,K_TEST_L    ,K_TEST_R    ,K_TEST_D    ,
//           C(KC_F)     ,XXXXXXX     ,XXXXXXX     ,A(KC_E)     ,C(KC_A)     ,K_GLOBAL     ,
//           C(KC_A)     ,K_UNDO      ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
//                        XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,C(KC_SLSH)  ,
//           // Thumb
//                        XXXXXXX     ,XXXXXXX     ,
//                                     XXXXXXX     ,
//           XXXXXXX     ,C(KC_BSPC)  ,XXXXXXX     ,
//           // Right Hand
//           K_RESET     ,RESET       ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
//           XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
//           XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
//           XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
//           XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
//                        XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,XXXXXXX     ,
//           // Thumb
//           XXXXXXX     ,XXXXXXX     ,
//           XXXXXXX     ,
//           XXXXXXX     ,C(KC_SPC)     ,XXXXXXX     
//     ),
};


bool adaptive(uint16_t base, uint16_t prior, uint16_t adapt, uint16_t keycode, keyrecord_t *record){
  if(keycode == base){
    if (record->event.pressed) {
        if ((prior_keycode == prior) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
            tap_code(adapt);  
 
            #ifdef CONSOLE_ENABLE
                bool isShift = (get_mods() & MOD_MASK_SHIFT) | (get_oneshot_mods() & MOD_MASK_SHIFT);
                bool isCtrl = (get_mods() & MOD_MASK_CTRL) | (get_oneshot_mods() & MOD_MASK_CTRL);
                uprintf("0x%04X,%u,%u,%u,%s,%s\n", adapt, record->event.key.row, record->event.key.col, get_highest_layer(layer_state), isShift ? "Shift": "", isCtrl? "Ctrl": "");
            #endif
            return true;
        }
    }
  }
  return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    bool return_state = true;
    uint16_t record_code = keycode;

    bool adapted = adaptive(KC_D, KC_T, KC_H, keycode, record)
        || adaptive(KC_D, KC_S, KC_H, keycode, record)
        // || adaptive(KC_D, KC_P, KC_H, keycode, record)
        || adaptive(KC_D, KC_W, KC_H, keycode, record)
        || adaptive(KC_M, KC_C, KC_H, keycode, record)
        || adaptive(KC_M, KC_G, KC_H, keycode, record)
        || adaptive(KC_MINS, KC_O, KC_U, keycode, record)
        || adaptive(KC_C, KC_B, KC_L, keycode, record)
        || adaptive(KC_B, KC_C, KC_L, keycode, record)
        // || adaptive(KC_V, KC_M, KC_B, keycode, record)
        || adaptive(KC_G, KC_M, KC_P, keycode, record)
       // || adaptive(KC_L, KC_B, KC_M, keycode, record)// // adaptive BL to BM
        ;
    if(adapted){
        return_state = false;
    }

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
        case K_RESET:
            if (record->event.pressed) {
                tap_code16(K_AHK);
                _delay_ms(100);
                SEND_STRING("teen");
                _delay_ms(100);
                tap_code16(KC_ENT);                
                _delay_ms(200);
                reset_keyboard();
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

    if (record->event.pressed) {
        prior_keycode = keycode;
        prior_keydown = timer_read(); 
    }

    #ifdef CONSOLE_ENABLE
        if(!adapted){
            if (record->event.pressed) {
                bool isShift = (get_mods() & MOD_MASK_SHIFT) | (get_oneshot_mods() & MOD_MASK_SHIFT);
                bool isCtrl = (get_mods() & MOD_MASK_CTRL) | (get_oneshot_mods() & MOD_MASK_CTRL);
                uprintf("0x%04X,%u,%u,%u,%s,%s\n", record_code, record->event.key.row, record->event.key.col, get_highest_layer(layer_state), isShift ? "Shift": "", isCtrl? "Ctrl": "");
            }
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
    writePin(LED_CAPS_LOCK_PIN, !(hi_state == _WASD));    

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


bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L1_SPC:
            return true; 
        default:
            return false;
    }
}