#include QMK_KEYBOARD_H
#include "features/swapper.h"

enum layers {
  BASE,
  NUM,
  NAV,
  LSYM,
  RSYM,
  META
};

enum custom_keycodes {
  SW_WIN = SAFE_RANGE,
  ARROWS,
};

#define HRM_N LCTL_T(KC_N)
#define HRM_R LT(RSYM, KC_R)
#define HRM_T LGUI_T(KC_T)
#define HRM_S LSFT_T(KC_S)

#define HRM_H RSFT_T(KC_H)
#define HRM_A RGUI_T(KC_A)
#define HRM_E LT(LSYM, KC_E)
#define HRM_I RCTL_T(KC_I)

#define HRM_Z LALT_T(KC_Z)
#define HRM_DOT LALT_T(KC_DOT)

#define HRM_SPC LT(NAV, KC_SPC)
#define HRM_ESC RALT_T(KC_ESC)
#define HRM_ENT LT(NUM, KC_ENT)
#define MGIC_SFT LSFT_T(KC_NO)

#define RGHT_TAB C(KC_TAB)
#define LEFT_TAB C(S(KC_TAB))
#define SFT_TAB S(KC_TAB)

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_QUES},
    {HRM_DOT, KC_QUES},
    {KC_COMM, KC_EXLM},
    {KC_UNDS, KC_AT},
    {KC_BSPC, KC_DEL},
};

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
       XXXXXXX,   HRM_Z,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_P, KC_QUOT, KC_UNDS, HRM_DOT, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    HRM_SPC, HRM_ESC,    HRM_ENT, MGIC_SFT
                                                 //`----------------'  `------------------'
  ),
  [NUM] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, XXXXXXX,    KC_9,    KC_8,    KC_7, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX,    KC_3,    KC_2,    KC_1, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RGUI, _______, KC_RCTL, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX,    KC_6,    KC_5,    KC_4, XXXXXXX,                      XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                       KC_0, _______,    _______, _______
                                                 //`----------------'  `------------------'
   ),
  [NAV] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LCTL, _______, KC_LGUI, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_TAB, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     LEFT_TAB, KC_BSPC, CW_TOGG,RGHT_TAB,  SW_WIN, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    _______, _______,    _______, _______
                                                 //`----------------'  `------------------'
   ),
  [LSYM] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX,   KC_AT, KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_EXLM, KC_ASTR, KC_SLSH,  KC_EQL, KC_AMPR,                      XXXXXXX, KC_RSFT, KC_RGUI, _______, KC_RCTL, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    _______, _______,    _______, _______
                                                 //`----------------'  `------------------'
   ),
  [RSYM] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_CIRC, KC_RCBR, KC_LCBR,  KC_DLR,  KC_GRV, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LCTL, _______, KC_LGUI, KC_LSFT, XXXXXXX,                      KC_HASH, KC_RPRN, KC_LPRN,  ARROWS, KC_SCLN, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_BSLS, KC_COLN, KC_DQUO, KC_UNDS, KC_QUES, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    _______, _______,    _______, _______
                                                 //`----------------'  `------------------'
   ),
  [META] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, QK_BOOT, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, RM_TOGG, RM_NEXT, RM_VALD, RM_VALU, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
                                                 //`----------------'  `------------------'
   ),
};


bool sw_win_active = false;


const uint16_t meta[] PROGMEM = {KC_QUOT, KC_UNDS, COMBO_END};

combo_t key_combos[] = {
    COMBO(meta, MO(META))
};

// Only the home-row symbol keys opt out. Tapping `e` and then immediately
// holding `e` for LSYM must open the layer, not repeat the letter -- `value =`
// is exactly that sequence. Everything else keeps the global window, which is
// what lets a tap-then-hold on Space repeat spaces instead of opening NAV, and
// what makes a second Magic tap land on Caps Word.
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_R:
        case HRM_E:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // The dedicated thumb Shift needs to engage on key-down, with no
        // perceptible wait for the other key to be released.
        case MGIC_SFT:
            return true;

        // Everything else stays permissive-only. HRM_ENT in particular must
        // not settle on another key's press: Enter, then typing straight into
        // the new line, would otherwise roll into NUM + that key.
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
    // Flow Tap is BASE-mod-HRM-only. It deliberately excludes HRM_R and HRM_E:
    // symbols follow letters constantly (`foo->bar`), so suppressing those
    // holds mid-flow would be exactly wrong. The thumbs are excluded too.
    if (get_highest_layer(layer_state) != BASE || !flow_prev_is_typing_key(prev_keycode)) {
        return 0;
    }

    // Once a real shortcut modifier is already active, prioritize chording.
    if (get_mods() & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) {
        return 0;
    }

    // One shared term for every mod HRM, deliberately shorter than QMK's
    // generic 150 ms starting point. If a single finger ever feels wrong, split
    // it out of this list and give it its own value: lower means the mod
    // becomes available sooner after a keystroke (better for Vim Ctrl chords),
    // higher means a stronger guard against an accidental mod mid-roll.
    switch (keycode) {
        case HRM_N:
        case HRM_T:
        case HRM_S:
        case HRM_Z:
        case HRM_H:
        case HRM_A:
        case HRM_I:
        case HRM_DOT:
            return FLOW_TAP_TERM;
        default:
            return 0;
    }
}
#endif


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


// Magic Shift is Shift with a smarter tap:
//   hold                   -> normal Shift
//   tap                    -> sticky/one-shot Shift (ONESHOT_TIMEOUT)
//   tap while Shift active -> Caps Word
// MGIC_SFT is an ordinary LSFT mod-tap with KC_NO as its tap payload, so QMK
// handles the hold side and only the tap side is replaced here.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, MOD_MASK_GUI, KC_TAB, SW_WIN,
        keycode, record
    );

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
                // One-shot Shift lives outside get_mods(), so both have to be
                // consulted and both cleared before sending the literal.
                const uint8_t saved_mods = get_mods();
                const uint8_t saved_osm  = get_oneshot_mods();

                if ((saved_mods | saved_osm) & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    set_oneshot_mods(saved_osm & ~MOD_MASK_SHIFT);
                    SEND_STRING("=> ");
                    set_mods(saved_mods);
                } else {
                    SEND_STRING("-> ");
                }
                return false;
            }
            break;
    }

    return true;
}
