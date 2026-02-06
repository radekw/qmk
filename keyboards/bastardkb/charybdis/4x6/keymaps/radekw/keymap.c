#include QMK_KEYBOARD_H
#include <stdio.h>
#include "g/keymap_combo.h"
#include "features/achordion.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#include "timer.h"
#endif

enum charybdis_keymap_layers {
    LAYER_QWERTY = 0,
    LAYER_QWERTY_HRM,
    LAYER_COLEMAKDH,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_FN,
    LAYER_SYM,
    LAYER_POINTER,
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
    KC_QWER = SAFE_RANGE,
    KC_QHRM,
    KC_COLE,
    USRNAME,
    ALT_TAB,
    // CTRXHM,
    // CTRXCAD,
};

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     USRNAME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,       KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_V,     KC_B,       KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
                                  L_NAV,    KC_ENT,   L_NUM,      L_SYM,    KC_SPC,
                                            KC_LALT,  KC_LGUI,    L_FN
  ),

  [LAYER_QWERTY_HRM] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     USRNAME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_BSPC,  HR_G_A,   HR_A_S,   HR_C_D,   HR_S_F,   KC_G,       KC_H,     HR_S_J,   HR_C_K,   HR_A_L,   HR_G_SC,  KC_QUOT,
    KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_V,     KC_B,       KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
                                  L_NAV,    KC_ENT,   L_NUM,      L_SYM,    KC_SPC,
                                            KC_LALT,  KC_LGUI,    L_FN
  ),

  [LAYER_COLEMAKDH] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     USRNAME,
    KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,       KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSLS,
    KC_BSPC,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,       KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
    KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_D,     KC_V,       KC_K,     KC_H,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
                                  L_NAV,    KC_ENT,   L_NUM,      L_SYM,    KC_SPC,
                                            KC_LALT,  KC_LGUI,    L_FN
  ),

  [LAYER_NAV] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT,  KC_MPLY,    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT,  KC_MPLY,
    ALT_TAB,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_NO,    KC_PSCR,
    KC_BSPC,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  A_C_BRK,  A_C_DEL,
    KC_NO,    U_UND,    U_CUT,    U_CPY,    U_PST,    U_RDO,      U_UND,    U_CUT,    U_CPY,    U_PST,    U_RDO,    A_C_END,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

  [LAYER_NUM] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_BSPC,
    QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_COMM,  KC_7,     KC_8,     KC_9,   S(KC_EQL),  KC_MINS,
    KC_BSPC,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,      KC_DOT,   KC_4,     KC_5,     KC_6,   S(KC_8),    KC_SLSH,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_0,     KC_1,     KC_2,     KC_3,     KC_0,     KC_EQL,
                                  KC_DOT,   KC_TRNS,  KC_TRNS,    KC_DOT,   KC_SPC,
                                            KC_TRNS,  KC_TRNS,    KC_COMM
  ),

  [LAYER_FN] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      CG_TOGG,  KC_QWER,  KC_QHRM,  KC_COLE,  DB_TOGG,  KC_NO,
    KC_NO,    KC_NO,    KC_F7,    KC_F8,    KC_F9,    KC_F12,     S_D_RMOD, S_D_MOD,  KC_NO,    DPI_RMOD, DPI_MOD,  KC_NO,
    KC_NO,    KC_NO,    KC_F4,    KC_F5,    KC_F6,    KC_F11,     KC_NO,    KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,  KC_NO,
    KC_NO,    KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F10,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

[LAYER_SYM] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    QK_BOOT,
    KC_NO,    KC_NO,    KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    QK_BOOT,
    KC_BSPC,  KC_NO,    KC_DLR,   KC_PERC,  KC_CIRC,  KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_EXLM,  KC_AT,    KC_HASH,  KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

  [LAYER_POINTER] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      S_D_RMOD, S_D_MOD,  KC_NO,    DPI_RMOD, DPI_MOD,  KC_NO,
    KC_NO,    KC_TRNS,  DRGSCRL,  MS_BTN3,  MS_BTN1,  MS_BTN2,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  DRGSCRL,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    EE_CLR,   KC_NO,    KC_NO,    MS_BTN4,  MS_BTN5,  SNIPING,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                  MS_BTN3,  MS_BTN1,  MS_BTN2,    KC_NO,    KC_NO,
                                            MS_BTN4,  MS_BTN5,    KC_NO
  ),
};

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    achordion_task();
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif // POINTING_DEVICE_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(LAYER_QWERTY_HRM)) {
        if (!process_achordion(keycode, record)) { return false; }
    }
    const uint8_t mods = get_mods();
    const uint8_t all_mods = (mods | get_weak_mods());
    const bool shifted = all_mods & MOD_MASK_SHIFT;
    const bool ctrl = all_mods & MOD_MASK_CTRL;

    switch (keycode) {
        case KC_QWER:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LAYER_QWERTY);
            }
            return false;
            break;
        case KC_QHRM:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LAYER_QWERTY_HRM);
            }
            return false;
            break;
        case KC_COLE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LAYER_COLEMAKDH);
            }
            return false;
            break;
        case USRNAME: // Type my username, or if Shift is held, my last name.
            if (record->event.pressed) {
                static const char username[] PROGMEM = "radekw";
                static const char domain[] PROGMEM = "domain.com";
                static const char at_domain[] PROGMEM = "@domain.com";
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
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        // case CTRXHM:
        //     if (record->event.pressed) {
        //         tap_code16(LCA(KC_BRK));
        //         wait_ms(250);
        //         tap_code(KC_H);
        //         wait_ms(200);
        //         tap_code(KC_ENT);
        //     }
        //     return false;
        //     break;
        // case CTRXCAD:
        //     if (record->event.pressed) {
        //         tap_code16(LCA(KC_BRK));
        //         wait_ms(250);
        //         tap_code(KC_C);
        //     }
        //     return false;
        //     break;
    }
    return true;
}

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

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

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand in Magic Sturdy.
    switch (tap_hold_keycode) {
    case L_NAV:
    case L_NUM:
    case L_FN:
    case L_SYM:
        return true;
    case C_Z:
        switch (other_keycode) {
            case KC_X:
            case KC_C:
            case KC_V:
            case KC_R:
            case KC_F:
            case KC_G:
                return true;
        }
    }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

