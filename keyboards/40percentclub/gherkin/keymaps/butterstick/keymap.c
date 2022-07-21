#include QMK_KEYBOARD_H

#define FN1_B       LT(1, KC_B)
#define FN1_V       LT(1, KC_V)
#define FN2_K       LT(2, KC_K)
#define FN3_C       LT(3, KC_C)
#define FN4_X       LT(4, KC_X)
#define FN5_ENT     LT(5, KC_ENT)
#define FN6_Z       LT(6, KC_Z)
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

const uint16_t PROGMEM combo1[] = {LCTL_I, RSFT_O, COMBO_END};
const uint16_t PROGMEM combo2[] = {LSFT_A, LCTL_R, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo1, KC_DEL),
    COMBO(combo2, KC_ESC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



  [0] = LAYOUT_ortho_3x10(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    LSFT_A,     LCTL_R,     LALT_S,     MAC_T,      KC_D,       KC_H,       MAC_N,      RALT_E,     LCTL_I,     RSFT_O,
    FN6_Z,      FN4_X,      FN3_C,      FN1_V,      KC_SPC,     KC_BSPC,    FN1_B,      FN2_K,      KC_M,       FN5_ENT
  ),

   [1] = LAYOUT_ortho_3x10(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_J,       KC_L,       KC_U,       KC_Y,       BR_CCED,
    KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_NO,      KC_NO,      KC_NO
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
    KC_CAPS,    KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_TRNS,    KC_NO,      KC_TRNS,    KC_NO,      KC_NO
  ),

  [3] = LAYOUT_ortho_3x10(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_GRV,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_SCLN,
    KC_TAB,     KC_NO,      KC_TRNS,    KC_NO,      KC_TRNS,    KC_BSLS,    KC_COMM,    KC_DOT,     KC_SLSH,    KC_QUOT
  ),

  [4] = LAYOUT_ortho_3x10(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_LSFT,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,      KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
  ),

  [5] = LAYOUT_ortho_3x10(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_NO,      KC_NO,      KC_TRNS
  ),

  [6] = LAYOUT_ortho_3x10(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      BL_TOGG,    BL_INC,     BL_DEC,     KC_NO,      KC_NO,      QK_BOOT,
    KC_RCTL,    EXP_AS,     KC_NO,      KC_NO,      PRINT_3,    PRINT_4,    KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_TRNS,    KC_NO,      EXP_WEB,    KC_NO,      KC_NO,      KC_MPLY,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT
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

