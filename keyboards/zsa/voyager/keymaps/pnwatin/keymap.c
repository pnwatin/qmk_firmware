#include QMK_KEYBOARD_H
#include "features/swapper.h"

// SYM_L and SYM_R are two *identical* symbol layers. Keeping them separate
// avoids the layer_off() race of two LT() keys sharing one layer, and lets the
// pair compose into NUM through update_tri_layer_state().
enum layers {
    BASE,
    NAV,
    SYM_L,
    SYM_R,
    NUM,
    META,
};

enum custom_keycodes {
    SW_WIN = SAFE_RANGE,
    SW_LANG,
    ARROWS,
    NW_TOGG,
};

// -----------------------------------------------------------------------------
// Base-layer home-row mods. Keep the same modifier on the same finger on both
// HRM-v2 variants so that the only A/B variable is Flow Tap.
// -----------------------------------------------------------------------------
#define HRM_N LCTL_T(KC_N)
#define HRM_R LALT_T(KC_R)
#define HRM_T LGUI_T(KC_T)
#define HRM_S LSFT_T(KC_S)

#define HRM_H RSFT_T(KC_H)
#define HRM_A RGUI_T(KC_A)
#define HRM_E RALT_T(KC_E)
#define HRM_I RCTL_T(KC_I)

// -----------------------------------------------------------------------------
// Thumbs:
//   left:  Space/Nav, Esc/SymL
//   right: Enter/SymR, Magic Shift
//
// Symbols get two access keys because they are a second alphabet in Rust/TS.
// Numbers are the chord of the two: hold both inner thumbs -> NUM.
// -----------------------------------------------------------------------------
#define TH_SPC LT(NAV, KC_SPC)
#define TH_LSYM LT(SYM_L, KC_ESC)
#define MGIC_SFT LSFT_T(KC_NO)
#define TH_RSYM LT(SYM_R, KC_ENT)


// -----------------------------------------------------------------------------
// Browser/tab shortcuts
// -----------------------------------------------------------------------------
#define RGHT_TAB C(KC_TAB)
#define LEFT_TAB C(S(KC_TAB))

// -----------------------------------------------------------------------------
// Explicit handedness removes any dependency on QMK guessing the Voyager
// matrix geometry. Thumbs are '*': Chordal Hold does not constrain them.
// -----------------------------------------------------------------------------
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L','L','L','L','L','L',                         'R','R','R','R','R','R',
    'L','L','L','L','L','L',                         'R','R','R','R','R','R',
    'L','L','L','L','L','L',                         'R','R','R','R','R','R',
    'L','L','L','L','L','L',                         'R','R','R','R','R','R',
                         '*','*',             '*','*'
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX,    KC_Q,    KC_L,    KC_D,    KC_W,    KC_B,                         KC_J,    KC_F,    KC_O,    KC_U, KC_COMM, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,   HRM_N,   HRM_R,   HRM_T,   HRM_S,    KC_G,                         KC_Y,   HRM_H,   HRM_A,   HRM_E,   HRM_I, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_P, KC_QUOT, KC_UNDS,  KC_DOT, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                     TH_SPC, TH_LSYM,    TH_RSYM, MGIC_SFT
                                                 //`----------------'  `------------------'
  ),
  [NAV] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_TAB, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     LEFT_TAB, KC_BSPC, CW_TOGG,RGHT_TAB,  SW_WIN, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    _______, _______,    _______, _______
                                                 //`----------------'  `------------------'
   ),
  // SYM_L and SYM_R must stay byte-for-byte identical: to the hands they are
  // one "Sym". Left `!` is kept (not `:`) so that the ! -> = inroll types `!=`.
  [SYM_L] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX,   KC_AT, KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                      KC_CIRC, KC_RCBR, KC_LCBR,  KC_DLR,  KC_GRV, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_EXLM, KC_ASTR, KC_SLSH,  KC_EQL, KC_AMPR,                      KC_HASH, KC_RPRN, KC_LPRN,  ARROWS, KC_SCLN, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                      KC_BSLS, KC_COLN, KC_DQUO, KC_UNDS, KC_QUES, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    _______, _______,    _______, _______
                                                 //`----------------'  `------------------'
   ),
  [SYM_R] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX,   KC_AT, KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                      KC_CIRC, KC_RCBR, KC_LCBR,  KC_DLR,  KC_GRV, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_EXLM, KC_ASTR, KC_SLSH,  KC_EQL, KC_AMPR,                      KC_HASH, KC_RPRN, KC_LPRN,  ARROWS, KC_SCLN, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                      KC_BSLS, KC_COLN, KC_DQUO, KC_UNDS, KC_QUES, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    _______, _______,    _______, _______
                                                 //`----------------'  `------------------'
   ),
  // Reached by holding BOTH Sym thumbs (tri-layer). Only the right half is
  // overridden; the transparent left half falls through to the Sym layer
  // underneath, so `[`, `]`, `(`, `-` stay available while typing digits.
  // NumWord uses this layer on its own, where the left half falls to BASE.
  [NUM] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, _______, _______, _______, _______, _______,                      KC_SLSH,    KC_7,    KC_8,    KC_9, KC_ASTR, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, _______, _______, _______, _______, _______,                      KC_PLUS,    KC_4,    KC_5,    KC_6, KC_MINS, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, _______, _______, _______, _______, _______,                         KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    _______, _______,    _______, _______
                                                 //`----------------'  `------------------'
   ),
  [META] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, QK_BOOT, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,                       KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, SW_LANG, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,                       KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, RM_TOGG, RM_NEXT, RM_VALD, RM_VALU, XXXXXXX,                       KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
                                                 //`----------------'  `------------------'
   ),
};

