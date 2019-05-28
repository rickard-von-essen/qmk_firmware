#include QMK_KEYBOARD_H
#include "rickard.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _L1 3
#define _L2 4
#define _L3 5
#define L2_ESC LT(_L1, KC_ESC)

enum custom_keycodes {
  AA = SAFE_RANGE,  // Å
  AE,               // Ä
  OSLH,             // Ö
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    L2_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MO(_L1),
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_L2),
    KC_LCTL, MO(_L2), KC_LGUI,                   KC_ENT,  KC_SPC,                    KC_RALT, KC_ESC,  MO(_L3)
  ),
  [_L1] = LAYOUT( /* LAYER 1 */
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, KC_ESC,  _______, KC_PSCR, KC_LBRC, KC_RBRC, _______, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_RSFT,
    _______, KC_LGUI, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_L2] = LAYOUT( /* LAYER 2 */
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_ESC,  KC_PIPE, KC_DQUO, KC_UNDS, KC_PLUS, _______, _______, KC_4,    KC_5,    KC_6,    KC_VOLU, KC_ENT,
    _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_0,    KC_1,    KC_2,    KC_3,    KC_VOLD, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_L3] = LAYOUT( /* LAYER 3 */
    _______, AA,      _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
    KC_ESC,  AE,      OSLH,    _______, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, KC_LSFT, KC_B,                      KC_SPC,  KC_C,                      _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AA: // Å
      if (record->event.pressed)
        SS_IF_SHIFT(SS_LALT("00C5"), SS_LALT("00E5"));
      return false;
    case AE: // Ä
      if (record->event.pressed)
        SS_IF_SHIFT(SS_LALT("00C4"), SS_LALT("00E4"));
      return false;
    case OSLH: // Ö
      if (record->event.pressed)
        SS_IF_SHIFT(SS_LALT("00D6"), SS_LALT("00F6"));
      return false;
  }
  return true;
}
