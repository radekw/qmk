#include QMK_KEYBOARD_H
#include <stdio.h>
#include "g/keymap_combo.h"
#include "features/orbital_mouse.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_QWERTY = 0,
    LAYER_COLEMAKDH,
    LAYER_GAMING,
    LAYER_NUM,
    LAYER_NAV,
    LAYER_SYM,
    LAYER_FN,
    LAYER_POINTER,
};

enum custom_keycodes {
    KC_QWER = SAFE_RANGE,
    KC_COLE,
    KC_GAME
};

/* Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define L_NAV   LT(LAYER_NAV, KC_ESC)
#define L_FN    LT(LAYER_FN, KC_TAB)
#define L_NUM   LT(LAYER_NUM, KC_BSPC)
#define L_SYM   LT(LAYER_SYM, KC_DEL)
#define PT_Q    LT(LAYER_POINTER, KC_Q)
#define PT_P    LT(LAYER_POINTER, KC_P)
#define PT_SCLN LT(LAYER_POINTER, KC_SCLN)

#define A_C_D   LCA(KC_DEL)
#define A_C_TAB LCA(KC_TAB)
#define C_Z     LCTL_T(KC_Z)
#define C_SLSH  RCTL_T(KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_TAB,   PT_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,       KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_V,     KC_B,       KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
                                  L_NAV,    KC_ENT,   L_FN,       L_NUM,    KC_SPC,
                                            KC_LALT,  KC_LGUI,    L_SYM
  ),

  [LAYER_COLEMAKDH] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_TAB,   PT_Q,     KC_W,     KC_F,     KC_P,     KC_B,       KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSLS,
    KC_BSPC,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,       KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
    KC_LSFT,  C_Z,      KC_X,     KC_C,     KC_D,     KC_V,       KC_K,     KC_H,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
                                  L_NAV,    KC_ENT,   L_FN,       L_NUM,    KC_SPC,
                                            KC_LALT,  KC_LGUI,    L_SYM
  ),

  [LAYER_GAMING] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_T,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_G,     KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,       KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_B,     KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,       KC_N,     KC_M,     KC_COMM,  KC_DOT,   C_SLSH,   SC_SENT,
                                  L_NAV,    KC_SPC,   L_FN,       L_NUM,    KC_SPC,
                                            KC_LALT,  KC_ENT,     L_SYM
  ),

  [LAYER_NUM] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_ESC,   KC_NUM,   KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_BSPC,  KC_PAST,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,    KC_NO,    KC_RSFT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_DEL,   KC_P0,    KC_P1,    KC_P2,    KC_P3,    KC_EQL,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                  KC_DOT,   KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

  [LAYER_NAV] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT,  KC_MPLY,    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT,  KC_MPLY,
    A_C_TAB,  KC_NO,    KC_UP,    KC_TAB,   KC_LALT,  KC_NO,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_NO,    KC_PSCR,
    KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_LSFT,  KC_NO,      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,    A_C_D,
    U_UND,    U_CUT,    U_CPY,    U_PST,    U_RDO,    KC_NO,      U_UND,    U_CUT,    U_CPY,    U_PST,    U_RDO,    KC_NO,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

[LAYER_SYM] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_LT,    KC_GT,    KC_PMNS,  KC_UNDS,  KC_PLUS,  KC_EQL,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_LPRN,  KC_RPRN,  KC_AMPR,  KC_ASTR,  KC_PIPE,  KC_TILD,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_LBRC,  KC_RBRC,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_GRV,     KC_NO,    KC_RSFT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_LCBR,  KC_RCBR,  KC_EXLM,  KC_AT,    KC_HASH,  KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                  KC_DOT,   KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

  [LAYER_FN] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      CG_TOGG,  KC_QWER,  KC_COLE,  KC_GAME,  DB_TOGG,  QK_BOOT,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_F7,    KC_F8,    KC_F9,    KC_F12,   KC_PSCR,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_F4,    KC_F5,    KC_F6,    KC_F11,   A_C_D,
    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MNXT,  KC_MPLY,    KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F10,   KC_NO,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

  [LAYER_POINTER] = LAYOUT(
//  --------  --------  --------  --------  --------  --------    --------  --------  --------  --------  --------  --------
    XXXXXXX,  DPI_RMOD, DPI_MOD,  XXXXXXX,  S_D_RMOD, S_D_MOD,    S_D_RMOD, S_D_MOD,  XXXXXXX,  DPI_RMOD, DPI_MOD,  XXXXXXX,
    S_D_MOD,  _______,  DRGSCRL,  KC_BTN3,  KC_BTN1,  KC_BTN2,    OM_DBLS,  OM_BTNS,  OM_U,     OM_BTN2,  OM_SEL1,  XXXXXXX,
    S_D_RMOD, KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  DRGSCRL,    OM_HLDS,  OM_L,     OM_D,     OM_R,     OM_SEL2,  XXXXXXX,
    EE_CLR,   XXXXXXX,  XXXXXXX,  KC_BTN4,  KC_BTN5,  SNIPING,    OM_RELS,  OM_W_D,   OM_W_U,   OM_BTN3,  OM_SEL3,  XXXXXXX,
                                  KC_BTN3,  KC_BTN1,  KC_BTN2,    KC_BTN2,  KC_BTN1,
                                            KC_BTN4,  KC_BTN5,    KC_BTN3
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
    orbital_mouse_task();
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
#endif     // POINTING_DEVICE_ENABLE


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_orbital_mouse(keycode, record)) { return false; }
    switch (keycode) {
        case KC_QWER:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LAYER_QWERTY);
            }
            return false;
            break;
        case KC_COLE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LAYER_COLEMAKDH);
            }
            return false;
            break;
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LAYER_GAMING);
            }
            return false;
            break;
    }
    return true;
}