// -----------------------------------------------------------------------------
// Combos: intentionally rare conveniences, not architecture.
// X+M toggles NumWord. Quote+underscore retains the original held META combo.
// -----------------------------------------------------------------------------
enum combo_events {
    C_NUMWORD,
    C_META,
};

const uint16_t PROGMEM numword_combo[]  = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM meta_combo[]     = {KC_QUOT, KC_UNDS, COMBO_END};

combo_t key_combos[] = {
    [C_NUMWORD]  = COMBO(numword_combo, NW_TOGG),
    [C_META]     = COMBO(meta_combo, MO(META)),
};



// -----------------------------------------------------------------------------
// Custom Shift keys
// -----------------------------------------------------------------------------
const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT,  KC_QUES},
    {KC_COMM, KC_EXLM},
    {KC_UNDS, KC_AT},
    {KC_BSPC, KC_DEL},
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Do not let a previous tap force the next intended layer/Shift hold
        // back into another tap. This is particularly important in Vim.
        case TH_LSYM:
        case TH_RSYM:
        case MGIC_SFT:
            return 0;
        case TH_SPC:
            return 125;
        default:
            return QUICK_TAP_TERM;
    }
}


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // The right Sym thumb and the dedicated thumb Shift need to engage on
        // key-down, with no perceptible wait for the other key to be released.
        case TH_RSYM:
        case MGIC_SFT:
            return true;

        // Esc/SymL deliberately stays permissive-only: Esc-down, j-down,
        // Esc-up, j-up is still Escape+j rather than Sym+j. Global
        // PERMISSIVE_HOLD still settles it as a hold on a nested press/release,
        // so right-hand symbols through the left thumb stay responsive.
        case TH_LSYM:
        case TH_SPC:
        default:
            return false;
    }
}

#ifdef FLOW_TAP_TERM
static bool flow_prev_is_typing_key(uint16_t keycode) {
    // Intentionally ALPHA-ONLY for Neovim. In particular, Space is often a
    // leader key and punctuation is command syntax, so neither should suppress
    // an intentional modifier that follows it.
    const uint16_t tap = get_tap_keycode(keycode);
    return tap >= KC_A && tap <= KC_Z;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record,
                           uint16_t prev_keycode) {
    // Flow Tap is BASE-HRM-only. Never let it touch Sym/Num/Nav thumbs.
    if (get_highest_layer(layer_state) != BASE || !flow_prev_is_typing_key(prev_keycode)) {
        return 0;
    }

    // Once a real shortcut modifier is already active, prioritize chording.
    if (get_mods() & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) {
        return 0;
    }

    // Deliberately much shorter than QMK's generic 150 ms starting point.
    // Ctrl is the most Vim-sensitive; Shift gets the strongest typing guard.
    switch (keycode) {
        case HRM_N:
        case HRM_I:
            return 60;
        case HRM_R:
        case HRM_E:
            return 75;
        case HRM_T:
        case HRM_A:
            return 90;
        case HRM_S:
        case HRM_H:
            return 105;
        default:
            return 0;
    }
}
#endif

