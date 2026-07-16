#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum {
    BL = 0,
    NUM = 1,
    CH = 2,
    FN = 3,
};

enum my_keycodes {
    AP_GLOB = SAFE_RANGE,
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//     case AP_GLOB:
//                 dprintf("AP_GLOB %s\n", record->event.pressed ? "down" : "up");
//         if (record->event.pressed) {
//             host_consumer_send(0x029D);
//             register_code(KC_LCTL);
//         } else {
//             unregister_code(KC_LCTL);
//             host_consumer_send(0);
//         }
//         return false;
//     }
//     return true;
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BL] = LAYOUT_split_3x6_3(
	        XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,
	        XXXXXXX, LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,  KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), XXXXXXX,
	        XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B,                                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
	                             XXXXXXX, MO(CH), MT(MOD_RALT, KC_ENT),      LT(NUM, KC_SPC), MT(MOD_HYPR, KC_LALT), XXXXXXX
	      ),
	[NUM] = LAYOUT_split_3x6_3(
	        XXXXXXX,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    XXXXXXX,
	        XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX,
	        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
	                                            XXXXXXX, _______, _______,    _______, _______, XXXXXXX
	      ),

	[CH] = LAYOUT_split_3x6_3(
	        XXXXXXX,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_CIRC, XXXXXXX,
	        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PIPE, KC_EQL,  KC_LBRC, KC_RBRC,  KC_MINS, XXXXXXX,
	        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_TILD, KC_PLUS, KC_LCBR, KC_RCBR,  KC_BSLS, XXXXXXX,
	                                            XXXXXXX, _______, _______,   _______, _______, XXXXXXX
	      ),

	[FN] = LAYOUT_split_3x6_3(
	        XXXXXXX, KC_F2,   KC_F3,        KC_F4,              KC_F5,              KC_F6,                          KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  XXXXXXX,
	        XXXXXXX, KC_F1,   KC_KB_MUTE,   KC_KB_VOLUME_DOWN,  KC_KB_VOLUME_UP,    XXXXXXX,                        MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, KC_F12,  XXXXXXX,
	        XXXXXXX, QK_BOOT, XXXXXXX,      KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,   XXXXXXX,                        XXXXXXX, MS_BTN1, MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
	                                                            XXXXXXX, _______, _______,   _______, _______, XXXXXXX
	      ),
};

// Hold CH + NUM together to reach the FN layer (the old MO(FN) thumb is gone
// after the 6->4 thumb collapse). CH = left-outer thumb, NUM = right-inner thumb.
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, CH, NUM, FN);
}

