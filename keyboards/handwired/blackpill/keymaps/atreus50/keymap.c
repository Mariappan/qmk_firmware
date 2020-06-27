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
#define _MOUSE    3
#define _EMPTY    4
#define _MOVEMENT 5
#define _COLEMAK  6
#define _DVORAK   7
#define _ADJUST   8

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
  MOUSE,
  MOVEMENT,
  COLEMAK,
  DVORAK,
  PASSWORD
};

// Fillers to make layering more clear
#define X0 MT(MOD_LCTL, KC_ESC)  // Hold for Left Ctrl, Tap for ESC

#define __QWERT TO(_QWERTY)
#define __LOWER TG(_LOWER)
#define __MOUSE TG(_MOUSE)

#undef _______
#define _______ XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_INS,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_DEL,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,
    KC_LCTL, KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  KC_LCTL, KC_LALT, KC_SPC,MO(_RAISE), KC_MINS, KC_QUOT, KC_ENT, KC_DOWN
  ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RAISE] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                    KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR , RESET,
    KC_DEL,  KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                     KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS , KC_F8,
    _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                    KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS , KC_F12,
    _______, __LOWER, __MOUSE,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL  , KC_ENT
  ),

  [_MOUSE] = LAYOUT(
    _______, _______, KC_BTN1, KC_WH_U, KC_BTN2, _______,                   _______, _______, KC_MS_U, _______, _______, _______,
    _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, __QWERT, _______, _______, _______, _______
  ),

  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LOWER] = LAYOUT(
    KC_TILD, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  , KC_DEL,
    KC_DEL,  KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  , KC_PIPE,
    _______, KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  , _______,
    _______, KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  __QWERT, KC_PSCR, KC_SLCK, KC_PAUS , KC_MPLY
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
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
        case MOUSE:
          if (record->event.pressed) {
            layer_on(_MOUSE);
          } else {
            layer_off(_MOUSE);
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
        0x81, 0x82, 0x83, 0x84, 0x80,
        0xA1, 0xA2, 0xA3, 0xA4, 0xA0,
        0xC1, 0xC2, 0xC3, 0xC4, 0xC0,
        0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 'Q',  'M',  'K',  '\n', '\n', '\n', 0x00
    };

    oled_write_P(qmk_logo, false);
}


oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return OLED_ROTATION_0;
}

void oled_task_user(void) {
    render_logo();

    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Def\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("COLE\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case _DVORAK:
            oled_write_P(PSTR("DVOR\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("FN\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWR\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOUSE\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("UND"), false);
            oled_write_P(PSTR("\n"), false);
    }

    // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    // oled_write_ln_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    // oled_write_ln_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    uint8_t modifiers = get_mods();

    oled_write_ln_P((modifiers & MOD_MASK_SHIFT) ? PSTR("SHIFT") : PSTR("\n"), false);
    oled_write_ln_P((modifiers & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR("\n"), false);
    oled_write_ln_P((modifiers & MOD_MASK_ALT) ? PSTR("ALT  ") : PSTR("\n"), false);
    oled_write_ln_P((modifiers & MOD_MASK_GUI) ? PSTR("SUPER") : PSTR("\n"), false);

    oled_write_P(PSTR("\n"), false);

}
#endif

