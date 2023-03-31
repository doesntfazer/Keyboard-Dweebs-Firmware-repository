#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
//      0        1        2        3        4        5        6        7        8        9        10       11       12       13       14       15       16       17
        KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
        KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
        KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
        KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
        KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
                                            KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
};