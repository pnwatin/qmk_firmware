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
#define HRM_T LSFT_T(KC_T)
#define HRM_S LT(NAV, KC_S)

#define HRM_H LT(NUM, KC_H)
#define HRM_A RSFT_T(KC_A)
#define HRM_E LT(LSYM, KC_E)
#define HRM_I RCTL_T(KC_I)

// BOTTOMROW

#define HRM_Z LALT_T(KC_Z)
#define HRM_C LGUI_T(KC_C)

#define HRM_P RGUI_T(KC_P)
#define HRM_UND LALT_T(KC_F23)

// THUMBROW

// TABS
#define RGHT_TAB C(KC_TAB)
#define LEFT_TAB C(S(KC_TAB))
#define SFT_TAB S(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX,    KC_Q,    KC_L,    KC_D,    KC_W,    KC_B,                         KC_J,    KC_F,    KC_O,    KC_U, KC_QUOT, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,   HRM_N,   HRM_R,   HRM_T,   HRM_S,    KC_G,                         KC_Y,   HRM_H,   HRM_A,   HRM_E,   HRM_I, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,   HRM_Z,    KC_X,    KC_M,   HRM_C,    KC_V,                         KC_K,   HRM_P, KC_COMM,  KC_DOT, HRM_UND, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                     KC_SPC,  KC_ESC,     KC_ENT, KC_BSPC
                                                 //`----------------'  `------------------'
    ),
  [NUM] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, KC_SLSH,    KC_9,    KC_8,    KC_7, KC_ASTR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_MINS,    KC_3,    KC_2,    KC_1, KC_PLUS,                      XXXXXXX, _______, KC_RSFT, KC_RGUI, KC_RCTL, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,    KC_X,    KC_6,    KC_5,    KC_4, KC_PERC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, XXXXXXX,
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
       XXXXXXX, KC_LCTL, KC_LGUI, KC_LSFT, _______, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     LEFT_TAB,  KC_TAB, CW_TOGG,RGHT_TAB, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    _______, _______,     SW_WIN, _______
                                                 //`----------------'  `------------------'
   ),
  [LSYM] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX,   KC_AT, KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_EXLM, KC_ASTR, KC_SLSH,  KC_EQL, KC_AMPR,                      XXXXXXX, XXXXXXX, KC_RSFT, _______, KC_RCTL, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                      XXXXXXX, KC_RGUI, XXXXXXX, XXXXXXX, KC_LALT, XXXXXXX,
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
       XXXXXXX, KC_LCTL, _______, KC_LSFT, XXXXXXX, XXXXXXX,                      KC_HASH, KC_RPRN, KC_LPRN,  ARROWS, KC_SCLN, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, KC_LGUI, XXXXXXX,                      KC_BSLS, KC_COLN, KC_QUES, KC_EXLM, KC_UNDS, XXXXXXX,
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
const uint16_t capsword[] PROGMEM = {KC_M, KC_COMM, COMBO_END};
const uint16_t meta[] PROGMEM = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(capsword, CW_TOGG),
    COMBO(meta, MO(META))
};

// CUSTOM SHIFT
const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_QUES},
    {KC_COMM, KC_EXLM},
    {KC_UNDS, KC_AT},
    {HRM_UND, KC_AT},
    {KC_BSPC, KC_DEL},
    {KC_SLSH, KC_BSLS},
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, MOD_MASK_GUI, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, MOD_MASK_CTRL | MOD_MASK_ALT, KC_SPC, SW_LANG,
        keycode, record
    );

    switch (keycode) {
        case HRM_UND:
            if (record->event.pressed && record->tap.count > 0) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;

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

