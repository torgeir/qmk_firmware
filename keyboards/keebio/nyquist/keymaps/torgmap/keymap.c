// Copyright 2025 Torgeir Thoresen (@torgeir)
// SPDX-License-Identifier: GPL-2.0-or-later

// apple iso layout, no_nb (norwgian bokmaal)
// qmk compile -kb keebio/nyquist/rev5 -km torgmap && qmk flash -kb keebio/nyquist/rev5 -km torgmap

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h" // NO_*
#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#endif

// order matters
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUN,
    _ADJUST,
    _NAV,
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE
};

// S(kc) is Left shift
// A(kc) is Alt
// OSM(MOD_LSFT) not nescessary to keep shift pressed to make next typed letter uppercase, does not work with double tap like intellij wants

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,               KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   /**/  KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,         KC_BSPC,
  MT(MOD_LCTL, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   /**/  KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN/*ø*/, KC_QUOT/*æ*/,
  OSM(MOD_LSFT),        KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   /**/  KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,      KC_ENT,
  MOD_HYPR,             KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, /**/  KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,        KC_RGHT
),
[_LOWER] = LAYOUT_ortho_4x12(
  KC_GRV/*'*/, KC_EXLM/*!*/, KC_AT/*"*/,   KC_HASH/*#*/,    KC_DLR/*$*/, KC_PERC/*%*/, /**/  KC_CIRC,         NO_LCBR/*|*/, KC_ASTR/*(*/,    KC_LPRN/*)*/,    S(KC_MINS)/*?*/, S(KC_EQL)/*`*/,
  _______,     _______,      NO_LBRC/*[*/, NO_RBRC/*]*/,    _______,     _______,      /**/  S(NO_LCBR)/*\*/, KC_PSLS/*/*/, S(KC_8)/*(*/,    S(KC_9)/*)*/,    S(KC_RBRC)/*^*/, KC_PEQL/*=*/,
  _______,     _______,      KC_NUBS/*<*/, S(KC_NUBS)/*>*/, _______,     _______,      /**/  _______,         KC_PLUS/*+*/, S(NO_LBRC)/*{*/, S(NO_RBRC)/*}*/, KC_PMNS/*-*/,    A(KC_RBRC)/*~*/,
  TO(_RAISE),  _______,      _______,      _______,         _______,     KC_BSPC,      /**/  _______,         _______,      _______,         _______,         _______,         _______
),
[_RAISE] = LAYOUT_ortho_4x12(
  KC_EQL,      KC_1,               KC_2,                KC_3,                KC_4,   KC_5,        /**/ KC_6,         KC_7,    KC_8, KC_9,   KC_0,         KC_LBRC/*å*/,
  S(KC_BSPC),  KC_F1,              KC_F2,               KC_F3,               KC_F4,  KC_PERC,     /**/ KC_PSLS/*/*/, KC_4,    KC_5, KC_6,   KC_PAST/***/, KC_PEQL/*=*/,
  KC_LSFT,     KC_F5,              KC_F6,               KC_F7,               KC_F8,  _______,     /**/ KC_PPLS/*+*/, KC_1,    KC_2, KC_3,   KC_PMNS/*-*/, KC_BSLS/*@*/,
  TO(_QWERTY), MT(KC_LCTL, KC_F9), MT(KC_LALT, KC_F10), MT(KC_LGUI, KC_F11), KC_F12, TO(_QWERTY), /**/ KC_BSPC,      _______, KC_0, KC_DOT, KC_COMM,      TO(_NAV)
),
[_ADJUST] = LAYOUT_ortho_4x12(
  _______,  _______,  MS_WHLD, MS_UP,   MS_WHLU, _______, /**/ _______, KC_PGDN, KC_PGUP, KC_MPRV, KC_MPLY, KC_MNXT,
  _______,  _______,  MS_LEFT, MS_DOWN, MS_RGHT, _______, /**/ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MUTE, KC_VOLU,
  RGB_TOG,  RGB_MOD,  RGB_HUI, RGB_VAI, RGB_SPI, EE_CLR,  /**/ _______, MS_BTN1, MS_BTN3, MS_BTN2, _______, KC_VOLD,
  TO(_FUN), RGB_RMOD, RGB_HUD, RGB_VAD, RGB_SPD, QK_RBT,  /**/ QK_BOOT, _______, _______, _______, _______, _______
),
[_FUN] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, /**/ _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, /**/ _______, TO(_QWERTY), _______, _______, _______, _______
),
[_NAV] = LAYOUT_ortho_4x12(
  _______, _______, MS_WHLD, MS_UP,   MS_WHLU, _______, /**/ _______, KC_PGDN,     KC_PGUP, _______, _______, _______,
  _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, /**/ KC_LEFT, KC_DOWN,     KC_UP,  KC_RGHT,  _______, _______,
  _______, _______, _______, _______, _______, _______, /**/ _______, _______,     _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, /**/ _______, TO(_QWERTY), _______, _______, _______, _______
)
};

