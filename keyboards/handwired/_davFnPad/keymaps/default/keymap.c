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


#define K_SAVE LCTL(KC_S)
#define LSYS_NO LT(SYS,KC_NO)

// F2, Save
// No, No
// F9, F10,
// F11, F12, 

/*
qmk compile -kb handwired/_davFnPad -km default
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
     KC_F2   ,LSYS_NO
    ,KC_F7   ,KC_F8
    ,KC_F10  ,KC_F11
    ,KC_F12  ,K_SAVE
  ),
  [SYS] = LAYOUT(
    RESET     ,KC_NO     
    ,KC_NO    ,KC_NO     
    ,KC_NO    ,KC_NO  
    ,KC_NO    ,KC_NO        
  )
};