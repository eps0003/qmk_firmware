#include QMK_KEYBOARD_H

#include "oneshot.h"

// layers
#define LA_ACT MO(ACT)
#define LA_SYM MO(SYM)

// Shortcuts
#define KC_BTAB S(KC_TAB)

enum layers { ABC, ACT, SYM };

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // [ABC] = LAYOUT_planck_grid(
    //     XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, XXXXXXX,
    //     XXXXXXX, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    XXXXXXX,
    //     XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SCLN, XXXXXXX,
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LA_ACT,  KC_SPC,  KC_RSFT, LA_SYM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    // ),

    [ABC] = LAYOUT_planck_grid(
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
        XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LA_ACT,  KC_SPC,  KC_RSFT, LA_SYM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [ACT] = LAYOUT_planck_grid(
        XXXXXXX, QK_BOOT, CW_TOGG, KC_BTN4, KC_BTN5, KC_PGUP, XXXXXXX, KC_BTAB, KC_UP,   KC_TAB,  XXXXXXX, XXXXXXX,
        XXXXXXX, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, KC_PGDN, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_ENT,  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [SYM] = LAYOUT_planck_grid(
        XXXXXXX, KC_BSLS, KC_1,    KC_2,    KC_3,    KC_SLSH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
        XXXXXXX, KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC, XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXXXXX,
        XXXXXXX, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_DOT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  KC_MINS, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

};
/* clang-format on */

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_ACT:
        case LA_SYM:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LA_ACT:
        case LA_SYM:
        case KC_LSFT:
        case KC_RSFT:
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
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

    return true;
}
