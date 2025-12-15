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
  SW_LANG,
  ARROWS,
};

// HOMEROW
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

// THUMBROW
#define HRM_SPC LT(NAV, KC_SPC)
#define HRM_ESC RALT_T(KC_ESC)
#define HRM_ENT RSFT_T(KC_ENT)
#define HRM_BSP LT(NUM, KC_BSPC)

// TABS
#define RGHT_TAB C(KC_TAB)
#define LEFT_TAB C(S(KC_TAB))
#define SFT_TAB S(KC_TAB)

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
                                                    HRM_SPC, HRM_ESC,    HRM_ENT, HRM_BSP
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
       XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     LEFT_TAB,  KC_TAB, CW_TOGG,RGHT_TAB,  SW_WIN, XXXXXXX,
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
       XXXXXXX, SW_LANG, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, RM_TOGG, RM_NEXT, RM_VALD, RM_VALU, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
                                                 //`----------------'  `------------------'
   ),
};

// SWAPPERS booleans
bool sw_win_active = false;
bool sw_lang_active = false;

// COMBOS
const uint16_t capsword[] PROGMEM = {KC_M, KC_QUOT, COMBO_END};
const uint16_t meta[] PROGMEM = {KC_QUOT, KC_UNDS, COMBO_END};

combo_t key_combos[] = {
    COMBO(capsword, CW_TOGG),
    COMBO(meta, MO(META))
};

// CUSTOM SHIFT
const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_QUES},
    {HRM_DOT, KC_QUES},

    {KC_COMM, KC_EXLM},
    {KC_UNDS, KC_AT},

    {KC_BSPC, KC_DEL},
    {HRM_BSP, KC_DEL},

    {KC_SLSH, KC_BSLS},
};

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case HRM_BSP:
        case HRM_SPC:
        case HRM_ESC:
        case HRM_ENT: {
            return true;
        }
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    // If you use combos, you can special-case them; otherwise keep it simple:
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;

    uprintf("0x%04X,%u,%u,%u,%u,0x%02X,0x%02X,%u\n",
            keycode,                             // 0x#### (hex keycode)
            row,                                 // row
            col,                                 // col
            get_highest_layer(layer_state),      // layer
            record->event.pressed ? 1 : 0,       // pressed (0/1)  <-- was %b
            (unsigned)get_mods(),                // current mods (hex)
            (unsigned)get_oneshot_mods(),        // oneshot mods (hex)
            record->tap.count);                  // tap count
#endif
    update_swapper(
        &sw_win_active, MOD_MASK_GUI, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, MOD_MASK_CTRL | MOD_MASK_ALT, KC_SPC, SW_LANG,
        keycode, record
    );

    switch (keycode) {
        case ARROWS:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    uint8_t saved_mods = get_mods();
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("=>");
                    set_mods(saved_mods);
                } else {
                    SEND_STRING("->");
                }
                return false;
            }
            break;
    }

    return true;
}

