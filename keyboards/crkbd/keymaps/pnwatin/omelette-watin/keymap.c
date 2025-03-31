/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "features/swapper.h"

enum layers {
  BASE,
  NUM,
  NAV,
  SYM,
  META
};

enum custom_keycodes {
  SW_WIN = SAFE_RANGE,
  SW_LANG,
};

enum tap_dances {
  TD_ARROWS
};

// HOMEROW
#define HRM_A LCTL_T(KC_A)
#define HRM_S LSFT_T(KC_S)
#define HRM_R LT(SYM, KC_R)
#define HRM_T LT(NAV, KC_T)

#define HRM_N LT(NUM, KC_N)
#define HRM_E RSFT_T(KC_E)
#define HRM_I LT(SYM, KC_I)
#define HRM_O RCTL_T(KC_O)

// SUBROW
#define HRM_D LGUI_T(KC_D)
#define HRM_Z LALT_T(KC_Z)

#define HRM_H RGUI_T(KC_H)
#define HRM_DOT LT(META, KC_DOT)
#define HRM_UND LALT_T(KC_F23)

// TABS
#define RGHT_TAB C(KC_TAB)
#define LEFT_TAB C(S(KC_TAB))
#define SFT_TAB S(KC_TAB)

// TAP DANCES
#define ARROWS TD(TD_ARROWS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,   HRM_A,   HRM_R,   HRM_S,   HRM_T,    KC_G,                         KC_M,   HRM_N,   HRM_E,   HRM_I,   HRM_O, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,   HRM_Z,    KC_X,    KC_C,   HRM_D,    KC_V,                         KC_K,   HRM_H, KC_COMM, HRM_DOT, HRM_UND, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           XXXXXXX,  KC_ESC,  KC_SPC,     KC_ENT, KC_BSPC, XXXXXXX
                                       //`--------------------------'  `--------------------------'
   ),
  [NUM] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, KC_SLSH,    KC_9,    KC_8,    KC_7, KC_ASTR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_MINS,    KC_3,    KC_2,    KC_1, KC_PLUS,                      XXXXXXX, _______, KC_RSFT, KC_RGUI, KC_RCTL, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,    KC_X,    KC_6,    KC_5,    KC_4, KC_PERC,                      XXXXXXX, XXXXXXX, KC_COMM,  KC_DOT, KC_LALT, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           XXXXXXX, XXXXXXX,    KC_0,    _______, _______, XXXXXXX
                                       //`--------------------------'  `--------------------------'
   ),
  [NAV] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LCTL, KC_LGUI, KC_LSFT, _______, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_TAB, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     LEFT_TAB,  KC_TAB, SFT_TAB,RGHT_TAB, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           XXXXXXX, _______, XXXXXXX,     SW_WIN, _______, XXXXXXX
                                       //`--------------------------'  `--------------------------'
   ),
  [SYM] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                      KC_CIRC, KC_RCBR, KC_LCBR,  KC_DLR,  KC_GRV, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_EXLM, KC_ASTR, KC_SLSH,  KC_EQL, KC_AMPR,                      KC_HASH, KC_RPRN, KC_LPRN,  ARROWS, KC_SCLN, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                      KC_BSLS, KC_COLN, KC_COMM,  KC_DOT, KC_UNDS, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           XXXXXXX, _______, _______,    _______, _______, XXXXXXX
                                       //`--------------------------'  `--------------------------'
   ),
  [META] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, QK_BOOT, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+                    |--------+--------|--------+--------|--------+--------|
       XXXXXXX, SW_LANG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
                                       //`--------------------------'  `--------------------------'
   ),
};

// SWAPPERS booleans
bool sw_win_active = false;
bool sw_lang_active = false;

// COMBOS
const uint16_t caps_combo[] PROGMEM = {KC_C, KC_COMM, COMBO_END};
const uint16_t x_c_combo[] PROGMEM = {KC_X, KC_C, COMBO_END};
const uint16_t comma_dot_comba[] PROGMEM = {KC_COMM, HRM_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(caps_combo, CW_TOGG),
    COMBO(x_c_combo, KC_BSLS),
    COMBO(comma_dot_comba, KC_SCLN),
};

// CUSTOM SHIFT
const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT , KC_QUES},
    {HRM_DOT , KC_QUES},
    {KC_COMM, KC_EXLM},
    {KC_UNDS, KC_AT},
    {HRM_UND, KC_AT},
    {KC_BSPC, KC_DEL},
    {KC_SLSH, KC_BSLS},
};

// TAP DANCES
void dance_arrow(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("->");
    }

    if (state->count == 2) {
        SEND_STRING("=>");
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_ARROWS] = ACTION_TAP_DANCE_FN(dance_arrow),
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

    // if (!process_custom_shift_keys(keycode, record)) { return false; }

    switch (keycode) {
        case HRM_UND:
            if (record->event.pressed && record->tap.count > 0) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
    }

    return true;
}

