/*
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

enum unicode_names {
  UM_AA,      // å
  UM_AE,      // ä
  UM_OSLH,    // ö
  UM_AA_U,    // Å
  UM_AE_U,    // Ä
  UM_OSLH_U,  // Ö
};

const uint32_t PROGMEM unicode_map[] = {
    [UM_AA]      = 0x00e5,  // å
    [UM_AE]      = 0x00e4,  // ä
    [UM_OSLH]    = 0x00f6,  // ö
    [UM_AA_U]    = 0x00c5,  // Å
    [UM_AE_U]    = 0x00c4,  // Ä
    [UM_OSLH_U]  = 0x00d6,  // Ö // This doesn't seem to work on macOS ?!
};

#define AA      XP(UM_AA, UM_AA_U)
#define AE      XP(UM_AE, UM_AE_U)
#define OSLH    XP(UM_OSLH, UM_OSLH_U)

// Layer shorthand
enum layer {
  _2UARROW,
  _FN,
  _ADJUST,
};

#define FN      MO(_FN)
#define ADJ     MO(_ADJUST)
#define ENT_FN  LT(_FN, KC_ENT)
#define SPC_FN  LT(_FN, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* BASE
 .------------------------------------------------------------------------------------------------------------------------------.
 |        | 1      | 2      | 3      | 4      | 5      | ` ~    || \ |    | 6      | 7      | 8      | 9      | 0      | BACKSP |
 |--------+--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+-----------------|
 | TAB    | Q      | W      | E      | R      | T      | [ {    || ] }    | Y      | U      | I      | O      | P      | BACKSP |
 |--------+--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+-----------------+--------|
 | ESC    | A      | S      | D      | F      | G      | (      || )      | H      | J      | K      | L      | ;      | '      |
 |--------+--------+--------+--------+--------+--------+--------++--------+--------+--------+--------------------------+--------|
 | LSHIFT | Z      | X      | C      | V      | B      | - _    || = +    | N      | M      | ,      | .      | /      | ENTER  |
 |--------+--------+--------+--------+--------+-----------------++--------+--------+--------+-----------------+--------+--------|
 | ADJUST | LCTRL  | LALT   | LGUI   | Fn     |   ENTER / Fn    ||    SPACE / Fn   | Fn     | LGUI   | RSHIFT |        |        |
 '------------------------------------------------------------------------------------------------------------------------------'
 */

 [_2UARROW] = LAYOUT_ortho_2x2u(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_GRV,   KC_BSLS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_LBRC,  KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_LPRN,  KC_RPRN,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_MINS,  KC_EQL,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,  \
  ADJ,     KC_LCTL, KC_LALT, KC_LGUI, FN,         ENT_FN,              SPC_FN,      FN,      KC_LGUI, KC_RSFT, _______,  _______
 ),

 /* FUNCTION
 .------------------------------------------------------------------------------------------------------------------------------.
 |        | !      | @      | #      | $      | %      | ~      || |      | ^      | &      | *      | (      | )      |        |
 |--------+--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+-----------------|
 |        | F1     | F2     | F3     | F4     | F5     | {      || }      | F6     | F7     | F8     | F9     | F10    |        |
 |--------+--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+-----------------+--------|
 |        | F11    | F12    |        |        |        | (      || )      | LEFT   | DOWN   | UP     | RIGHT  | :      | "      |
 |--------+--------+--------+--------+--------+--------+--------++--------+--------+--------+--------------------------+--------|
 |        |        |        |        |        |        | _      || +      |        |        | <      | >      | ?      |        |
 |--------+--------+--------+--------+--------+-----------------++--------+--------+--------+-----------------+--------+--------|
 |        |        |        |        |        |                 ||                 |        | Fwd    | Vol-   | Vol+   |PlayPaus|
 '------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = LAYOUT_ortho_2x2u(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TILD, KC_PIPE, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR, KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_F11,  KC_F12,  _______, _______, _______, KC_LPRN, KC_RPRN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQT,  \
  _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, _______, _______, KC_LT,   KC_GT,   KC_QUES, _______, \
  _______, _______, _______, _______, _______,     _______,           _______,     _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
 ),

 /* ADJUST
 .------------------------------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        || Reset  |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+-----------------|
 |        |        |        |        |        |        |        ||        |        |        |        |        |        | Å      |
 |--------+--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+-----------------+--------|
 |        |        |        |        |        |        |        ||        | ´      | ~ ISO  | | ISO  |        | Ö      | Ä      |
 |--------+--------+--------+--------+--------+--------+--------++--------+--------+--------+--------------------------+--------|
 |        |LED Tog |LED Mode|LED Hue-|LED Hue+|LED Sat-|UC Mode ||        |LED Sat+|LED Bri-|LED Bri+|        |        |        |
 |--------+--------+--------+--------+--------+-----------------++--------+--------+--------+-----------------+--------+--------|
 |        |        |        |        |        |                 ||                 |        |        |        |        |        |
 '------------------------------------------------------------------------------------------------------------------------------'
 */

 [_ADJUST] = LAYOUT_ortho_2x2u(
  _______, _______, _______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, AA,      \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_NUBS, _______, OSLH,    AE,      \
  _______, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, UC_MOD,  _______, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, _______, \
  _______, _______, _______, _______, _______,     _______,           _______,     _______, _______, _______, _______, _______
 )
};
