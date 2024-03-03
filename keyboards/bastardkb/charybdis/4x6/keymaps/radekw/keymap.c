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

enum custom_keycodes {
    KC_QWER = SAFE_RANGE,
    KC_QHRM,
    KC_COLE,
};

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,       KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_V,     KC_B,       KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
                                  L_NAV,    KC_ENT,   L_NUM,      L_FN,     KC_SPC,
                                            KC_LALT,  KC_LGUI,    L_SYM
  ),

  [LAYER_QWERTY_HRM] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_BSPC,  HR_G_A,   HR_A_S,   HR_C_D,   HR_S_F,   KC_G,       KC_H,     HR_S_J,   HR_C_K,   HR_A_L,   HR_G_SC,  KC_QUOT,
    KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_V,     KC_B,       KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
                                  L_NAV,    KC_ENT,   L_NUM,      L_FN,     KC_SPC,
                                            KC_LALT,  KC_LGUI,    L_SYM
  ),

  [LAYER_COLEMAKDH] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,       KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSLS,
    KC_BSPC,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,       KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
    KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_D,     KC_V,       KC_K,     KC_H,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
                                  L_NAV,    KC_ENT,   L_NUM,      L_FN,     KC_SPC,
                                            KC_LALT,  KC_LGUI,    L_SYM
  ),

  [LAYER_NAV] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT,  KC_MPLY,    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT,  KC_MPLY,
    A_C_TAB,  KC_NO,    KC_NO,    KC_TAB,   KC_LALT,  KC_NO,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_NO,    KC_PSCR,
    KC_BSPC,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,    A_C_D,
    U_UND,    U_CUT,    U_CPY,    U_PST,    U_RDO,    KC_NO,      U_UND,    U_CUT,    U_CPY,    U_PST,    U_RDO,    KC_NO,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

  [LAYER_NUM] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_BSPC,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_MINS,  KC_7,     KC_8,     KC_9,     KC_SLSH,  KC_COMM,
    KC_NO,    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,    S(KC_EQL),  KC_4,     KC_5,     KC_6,   S(KC_8),    KC_DOT,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_EQL,   KC_1,     KC_2,     KC_3,     KC_0,     KC_DOT,
                                  KC_DOT,   KC_TRNS,  KC_TRNS,    KC_DOT,   KC_SPC,
                                            KC_TRNS,  KC_TRNS,    KC_COMM
  ),

  [LAYER_FN] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      CG_TOGG,  KC_QWER,  KC_QHRM,  KC_COLE,  DB_TOGG,  QK_BOOT,
    KC_NO,    KC_NO,    KC_F7,    KC_F8,    KC_F9,    KC_F12,     S_D_RMOD, S_D_MOD,  KC_NO,    DPI_RMOD, DPI_MOD,  KC_NO,
    KC_NO,    KC_NO,    KC_F4,    KC_F5,    KC_F6,    KC_F11,     KC_NO,    KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,  KC_NO,
    KC_NO,    KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F10,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

[LAYER_SYM] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_LT,    KC_GT,    KC_PMNS,  KC_UNDS,  KC_PLUS,  KC_EQL,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_LPRN,  KC_RPRN,  KC_AMPR,  KC_ASTR,  KC_PIPE,  KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_LBRC,  KC_RBRC,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_NO,      KC_NO,    KC_RSFT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_LCBR,  KC_RCBR,  KC_EXLM,  KC_AT,    KC_HASH,  KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                  KC_DOT,   KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

  [LAYER_POINTER] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      S_D_RMOD, S_D_MOD,  KC_NO,    DPI_RMOD, DPI_MOD,  KC_NO,
    KC_NO,    KC_TRNS,  DRGSCRL,  KC_BTN3,  KC_BTN1,  KC_BTN2,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  DRGSCRL,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    EE_CLR,   KC_NO,    KC_NO,    KC_BTN4,  KC_BTN5,  SNIPING,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                  KC_BTN3,  KC_BTN1,  KC_BTN2,    KC_NO,    KC_NO,
                                            KC_BTN4,  KC_BTN5,    KC_NO
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
    if (!process_achordion(keycode, record)) { return false; }

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
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_NAV:
            return TAPPING_TERM + 300;
        case L_NUM:
            return TAPPING_TERM + 300;
        case L_FN:
            return TAPPING_TERM + 300;
        case HR_A_S:
            return TAPPING_TERM + 1000;
        case HR_A_L:
            return TAPPING_TERM + 1000;
        case HR_G_A:
            return TAPPING_TERM + 1000;
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
    case C_Z:
      if (other_keycode == KC_X || other_keycode == KC_C || other_keycode == KC_V || other_keycode == KC_R) {
        return true;
      }
      break;
  }

  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

