#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PREONIC_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

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

