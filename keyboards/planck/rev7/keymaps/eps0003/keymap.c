#include QMK_KEYBOARD_H
#include "print.h"

enum layers { DEF, TXT, MSE, NUM };

enum keycodes {
    KC_DDS = SAFE_RANGE, // KC_DOT_DOT_SLASH
};

// Layers
#define LA_MSE LT(MSE, KC_DEL)
#define LA_TXT LT(TXT, KC_TAB)

// Mod-Tap keys
#define MOD_A LGUI_T(KC_A)
#define MOD_S LALT_T(KC_S)
#define MOD_D LCTL_T(KC_D)
#define MOD_F LSFT_T(KC_F)

#define MOD_J RSFT_T(KC_J)
#define MOD_K RCTL_T(KC_K)
#define MOD_L RALT_T(KC_L)
#define MOD_SCL RGUI_T(KC_SCLN)

#define MOD_1 LGUI_T(KC_1)
#define MOD_2 LALT_T(KC_2)
#define MOD_3 LCTL_T(KC_3)
#define MOD_4 LSFT_T(KC_4)

#define MOD_7 RSFT_T(KC_7)
#define MOD_8 RCTL_T(KC_8)
#define MOD_9 RALT_T(KC_9)
#define MOD_0 RGUI_T(KC_0)

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
        KC_ESC,  MOD_A,   MOD_S,   MOD_D,   MOD_F,   KC_G,    KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SCL, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_ENT,  LA_TXT,  KC_SPC,  KC_BSPC, LA_MSE,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    [NUM] = LAYOUT_planck_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  MOD_1,   MOD_2,   MOD_3,   MOD_4,   KC_5,    KC_6,    MOD_7,   MOD_8,   MOD_9,   MOD_0,   KC_BSLS,
        KC_CAPS, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
    ),

    [MSE] = LAYOUT_planck_grid(
        QK_BOOT, XXXXXXX, XXXXXXX, KC_MS_U, KC_WH_U, SCR_TOP, XXXXXXX, TAB_PRV, TAB_1,   TAB_NXT, XXXXXXX, XXXXXXX,
        KC_ESC,  KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN5, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, SCR_BOT, XXXXXXX, KC_BTN4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [TXT] = LAYOUT_planck_grid(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_INS,  KC_PSCR, KC_BSPC,
        KC_ESC,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

};
/* clang-format on */

bool is_mod_tap_key(uint16_t keycode) {
    return keycode & QK_MOD_TAP;
}

bool is_shift_active(void) {
    return get_mods() & MOD_MASK_SHIFT;
}

bool is_shift_key(uint16_t keycode) {
    return keycode == KC_LSFT || keycode == KC_RSFT;
}

bool is_shift_pressed(uint16_t keycode, keyrecord_t *record) {
    return (is_shift_key(keycode) || (is_mod_tap_key(keycode) && QK_MOD_TAP_GET_MODS(keycode) & MOD_MASK_SHIFT)) && record->event.pressed && record->tap.count == 0;
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

    // // Disable caps lock if shift is pressed
    // if (is_shift_pressed(keycode, record) && is_caps_lock_active()) {
    //     tap_code(KC_CAPS);
    // }

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

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LA_TXT:
        case LA_MSE:
            return true;
        default:
            return false;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LA_TXT:
        case LA_MSE:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    uint8_t col = record->event.key.col;
    if (record->event.key.row < MATRIX_ROWS / 2) {
        col = MATRIX_COLS - col - 1;
    }

    return TAPPING_TERM + MAX(0, 25 * (col - 1));
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, TXT, MSE, NUM);
}
