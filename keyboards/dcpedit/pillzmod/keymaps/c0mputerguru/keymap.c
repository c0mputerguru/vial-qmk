#include QMK_KEYBOARD_H


enum layers {
    CUST,
    ORIG,
    NUM,
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[CUST] = LAYOUT(
      KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,  TG(NUM), MO(NUM),
      KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
      KC_ESC,   HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,                                        KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,KC_QUOT,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                        KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                                   KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                                        KC_LCTL,  KC_LALT,                           KC_RGUI,  KC_RCTL,
                                                                  KC_HOME,                           KC_PGUP,
                                              KC_BSPC,  KC_DEL,   KC_END,                            KC_PGDN,  KC_ENTER, KC_SPC
    ),
	[ORIG] = LAYOUT(
      KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,  TG(NUM), MO(NUM),
      KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
      KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                        KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                        KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                                   KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                                        KC_LCTL,  KC_LALT,                           KC_RGUI,  KC_RCTL,
                                                                  KC_HOME,                           KC_PGUP,
                                              KC_BSPC,  KC_DEL,   KC_END,                            KC_PGDN,  KC_ENTER, KC_SPC
    ),
	[NUM] = LAYOUT(

      QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                     _______,  KC_NUM,   KC_PEQL,  KC_PSLS,  KC_PAST,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                     _______,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                     _______,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                     _______,  KC_P1,    KC_P2,    KC_P3,    KC_PENT,  _______,
                _______,  _______,  _______,  _______,                                                         _______,  _______,  KC_PDOT,  KC_PENT,
                                                        _______,  _______,                           _______,  _______,
                                                                  _______,                           _______,
                                              _______,  _______,  _______,                           _______,  _______,  KC_P0

    ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	[0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
	[1] = {ENCODER_CCW_CW(_______, _______)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

layer_state_t default_layer_state_set_user(layer_state_t state) {
    if(layer_state_cmp(state, ORIG)) {
        autoshift_disable();
    } else {
        autoshift_enable();
    }
    return state;
}
