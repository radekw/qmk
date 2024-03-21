#include QMK_KEYBOARD_H
#include "muse.h"
#include <stdio.h>
#include "g/keymap_combo.h"

enum preonic_layers {
    _QWERTY,
    _COLEMAK,
    _GAME,
    _NUM,
    _NAV,
    _SYM,
    _FN
};

enum preonic_keycodes {
    KC_QWER = SAFE_RANGE,
    KC_COLE,
    KC_GAME,
    USRNAME,
    CTRXHM,
    CTRXCAD,
    BACKLIT,
    VIM_WA,
    VIM_QA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_preonic_grid (
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,    KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     USRNAME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,    KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_V,    KC_B,      KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
    KC_LCTL,  KC_LCMD,  KC_LALT,  L_NUM,    L_NAV,   KC_ENT,    KC_SPC,   L_SYM,    L_FN,     KC_LGUI,  KC_RCMD,  KC_RCTL
),
[_COLEMAK] = LAYOUT_preonic_grid(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     USRNAME,
    KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSLS,
    KC_BSPC,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
    KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_D,     KC_V,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
    KC_LCTL,  KC_NO,    KC_LALT,  L_NUM,    L_NAV,    KC_ENT,   KC_SPC,   L_SYM,    L_FN,     KC_LGUI,  KC_NO,    KC_RCTL
),
[_GAME] = LAYOUT_preonic_grid(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SC_SENT,
    KC_LCTL,  KC_NO,    KC_LALT,  L_NUM,    L_NAV,    KC_SPC,   KC_SPC,   L_NUM,    L_SYM,    KC_LGUI,  KC_NO,    KC_RCTL
),
[_NAV] = LAYOUT_preonic_grid(
    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT,  KC_MPLY,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT,  KC_MPLY,
    A_C_TAB,  CTRXHM,   CTRXCAD,  KC_TAB,   KC_LALT,  KC_NO,    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   CTRXHM,   KC_PSCR,
    KC_BSPC,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  A_C_BRK,  A_C_DEL,
    KC_NO,    U_UND,    U_CUT,    U_CPY,    U_PST,    U_RDO,    U_UND,    U_CUT,    U_CPY,    U_PST,    U_RDO,    A_C_END,
    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,    KC_NO
),
[_NUM] = LAYOUT_preonic_grid(
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_BSPC,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MINS,  KC_7,     KC_8,     KC_9,     KC_SLSH,  KC_COMM,
    KC_NO,    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,  S(KC_EQL),  KC_4,     KC_5,     KC_6,   S(KC_8),    KC_DOT,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_EQL,   KC_1,     KC_2,     KC_3,     KC_0,     KC_DOT,
    KC_NO,    KC_NO,    KC_NO,    KC_DOT,   KC_DOT,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,    KC_NO
),
[_FN] = LAYOUT_preonic_grid(
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    CG_TOGG,  KC_QWER,  KC_GAME,  KC_COLE,  DB_TOGG,  QK_BOOT,
    KC_NO,    KC_NO,    KC_F7,    KC_F8,    KC_F9,    KC_F12,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_F4,    KC_F5,    KC_F6,    KC_F11,   KC_NO,    KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,  KC_NO,
    KC_NO,    KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F10,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,    KC_NO
),
[_SYM] = LAYOUT_preonic_grid(
    KC_NO,    KC_LT,    KC_NO,    KC_NO,    KC_NO,    KC_GT,    KC_LT,    KC_NO,    KC_NO,    KC_NO,    KC_GT,    KC_NO,
    KC_NO,    KC_LPRN,  KC_AMPR,  KC_ASTR,  KC_PIPE,  KC_RPRN,  KC_LPRN,  KC_AMPR,  KC_ASTR,  KC_PIPE,  KC_RPRN,  KC_NO,
    KC_BSPC,  KC_LBRC,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_RBRC,  KC_LBRC,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_RBRC,  KC_NO,
    KC_NO,    KC_LCBR,  KC_EXLM,  KC_AT,    KC_HASH,  KC_RCBR,  KC_LCBR,  KC_EXLM,  KC_AT,    KC_HASH,  KC_RCBR,  KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_DOT,   KC_DOT,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,    KC_NO
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    const uint8_t all_mods = (mods | get_weak_mods());
    const bool shifted = all_mods & MOD_MASK_SHIFT;
    const bool ctrl = all_mods & MOD_MASK_CTRL;

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
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_NAV:
        case L_NUM:
        case L_FN:
            return TAPPING_TERM + 300;
        case HR_A_S:
        case HR_A_L:
        case HR_G_A:
        case HR_G_SC:
            return TAPPING_TERM + 1000;
        default:
            return TAPPING_TERM;
    }
}
