#include QMK_KEYBOARD_H
#include "print.h"

enum layers { DEF, SYM, NAV, NUM };

enum keycodes {
    KC_DDS = SAFE_RANGE, // KC_DOT_DOT_SLASH
};

// Layers
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

// Shortcuts
#define SCR_TOP C(KC_HOME)
#define SCR_BOT C(KC_END)

#define TAB_NXT C(KC_PGDN)
#define TAB_PRV C(KC_PGUP)
#define TAB_1 C(KC_1)

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t next_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_MPLY, KC_MNXT, ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);
const key_override_t prev_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_MPLY, KC_MPRV, ~0, MOD_MASK_ALT, ko_option_no_reregister_trigger);

/* clang-format off */
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &next_track_override,
    &prev_track_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEF] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_ENT,  LA_NAV,  KC_SPC,  KC_RSFT, LA_SYM,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    [SYM] = LAYOUT_planck_grid(
        KC_BSLS, KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_AMPR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        KC_GRV,  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_ASTR, XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
        CW_TOGG, KC_PERC, KC_PERC, KC_LCBR, KC_RCBR, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______, _______, KC_MINS, _______, _______, _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_planck_grid(
        QK_BOOT, XXXXXXX, TAB_1,   TAB_PRV, TAB_NXT, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_INS,  KC_PSCR, KC_BSPC,
        KC_ESC,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [NUM] = LAYOUT_planck_grid(
        KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_ESC,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_F11,  KC_F12,  KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
        KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

};
/* clang-format on */

bool is_shift_active(void) {
    return get_mods() & MOD_MASK_SHIFT;
}

bool is_caps_lock_active(void) {
    return host_keyboard_led_state().caps_lock;
}

bool is_alpha_key(uint16_t keycode) {
    return keycode >= KC_A && keycode <= KC_Z;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    // Stay uppercase when caps lock and shift are active
    if (is_caps_lock_active() && is_shift_active() && is_alpha_key(keycode)) {
        unregister_mods(MOD_MASK_SHIFT);
    }

    switch (keycode) {
        case KC_DDS:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            break;
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
