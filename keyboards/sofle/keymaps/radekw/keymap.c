#include QMK_KEYBOARD_H
#include <stdio.h>
#include "g/keymap_combo.h"

#define A_C_D LCA(KC_DEL)
#define A_C_TAB LCA(KC_TAB)
#define MT_C_Z LCTL_T(KC_Z)
#define MT_C_SLSH RCTL_T(KC_SLSH)
#define MT_S_A LSFT_T(KC_A)
#define MT_S_SCLN RSFT_T(KC_SCLN)
#define PT_Q LT(_POINTER, KC_Q)
#define L_NAV   LT(_NAV, KC_ESC)
#define L_FN    LT(_FN, KC_TAB)
#define L_NUM   LT(_NUM, KC_BSPC)
#define L_SYM   LT(_SYM, KC_DEL)

enum sofle_layers {
    _QWERTY,
    _COLEMAKDH,
    _NUM,
    _NAV,
    _FN,
    _SYM,
    _POINTER
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLE,
    VIM_WA,
    VIM_QA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4, KC_5,                    KC_6,  KC_7,  KC_8,    KC_9,   KC_0,      KC_DEL,
  KC_TAB,  PT_Q,   KC_W,    KC_E,    KC_R, KC_T,                    KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,      KC_BSLS,
  KC_BSPC, KC_A,   KC_S,    KC_D,    KC_F, KC_G,                    KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN,   KC_QUOT,
  KC_LSFT, MT_C_Z, KC_X,    KC_C,    KC_V, KC_B,  KC_HOME, KC_MUTE, KC_N,  KC_M,  KC_COMM, KC_DOT, MT_C_SLSH, SC_SENT,
                   KC_LCTL, KC_LALT, L_FN, L_NAV, KC_ENT,  KC_SPC,  L_NUM, L_SYM, KC_LGUI, KC_RCTL
),
[_COLEMAKDH] = LAYOUT(
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4, KC_5,                    KC_6,  KC_7,     KC_8,    KC_9,   KC_0,      KC_DEL,
  KC_TAB,  PT_Q,   KC_W,    KC_F,    KC_P, KC_B,                    KC_J,  KC_L,  KC_U,    KC_Y,   KC_SCLN,   KC_BSLS,
  KC_BSPC, KC_A,   KC_R,    KC_S,    KC_T, KC_G,                    KC_M,  KC_N,  KC_E,    KC_I,   KC_O,      KC_QUOT,
  KC_LSFT, MT_C_Z, KC_X,    KC_C,    KC_D, KC_V,  KC_HOME, KC_MUTE, KC_K,  KC_H,  KC_COMM, KC_DOT, MT_C_SLSH, SC_SENT,
                   KC_LCTL, KC_LALT, L_FN, L_NAV, KC_ENT,  KC_SPC,  L_NUM, L_SYM, KC_LGUI, KC_RCTL
),
[_NUM] = LAYOUT(
  KC_ESC,  KC_NO,   KC_NO, KC_NO, KC_LPRN, KC_RPRN,                 KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,
  KC_NO,   KC_PSLS, KC_P7, KC_P8, KC_P9,   KC_PMNS,                 KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,
  KC_BSPC, KC_PAST, KC_P4, KC_P5, KC_P6,   KC_PPLS,                 KC_NO,   KC_RSFT, KC_NO,   KC_NO,  KC_NO, KC_NO,
  KC_DEL,  KC_P0,   KC_P1, KC_P2, KC_P3,   KC_EQL,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,
                    KC_P0, KC_P0, KC_DOT,  KC_TRNS, KC_ENT, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_SYM] = LAYOUT(
  KC_LT,   KC_GT,   KC_PMNS, KC_UNDS, KC_PLUS, KC_EQL,                  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,
  KC_LPRN, KC_RPRN, KC_AMPR, KC_ASTR, KC_PIPE, KC_NO,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,
  KC_LBRC, KC_RBRC, KC_DLR,  KC_PERC, KC_CIRC, KC_NO,                   KC_NO,   KC_RSFT, KC_NO,   KC_NO,  KC_NO, KC_NO,
  KC_LCBR, KC_RCBR, KC_EXLM, KC_AT,   KC_HASH, KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_NAV] = LAYOUT(
  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV,  KC_MNXT, KC_MPLY,                   KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY,
  A_C_TAB, KC_NO,   KC_UP,   KC_TAB,   KC_LALT, KC_NO,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_PSCR,
  KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,   KC_NO,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   A_C_D,
  U_UND,   U_CUT,   U_CPY,   U_PST,    U_RDO,   KC_NO,   KC_TRNS, KC_TRNS, U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   KC_NO,
                    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_FN] = LAYOUT(  
  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                     CG_TOGG, KC_QWERTY, KC_COLE, KC_NO,  DB_TOGG, QK_BOOT,
  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_F7,     KC_F8,   KC_F9,  KC_F12,  KC_PSCR,
  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_F4,     KC_F5,   KC_F6,  KC_F11,  A_C_D,
  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_F1,     KC_F2,   KC_F3,  KC_F10,  KC_NO,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
),
[_POINTER] = LAYOUT(
  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     CG_TOGG, KC_QWERTY, KC_COLE, KC_NO,  DB_TOGG, QK_BOOT,
  KC_NO, KC_TRNS, KC_NO,   KC_BTN3, KC_BTN1, KC_BTN2,                   KC_NO,   KC_F7,     KC_F8,   KC_F9,  KC_F12,  KC_PSCR,
  KC_NO, KC_NO,   KC_NO,   KC_BTN4, KC_BTN5, KC_NO,                     KC_NO,   KC_F4,     KC_F5,   KC_F6,  KC_F11,  A_C_D,
  KC_NO, KC_NO,   KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_NO,   KC_F1,     KC_F2,   KC_F3,  KC_F10,  KC_NO,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
)
};

#ifdef OLED_ENABLE
#include "luna.c"
#include "arasaka.c"

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
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("COLK"), false);
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
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("COLEMAKDH"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("FN"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case _POINTER:
            oled_write_ln_P(PSTR("PTR"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UNDF"), false);
    }
    oled_write_P(PSTR("\n"), false);
    // Luna
    render_luna(0, 13);
}

// static void print_right_display(void) {
//     // WPM counter
//     char wpm_str[4];
//     oled_set_cursor(1, 1);
//     wpm_str[3] = '\0';
//     wpm_str[2] = '0' + current_wpm % 10;
//     wpm_str[1] = '0' + (current_wpm /= 10) % 10;
//     wpm_str[0] = '0' + current_wpm / 10;
//     oled_write(wpm_str, false);
//     oled_set_cursor(1, 2);
//     oled_write("WPM", false);
// }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    current_wpm = get_current_wpm();
    if (is_keyboard_master()) {
        print_left_display();
    } else {
        //print_right_display();
#ifdef CONVERT_TO_KB2040
        arasaka_draw();
#else
        arasaka_text_clean();
#endif
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
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

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return true;
}

#endif
