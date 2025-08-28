// Copyright 2025 Torgeir Thoresen (@torgeir)
// SPDX-License-Identifier: GPL-2.0-or-later

// apple iso layout, no_nb (norwgian bokmaal)
// qmk compile -kb keebio/nyquist/rev5 -km torgmap && qmk flash -kb keebio/nyquist/rev5 -km torgmap

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h" // NO_*
#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#endif

// TODO not working
/* void keyboard_post_init_user(void) { */
/*     // Set per-key RGB mode (adjust as needed) */
/*     rgb_matrix_mode(RGB_MATRIX_RAINBOW_BEACON); */
/*     // Set underglow to a solid color (e.g., blue) */
/*     rgblight_mode(1); */
/*     rgblight_sethsv(180, 255, 128); // Hue 180 = blue, adjust as needed */
/* } */

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
  MO(_FUN), RGB_RMOD, RGB_HUD, RGB_VAD, RGB_SPD, QK_RBT,  /**/ QK_BOOT, _______, _______, _______, _______, _______
),
[_FUN] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, /**/ _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______
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

static void save_rgb_state(void) {
  if (!layer_override_active) {
    saved_rgb_mode = rgb_matrix_get_mode();
    saved_hsv[0] = rgb_matrix_get_hue();
    saved_hsv[1] = rgb_matrix_get_sat();
    saved_hsv[2] = rgb_matrix_get_val();
    layer_override_active = true;
  }
}

static void restore_rgb_state(void) {
  if (layer_override_active) {
    layer_override_active = false;
    rgb_matrix_sethsv_noeeprom(saved_hsv[0], saved_hsv[1], saved_hsv[2]);
    rgb_matrix_mode_noeeprom(saved_rgb_mode);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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

    // Handle RGB changes - update saved state when they're used
    case RGB_MOD:
    case RGB_RMOD:
    case RGB_HUI:
    case RGB_HUD:
    case RGB_SAI:
    case RGB_SAD:
    case RGB_VAI:
    case RGB_VAD:
    case RGB_TOG:
    case RGB_MODE_PLAIN:
    case RGB_MODE_BREATHE:
    case RGB_MODE_RAINBOW:
    case RGB_MODE_SWIRL:
    case RGB_MODE_SNAKE:
    case RGB_MODE_KNIGHT:
    case RGB_MODE_XMAS:
    case RGB_MODE_GRADIENT:
    case RGB_MODE_RGBTEST:
      if (record->event.pressed && layer_override_active) {
        // Let the RGB change happen first
        bool result = true; // Process the keycode normally

        // Update our saved values with the new RGB settings
        saved_rgb_mode = rgb_matrix_get_mode();
        saved_hsv[0] = rgb_matrix_get_hue();
        saved_hsv[1] = rgb_matrix_get_sat();
        saved_hsv[2] = rgb_matrix_get_val();

        return result;
      }
    break;
  }

  return true;
}

static void set_layer_color(uint8_t layer) {
  save_rgb_state();

  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  switch(layer) {
    case _LOWER:
      rgb_matrix_sethsv_noeeprom(HSV_BLUE);    // Blue for LOWER
      break;
    case _RAISE:
      rgb_matrix_sethsv_noeeprom(HSV_GREEN);   // Green for RAISE
      break;
    case _ADJUST:
      rgb_matrix_sethsv_noeeprom(HSV_RED);     // Red for ADJUST
      break;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  if (layer_state_cmp(state, _ADJUST)) {
    set_layer_color(_ADJUST);
  } else if (layer_state_cmp(state, _RAISE)) {
    set_layer_color(_RAISE);
  } else if (layer_state_cmp(state, _LOWER)) {
    set_layer_color(_LOWER);
  } else {
    restore_rgb_state();
  }
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
