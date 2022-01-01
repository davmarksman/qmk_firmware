#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

/*
* Combos
*/
enum combos {
  FIND,
  REPLACE,
  ALL,
  COPY,
  PASTE,

  QU,
  DM_DAV,
  OBRACK,
  CBRACK,
  SB_BROK,
  ING,
  AK,
  INSU,
  FOR,
  BL,
  OU,

  // Prevents missfires
  L1_LPRN,
  L1_RPRN,
  L1_QU,
  QUOTE,
  // // This must be the last item in the enum.
  // This is used to automatically update the combo count.
  COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM qu_combo[] = {KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM sb_combo[] = {KC_P, KC_S, COMBO_END};

const uint16_t PROGMEM ing_combo[] = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM ak_combo[] = {HOME_CT_A, KC_K, COMBO_END};
const uint16_t PROGMEM for_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM ins_combo[] = {KC_W, KC_B, COMBO_END};
const uint16_t PROGMEM fb_combo[] = {KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM ou_combo[] = { KC_MINS, KC_O, COMBO_END};


const uint16_t PROGMEM all_combo[] = {KC_Q, KC_Y, COMBO_END};
const uint16_t PROGMEM find_combo[] = {KC_Y, KC_MINS, COMBO_END};


const uint16_t PROGMEM obrack_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM cbrack_combo[] = {KC_O, KC_E, COMBO_END};


const uint16_t PROGMEM spe_combo[] = {L1_SPC, KC_E, COMBO_END};
const uint16_t PROGMEM spd_combo[] = {L1_SPC, KC_D, COMBO_END};
const uint16_t PROGMEM spa_combo[] = {L1_SPC, HOME_CT_A, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END}; 

const uint16_t PROGMEM copy_combo[] = {KC_DOT, TD(TD_CMSC), COMBO_END}; 
const uint16_t PROGMEM paste_combo[] = {KC_U, TD(TD_CMSC), COMBO_END}; 

combo_t key_combos[] = {
  //[REPLACE] = COMBO_ACTION(rep_combo),
  [QU] = COMBO_ACTION(qu_combo),
  [DM_DAV] = COMBO_ACTION(dv_combo),
  [OBRACK] = COMBO_ACTION(obrack_combo),
  [CBRACK] = COMBO_ACTION(cbrack_combo),
  [SB_BROK] = COMBO_ACTION(sb_combo),
  [ING] = COMBO_ACTION(ing_combo),
  [AK] = COMBO_ACTION(ak_combo),
  [FOR] = COMBO_ACTION(for_combo),
  [INSU] = COMBO_ACTION(ins_combo),
  [ALL] = COMBO_ACTION(all_combo),
  [BL] = COMBO_ACTION(fb_combo),
  [OU] = COMBO_ACTION(ou_combo),

  [FIND] = COMBO_ACTION(find_combo),
  [L1_LPRN] = COMBO_ACTION(spe_combo),
  [L1_RPRN] = COMBO_ACTION(spa_combo),
  [L1_QU] = COMBO_ACTION(spd_combo),
  [QUOTE] = COMBO_ACTION(cd_combo),

  [COPY] = COMBO_ACTION(copy_combo),
  [PASTE] = COMBO_ACTION(paste_combo),
};

void word_combo(bool pressed, uint8_t mod_state, char* word) {
  if (pressed) {
    if (mod_state & MOD_MASK_SHIFT) {
      del_mods(MOD_MASK_SHIFT);
      send_string(word);
      set_mods(mod_state);
    }
    else {
      word[0] = word[0] + 32; // make first char lower
      send_string(word);
      word[0] = word[0] - 32; // reset
    }
  }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
#ifdef CONSOLE_ENABLE
    if (pressed) {
        combo_t *combo = &key_combos[combo_index];
        uint8_t idx = 0;
        uint16_t combo_keycode;
        while ((combo_keycode = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
            uprintf("0x%04X,NA,NA,%u\n", combo_keycode, get_highest_layer(layer_state));
            idx++;
        }
    }
#endif

  mod_state = get_mods();
  switch(combo_index) {

    case FOR:
      word_combo(pressed,mod_state, "For");
      break;
    case ING:
      if (pressed) {
        SEND_STRING("ing");
      }
      break;
    case INSU:
      word_combo(pressed,mod_state, "Insur");
      break;
    case OBRACK:
        if (pressed) {
          tap_code16(KC_LCBR);
        }
        break;
    case CBRACK:
        if (pressed) {
          tap_code16(KC_RCBR);
        }
        break; 
    case QU:
      word_combo(pressed,mod_state, "Qu");
      break; 
    case BL:
      word_combo(pressed,mod_state, "Bl");
      break; 
    case OU:
      word_combo(pressed,mod_state, "Ou");
      break; 
    case FIND:
      if (pressed) {
        tap_code16(C(KC_F));
      }
      break;
    case ALL:
      if (pressed) {
        tap_code16(C(KC_A));
      }
      break;
    case COPY:
      if (pressed) {
        tap_code16(C(KC_C));
      }
      break;
    case PASTE:
      if (pressed) {
        tap_code16(C(KC_V));
      }
      break;

    case DM_DAV:
      if (pressed) {
      word_combo(pressed,mod_state, "David");
      }
      break;
    case SB_BROK:
      word_combo(pressed,mod_state, "Brok");
      break;
    case AK:
      if (pressed) {
        SEND_STRING("ak");
      }
      break;
    case L1_LPRN:
      if (pressed) {
        tap_code16(KC_LPRN);     
      }
      break;
    case L1_RPRN:
      if (pressed) {
        tap_code16(KC_RPRN);     
      }
      break;
    case L1_QU:
      if (pressed) {
        tap_code16(K_DQUOT);     
      }
      break;
    case QUOTE:
      if (pressed) {
        tap_code16(K_DQUOT);     
      }
      break;
  }
}
