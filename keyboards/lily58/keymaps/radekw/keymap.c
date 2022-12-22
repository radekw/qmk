#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT(
  QK_GESC, KC_1,        KC_2, KC_3, KC_4,       KC_5,                  KC_6, KC_7,       KC_8,    KC_9,   KC_0,           KC_MINS,
  KC_TAB,  KC_Q,        KC_W, KC_E, KC_R,       KC_T,                  KC_Y, KC_U,       KC_I,    KC_O,   KC_P,           KC_BSLS,
  KC_BSPC, KC_A,        KC_S, KC_D, LT(1,KC_F), KC_G,                  KC_H, LT(2,KC_J), KC_K,    KC_L,   KC_SCLN,        KC_QUOT,
  KC_LSFT, CTL_T(KC_Z), KC_X, KC_C, LT(4,KC_V), KC_B, KC_BSPC, KC_DEL, KC_N, KC_M,       KC_COMM, KC_DOT, CTL_T(KC_SLSH), SC_SENT,
                        KC_LALT, MO(_LOWER), KC_BSPC, KC_ENT,  KC_SPC, KC_SPC, MO(_RAISE), KC_LGUI
),

[_LOWER] = LAYOUT(
  KC_TILD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_NO,   KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_PSLS, KC_P7, KC_P8, KC_P9,   KC_PMNS, KC_NO,
  KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_PAST, KC_P4, KC_P5, KC_P6,   KC_PPLS, KC_NO,
  KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,  KC_DOT, KC_P0,   KC_P1, KC_P2, KC_P3,   KC_EQL,  KC_NO,
                         KC_NO, MO(_LOWER), KC_DEL, KC_ENT, KC_SPC, KC_SPC, MO(_RAISE), KC_PDOT
),

[_RAISE] = LAYOUT(
  KC_GRV, KC_NO,   KC_NO,   KC_LT,   KC_GT,   KC_NO,                   KC_NO,  KC_LT,   KC_GT,   KC_NO,   KC_NO,   KC_DEL,
  KC_NO,  KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_NO,                   KC_NO,  KC_LPRN, KC_RPRN, KC_NO,   KC_NO,   KC_NO,
  KC_NO,  KC_PMNS, KC_PLUS, KC_LBRC, KC_RBRC, KC_NO,                   KC_NO,  KC_LBRC, KC_RBRC, KC_PMNS, KC_PLUS, KC_NO,
  KC_NO,  KC_UNDS, KC_EQL,  KC_LCBR, KC_RCBR, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL,  KC_NO,
                            KC_NO, MO(_LOWER), KC_DEL, KC_ENT, KC_SPC, KC_SPC, MO(_RAISE), KC_NO
),

[_ADJUST] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   QK_BOOT, DB_TOGG, KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_VOLD, KC_VOLU, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[_NAV] = LAYOUT(
  KC_F12, KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
  KC_NO,  MEH(KC_Q), MEH(KC_W), MEH(KC_E), MEH(KC_R), KC_NO,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,  KC_PSCR,
  KC_NO,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,  LCA(KC_DEL),
  KC_NO,  KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_NO,   KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,  KC_NO,
                                KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

// key overrides
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

