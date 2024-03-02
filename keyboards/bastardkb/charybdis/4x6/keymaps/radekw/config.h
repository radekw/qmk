#pragma once

#define MOUSE_EXTENDED_REPORT

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 1

// Automatically enable sniping-mode on the pointer layer.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#else // !POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define DPI_RMOD KC_NO
#    define S_D_MOD KC_NO
#    define S_D_RMOD KC_NO
#    define SNIPING KC_NO
#endif // POINTING_DEVICE_ENABLE

// layer keys
#define L_NAV   LT(LAYER_NAV, KC_ESC)
#define L_NUM   LT(LAYER_NUM, KC_TAB)
#define L_FN    LT(LAYER_FN, KC_BSPC)
#define L_SYM   LT(LAYER_SYM, KC_DEL)
#define PT_Q    LT(LAYER_POINTER, KC_Q)
#define PT_QUOT LT(LAYER_POINTER, KC_QUOT)

// shortcuts
#define A_C_D   LCA(KC_DEL)
#define A_C_TAB LCA(KC_TAB)
#define C_Z     LCTL_T(KC_Z)
#define C_SLSH  RCTL_T(KC_SLSH)
#define NUM_EQL KC_EQL
#define NUM_PLS LSFT(KC_EQL)
#define NUM_MIN KC_MINS
#define NUM_AST LSFT(KC_8)
#define NUM_DIV KC_SLSH

// caps word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 2500

// tap mod
#undef  TAPPING_TERM
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

// combos
#define COMBO_TERM 22
#define COMBO_ONLY_FROM_LAYER 0
// #define COMBO_MUST_HOLD_MODS
// #define COMBO_HOLD_TERM 175
#define EXTRA_LONG_COMBOS

// home row mods
#define HRM_F    LSFT_T(KC_F)
#define HRM_D    LCTL_T(KC_D)
#define HRM_S    LALT_T(KC_S)
#define HRM_A    LGUI_T(KC_A)
#define HRM_J    LSFT_T(KC_J)
#define HRM_K    LCTL_T(KC_K)
#define HRM_L    LALT_T(KC_L)
#define HRM_SCLN LGUI_T(KC_SCLN)

// miryoku
#define MIRYOKU_CLIPBOARD_WIN

// miryoku clipboard
#if defined (MIRYOKU_CLIPBOARD_FUN)
  #define U_RDO KC_AGIN
  #define U_PST KC_PSTE
  #define U_CPY KC_COPY
  #define U_CUT KC_CUT
  #define U_UND KC_UNDO
#elif defined (MIRYOKU_CLIPBOARD_MAC)
  #define U_RDO SCMD(KC_Z)
  #define U_PST LCMD(KC_V)
  #define U_CPY LCMD(KC_C)
  #define U_CUT LCMD(KC_X)
  #define U_UND LCMD(KC_Z)
#elif defined (MIRYOKU_CLIPBOARD_WIN)
  #define U_RDO C(KC_Y)
  #define U_PST C(KC_V)
  #define U_CPY C(KC_C)
  #define U_CUT C(KC_X)
  #define U_UND C(KC_Z)
#else
  #define U_RDO KC_AGIN
  #define U_PST S(KC_INS)
  #define U_CPY C(KC_INS)
  #define U_CUT S(KC_DEL)
  #define U_UND KC_UNDO
#endif

//#define ORBITAL_MOUSE_RADIUS       48
//#define ORBITAL_MOUSE_WHEEL_SPEED  0.2
//#define ORBITAL_MOUSE_DBL_DELAY_MS 50
//#define ORBITAL_MOUSE_SPEED_CURVE  {20, 21, 23, 27, 32, 38, 46, 55, 64, 64, 64, 64, 64, 64, 64, 64}
