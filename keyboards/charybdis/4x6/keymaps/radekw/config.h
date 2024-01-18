/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE
#define MOUSE_EXTENDED_REPORT

// caps word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 2500

// tap mod
#undef  TAPPING_TERM
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

// combos
#define COMBO_TERM 25
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_MUST_HOLD_MODS
#define COMBO_HOLD_TERM 175
#define EXTRA_LONG_COMBOS

// home row mods
#define HRMQ_F    LSFT_T(KC_F)
#define HRMQ_D    LCTL_T(KC_D)
#define HRMQ_S    LALT_T(KC_S)
#define HRMQ_A    LGUI_T(KC_A)
#define HRMQ_J    LSFT_T(KC_J)
#define HRMQ_K    LCTL_T(KC_K)
#define HRMQ_L    LALT_T(KC_L)
#define HRMQ_SCLN LGUI_T(KC_SCLN)

#define HRMC_T    LSFT_T(KC_T)
#define HRMC_S    LCTL_T(KC_S)
#define HRMC_R    LALT_T(KC_R)
#define HRMC_A    LGUI_T(KC_A)
#define HRMC_N    LSFT_T(KC_N)
#define HRMC_E    LCTL_T(KC_E)
#define HRMC_I    LALT_T(KC_I)
#define HRMC_O    LGUI_T(KC_O)

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

#define ORBITAL_MOUSE_RADIUS        48
#define ORBITAL_MOUSE_WHEEL_SPEED   0.2
#define ORBITAL_MOUSE_DBL_DELAY_MS  50
#define ORBITAL_MOUSE_SPEED_CURVE \
      {20, 21, 23, 27, 32, 38, 46, 55, 64, 64, 64, 64, 64, 64, 64, 64}

