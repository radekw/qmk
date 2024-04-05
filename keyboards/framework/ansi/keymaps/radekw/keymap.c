// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "framework.h"
#include <stdio.h>
#include "g/keymap_combo.h"

enum _layers {
    _BASE,
    _FN,
    _FN_LOCK,
    _FM
};

enum custom_keycodes {
    FN_LCK = FN_LOCK,
    USRNAME,
    CTRXHM,
    CTRXCAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,   KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_BRID,  KC_BRIU,  KC_SCRN,  KC_AIRP,  KC_PSCR,  KC_MSEL,  KC_DEL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   USRNAME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_SLSH,                       KC_RSFT,
        KC_LCTL,  MO(_FN),  KC_LGUI,  KC_LALT,            KC_SPC,                       KC_RALT,  KC_RCTL,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RGHT
    ),
    [_FN] = LAYOUT(
        FN_LCK,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  CTRXHM,   CTRXCAD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  _______,  _______,  _______,            _______,                      _______,  _______,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END
    ),
    // Function lock layer
    // Everything on F-row locked to function layer, except ESC and DEL
    [_FN_LOCK] = LAYOUT(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  MO(_FM),  _______,  _______,            _______,                      _______,  _______,  _______,  _______,  _______,  _______
    ),
    // Locked+temporary FN (back to base plus extra keys)
    [_FM] = LAYOUT(
        FN_LCK,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_BRID,  KC_BRIU,  KC_SCRN,  KC_AIRP,  KC_PSCR,  KC_MSEL,  KC_INS,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  CTRXHM,   CTRXCAD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  _______,  _______,  _______,            _______,                      _______,  _______,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    const uint8_t all_mods = (mods | get_weak_mods());
    const bool shifted = all_mods & MOD_MASK_SHIFT;
    const bool ctrl = all_mods & MOD_MASK_CTRL;
    switch (keycode) {
        // Make sure to keep FN Lock even after reset
        case FN_LCK:
            if (record->event.pressed) {
                if (layer_state_is(_FN)) {
                    set_single_persistent_default_layer(_FN_LOCK);
                }
                if (layer_state_is(_FM)) {
                    set_single_persistent_default_layer(_BASE);
                }
            }
            return false;
            break;
        case USRNAME: // Type my username, or if Shift is held, my last name.
            if (record->event.pressed) {
                static const char username[] PROGMEM = "rwierzbicki";
                static const char domain[] PROGMEM = ".com";
                static const char at_domain[] PROGMEM = "@.com";
                clear_weak_mods();
                unregister_mods(mods);  // Clear mods before send_string.
                if (shifted) {
                    send_string_with_delay_P(domain, TAP_CODE_DELAY);
                } else if (ctrl) {
                    send_string_with_delay_P(at_domain, TAP_CODE_DELAY);
                } else {
                    send_string_with_delay_P(username, TAP_CODE_DELAY);
                }
                register_mods(mods);  // Restore mods.
            }
            return false;
            break;
        case CTRXHM:
            if (record->event.pressed) {
                tap_code16(LCA(KC_BRK));
                wait_ms(250);
                tap_code(KC_H);
                wait_ms(200);
                tap_code(KC_ENT);
            }
            return false;
            break;
        case CTRXCAD:
            if (record->event.pressed) {
                tap_code16(LCA(KC_BRK));
                wait_ms(250);
                tap_code(KC_C);
            }
            return false;
            break;
        default:
            break;
    }
    return true;
}

