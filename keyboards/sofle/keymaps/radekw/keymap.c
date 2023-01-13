#include QMK_KEYBOARD_H
#include <stdio.h>
#include "g/keymap_combo.h"

#define G_C_L G(C(KC_LEFT))
#define G_C_R G(C(KC_RIGHT))
#define A_C_D LCA(KC_DEL)
#define MT_C_Z LCTL_T(KC_Z)
#define MT_C_SLSH RCTL_T(KC_SLSH)
#define MT_S_A LSFT_T(KC_A)
#define MT_S_SCLN RSFT_T(KC_SCLN)

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAV,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAME,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,     KC_5,                         KC_6,       KC_7,   KC_8,    KC_9,   KC_0,      KC_MINS,
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,                         KC_Y,       KC_U,   KC_I,    KC_O,   KC_P,      KC_BSLS,
  KC_BSPC, KC_A,   KC_S,    KC_D,    KC_F,     KC_G,                         KC_H,       KC_J,   KC_K,    KC_L,   KC_SCLN,   KC_QUOT,
  KC_LSFT, MT_C_Z, KC_X,    KC_C,    KC_V,     KC_B,       KC_MUTE, KC_NO,   KC_N,       KC_M,   KC_COMM, KC_DOT, MT_C_SLSH, SC_SENT,
                   KC_LCTL, KC_LALT, MO(_NAV), MO(_LOWER), KC_ENT,  KC_SPC,  MO(_RAISE), KC_DEL, KC_LGUI, KC_RCTL
),

[_GAME] = LAYOUT(
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,     KC_5,                         KC_6,       KC_7,   KC_8,    KC_9,   KC_0,      KC_MINS,
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,                         KC_Y,       KC_U,   KC_I,    KC_O,   KC_P,      KC_BSLS,
  KC_BSPC, KC_A,   KC_S,    KC_D,    KC_F,     KC_G,                         KC_H,       KC_J,   KC_K,    KC_L,   KC_SCLN,   KC_QUOT,
  KC_LSFT, MT_C_Z, KC_X,    KC_C,    KC_V,     KC_B,       KC_MUTE, KC_NO,   KC_N,       KC_M,   KC_COMM, KC_DOT, MT_C_SLSH, SC_SENT,
                   KC_LCTL, KC_LALT, MO(_NAV), MO(_LOWER), KC_ENT,  KC_SPC,  MO(_RAISE), KC_DEL, KC_LGUI, KC_RCTL
),

[_LOWER] = LAYOUT(
  KC_ESC, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,      KC_NO,   KC_NO, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_PSLS,    KC_P7,   KC_P8, KC_P9,   KC_PMNS, KC_NO,
  KC_DEL, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_PAST,    KC_P4,   KC_P5, KC_P6,   KC_PPLS, KC_DOT,
  KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,  KC_NO,  KC_P0,      KC_P1,   KC_P2, KC_P3,   KC_EQL,  KC_DOT,
                 KC_TRNS, KC_TRNS, KC_TRNS, MO(_LOWER), KC_ENT, KC_SPC, MO(_RAISE), KC_TRNS, KC_TRNS, KC_TRNS
),

[_RAISE] = LAYOUT(
  KC_ESC, KC_NO,   KC_NO,   KC_LT,   KC_GT,   KC_NO,                      KC_NO,      KC_LT,   KC_GT,   KC_NO,   KC_NO,   KC_BSPC,
  KC_NO,  KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_NO,                      KC_NO,      KC_LPRN, KC_RPRN, KC_NO,   KC_NO,   KC_NO,
  KC_DEL, KC_PMNS, KC_PLUS, KC_LBRC, KC_RBRC, KC_NO,                      KC_NO,      KC_LBRC, KC_RBRC, KC_PMNS, KC_PLUS, KC_NO,
  KC_NO,  KC_UNDS, KC_EQL,  KC_LCBR, KC_RCBR, KC_NO,      KC_NO,  KC_NO,  KC_NO,      KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL,  KC_NO,
                   KC_TRNS, KC_TRNS, KC_TRNS, MO(_LOWER), KC_ENT, KC_SPC, MO(_RAISE), KC_TRNS, KC_TRNS, KC_TRNS
),

[_ADJUST] = LAYOUT(
  KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   QK_BOOT,   DB_TOGG, KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_QWERTY, KC_GAME, CG_TOGG, KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_VOLD,   KC_VOLU, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPRV, KC_MNXT, KC_MPLY, KC_NO,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[_NAV] = LAYOUT(
  KC_F12,    KC_F1,   KC_F2,      KC_F3,      KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
  G(KC_TAB), KC_NO,   KC_UP,      G_C_L,      G_C_R,   KC_NO,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,  KC_PSCR,
  KC_DEL,    KC_LEFT, KC_DOWN,    KC_RIGHT,   KC_NO,   KC_NO,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,  A_C_D,
  KC_NO,     KC_NO,   G(KC_PGDN), G(KC_PGUP), KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,  KC_NO,
                      KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _GAME:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undf"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
