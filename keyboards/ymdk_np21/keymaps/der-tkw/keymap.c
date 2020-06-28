#include QMK_KEYBOARD_H

/* keymaps */
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
    * ,-----------------------------------------.
    * |   0  |   1  |   4  |   7  | NUM  | F1   |
    * |------+------+------+------+------+------|
    * |   .  |   2  |   5  |   8  |   /  | F2   |---,
    * |------+------+------+------+------+------|USB|
    * |  DOT |   3  |   6  |   9  |   *  | F3   |---'
    * |------+------+------+------+------+------|
    * | Enter| Enter|   +  |   +  |   -  | F4   |
    * `-----------------------------------------'
    */
    [0] = LAYOUT(
      KC_KP_0,     KC_KP_1,     KC_KP_4,    KC_KP_7,    KC_NUMLOCK,     KC_F1,
      KC_DOT,      KC_KP_2,     KC_KP_5,    KC_KP_8,    KC_KP_SLASH,    KC_F2,
      KC_KP_DOT,   KC_KP_3,     KC_KP_6,    KC_KP_9,    KC_KP_ASTERISK, KC_F3,
      KC_KP_ENTER, KC_KP_ENTER, KC_KP_PLUS, KC_KP_PLUS, KC_KP_MINUS,    KC_F4
    )
};
// clang-format on
