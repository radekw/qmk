#pragma once

/* Handedness. */
#define SPLIT_HAND_PIN GP29
#define SPLIT_HAND_PIN_LOW_IS_LEFT // High -> right, Low -> left.

/* VBUS detection. */
#define USB_VBUS_PIN GP19

/* CRC. */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

/* Cirque trackpad over SPI. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20
#define POINTING_DEVICE_CS_PIN GP21
#undef CIRQUE_PINNACLE_DIAMETER_MM
#define CIRQUE_PINNACLE_DIAMETER_MM 40

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* RGB matrix support. */
#define SPLIT_TRANSPORT_MIRROR
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

// Startup values.
#define RGB_MATRIX_DEFAULT_VAL 64
#define RGB_MATRIX_DEFAULT_SPD 32

// layer keys
#define L_NAV   LT(LAYER_NAV, KC_ESC)
#define L_NUM   LT(LAYER_NUM, KC_TAB)
#define L_FN    LT(LAYER_FN, KC_DEL)
#define L_SYM   LT(LAYER_SYM, KC_BSPC)
#ifdef POINTING_DEVICE_ENABLE
#define PT_Q    LT(LAYER_POINTER, KC_Q)
#define PT_QUOT LT(LAYER_POINTER, KC_QUOT)
#endif

// shortcuts
#define A_C_DEL LCA(KC_DEL)
#define A_C_END LCA(KC_END)
#define A_C_BRK LCA(KC_BRK)
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
#define TAPPING_TERM_PER_KEY
#undef HOLD_ON_OTHER_KEY_PRESS
#define PERMISSIVE_HOLD

// combos
#define COMBO_TERM 22
#define COMBO_ONLY_FROM_LAYER 0
// #define COMBO_MUST_HOLD_MODS
// #define COMBO_HOLD_TERM 175
#define EXTRA_LONG_COMBOS

// home row mods
#define HR_S_F   LSFT_T(KC_F)
#define HR_C_D   LCTL_T(KC_D)
#define HR_A_S   LALT_T(KC_S)
#define HR_G_A   LGUI_T(KC_A)
#define HR_S_J   LSFT_T(KC_J)
#define HR_C_K   LCTL_T(KC_K)
#define HR_A_L   LALT_T(KC_L)
#define HR_G_SC  LGUI_T(KC_SCLN)

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

