/*
qmk compile -kb handwired/_davFnPad -km default
*/

#include QMK_KEYBOARD_H


// layers
enum layer_names {
    BASE,
    APP,
    SYS,
};



#define K_SAVE LCTL(KC_S)
#define LSYS_F7 LT(SYS,KC_F7)

#define LAPP TO(APP)
#define LBASE TO(BASE)

 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
     KC_F2   ,LAPP
    ,LSYS_F7 ,KC_F8
    ,KC_F10  ,KC_F11
    ,KC_F12  ,K_SAVE
  ),
  [APP] = LAYOUT(
     RESET     ,LBASE     
    ,KC_F13    ,KC_F14     
    ,KC_F15    ,KC_F16  
    ,KC_F17    ,KC_F18        
  ),
  [SYS] = LAYOUT(
     KC_NO    ,KC_NO     
    ,KC_NO    ,RESET     
    ,KC_NO    ,KC_NO  
    ,KC_NO    ,KC_NO        
  )
};
