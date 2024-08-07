// Copyright 2021 Keyboard Dweebs (@doesntfazer)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#define CTLA LCTL(KC_A)
#define CAE LCTL(LALT(KC_END))
#define CAD LCTL(LALT(KC_DEL))

enum crow_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_3x5_2 (
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        LCTL_T(KC_A),    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
        LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM,    KC_DOT, RSFT_T(KC_SLSH),
                          TL_LOWR,    KC_SPACE,    KC_BSPC,    TL_UPPR
    ),

    [_LOWER] = LAYOUT_split_3x5_2 (
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,    KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_TRNS,    KC_MINUS,    KC_EQUAL,    KC_LBRC,    KC_RBRC,
        KC_LCTL,    KC_GRAVE,    KC_LGUI,    KC_LALT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_BSLS,    KC_SCLN,
                          TL_LOWR,    KC_TRNS,    KC_ENTER,    TL_UPPR
    ),
    [_RAISE] = LAYOUT_split_3x5_2 (
        KC_EXLM,    KC_AT,    KC_HASH,    KC_DLR,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,
        KC_ESC,    KC_DEL,    CTLA,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,
        KC_CAPS,    KC_TILDE,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PIPE,    KC_COLN,
                           TL_LOWR,    KC_TRNS,    KC_TRNS,    TL_UPPR
    ),
    [_ADJUST] = LAYOUT_split_3x5_2 (
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
        KC_F11,    KC_F12,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    CAD,    CAE,    CAD,    CAD,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
};


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        default:
            // Force the mod-tap key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return true;
    }
}



