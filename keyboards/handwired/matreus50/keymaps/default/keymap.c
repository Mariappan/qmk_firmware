// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#include <print.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY   0
#define _RAISE    1
#define _LOWER    2
#define _MOUSE    3
#define _EMPTY    4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
  MOUSE,
  MINE
};

#define __QWERT TO(_QWERTY)
#define __RAISE MO(_RAISE)
#define __LOWER TG(_LOWER)
#define __MOUSE TG(_MOUSE)

#undef _______
#define _______ XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, KC_ESC,  KC_TAB,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  __RAISE, KC_MINS, KC_QUOT, KC_ENT,  C_S_T(KC_ENT)
  ),

  [_RAISE] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,    KC_9,    KC_ASTR, RESET,
    KC_DEL,  KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_PGDN, KC_4,    KC_5,    KC_6,    KC_PLUS, MINE,
    _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_F12,
    _______, __LOWER, __MOUSE, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_ENT
  ),

  [_LOWER] = LAYOUT(
    KC_TILD, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    KC_DEL,  KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_PIPE,
    _______, KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
    _______, KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  __QWERT, KC_PSCR, KC_SLCK, KC_PAUS, KC_MPLY
  ),

  [_MOUSE] = LAYOUT(
    _______, _______, KC_BTN1, KC_WH_U, KC_BTN2, _______,                   _______, _______, KC_MS_U, _______, _______, _______,
    _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, __QWERT, _______, _______, _______, _______
  ),

  [_EMPTY] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

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
        case MINE:
          if (record->event.pressed) {
            SEND_STRING("#$Aricent12"SS_TAP(X_ENTER));
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
    return OLED_ROTATION_90;
}

void oled_task_user(void) {
    render_logo();

    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Def\n"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("FN\n"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWR\n"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("MOUSE\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UND"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("\n"), false);

    uint8_t modifiers = get_mods();

    oled_write_ln_P((modifiers & MOD_MASK_SHIFT) ? PSTR("SHIFT") : PSTR("\n"), false);
    oled_write_ln_P((modifiers & MOD_MASK_CTRL) ? PSTR("CTRL") : PSTR("\n"), false);
    oled_write_ln_P((modifiers & MOD_MASK_ALT) ? PSTR("ALT") : PSTR("\n"), false);
    oled_write_ln_P((modifiers & MOD_MASK_GUI) ? PSTR("SUPER") : PSTR("\n"), false);

    oled_write_P(PSTR("\n"), false);

}
#endif

