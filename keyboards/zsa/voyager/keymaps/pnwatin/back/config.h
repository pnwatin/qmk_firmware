#pragma once

#define MASTER_LEFT

// Tap-hold configuration
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

#define QUICK_TAP_TERM 250
#define QUICK_TAP_TERM_PER_KEY

#define PERMISSIVE_HOLD

#define CHORDAL_HOLD

// Holding Shift while Caps Word is active inverts the shift state.
#define CAPS_WORD_INVERT_ON_SHIFT
// When idle, turn off Caps Word after 5 seconds.
#define CAPS_WORD_IDLE_TIMEOUT 5000

// Don't apply custom shift keys with mods other than Shift.
#define CUSTOM_SHIFT_KEYS_NEGMODS ~MOD_MASK_SHIFT

// When idle, turn off Layer Lock after 60 seconds.
#define LAYER_LOCK_IDLE_TIMEOUT 60000

#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS
