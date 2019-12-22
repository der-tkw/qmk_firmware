#include QMK_KEYBOARD_H

/* enable underglow on startup and configure color */
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(0, 0, 255);
}

/* keymaps */
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x4(
        KC_KP_9,  KC_KP_3,  KC_KP_0,  KC_PAST,
        KC_KP_8,  KC_KP_2,  KC_KP_4,  KC_KP_6,
        KC_KP_7,  KC_KP_1,  KC_PDOT,  KC_KP_5,
        KC_DOWN,  KC_LEFT,  KC_RGHT,  KC_UP
    )
};
// clang-format on
