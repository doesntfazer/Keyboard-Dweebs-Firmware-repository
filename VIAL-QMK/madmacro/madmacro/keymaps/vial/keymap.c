// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H



enum custom_keycodes {
    SLIDE_CANCEL = QK_KB_0,
    ST_A,
    ST_D
};

// Global state variables
bool is_a_pressed = false;
bool is_d_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool holding_key = false;

    switch (keycode) {
        case SLIDE_CANCEL:
            if (record->event.pressed) {
                // When key is pressed, hold it down
                register_code(KC_C);  // Replace KC_C with the key you want to hold
                holding_key = true;
            } else {
                // When key is released, press and release an additional key
                if (holding_key) {
                    unregister_code(KC_C);  // Release the held key
                    tap_code(KC_SPACE);     // Replace KC_SPACE with the additional key
                    holding_key = false;
                }
            }
            return false; // Skip further processing of this key

        case ST_A:
            if (record->event.pressed) {
                is_a_pressed = true;
                if (is_d_pressed) {
                    unregister_code(KC_D);
                }
                register_code(KC_A);
            } else {
                is_a_pressed = false;
                unregister_code(KC_A);
                if (is_d_pressed) {
                    register_code(KC_D);
                }
            }
            return false; // Prevent further processing

        case ST_D:
            if (record->event.pressed) {
                is_d_pressed = true;
                if (is_a_pressed) {
                    unregister_code(KC_A);
                }
                register_code(KC_D);
            } else {
                is_d_pressed = false;
                unregister_code(KC_D);
                if (is_a_pressed) {
                    register_code(KC_A);
                }
            }
            return false; // Prevent further processing

        default:
            return true; // Process all other keycodes normally
    }
}




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │
     * ├───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │
     * ├───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │
     * ├───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │
     * ├───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │
     * └───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_5x5(
                 KC_A,    KC_B,    KC_C,    KC_D, KC_E, KC_E,
                 KC_A,    KC_B,    KC_C,    KC_D, KC_E, KC_E,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E, KC_E, KC_E,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E, KC_E, KC_E,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E, KC_E, KC_E
    )
};


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            rgblight_sethsv_noeeprom(170, 255, 255); // Blue for layer 0
            break;
        case 1:
            rgblight_sethsv_noeeprom(0, 255, 255);   // Red for layer 1
            break;
        case 2:
            rgblight_sethsv_noeeprom(85, 255, 255);  // Green for layer 2
            break;
        case 3:
            rgblight_sethsv_noeeprom(20, 100, 255);  // Green for layer 3
            break;
        default:
            rgblight_sethsv_noeeprom(0, 0, 255);     // White for all other layers
            break;
    }
    return state;
}

void keyboard_post_init_user(void) {
    rgblight_enable();  // Enable the RGB lighting
}
