#include QMK_KEYBOARD_H
#include "rtc.h"



void keyboard_post_init_user(void) {
    rtc_init();
}
void housekeeping_task_user(void) {
    rtc_task();
}

bool oled_task_user() {
    oled_set_cursor(0, 0);
    oled_write(rtc_read_time_str(), false);
    oled_set_cursor(0, 1);
    oled_write(rtc_read_date_str(), false);
    return false;
}
    
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_A,   KC_B,   KC_C,   KC_D,
        KC_E,   KC_F,   KC_G,   KC_H,
        KC_I,   KC_J,   KC_K,   KC_L
    )

};

/*
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { First encoder
if (clockwise) {
    tap_code(KC_PGDN);
} else {
    tap_code(KC_PGUP);
}
}
}

*/
