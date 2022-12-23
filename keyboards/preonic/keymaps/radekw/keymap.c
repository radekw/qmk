/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum {
    TD_ESC,
};

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid(
  TD(TD_ESC), KC_1,        KC_2,    KC_3,  KC_4,       KC_5,   KC_6,   KC_7,       KC_8,    KC_9,    KC_0,           KC_MINS,
  KC_TAB,     KC_Q,        KC_W,    KC_E,  KC_R,       KC_T,   KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,           KC_BSLS,
  KC_BSPC,    KC_A,        KC_S,    KC_D,  LT(1,KC_F), KC_G,   KC_H,   LT(2,KC_J), KC_K,    KC_L,    KC_SCLN,        KC_QUOT,
  KC_LSFT,    CTL_T(KC_Z), KC_X,    KC_C,  LT(4,KC_V), KC_B,   KC_N,   KC_M,       KC_COMM, KC_DOT,  CTL_T(KC_SLSH), SC_SENT,
  KC_LCTL,    KC_NO,       KC_LALT, LOWER, KC_NO,      KC_ENT, KC_SPC, TO(_LOWER), RAISE,   KC_LGUI, KC_NO,          KC_NO
),

[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  KC_NO,   KC_NO,      KC_NO,  KC_LPRN,  KC_RPRN,  KC_BSPC,
  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  KC_PSLS, KC_P7,      KC_P8,  KC_P9,    KC_PMNS,  KC_NO,
  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  KC_PAST, KC_P4,      KC_P5,  KC_P6,    KC_PPLS,  KC_NO,
  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  KC_P0,   KC_P1,      KC_P2,  KC_P3,    KC_EQL,   KC_NO,
  KC_NO,   KC_NO,  KC_NO,  LOWER,  TO(_QWERTY), KC_ENT, KC_SPC,  TO(_RAISE), RAISE,  KC_PDOT,  KC_NO,    KC_NO
),

[_RAISE] = LAYOUT_preonic_grid (
  KC_GRV,  KC_NO,   KC_NO,   KC_LT,   KC_GT,       KC_NO,   KC_NO,  KC_LT,    KC_GT,   KC_NO,   KC_NO,      KC_DEL,
  KC_NO,   KC_NO,   KC_NO,   KC_LPRN, KC_RPRN,     KC_NO,   KC_NO,  KC_LPRN,  KC_RPRN, KC_NO,   KC_NO,      KC_NO,
  KC_NO,   KC_PMNS, KC_PLUS, KC_LBRC, KC_RBRC,     KC_NO,   KC_NO,  KC_LBRC,  KC_RBRC, KC_PMNS, KC_PLUS,    KC_NO,
  KC_NO,   KC_UNDS, KC_EQL,  KC_LCBR, KC_RCBR,     KC_NO,   KC_NO,  KC_LCBR,  KC_RCBR, KC_UNDS, KC_EQL,     KC_NO,
  KC_NO,   KC_NO,   KC_NO,   LOWER,   TO(_QWERTY), KC_ENT,  KC_SPC, TO(_NAV), RAISE,   KC_NO,   KC_NO,      KC_NO
),

[_ADJUST] = LAYOUT_preonic_grid(
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  BACKLIT,  QK_BOOT,  DB_TOGG,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,    MU_NEXT,  AU_ON,    AU_OFF,   AG_NORM,  AG_SWAP,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,    AU_PREV,  AU_NEXT,  MU_ON,    MU_OFF,   MI_ON,    MI_OFF,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT
),

[_NAV] = LAYOUT_preonic_grid(
  KC_F12,  KC_F1,     KC_F2,     KC_F3,     KC_F4,       KC_F5,   KC_F6,   KC_F7,       KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_NO,   MEH(KC_Q), MEH(KC_W), MEH(KC_E), MEH(KC_R),   KC_NO,   KC_HOME, KC_PGDN,     KC_PGUP, KC_END,  KC_NO,   KC_PSCR,
  KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,       KC_NO,   KC_LEFT, KC_DOWN,     KC_UP,   KC_RGHT, KC_NO,   LCA(KC_DEL),
  KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,       KC_TRNS, KC_WH_L, KC_WH_D,     KC_WH_U, KC_WH_R, KC_UP,   KC_NO,
  KC_NO,   KC_NO,     KC_NO,     KC_NO,     TO(_QWERTY), KC_NO,   KC_NO,   TO(_QWERTY), KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT
)
};

// key overrides
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
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

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
      }
  }
  return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
  if (muse_mode) {
    if (muse_counter == 0) {
      uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
      if (muse_note != last_muse_note) {
        stop_note(compute_freq_for_midi_note(last_muse_note));
        play_note(compute_freq_for_midi_note(muse_note), 0xF);
        last_muse_note = muse_note;
      }
    }
    muse_counter = (muse_counter + 1) % muse_tempo;
  } else {
    if (muse_counter) {
      stop_all_notes();
      muse_counter = 0;
    }
  }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

// tap dance actions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
};

