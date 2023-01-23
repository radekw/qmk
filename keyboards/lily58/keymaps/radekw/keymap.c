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

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAV,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAME,
    VIM_WA,
    VIM_QA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_GRV,  KC_1,   KC_2, KC_3,    KC_4,     KC_5,                         KC_6,       KC_7,   KC_8,    KC_9,   KC_0,      KC_MINS,
  KC_TAB,  KC_Q,   KC_W, KC_E,    KC_R,     KC_T,                         KC_Y,       KC_U,   KC_I,    KC_O,   KC_P,      KC_BSLS,
  KC_BSPC, KC_A,   KC_S, KC_D,    KC_F,     KC_G,                         KC_H,       KC_J,   KC_K,    KC_L,   KC_SCLN,   KC_QUOT,
  KC_LSFT, MT_C_Z, KC_X, KC_C,    KC_V,     KC_B,       KC_LCTL, KC_RCTL, KC_N,       KC_M,   KC_COMM, KC_DOT, MT_C_SLSH, SC_SENT,
                         KC_LALT, MO(_NAV), MO(_LOWER), KC_ENT,  KC_SPC,  MO(_RAISE), KC_DEL, KC_LGUI
),

[_LOWER] = LAYOUT(
  KC_ESC, KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,                      KC_NO,      KC_NO,   KC_NO, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_NO,  VIM_QA, VIM_WA, KC_NO,   KC_NO,   KC_NO,                      KC_PSLS,    KC_P7,   KC_P8, KC_P9,   KC_PMNS, KC_NO,
  KC_DEL, KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,                      KC_PAST,    KC_P4,   KC_P5, KC_P6,   KC_PPLS, KC_DOT,
  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,      KC_NO,  KC_NO,  KC_P0,      KC_P1,   KC_P2, KC_P3,   KC_EQL,  KC_DOT,
                          KC_TRNS, KC_TRNS, MO(_LOWER), KC_ENT, KC_SPC, MO(_RAISE), KC_TRNS, KC_TRNS
),

[_RAISE] = LAYOUT(
  KC_ESC, KC_NO,   KC_NO,   KC_LT,   KC_GT,   KC_NO,                      KC_NO,      KC_LT,   KC_GT,   KC_NO,   KC_NO,   KC_BSPC,
  KC_NO,  KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_NO,                      KC_NO,      KC_LPRN, KC_RPRN, KC_NO,   KC_NO,   KC_NO,
  KC_DEL, KC_PMNS, KC_PLUS, KC_LBRC, KC_RBRC, KC_NO,                      KC_NO,      KC_LBRC, KC_RBRC, KC_PMNS, KC_PLUS, KC_NO,
  KC_NO,  KC_UNDS, KC_EQL,  KC_LCBR, KC_RCBR, KC_NO,      KC_NO,  KC_NO,  KC_NO,      KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL,  KC_NO,
                            KC_TRNS, KC_TRNS, MO(_LOWER), KC_ENT, KC_SPC, MO(_RAISE), KC_TRNS, KC_TRNS
),

[_ADJUST] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   QK_BOOT, DB_TOGG, KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPRV, KC_MNXT, KC_MPLY, KC_NO,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[_NAV] = LAYOUT(
  KC_F12,    KC_F1,   KC_F2,      KC_F3,      KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
  G(KC_TAB), KC_NO,   KC_UP,      G_C_L,      G_C_R,   KC_NO,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,  KC_PSCR,
  KC_DEL,    KC_LEFT, KC_DOWN,    KC_RIGHT,   KC_NO,   KC_NO,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,  A_C_D,
  KC_NO,     KC_NO,   G(KC_PGDN), G(KC_PGUP), KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,  KC_NO,
                                  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


#ifdef OLED_ENABLE
#include "luna.c"
#include "arasaka_small.c"

static void print_left_display(void) {
    // Print current mode
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWRT"), false);
            break;
            break;
        default:
            oled_write_P(PSTR("UNDF"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWER"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UNDF"), false);
    }
    oled_write_P(PSTR("\n"), false);
    // Luna
    render_luna(0, 13);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    oled_set_brightness(0);
    current_wpm = get_current_wpm();
    if (is_keyboard_master()) {
        print_left_display();
    } else {
        arasaka_draw();
    }
    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* MACROS START */
        case VIM_WA:
            if (record->event.pressed) {
                SEND_STRING(":wa\n");
            }
            break;
        case VIM_QA:
            if (record->event.pressed) {
                SEND_STRING(":qa\n");
            }
            break;
        /* MACROS END */
        /* LUNA START */
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        /* LUNA END */
    }
    return true;
}