static uint8_t saved_rgb_mode = 0;
static uint8_t saved_hsv[3] = {0}; // [hue, sat, val]
static bool layer_override_active = false;
static bool in_bootloader_mode = false;
static bool bootloader_queued = false;
static uint32_t bootloader_jump_timer = 0;

__attribute__((unused))
static void save_rgb_state(void) {
  if (!layer_override_active) {
    layer_override_active = true;
    saved_rgb_mode = rgb_matrix_get_mode();
    saved_hsv[0] = rgb_matrix_get_hue();
    saved_hsv[1] = rgb_matrix_get_sat();
    saved_hsv[2] = rgb_matrix_get_val();
  }
}

__attribute__((unused))
static void restore_rgb_state(void) {
  if (layer_override_active) {
    layer_override_active = false;
    rgb_matrix_sethsv_noeeprom(saved_hsv[0], saved_hsv[1], saved_hsv[2]);
    rgb_matrix_mode_noeeprom(saved_rgb_mode);
  }
}

__attribute__((unused))
static void update_rgb_state(void) {
  saved_rgb_mode = rgb_matrix_get_mode();
  saved_hsv[0] = rgb_matrix_get_hue();
  saved_hsv[1] = rgb_matrix_get_sat();
  saved_hsv[2] = rgb_matrix_get_val();
}

