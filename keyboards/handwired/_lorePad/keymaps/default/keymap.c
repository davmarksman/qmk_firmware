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
#define KT_C_END LCTL_T(KC_END)


#define K_UNDO LCTL(KC_Z)
#define K_REDO LCTL(KC_Y)
#define K_COPY LCTL(KC_C)
#define K_CUT LCTL(KC_X)
#define K_PASTE LCTL(KC_V)
#define K_SAVE LCTL(KC_S)
#define LSYS_HOME LT(SYS,K_SAVE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    K_UNDO  ,K_REDO, 
    K_COPY  ,K_PASTE    ,
    K_CUT   ,K_SAVE
  ),
  [SYS] = LAYOUT(
    KC_NO     ,RESET     
    ,KC_NO    ,KC_NO     
    ,KC_NO    ,KC_NO     
  )
};