// -----------------------------------------------------------------------------
// Caps Word.
// -----------------------------------------------------------------------------
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_MINS:
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;
        default:
            return false;
    }
}

// -----------------------------------------------------------------------------
// NumWord: a lightweight QMK auto-NUM layer.
// Holding both Sym thumbs remains the preferred path for Vim counts, because
// releasing them is unambiguous; NumWord is a convenience for long runs such
// as 192.168.42.123. The transparent NUM left half falls through to Base and
// terminates NumWord when its Base key isn't in the continue list.
// -----------------------------------------------------------------------------
#define NUM_WORD_IDLE_TIMEOUT 5000
static bool num_word_active = false;
static uint32_t num_word_timer = 0;

static void num_word_on(void) {
    num_word_active = true;
    num_word_timer  = timer_read32();
    layer_on(NUM);
}

static void num_word_off(void) {
    num_word_active = false;
    layer_off(NUM);
}

static bool num_word_continue(uint16_t keycode) {
    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_DOT:
        case KC_COMM:
        case KC_MINS:
        case KC_PLUS:
        case KC_ASTR:
        case KC_SLSH:
        case KC_EQL:
        case KC_BSPC:
        case KC_DEL:
            return true;
        default:
            return false;
    }
}

void housekeeping_task_user(void) {
    if (num_word_active && timer_elapsed32(num_word_timer) > NUM_WORD_IDLE_TIMEOUT) {
        num_word_off();
    }
}

// -----------------------------------------------------------------------------
// Tri-layer: SymL + SymR -> NUM.
// NumWord owns NUM outright while it is active, so the tri-layer rule is
// skipped there; otherwise update_tri_layer_state() would immediately clear the
// layer NumWord just turned on.
// -----------------------------------------------------------------------------
layer_state_t layer_state_set_user(layer_state_t state) {
    if (num_word_active) {
        return state;
    }
    return update_tri_layer_state(state, SYM_L, SYM_R, NUM);
}



// -----------------------------------------------------------------------------
// SWAPPERS booleans.
// -----------------------------------------------------------------------------
bool sw_win_active  = false;
bool sw_lang_active = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, MOD_MASK_GUI, KC_TAB, SW_WIN, keycode, record);
    update_swapper(&sw_lang_active, MOD_MASK_CTRL | MOD_MASK_ALT, KC_SPC,
                   SW_LANG, keycode, record);

    // NumWord first, so a terminating transparent Base key disables NUM before
    // it is sent. Pressing the NumWord combo again toggles it off.
    if (keycode == NW_TOGG) {
        if (record->event.pressed) {
            if (num_word_active) {
                num_word_off();
            } else {
                num_word_on();
            }
        }
        return false;
    }
    if (num_word_active && record->event.pressed) {
        if (num_word_continue(keycode)) {
            num_word_timer = timer_read32();
        } else {
            num_word_off();
        }
    }

    switch (keycode) {
        case MGIC_SFT:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    const uint8_t shifts = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;

                    if (shifts) {
                        // A prior Magic tap leaves one-shot Shift active, so a
                        // second tap naturally becomes Caps Word.
                        del_oneshot_mods(MOD_MASK_SHIFT);
                        caps_word_on();
                    } else {
                        add_oneshot_mods(MOD_BIT(KC_LSFT));
                    }
                }
                return false;
            }
            // tap.count == 0: let the LSFT mod-tap hold behavior run normally.
            break;
        case ARROWS:
            if (record->event.pressed) {
                const uint8_t saved_mods = get_mods();
                const uint8_t saved_osm  = get_oneshot_mods();
                const bool shifted = ((saved_mods | saved_osm) & MOD_MASK_SHIFT) != 0;

                if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    set_oneshot_mods(saved_osm & ~MOD_MASK_SHIFT);
                    SEND_STRING("=> ");
                    set_mods(saved_mods);
                } else {
                    SEND_STRING("-> ");
                }
            }
            return false;
    }

    return true;
}
