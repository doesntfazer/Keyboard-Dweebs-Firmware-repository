#include QMK_KEYBOARD_H
#include "custom_keycodes.h"
#include "taipo.c"


enum layers {
  _TAIPO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_TAIPO] = LAYOUT_split_3x5_2(
        TP_TLP,   TP_TLR,   TP_TLM,   TP_TLI,   KC_NO,    KC_NO,    TP_TRI,   TP_TRM,   TP_TRR,   TP_TRP,
        TP_BLP,   TP_BLR,   TP_BLM,   TP_BLI,   KC_NO,    KC_NO,    TP_BRI,   TP_BRM,   TP_BRR,   TP_BRP,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                      TP_LIT,   TP_LOT,   TP_ROT,   TP_RIT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(_TAIPO)) {
        return taipo_process_record_user(keycode, record);
    }  else {
        return true;
    }
};

void matrix_scan_user(void) {
    taipo_matrix_scan_user();
}
