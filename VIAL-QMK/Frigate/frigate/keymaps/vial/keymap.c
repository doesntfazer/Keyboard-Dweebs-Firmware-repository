#include QMK_KEYBOARD_H
#include "pointing_device.h"
#include "timer.h"
#include <math.h>

#define CTLA LCTL(KC_A)
#define CAE LCTL(LALT(KC_END))
#define CAD LCTL(LALT(KC_DEL))


enum frigate_layers {_QWERTY, _LOWER, _RAISE, _ADJUST, _MOUSE};
enum custom_keycodes {DRAG_SCROLL = USER00, SCROLL_SPEED_UP, SCROLL_SPEED_DOWN};

bool set_scrolling = false, speed_up_pressed = false, speed_down_pressed = false, mouse_buttons_pressed = false;
uint16_t layer4_timer;
float scroll_divisor_h = .5, scroll_divisor_v = .5, scroll_accumulated_h = 0, scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        scroll_accumulated_h += (float)mouse_report.x * scroll_divisor_h;
        scroll_accumulated_v += (float)mouse_report.y * scroll_divisor_v;
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    if (mouse_report.x || mouse_report.y || mouse_report.v || mouse_report.h || mouse_report.buttons) {
        if (!mouse_buttons_pressed) {layer_on(_MOUSE); layer4_timer = timer_read(); mouse_buttons_pressed = true;}
        else {layer4_timer = timer_read();}
    } else if (timer_elapsed(layer4_timer) > 750 || !mouse_buttons_pressed) {layer_off(_MOUSE); mouse_buttons_pressed = false;}
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL: set_scrolling = record->event.pressed; break;
        case SCROLL_SPEED_UP:
            if (record->event.pressed && !speed_up_pressed) {scroll_divisor_h += 0.1; scroll_divisor_v += 0.1;}
            speed_up_pressed = record->event.pressed; break;
        case SCROLL_SPEED_DOWN:
            if (record->event.pressed && !speed_down_pressed) {
                scroll_divisor_h = fmax(0.1, scroll_divisor_h - 0.1);
                scroll_divisor_v = fmax(0.1, scroll_divisor_v - 0.1);
            }
            speed_down_pressed = record->event.pressed; break;
        default: break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) != AUTO_MOUSE_DEFAULT_LAYER) set_scrolling = false;
    return state;
}











const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT (
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LCTL_T(KC_A),    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
        LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT, RSFT_T(KC_SLSH),
                          FN_MO13,    KC_SPACE,    KC_BSPC,    FN_MO23
    ),

    [_LOWER] = LAYOUT (
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,    KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_TRNS,    KC_MINUS,    KC_EQUAL,    KC_LBRC,    KC_RBRC,
        KC_LCTL,    KC_GRAVE,    KC_LGUI,    KC_LALT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_BSLS,    KC_SCLN,
                          FN_MO13,    KC_TRNS,    KC_ENTER,    FN_MO23
    ),
    [_RAISE] = LAYOUT (
        KC_EXLM,    KC_AT,    KC_HASH,    KC_DLR,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,
        KC_ESC,    KC_DEL,    CTLA,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,
        KC_CAPS,    KC_TILDE,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PIPE,    KC_COLN,
                          FN_MO13,    KC_TRNS,    KC_TRNS,    FN_MO23
    ),
    [_ADJUST] = LAYOUT (
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
        KC_F11,    KC_F12,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    CAE,    CAD,    CAD,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                          KC_TRNS,    KC_TRNS,    QK_BOOT,    KC_TRNS
    ),

    [_MOUSE] = LAYOUT (
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                          DRAG_SCROLL,    KC_BTN1,    KC_BTN2,   KC_BTN3
    ),
};
