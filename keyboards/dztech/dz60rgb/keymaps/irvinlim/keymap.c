#include QMK_KEYBOARD_H
extern bool g_suspend_state;

#define DEFAULT_LAYER 0
#define FN_LAYER 1
#define MAC_FN_LAYER 2
#define SYSTEM_LAYER 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEFAULT_LAYER] = LAYOUT(
        // R1
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        // R2
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLASH,
        // R3
        CMD_T(KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        // R4
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), KC_UP, LT(MAC_FN_LAYER, KC_GRV),
        // R5
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RALT, MO(FN_LAYER), KC_LEFT, KC_DOWN, KC_RIGHT),

    [FN_LAYER] = LAYOUT(
        // R1
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PWR,
        // R2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // R3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // R4
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, MO(SYSTEM_LAYER),
        // R5
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDOWN, KC_TRNS),

    [MAC_FN_LAYER] = LAYOUT(
        // R1
        KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_MRWD, KC_MPLY, KC_MFFD, KC_TRNS, KC_TRNS, KC__MUTE, KC__VOLDOWN, KC__VOLUP, KC_DEL,
        // R2
        KC_TRNS, RGB_TOG, KC_TRNS, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // R3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPI, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS,
        // R4
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // R5
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(SYSTEM_LAYER), KC_TRNS, KC_TRNS, KC_TRNS),

    [SYSTEM_LAYER] = LAYOUT(
        // R1
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // R2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // R3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // R4
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // R5
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

int numrow_index(int number) {
  if (number < 0 || number > 12) {
    return 0;
  }

  return 13 - number;
}

void rgb_matrix_indicators_user(void) {
  uint8_t this_led = host_keyboard_leds();

  // Display current layer in Num row (if not default).
  if (!g_suspend_state) {
    rgb_matrix_set_color(numrow_index(biton32(layer_state)), 0x20, 0x20, 0x20);
  }

  // Enable Caps Lock lighting.
  if (this_led & (1 << USB_LED_CAPS_LOCK)) {
    rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
  }
}

void matrix_init_user(void) {
  // user initialization
}

void matrix_scan_user(void) {
  // user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { return true; }
