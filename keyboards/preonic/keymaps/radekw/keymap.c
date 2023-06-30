#include QMK_KEYBOARD_H
#include "muse.h"
#include <stdio.h>
#include "g/keymap_combo.h"

#define L_NAV   LT(_NAV, KC_ESC)
#define L_FN    LT(_FN, KC_TAB)
#define L_NUM   LT(_NUM, KC_BSPC)
#define L_SYM   LT(_SYM, KC_DEL)

#define A_C_D   LCA(KC_DEL)
#define A_C_TAB LCA(KC_TAB)
#define C_Z     LCTL_T(KC_Z)
#define C_SLSH  RCTL_T(KC_SLSH)

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _NUM,
  _NAV,
  _SYM,
  _FN
};

enum preonic_keycodes {
  KC_QWER = SAFE_RANGE,
  KC_COLE,
  BACKLIT,
  VIM_WA,
  VIM_QA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,  KC_2,    KC_3, KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,  KC_W,    KC_E, KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_BSPC, KC_A,  KC_S,    KC_D, KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, C_Z,   KC_X,    KC_C, KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  C_SLSH,  SC_SENT,
  KC_LCTL, KC_NO, KC_LALT, L_FN, L_NAV, KC_ENT, KC_SPC, L_NUM, L_SYM,   KC_LGUI, KC_NO,   KC_RCTL
),
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,  KC_2,    KC_3, KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,  KC_W,    KC_F, KC_P,  KC_B,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  KC_BSPC, KC_A,  KC_R,    KC_S, KC_T,  KC_G,   KC_M,   KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, C_Z,   KC_X,    KC_C, KC_D,  KC_V,   KC_K,   KC_H,  KC_COMM, KC_DOT,  C_SLSH,  SC_SENT,
  KC_LCTL, KC_NO, KC_LALT, L_FN, L_NAV, KC_ENT, KC_SPC, L_NUM, L_SYM,   KC_LGUI, KC_NO,   KC_RCTL
),
[_NUM] = LAYOUT_preonic_grid(
  KC_ESC,  KC_NUM,  KC_NO, KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_NO,   KC_PSLS, KC_P7, KC_P8,  KC_P9,  KC_PMNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_BSPC, KC_PAST, KC_P4, KC_P5,  KC_P6,  KC_PPLS, KC_NO,   KC_RSFT, KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_DEL,  KC_P0,   KC_P1, KC_P2,  KC_P3,  KC_EQL,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_NO, KC_DOT, KC_DOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
),
[_NAV] = LAYOUT_preonic_grid(
  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY,
  A_C_TAB, KC_NO,   KC_UP,   KC_TAB,  KC_LALT, KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_PSCR,
  KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_LSFT, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   A_C_D,
  U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   KC_NO,   U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO
),
[_SYM] = LAYOUT_preonic_grid(
  KC_LT,   KC_GT,   KC_PMNS, KC_UNDS, KC_PLUS, KC_EQL,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_LPRN, KC_RPRN, KC_AMPR, KC_ASTR, KC_PIPE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_LBRC, KC_RBRC, KC_DLR,  KC_PERC, KC_CIRC, KC_NO,   KC_NO,   KC_RSFT, KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_LCBR, KC_RCBR, KC_EXLM, KC_AT,   KC_HASH, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_DOT,  KC_DOT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
),
[_FN] = LAYOUT_preonic_grid(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   CG_TOGG, KC_QWER, KC_COLE, KC_NO, DB_TOGG, QK_BOOT,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F7,   KC_F8,   KC_F9, KC_F12,  KC_PSCR,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F4,   KC_F5,   KC_F6, KC_F11,  A_C_D,
  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY, KC_NO,   KC_F1,   KC_F2,   KC_F3, KC_F10,  KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,   KC_NO
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_QWER:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case KC_COLE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
        backlight_step();
        #endif
        #ifdef RGBLIGHT_ENABLE
        rgblight_step();
        #endif
        #ifdef __AVR__
        writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef __AVR__
        writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
};

