 /* Copyright 2020 Bratzworth 
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
  * (at your option) any later version. 
  * 
  * This program is distributed in the hope that it will be useful, 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
  * GNU General Public License for more details. 
  * 
  * You should have received a copy of the GNU General Public License 
  * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
  */
#include QMK_KEYBOARD_H


// layers
enum layer_names {
    BASE,
    SYS,
};


// layer keys
#define LSYS_HOME LT(SYS,KC_HOME)
#define KT_C_END LCTL_T(KC_END)
#define LSYS LT(SYS,KC_NO)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_HOME  ,KC_UP    ,KT_C_END   , 
    KC_LEFT    ,KC_DOWN  ,KC_RGHT   ,LSYS
  ),
  [SYS] = LAYOUT(
    KC_NO     ,KC_NO     ,RESET     ,
    KC_NO     ,KC_NO     ,KC_NO     ,KC_NO   
  )
};

// keyboards\handwired\6davkey\keymaps\default\keymap.c

// qmk compile -kb handwired/6davkey -km default

void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code16(C(KC_Y));
  } else {
    tap_code16(C(KC_Z));
  }
}