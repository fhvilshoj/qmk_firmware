#include QMK_KEYBOARD_H
#include "keymap_danish.h"

enum {
    BL = 0,
    NUM = 1,
    CH = 2,
    FN = 3,
    DK = 4
};

#include "g/keymap_combo.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BL] = LAYOUT_split_3x6_3(
	        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
	        KC_LCTL, LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
	        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, 
	                             KC_LGUI, MO(CH), MT(MOD_LCTL, KC_ENT),      MT(MOD_LSFT, KC_SPC), MO(NUM), KC_LALT
	      ),
	// ThisISA te† of how low the tapping term sho∂ beFor it to work properly for me.jJJ
	// This is a test of how well it works when I am typing. When I increa´the speed, I O feel ˆke øme stuff i not going pticulJ
	[NUM] = LAYOUT_split_3x6_3(
	        KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BSPC, 
	        KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX, 
	        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, 
	                                            KC_LGUI, MO(FN), KC_ENT,    KC_SPC, _______,   KC_LALT
	      ),

	[CH] = LAYOUT_split_3x6_3(
	        KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_CIRC, KC_BSPC, 
	        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PIPE, KC_EQL,  KC_LBRC, KC_RBRC,  KC_MINS, KC_UNDS, 
	        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_TILD, KC_PLUS, KC_LCBR, KC_RCBR,  KC_BSLS, KC_GRV, 
	                                            KC_LGUI, _______, KC_ENT,   KC_SPC, MO(FN), KC_LALT
	      ),

	[FN] = LAYOUT_split_3x6_3(
	        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12, 
	        XXXXXXX, XXXXXXX, KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, XXXXXXX,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX, 
	        QK_BOOT, XXXXXXX, XXXXXXX, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, XXXXXXX,                   XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, 
	                                            KC_LGUI, _______, KC_ENT,   KC_SPC, _______, KC_LALT
	      ),
	[DK] = LAYOUT_split_3x6_3(
	        KC_CAPS, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, UC(0xE5), 
	        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, UC(0xE6), UC(0xF8), 
	        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
	                                            _______, _______, _______,  _______, _______, _______
	)
};