// Runs continuously
void matrix_scan_user(void) {
  // Check if bootloader jump is queued and timer expired
  // Its done this way to be able to change the color before it runs
  if (bootloader_queued && timer_elapsed32(bootloader_jump_timer) > 300) {
    bootloader_jump();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Clear bootloader mode on any other keypress
  if (keycode != QK_BOOT && record->event.pressed) {
    in_bootloader_mode = false;
  }
  switch (keycode) {
    case QK_BOOT:
      if (record->event.pressed) {
        in_bootloader_mode = true;
        layer_override_active = false;
        rgb_matrix_sethsv_noeeprom(HSV_WHITE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
        update_rgb_state();
        bootloader_queued = true;
        bootloader_jump_timer = timer_read32();
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }

  return true;
}

void keyboard_post_init_user(void) {
  /* rgb_matrix_mode_noeeprom(RGB_MATRIX_JELLYBEAN_RAINDROPS); */
}

// Add this to see if the slave is getting layer updates
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_keyboard_master()) {
        uprintf("Master received layer: %d\n", get_highest_layer(state));
    }
    if (!is_keyboard_master()) {
        uprintf("Slave received layer: %d\n", get_highest_layer(state));
    }
    return state;
}

/*
 * // Row 0 (top row)
0  = [0,0] TAB      (flags: 4)
1  = [0,1] Q        (flags: 4)
2  = [0,2] W        (flags: 4)
3  = underglow      (flags: 2) <-- UNDERGLOW
4  = [0,3] E        (flags: 4)
5  = [0,4] R        (flags: 4)
6  = [0,5] T        (flags: 4)

// Row 1
7  = [1,5] G        (flags: 4)
8  = underglow      (flags: 2) <-- UNDERGLOW
9  = [1,4] F        (flags: 4)
10 = [1,3] D        (flags: 4)
11 = [1,2] S        (flags: 4)
12 = [1,1] A        (flags: 4)
13 = underglow      (flags: 2) <-- UNDERGLOW
14 = [1,0] ESC/CTRL (flags: 4)

// Row 2
15 = [2,0] SHIFT    (flags: 4)
16 = [2,1] Z        (flags: 4)
17 = [2,2] X        (flags: 4)
18 = [2,3] C        (flags: 4)
19 = [2,4] V        (flags: 4)
20 = [2,5] B        (flags: 4)

// Row 3
21 = [3,5] SPACE    (flags: 4)
22 = underglow      (flags: 2) <-- UNDERGLOW
23 = [3,4] LOWER    (flags: 4)
24 = [3,3] GUI      (flags: 4)
25 = underglow      (flags: 2) <-- UNDERGLOW
26 = [3,2] ALT      (flags: 4)
27 = [3,1] CTRL     (flags: 4)
28 = underglow      (flags: 2) <-- UNDERGLOW
29 = [3,0] HYPR     (flags: 4)

// Row 4 (broken off)
30-35 = Row 4 keys and underglow

 */
// Better approach - just list the actual key LEDs
const uint8_t ledsl[] = {
    0,   1,  2,  4,  5,  6, // Row 0
    14, 12, 11, 10,  9,  7, // Row 1
    15, 16, 17, 18, 19, 20, // Row 2
    29, 27, 26, 24, 23, 21  // Row 3
};

const uint8_t ledslu[] = {
    3,         // row 0
    13, 8,     // row 1
    // none    // row 2
    28, 25, 22 // row 3
};

const uint8_t ledsr[] = {
    36, 37, 38, 40, 41, 42, // Row 0
    50, 48, 47, 46, 45, 43, // Row 1
    51, 52, 53, 54, 55, 56, // Row 2
    65, 63, 62, 60, 59, 57  // Row 3
};
const uint8_t ledslr[] = {
    39,        // row 0
    49, 44,    // row 1
    // none    // row 2
    64, 61, 58 // row 3
};



// !!! remember to flash both halves when mucking around with led colors
bool rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    switch(layer) {
        case _ADJUST:
            rgb_matrix_set_color(3, RGB_WHITE); // underglow
            rgb_matrix_set_color(39, RGB_BLUE); // underglow
            break;

        case _LOWER:
            // Light up specific keys for LOWER layer
            rgb_matrix_set_color(0, RGB_RED);  // TAB
            rgb_matrix_set_color(1, RGB_RED);  // Q
            rgb_matrix_set_color(2, RGB_RED);  // W
            //
            rgb_matrix_set_color(3, RGB_GREEN); // underglow
            //
            rgb_matrix_set_color(4, RGB_RED);  // E (skip 3)
            rgb_matrix_set_color(5, RGB_RED);  // R
            rgb_matrix_set_color(6, RGB_RED);  // T

            // Light up top row right (skip underglow at index 39)
            rgb_matrix_set_color(36, RGB_YELLOW);  // Y
            rgb_matrix_set_color(37, RGB_YELLOW);  // U
            rgb_matrix_set_color(38, RGB_YELLOW);  // I
            //
            rgb_matrix_set_color(39, RGB_WHITE);
            //
            rgb_matrix_set_color(40, RGB_YELLOW);  // O (skip 39)
            rgb_matrix_set_color(41, RGB_YELLOW);  // P
            rgb_matrix_set_color(42, RGB_YELLOW);  // BSPC
            break;

        case _RAISE:
            // F-keys on left
            rgb_matrix_set_color(3, RGB_WHITE); // underglow
            rgb_matrix_set_color(39, RGB_BLUE); // underglow
            break;

        default:
            // Base layer - you can leave default effect or set subtle indicators
            // For example, highlight the layer keys
            rgb_matrix_set_color(28, RGB_WHITE);  // LOWER key
            rgb_matrix_set_color(43, RGB_WHITE);  // RAISE key
            break;
    }

    return false;  // Don't run default indicators
}
