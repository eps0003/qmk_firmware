#include QMK_KEYBOARD_H

enum layers { DEF, NUM, TXT, MSE, SCR };

// layers
#define LA_NUML LT(NUM, KC_SPC)
#define LA_NUMR LT(NUM, KC_BSPC)
#define LA_MSE LT(MSE, KC_DEL)
#define LA_TXT LT(TXT, KC_TAB)
#define LA_SCR MO(SCR)

// mod-tap keys
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

#define MOD_SFT LSFT_T(KC_CAPS)

// shortcuts
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
        MOD_SFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_ENT,  LA_TXT,  LA_NUML, LA_NUMR, LA_MSE,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    [NUM] = LAYOUT_planck_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  MOD_1,   MOD_2,   MOD_3,   MOD_4,   KC_5,    KC_6,    MOD_7,   MOD_8,   MOD_9,   MOD_0,   KC_BSLS,
        MOD_SFT, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

    [MSE] = LAYOUT_planck_grid(
        QK_BOOT, XXXXXXX, XXXXXXX, KC_MS_U, SCR_TOP, XXXXXXX, XXXXXXX, TAB_PRV, TAB_1,   TAB_NXT, XXXXXXX, XXXXXXX,
        KC_ESC,  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, LA_SCR,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SCR_BOT, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [SCR] = LAYOUT_planck_grid(
        QK_BOOT, XXXXXXX, XXXXXXX, KC_WH_U, KC_PGUP, XXXXXXX, XXXXXXX, TAB_PRV, TAB_1,   TAB_NXT, XXXXXXX, XXXXXXX,
        KC_ESC,  XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, LA_SCR,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [TXT] = LAYOUT_planck_grid(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_INS,  KC_PSCR, KC_BSPC,
        KC_ESC,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX,
        MOD_SFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

};
/* clang-format on */

bool is_shift_active(void) {
    return keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
}

bool is_caps_lock_active(void) {
    return host_keyboard_led_state().caps_lock;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Disable caps lock if shift is pressed
    if (is_shift_active() && is_caps_lock_active()) {
        tap_code(KC_CAPS);
    }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Hold shift if used quickly
        case MOD_SFT:
            return true;
        default:
            return false;
    }
}
