#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum {
    BL = 0,
    NUM = 1,
    CH = 2,
    FN = 3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	//      BASE LAYER
	//      ╭───┬───┬───┬───┬───┬───╮                      ╭───┬───┬───┬───┬───┬───╮
    //      │ ⇥ │ q │ w │ e │ r │ t │                      │ y │ u │ i │ o │ p │ ⌫ │
    //      ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┤
    //      │CTL│ a │ s │ d │ f │ g │                      │ h │ j │ k │ l │ ; │ ' │
    //      ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┤
    //      │SFT│ z │ x │ c │ v │ b │                      │ n │ m │ , │ . │ ; │ESC│
    //      ╰───┴───┴───┴───┴───┴───╯                      ╰───┴───┴───┴───┴───┴───╯
    //                         ╭─────┬────┬─────╮ ╭─────┬─────┬─────╮
    //                         │ CMD │ CH │ ⏎/C │ │ ␣/S │ NUM │ ALT │
    //                         ╰─────┴────┴─────╯ ╰─────┴─────┴─────╯
    //
	[BL] = LAYOUT_split_3x6_3(
	        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
	        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                                  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
	        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, 
	                             KC_LGUI, MO(CH), MT(MOD_LCTL, KC_ENT),      MT(MOD_LSFT, KC_SPC), MO(NUM), KC_LALT
	      ),

	//      NUMBERS AND ARROWS
	//      ╭───┬───┬───┬───┬───┬───╮                      ╭───┬───┬───┬───┬───┬───╮
    //      │ ⇥ │ 1 │ 2 │ 3 │ 4 │ 5 │                      │ 6 │ 7 │ 8 │ 9 │ 0 │ ⌫ │
    //      ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┤
    //      │CTL│   │SFT│ALT│CTL│   │                      │ ← │ ↓ │ ↑ │ → │   │   │
    //      ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┤
    //      │SFT│   │   │   │   │   │                      │   │   │   │   │   │   │
    //      ╰───┴───┴───┴───┴───┴───╯                      ╰───┴───┴───┴───┴───┴───╯
    //                         ╭─────┬────┬─────╮ ╭─────┬─────┬─────╮
    //                         │ CMD │ FN │ ENT │ │ SPC │ --- │ ALT │
    //                         ╰─────┴────┴─────╯ ╰─────┴─────┴─────╯
    //
	[NUM] = LAYOUT_split_3x6_3(
	        KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BSPC, 
	        KC_LCTL, XXXXXXX, KC_LSFT, KC_LALT, KC_LCTL, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX, 
	        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, 
	                                            KC_LGUI, MO(FN), KC_ENT,    KC_SPC, _______,   KC_LALT
	      ),

	//                                    SPECIAL CHARACTERS (RIGHT HAND)
	//      ╭───┬───┬───┬───┬───┬───╮                      ╭───┬───┬───┬───┬───┬───╮
    //      │ ⇥ │ ! │ @ │ # │ $ │ % │                      │ & │ * │ ( │ ) │ ^ │ ⌫ │
    //      ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┤
    //      │ C │   │   │   │   │   │                      │ | │ = │ [ │ ] │ - │ _ │
    //      ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┤
    //      │ S │   │   │   │   │   │                      │ ~ │ + │ { │ } │ \ │ ` │
    //      ╰───┴───┴───┴───┴───┴───╯                      ╰───┴───┴───┴───┴───┴───╯
    //                     ╭─────┬────┬─────╮      ╭─────┬─────┬─────╮
    //                     │ CMD │ -- │ ENT │      │ SPC │ FN  │ ALT │
    //                     ╰─────┴────┴─────╯      ╰─────┴─────┴─────╯
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
	      )
};

