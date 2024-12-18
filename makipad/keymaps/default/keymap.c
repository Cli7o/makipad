#include QMK_KEYBOARD_H
#include "rtc.h"

int              seleccion         = 0;
static int       capa_seleccionada = 0; // numpad, asdf, blender
static const int capa_minima       = 0;
static const int capa_maxima       = 3;
char             capa_str[16];


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
    oled_set_cursor(0, 2);
    snprintf(capa_str, sizeof(capa_str), "%d", capa_seleccionada);
    oled_write(capa_str, false);
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
        KC_I,   KC_J,   KC_K,   LT(1, KC_L)
    ),
    [1] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_TRNS
    )


};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (get_highest_layer(layer_state) == 1) {

        if (keycode == KC_F23 && record->event.pressed) {
            capa_seleccionada++;
        }
        if (keycode == KC_F24 && record->event.pressed) {
            capa_seleccionada--;
        }

        if (capa_seleccionada <= capa_minima) {
            capa_seleccionada = capa_minima;
        } else if (capa_seleccionada >= capa_maxima) {
            capa_seleccionada = capa_maxima;
        }
    }
    return true; // Permitir que otras acciones de la tecla se procesen
}


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

    [0] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_F23, KC_F24)},

};


