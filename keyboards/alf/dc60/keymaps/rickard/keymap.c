/* Copyright 2018 Rickard von Essen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "rickard.h"

#define _BASE 0
#define _CTRL 1
#define _FN 2

#define CT_SP LT(_CTRL, KC_SPACE)

enum custom_keycodes {
  AA = SAFE_RANGE,  // Å
  AE,               // Ä
  OSLH,             // Ö
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      KC_ESC,  KC_A,    KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, XXXXXXX, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,
      KC_LCTL, KC_LALT, KC_LGUI,                    CT_SP,   KC_SPACE, CT_SP,   KC_RGUI, KC_RALT,                   XXXXXXX, MO(_FN), KC_RCTL
      ),

  [_CTRL] = LAYOUT(
      KC_ESC,  KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
      _______, _______, _______,  _______, _______, _______, _______,  _______, _______, _______, _______, AA,      _______, _______,
      _______, _______, _______,  _______, _______, _______, KC_LEFT,  KC_DOWN, KC_UP,  KC_RIGHT, OSLH,    AE,      _______,
      _______, _______, _______,  _______, BL_DEC,  BL_TOGG, BL_INC,   BL_STEP, _______, _______, _______, _______, _______, _______,
      _______, _______, _______,                    _______, _______,  _______, _______, _______,                   _______, _______, _______
      ),

  [_FN] = LAYOUT(
      _______, _______, _______,  _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______,  _______, RESET,   _______, _______,  _______, _______, _______, KC_MPLY, _______, _______, _______,
      _______, RGB_MOD, RGB_HUI,  RGB_SAI, RGB_VAI, _______, KC_LEFT,  KC_DOWN, KC_UP,  KC_RIGHT, KC_MNXT, KC_VOLU, _______,
      _______, _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,  _______, _______, _______, _______, KC_VOLD, _______, _______,
      _______, _______, _______,                    RGB_TOG, _______,  _______, _______, _______,                   _______, _______, _______
      ),
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

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

void led_set_user(uint8_t usb_led) {

}
