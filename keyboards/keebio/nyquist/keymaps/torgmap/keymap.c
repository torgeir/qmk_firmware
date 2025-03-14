// Copyright 2025 Torgeir Thoresen (@torgeir)
// SPDX-License-Identifier: GPL-2.0-or-later

// qmk compile -kb keebio/nyquist/rev5 -km torgmap && qmk flash -kb keebio/nyquist/rev5 -km torgmap

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h" // NO_*

// order matters
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUN,
    _ADJUST,
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,               KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   /**/  KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,         KC_BSPC,
  MT(MOD_LCTL, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   /**/  KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN/*ø*/, KC_QUOT/*æ*/,
  OSM(MOD_LSFT),        KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   /**/  KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,      KC_ENT,
  OSM(MOD_HYPR),        KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, /**/  KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,        KC_RGHT
),
[_LOWER] = LAYOUT_ortho_4x12(
  KC_GRV/*'*/, KC_EXLM/*!*/, KC_AT/*"*/,   KC_HASH/*#*/,       KC_DLR/*$*/, KC_PERC/*%*/, /**/  KC_CIRC,         NO_LCBR/*|*/, KC_ASTR/*(*/,       KC_LPRN/*)*/,       LSFT(KC_MINS)/*?*/, LSFT(KC_EQL)/*`*/,
  _______,     _______,      NO_LBRC/*[*/, NO_RBRC/*]*/,       _______,     _______,      /**/  S(NO_LCBR)/*\*/, KC_PSLS/*/*/, LSFT(KC_8)/*(*/,    LSFT(KC_9)/*)*/,    S(KC_RBRC)/*^*/,    KC_PEQL/*=*/,
  _______,     _______,      KC_NUBS/*<*/, LSFT(KC_NUBS)/*>*/, _______,     _______,      /**/  _______,         KC_PLUS/*+*/, LSFT(NO_LBRC)/*{*/, LSFT(NO_RBRC)/*}*/, KC_PMNS/*-*/,       LALT(KC_RBRC)/*~*/,
  _______,     _______,      _______,      _______,            _______,     KC_BSPC,      /**/  KC_BSPC,         _______,      _______,            _______,            _______,            _______
),
[_RAISE] = LAYOUT_ortho_4x12(
  KC_EQL,     KC_1,  KC_2,  KC_3,   KC_4,   KC_5,    /**/ KC_6,         KC_7,    KC_8, KC_9,   KC_0,         KC_LBRC/*å*/,
  S(KC_BSPC), KC_F1, KC_F2, KC_F3,  KC_F4,  KC_PERC, /**/ KC_PSLS/*/*/, KC_4,    KC_5, KC_6,   KC_PAST/***/, KC_PEQL/*=*/,
  _______,    KC_F5, KC_F6, KC_F7,  KC_F8,  _______, /**/ KC_PPLS/*+*/, KC_1,    KC_2, KC_3,   KC_PMNS/*-*/, KC_BSLS/*@*/,
  _______,    KC_F9, KC_F10,KC_F11, KC_F12, KC_BSPC, /**/ KC_BSPC,      _______, KC_0, KC_DOT, KC_COMM,      _______
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
)
};


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
  }
  return true;
}
