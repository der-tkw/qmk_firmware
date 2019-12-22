#include QMK_KEYBOARD_H

/* enable underglow on startup, configure color and disable again */
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(95, 255, 100);
    wait_ms(2000);
    rgblight_disable_noeeprom();
}

/* enable underglow when caps lock is active */
bool led_update_user(led_t led_state) {
    static uint8_t caps_state = 0;
    if (caps_state != led_state.caps_lock) {
        led_state.caps_lock ? rgblight_enable_noeeprom() : rgblight_disable_noeeprom();
        caps_state = led_state.caps_lock;
    }
    return true;
}

/* keymaps */
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,   KC_F12,   KC_PSCR,  KC_PAUS,  KC_DEL,
        KC_GRV,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
        KC_CAPS,  KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,                      KC_ENT,   KC_PGDN,
        KC_LSFT,  KC_NUBS,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
        KC_LCTL,  KC_LGUI,   KC_LALT,                         KC_SPC,    KC_SPC,    KC_SPC,                          KC_RALT,   MO(1),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
    [1] = LAYOUT(
        RESET,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  _______,
        _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  RGB_TOG,  _______,
        _______,  MEH(KC_Q), MEH(KC_W), MEH(KC_E), MEH(KC_R), MEH(KC_T), MEH(KC_Y), MEH(KC_U), MEH(KC_I), MEH(KC_O), MEH(KC_P), _______,  _______,  _______,            _______,
        _______,  MEH(KC_A), MEH(KC_S), MEH(KC_D), MEH(KC_F), MEH(KC_G), MEH(KC_H), MEH(KC_J), MEH(KC_K), MEH(KC_L), _______,   _______,                      _______,  _______,
        _______,  _______,   MEH(KC_Z), MEH(KC_X), MEH(KC_C), MEH(KC_V), MEH(KC_B), MEH(KC_N), MEH(KC_M), _______,   _______,   _______,  _______,            KC_MPLY,  _______,
        _______,  _______,  _______,                          _______,   _______,   _______,                         _______,   _______,  _______,  KC_MPRV,  KC_MSTP,  KC_MNXT
      ),
};
// clang-format on
