#pragma once

#define MASTER_LEFT

// Tap-hold configuration. 250 ms is the single global baseline; the decision
// policy is tuned per key in the keymap rather than by moving this number.
#define TAPPING_TERM 250

// A 250 ms quick-tap window is too eager to repeat tap actions and can turn an
// intended layer/mod hold into another letter. Per-key overrides in the keymap.
#define QUICK_TAP_TERM 100
#define QUICK_TAP_TERM_PER_KEY

#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Flow Tap is selective in get_flow_tap_term(): the mod HRMs only. It never
// touches the home-row symbol layer taps, and never the thumbs.
#define FLOW_TAP_TERM 105

// Holding Shift while Caps Word is active inverts the shift state.
#define CAPS_WORD_INVERT_ON_SHIFT
// When idle, turn off Caps Word after 5 seconds.
#define CAPS_WORD_IDLE_TIMEOUT 5000

// Rare combos only; short windows reduce accidental rolls.
#define COMBO_TERM 35
#define COMBO_STRICT_TIMER

// Don't apply custom shift keys with mods other than Shift.
#define CUSTOM_SHIFT_KEYS_NEGMODS ~MOD_MASK_SHIFT

// When idle, turn off Layer Lock after 60 seconds.
#define LAYER_LOCK_IDLE_TIMEOUT 60000

#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS
