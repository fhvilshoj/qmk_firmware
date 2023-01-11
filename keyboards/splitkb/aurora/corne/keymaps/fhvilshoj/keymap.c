#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum {
    BL = 0,
    NUM = 1,
    CH = 2,
    SH = 3,
    FN = 4
    // ..., the rest of your layers
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BL] = LAYOUT_split_3x6_3(
	        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
	        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                                  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
	        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, 
	                             KC_LGUI, MO(NUM), LT(SH, KC_ENT),  LT(SH, KC_SPC), MO(CH), KC_RALT
	      ),

	[SH] = LAYOUT_split_3x6_3(
	        S(KC_TAB), S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),                                   S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), KC_BSPC, 
	        KC_LCTL, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),                                  S(KC_H), S(KC_J), S(KC_K), S(KC_L), S(KC_SCLN), S(KC_QUOT), 
	        KC_LSFT, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),                                  S(KC_N), S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH), KC_ESC, 
	                             S(KC_LGUI), MO(NUM), S(KC_ENT),                    S(KC_SPC), MO(CH), S(KC_RALT)
	      ),
	[NUM] = LAYOUT_split_3x6_3(
	        KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BSPC, 
	        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX, 
	        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, 
	                                            KC_LGUI, _______, KC_SPC,   KC_ENT, MO(FN),   KC_RALT
	      ),

	[CH] = LAYOUT_split_3x6_3(
	        KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_BSPC, 
	        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,  KC_BSLS, KC_GRV, 
	        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,  KC_PIPE, KC_TILD, 
	                                            KC_LGUI, MO(FN),   KC_SPC,   KC_ENT, _______, KC_RALT
	      ),

	[FN] = LAYOUT_split_3x6_3(
	        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12, 
	        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX, 
	        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
	                                            KC_LGUI, _______, KC_SPC,   KC_ENT, _______, KC_RALT
	      )
};

