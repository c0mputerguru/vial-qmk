#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/select_word.h"


enum layers {
    CUST,
    ORIG,
    NUM,
    NAV,
};

enum c0mputerguru_keycodes {
    LLOCK = SAFE_RANGE,
    SELWORD,
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

// Key to move between layers
#define ESC_NAV LT(NAV, KC_ESC)

// Undo, cut, copy, paste keys on Nav layer
#define UNDO C(KC_Z)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)

// Number of LEDs on the keyboard.
#define NUM_LEDS  4
// Period for LED_BLINK_FAST blinking. Smaller value implies faster.
#define LED_BLINK_FAST_PERIOD_MS  300

// Possible LED states.
enum { LED_OFF = 0, LED_ON = 1, LED_BLINK_SLOW = 2, LED_BLINK_FAST = 3 };
static uint8_t led_blink_state[NUM_LEDS] = {0};

#define LED_CAPS_LOCK_PIN B9
#define LED_NUM_LOCK_PIN A0
#define LED_SCROLL_LOCK_PIN A1
#define LED_NUM_LAYER_PIN A2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[CUST] = LAYOUT(
      KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,  TG(NUM), MO(NUM),
      KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
      ESC_NAV,  HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,                                        KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,KC_QUOT,
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

      _______,  _______,  _______,  _______,  _______,  _______,  DF(CUST), DF(ORIG), _______,       QK_BOOT,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                     _______,  KC_NUM,   KC_PEQL,  KC_PSLS,  KC_PAST,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                     _______,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                     _______,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,                                     _______,  KC_P1,    KC_P2,    KC_P3,    KC_PENT,  _______,
                _______,  _______,  _______,  _______,                                                         _______,  _______,  KC_PDOT,  KC_PENT,
                                                        _______,  _______,                           LLOCK,    _______,
                                                                  _______,                           _______,
                                              _______,  _______,  _______,                           _______,  _______,  KC_P0

    ),
	[NAV] = LAYOUT(

      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,
      _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
      _______,  SELWORD,  _______,  KC_WBAK,  KC_WFWD,  _______,                                     KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_ESC,   KC_INS,
      _______,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  _______,                                     KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_BSPC,  KC_DEL,
      _______,  UNDO,     CUT,      COPY,     PASTE,    _______,                                     _______,  _______,  _______,  _______,  _______,  _______,
                _______,  _______,  _______,  _______,                                                         _______,  _______,  _______,  _______,
                                                        _______,  _______,                           LLOCK,    _______,
                                                                  _______,                           _______,
                                              _______,  _______,  _______,                           _______,  _______,  _______

    ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	[0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
	[1] = {ENCODER_CCW_CW(_______, _______)}
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

static uint8_t get_layer_indicator(layer_state_t changed_state, bool is_default_change) {
    layer_state_t overall_layer = changed_state;
    if (is_default_change) {
        overall_layer |= layer_state;
    } else {
        overall_layer |= default_layer_state;
    }

    switch (get_highest_layer(overall_layer)) {
        case CUST:
            return LED_OFF;
        case NUM:
            return LED_BLINK_SLOW;
        case NAV:
            return LED_BLINK_FAST;
        default:
            return LED_ON;
    }
}

void matrix_scan_user(void) {
    layer_lock_task();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_layer_lock(keycode, record, LLOCK)) {
        return false;
    }

    if (!process_select_word(keycode, record, SELWORD)) {
        return false;
    }
    return true;
}

// Need to override so that mod tap keys get auto shifted as well.
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    if (IS_RETRO(keycode))
        return true;
    return false;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    if(layer_state_cmp(state, ORIG)) {
        autoshift_disable();
    } else {
        autoshift_enable();
    }
    led_blink_state[3] = get_layer_indicator(state, true);
    return state;
}

void keyboard_post_init_user(void) {
    uint32_t led_blink_callback(uint32_t trigger_time, void *cb_arg) {
        static const uint8_t pattern[4] = {0x00, 0xff, 0x0f, 0xaa};
        static uint8_t       phase      = 0;
        phase                           = (phase + 1) % 8;

        uint8_t bit = 1 << phase;
        // Adjust according to keyboard. See notes below.
        writePin(LED_CAPS_LOCK_PIN, (pattern[led_blink_state[0]] & bit) == 0);
        writePin(LED_NUM_LOCK_PIN, (pattern[led_blink_state[1]] & bit) == 0);
        writePin(LED_SCROLL_LOCK_PIN, (pattern[led_blink_state[2]] & bit) == 0);
        writePin(LED_NUM_LAYER_PIN, (pattern[led_blink_state[3]] & bit) == 0);

        return LED_BLINK_FAST_PERIOD_MS / 2;
    }

    defer_exec(1, led_blink_callback, NULL);
}

void matrix_init_user(void) {
    setPinOutput(LED_CAPS_LOCK_PIN);
    setPinOutput(LED_NUM_LOCK_PIN);
    setPinOutput(LED_SCROLL_LOCK_PIN);
    setPinOutput(LED_NUM_LAYER_PIN);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    led_blink_state[3] = get_layer_indicator(state, false);
    return state;
}

static bool is_caps_lock_on = false;

static void update_caps_indicator(void) {
    if (is_caps_lock_on) {
        led_blink_state[0] = LED_ON;
    } else if (is_caps_word_on()) {
        led_blink_state[0] = LED_BLINK_FAST;
    } else {
        led_blink_state[0] = LED_OFF;
    }
}

bool led_update_user(led_t led_state) {
    is_caps_lock_on = led_state.caps_lock;
    update_caps_indicator();

    if (led_state.num_lock) {
        led_blink_state[1] = LED_ON;
    } else {
        led_blink_state[1] = LED_OFF;
    }

    // Could use scroll lock led for something else as it's not really ever used.
    if (led_state.scroll_lock) {
        led_blink_state[2] = LED_ON;
    } else {
        led_blink_state[2] = LED_OFF;
    }

    return true;
}

void caps_word_set_user(bool active) {
    update_caps_indicator();
}
