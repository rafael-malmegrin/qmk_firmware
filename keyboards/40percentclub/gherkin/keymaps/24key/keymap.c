#include QMK_KEYBOARD_H

#define FN1_B       LT(1, KC_B)
#define FN2_V       LT(2, KC_V)
#define FN3_C       LT(3, KC_C)
#define FN3_K       LT(3, KC_K)
#define FN4_Y       LT(4, KC_Y)
#define FN5_Z       LT(5, KC_Z)
#define LSFT_A      LSFT_T(KC_A)
#define RSFT_O      RSFT_T(KC_O)
#define LCTL_R      LCTL_T(KC_R)
#define LCTL_I      LCTL_T(KC_I)
#define LALT_S      LALT_T(KC_S)
#define RALT_E      RALT_T(KC_E)
#define MAC_T       LGUI_T(KC_T)
#define MAC_N       RGUI_T(KC_N)
#define BR_CCED     RALT(KC_C)
#define PRINT_3     LGUI(LSFT(LCTL(KC_3)))
#define PRINT_4     LGUI(LSFT(LCTL(KC_4)))
#define EXP_AS      LGUI(LSFT(LALT(KC_W)))
#define EXP_WEB     LGUI(LSFT(LALT(KC_S)))

const uint16_t PROGMEM combo1[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo3[] = {FN2_V,FN1_B, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_M, FN4_Y, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo1, KC_ESC),
    COMBO(combo2, KC_BSPC),
    COMBO(combo3, KC_SPC),
    COMBO(combo4, KC_ENT),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



  [0] = LAYOUT_ortho_3x10(
    KC_Q,       KC_W,       KC_F,       KC_P,       KC_NO,      KC_NO,      KC_G,       KC_J,       KC_L,       KC_U,
    LSFT_A,     LCTL_R,     LALT_S,     MAC_T,      KC_NO,      KC_NO,      MAC_N,      RALT_E,     LCTL_I,     RSFT_O,
    FN5_Z,      KC_X,       FN3_C,      FN2_V,      KC_NO,      KC_NO,      FN1_B,     FN3_K,       KC_M,       FN4_Y
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_1,       KC_2,       KC_3,       KC_4,       KC_NO,      KC_NO,      KC_7,       KC_8,       KC_9,       KC_0,
    KC_LSFT,    KC_LALT,    KC_LGUI,    KC_5,       KC_NO,      KC_NO,      KC_6,       KC_NO,      KC_NO,      KC_NO,
    KC_CAPS,    KC_NO,      KC_NO,      KC_DEL,     KC_NO,      KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_GRV,     KC_NO,      KC_NO,      KC_MINS,    KC_NO,      KC_NO,      KC_EQL,     KC_LBRC,    KC_RBRC,    KC_SCLN,
    KC_LSFT,    KC_LALT,    KC_LGUI,    KC_BSLS,    KC_NO,      KC_NO,      KC_COMM,    KC_DOT,     KC_SLSH,    KC_QUOT,
    KC_TAB,     KC_NO,      KC_NO,      KC_TRNS,    KC_SPC,     KC_NO,      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT
  ),

  [3] = LAYOUT_ortho_3x10(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_LSFT,    KC_LALT,    KC_LGUI,    KC_D,       KC_NO,      KC_NO,      KC_H,       KC_RGUI,    KC_RALT,    KC_RSFT,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
  ),

  [4] = LAYOUT_ortho_3x10(
    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS
  ),

  [5] = LAYOUT_ortho_3x10(
    KC_RCTL,    EXP_AS,     KC_NO,      BL_TOGG,    KC_NO,      KC_NO,      BL_INC,     BL_DEC,     KC_NO,      QK_BOOT,
    KC_NO,      KC_NO,      EXP_WEB,    PRINT_3,    KC_NO,      KC_NO,      PRINT_4,    KC_NO,      KC_NO,      KC_MPLY,
    KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT
  ),

};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}

#include "features/caps_word.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }
  // Your macros ...

  return true;
}


