#include QMK_KEYBOARD_H
#include <stdio.h>
char wpm_str[10];

#define CTLA LCTL(KC_A)
#define CAE LCTL(LALT(KC_END))
#define CAD LCTL(LALT(KC_DEL))
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)



enum ostrich_layers {
_QWERTY,
_LOWER,
_RAISE,
_ADJUST,
};

     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │Bsp├───┐   ┌───┤Ent│
      *               └───┤Tab│   │Spc├───┘
      *                   └───┘   └───┘
      */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LCTL_T(KC_A),    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RCTL_T(KC_QUOT),
        LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT, RSFT_T(KC_SLSH),
                          LOWER,    KC_SPACE,    KC_BSPC,    RAISE
    ),

    [_LOWER] = LAYOUT_split_3x5_2(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,    KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_TRNS,    KC_MINUS,    KC_EQUAL,    KC_LBRC,    KC_RBRC,
        KC_LCTL,    KC_GRAVE,    KC_LGUI,    KC_LALT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_BSLS,    KC_SCLN,
                         LOWER,    KC_TRNS,    KC_ENTER,    RAISE
    ),
    [_RAISE] = LAYOUT_split_3x5_2(
        KC_EXLM,    KC_AT,    KC_HASH,    KC_DLR,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,
        KC_ESC,    KC_DEL,    CTLA,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,
        KC_CAPS,    KC_TILDE,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PIPE,    KC_COLN,
                          LOWER,    KC_TRNS,    KC_TRNS,    RAISE
    ),
    [_ADJUST] = LAYOUT_split_3x5_2(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
        KC_F11,    KC_F12,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    CAE,    CAD,    CAD,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
};





layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}




#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_RAISE] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_ADJUST] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif


/**
 * Put this somewhere at the beginning of the file --
 * Make sure you import only one of animations at a time
 * They all have same function exported, so it won't compile if you
 * include more than one at a time. You can also configure some options
 * before including the animation. Not all animations support them, but some do :P.
 */
 


#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 45 //Switch to fast animation when over words per minute

#ifdef OLED_ENABLE
    #include "crab.c"
#endif

// -- Probably some other stuff and then --

#ifdef OLED_ENABLE
bool oled_task_user(void) {

        oled_render_anim();
	

	return false;
}
#endif
