/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY   0
#define _RAISE    1
#define _LOWER    2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER
};

#define MO_R MO(_RAISE)
#define MO_L MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOTE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
    KC_LCTL, KC_LGUI, KC_LALT, KC_GRV,  MO_R,    KC_BSPC, KC_DEL,  KC_ENT,  KC_SPC,  MO_L,    KC_EQL,  KC_MINS, KC_BSLS, KC_ENT
  ),

  [_RAISE] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  QK_RESET,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_LOWER] = LAYOUT(
    _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_MPLY, KC_MSTP, KC_UP,   KC_F11,  KC_F12,  KC_WAKE,
    _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_BRIU, KC_SLEP,
    _______, KC_MRWD, KC_VOLD, KC_VOLU, KC_MUTE, KC_MFFD,                   KC_MPRV, KC_PSCR, KC_BRMD, KC_BRMU, KC_BRID, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
          } else {
            layer_off(_RAISE);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
          } else {
            layer_off(_LOWER);
          }
          return false;
          break;
      }
    return true;
};

void matrix_init_user(void) {
}

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x80, 0x80,
        0x81, 0x82, 0x83, 0x84, 0x80,
        0x80, 0x80,
        0x80, 0x80, 0x80,
        0xA1, 0xA2, 0xA3, 0xA4, 0xA0,
        0x80, 0x80,
        0x80, 0x80, 0x80,
        0xC1, 0xC2, 0xC3, 0xC4, 0xC0,
        0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 'Q',  'M',  'K',  '\n', '\n', '\n', 0x00
    };

    oled_write_ln_P(qmk_logo, false);
}


oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return OLED_ROTATION_0;
}

void oled_task_user(void) {
    render_logo();

    oled_write_ln_P(PSTR("Layer:"), false);
    oled_write_ln_P(PSTR("\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Default\n"), false);
            oled_write_ln_P(PSTR("\n"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Func\n"), false);
            oled_write_ln_P(PSTR("\n"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower\n"), false);
            oled_write_ln_P(PSTR("\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UND"), false);
            oled_write_ln_P(PSTR("\n"), false);
    }

    uint8_t modifiers = get_mods();

    oled_write_ln_P((modifiers & MOD_MASK_SHIFT) ? PSTR("SHIFT\n") : PSTR("\n"), false);
    oled_write_ln_P((modifiers & MOD_MASK_CTRL) ? PSTR("CTRL\n") : PSTR("\n"), false);
    oled_write_ln_P((modifiers & MOD_MASK_ALT) ? PSTR("ALT\n") : PSTR("\n"), false);
    oled_write_ln_P((modifiers & MOD_MASK_GUI) ? PSTR("SUPER\n") : PSTR("\n"), false);

    oled_write_ln_P(PSTR("\n"), false);

}
#endif

