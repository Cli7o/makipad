//TODO: SETEAR QUE CUANDO SE SUELTE EL BOTÓN SE APLIQUE LA CONFIGURACIÓN DE LA CAPA EN LA QUE ESTÁS

#include QMK_KEYBOARD_H
#include "rtc.h"

static int       capa_seleccionada = 0; // numpad, asdf, blender
static const int capa_minima       = 0;
static const int capa_maxima       = 3;
char             capa_str[16];

char             tiempo[16];
static int       seleccion_tiempo = 0;

void keyboard_post_init_user(void) {
    rtc_init();
}
void housekeeping_task_user(void) {
    rtc_task();
}




bool oled_task_user() {

    switch (biton32(layer_state)) {
        

        case 10:
        
            switch (capa_seleccionada) {
                
                case 0:
                    oled_write_ln("NUMPAD", true);
                    oled_write_ln("ASDF", false);
                    oled_write_ln("BLENDER", false);
                    oled_write_ln("TIEMPO", false);
                    oled_write_ln("", false);
                break;

                case 1:
                    oled_write_ln("NUMPAD", false);
                    oled_write_ln("ASDF", true);
                    oled_write_ln("BLENDER", false);
                    oled_write_ln("TIEMPO", false);
                    oled_write_ln("", false);
                break;

                case 2:
                    oled_write_ln("NUMPAD", false);
                    oled_write_ln("ASDF", false);
                    oled_write_ln("BLENDER", true);
                    oled_write_ln("TIEMPO", false);
                    oled_write_ln("", false);
                break;
                case 3:
                    oled_write_ln("NUMPAD", false);
                    oled_write_ln("ASDF", false);
                    oled_write_ln("BLENDER", false);
                    oled_write_ln("TIEMPO", true);
                    oled_write_ln("", false);
                break;
        }

        break;

        case 0:
        oled_write_ln("NUMPAD", false);
        oled_write("Capa: ", false);
        snprintf(capa_str, sizeof(capa_str), "%d", capa_seleccionada);
        oled_write(capa_str, false);

        break;

        case 1:
            oled_write_ln("ASDF", false);

            oled_write("Capa: ", false);
            snprintf(capa_str, sizeof(capa_str), "%d", capa_seleccionada);
            oled_write(capa_str, false);
        break;

        case 2:
            oled_write_ln("BLENDER", false);

            oled_write("Capa: ", false);
            snprintf(capa_str, sizeof(capa_str), "%d", capa_seleccionada);
            oled_write(capa_str, false);
        break;

        case 3:
        
            oled_write_ln("TIEMPO", false);
            oled_write("Capa: ", false);
            snprintf(capa_str, sizeof(capa_str), "%d", capa_seleccionada);
            oled_write_ln(capa_str, false);

            oled_write("Hora: ", false);
            oled_write_ln(rtc_read_time_str(), false);

            oled_write("Fecha: ", false);
            oled_write_ln(rtc_read_date_str(), false);

            if (seleccion_tiempo == 0) {
                oled_write("Alarma: ", true);
                oled_write_ln("05:00:00", false);

                oled_write("Tempo: ", false);
                oled_write_ln("00:15:00", false);
            }
            else if (seleccion_tiempo == 1) {
                oled_write("Alarma: ", false);
                oled_write_ln("05:00:00", false);

                oled_write("Tempo: ", true);
                oled_write_ln("00:15:00", false);
            }
            snprintf(tiempo, sizeof(tiempo), "%d", seleccion_tiempo);
            oled_write_ln(tiempo, false);


            
        break;
    }



    return false;
}











const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    
    [10] = LAYOUT(//menu
        KC_NO,    KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,
        KC_F13,   KC_NO,   KC_NO,   KC_F13
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ 0 │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ + │    NUMPAD
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * └───┴───┴───┴───┘
     */

    [0] = LAYOUT(//numpad
        KC_P7,   KC_P8,   KC_P9,   KC_P0,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,   LT(10, KC_PMNS)
    ),
    
    /*
     * ┌───┬───┬───┬───┐
     * │ Q │ W │ E │ R │
     * ├───┼───┼───┼───┤
     * │ A │ S │ D │ F │    ASDF
     * ├───┼───┼───┼───┤
     * │ Z │ X │ C │ V │
     * └───┴───┴───┴───┘
     */

    [1] = LAYOUT(//asdf
        KC_Q,   KC_W,   KC_E,   KC_R,
        KC_A,   KC_S,   KC_D,   KC_F,
        KC_Z,   KC_X,   KC_C,   LT(10, KC_V)
    ),

    /*
     * ┌─────┬───┬───┬───┐
       │ TAB │ Z │ A │ F │
     * ├─────┼───┼───┼───┤
     * │  X  │ Y │ Z │ E │  BLENDER
     * ├─────┼───┼───┼───┤
     * │  G  │ X │ R │ L │
     * └─────┴───┴───┴───┘
     */

    [2] = LAYOUT(//blender
        KC_TAB,  KC_Z,   KC_A,   KC_F,
        KC_X,    KC_Y,   KC_Z,   KC_E,
        KC_G,    KC_S,   KC_R,   LT(10, KC_L)
    ),
    [3] = LAYOUT(//tiempo
        KC_7,    KC_8,   KC_9,   KC_F24,
        KC_4,    KC_5,   KC_6,   KC_NO,
        KC_1,    KC_2,   KC_3,   LT(10, KC_NO)
    )


};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (get_highest_layer(layer_state) == 10) {
        if (keycode == KC_F23 && record->event.pressed) {            
            capa_seleccionada++;          
        }
        if (keycode == KC_F24 && record->event.pressed) {
            capa_seleccionada--;
        }
        
        if (keycode == KC_F13 && !record->event.pressed) {
            //layer_invert(0);
            layer_move(capa_seleccionada);
        }

        if (capa_seleccionada < capa_minima) {
            capa_seleccionada = capa_maxima;
        } else if (capa_seleccionada > capa_maxima) {
            capa_seleccionada = capa_minima;
        }
        oled_clear();
    }
    
    if (get_highest_layer(layer_state) == 3) {
        if (keycode == KC_F13 && record->event.pressed) {
            seleccion_tiempo--;
        }

        else if (keycode == KC_F14 && record->event.pressed) {
            seleccion_tiempo++;
        }

        if (seleccion_tiempo < 0) {
            seleccion_tiempo = 1;
        }
        else if (seleccion_tiempo > 1) {
            seleccion_tiempo = 0;
        }

        if (seleccion_tiempo == 1) {
        }

    }

    return true; // Permitir que otras acciones de la tecla se procesen
}


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

    [10] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_F23, KC_F24)},       // menu
    [0] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},//numpad
    [1] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_F23, KC_F24)},//asdf
    [2] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_F23, KC_F24)},//blender
    [3] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_F13, KC_F14)}// TIEMPO

};


