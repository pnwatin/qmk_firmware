#pragma once

#define MASTER_LEFT

// HRM core. 250 ms is intentionally retained as the baseline; the point of
// this branch is to tune decision policy, not change everything at once.
#define TAPPING_TERM 250

// The original 250 ms quick-tap window is too eager to repeat tap actions and
// can turn a second intended hold into another letter. Per-key overrides below.
#define QUICK_TAP_TERM 100
#define QUICK_TAP_TERM_PER_KEY

#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Flow Tap is selective in get_flow_tap_term(): HRMs only, never layer thumbs.
#define FLOW_TAP_TERM 105

// Magic Shift's sticky tap should not remain armed indefinitely.
#define ONESHOT_TIMEOUT 900

// Rare combos only; short windows reduce accidental rolls.
#define COMBO_TERM 35
#define COMBO_STRICT_TIMER

#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 5000

// Don't apply custom shift keys with mods other than Shift.
#define CUSTOM_SHIFT_KEYS_NEGMODS ~MOD_MASK_SHIFT
