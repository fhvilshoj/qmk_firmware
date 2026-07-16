#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

// Ported from splitkb/aurora/corne/keymaps/fhvilshoj — that keymap was already
// collapsed to a logical 34-key model (5 cols, 4 thumbs). On the Sweep the dead
// outer column + outer thumbs simply don't exist, so this is a straight drop
// into LAYOUT_split_3x5_2. See that keymap's charlieflex-transition-plan.md.

enum {
    BL = 0,
    NUM = 1,
    CH = 2,
    FN = 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BL] = LAYOUT_split_3x5_2(
	        KC_Q, KC_W, KC_E, KC_R, KC_T,                                        KC_Y, KC_U, KC_I, KC_O, KC_P,
	        LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,        KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
	        KC_Z, KC_X, KC_C, KC_V, KC_B,                                        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
	                            MO(CH), MT(MOD_RALT, KC_ENT),      LT(NUM, KC_SPC), MT(MOD_HYPR, KC_LALT)
	      ),
	[NUM] = LAYOUT_split_3x5_2(
	        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
	        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
	        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
	                                   _______, _______,              _______, _______
	      ),
	[CH] = LAYOUT_split_3x5_2(
	        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_CIRC,
	        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_PIPE, KC_EQL,  KC_LBRC, KC_RBRC,  KC_MINS,
	        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_TILD, KC_PLUS, KC_LCBR, KC_RCBR,  KC_BSLS,
	                                   _______, _______,              _______, _______
	      ),
	[FN] = LAYOUT_split_3x5_2(
	        KC_F2,   KC_F3,        KC_F4,              KC_F5,              KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
	        KC_F1,   KC_KB_MUTE,   KC_KB_VOLUME_DOWN,  KC_KB_VOLUME_UP,    XXXXXXX,     MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_F12,
	        QK_BOOT, XXXXXXX,      KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,   XXXXXXX,     XXXXXXX, MS_BTN1, MS_BTN2, XXXXXXX, XXXXXXX,
	                                                   _______, _______,      _______, _______
	      ),
};

// Hold CH + NUM together to reach the FN layer. CH = left thumb, NUM = right inner thumb.
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, CH, NUM, FN);
}
