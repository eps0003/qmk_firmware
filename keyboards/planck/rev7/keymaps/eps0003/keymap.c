#include QMK_KEYBOARD_H

#include "print.h"
#include "oneshot.h"

// Layers
#define LA_NUM MO(NUM)
#define LA_NAV MO(NAV)

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

#define KC_BTAB S(KC_TAB)

#define TAB_NXT C(KC_PGDN)
#define TAB_PRV C(KC_PGUP)
#define TAB_1 C(KC_1)

enum layers { DEF, NUM, NAV };

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t space_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_UNDS);
const key_override_t next_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_MPLY, KC_MNXT, ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);
const key_override_t prev_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_MPLY, KC_MPRV, ~0, MOD_MASK_ALT, ko_option_no_reregister_trigger);

/* clang-format off */
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &space_key_override,
    &next_track_override,
    &prev_track_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEF] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  MOD_A,   MOD_S,   MOD_D,   MOD_F,   KC_G,    KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SCL, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LCMD, KC_LALT, QK_REP,  LA_NAV,  KC_SPC,  KC_BSPC, LA_NUM,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    [NUM] = LAYOUT_planck_grid(
        KC_TAB,  KC_BSLS, KC_1,    KC_2,    KC_3,    KC_SLSH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, KC_BSPC,
        KC_ESC,  KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC, XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXXXXX,
        CW_TOGG, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_DOT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, KC_EQL,  KC_MINS, _______, _______, _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_planck_grid(
        KC_TAB,  QK_BOOT, XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX, KC_PGUP, KC_BTAB, KC_UP,   KC_TAB,  KC_INS,  KC_BSPC,
        KC_ESC,  OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_PSCR,
        CW_TOGG, XXXXXXX, TAB_1,   TAB_PRV, TAB_NXT, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, _______, KC_ENT,  KC_ESC,  _______, _______, _______, _______
    ),

};
/* clang-format on */

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_NAV:
        case LA_NUM:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        // Layers
        case LA_NAV:
        case LA_NUM:
        // Left modifiers
        case KC_LSFT:
        case KC_LCTL:
        case KC_LALT:
        case KC_LCMD:
        // Right modifiers
        case KC_RSFT:
        case KC_RCTL:
        case KC_RALT:
        case KC_RCMD:
        // One-shot modifiers
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    uint8_t col = record->event.key.col;
    if (record->event.key.row < MATRIX_ROWS / 2) {
        col = MATRIX_COLS - col - 1;
    }

    return TAPPING_TERM + MAX(0, 25 * (col - 1));
}
