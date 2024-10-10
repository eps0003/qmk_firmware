#include QMK_KEYBOARD_H

#include "print.h"

#include "features/achordion.h"
#include "features/oneshot.h"

// Layers
#define LA_COL TG(COL)
#define LA_NUM MO(NUM)
#define LA_NAV MO(NAV)
#define LA_FUN MO(FUN)
#define LA_MSE MO(MSE)

// Colemak-DH mod-tap keys
#define MT_A LGUI_T(KC_A)
#define MT_R LALT_T(KC_R)
#define MT_S LCTL_T(KC_S)
#define MT_T LSFT_T(KC_T)

#define MT_N RSFT_T(KC_N)
#define MT_E RCTL_T(KC_E)
#define MT_I RALT_T(KC_I)
#define MT_O RGUI_T(KC_O)

// QWERTY mod-tap keys
#define MT_A LGUI_T(KC_A)
#define MT_S2 LALT_T(KC_S)
#define MT_D LCTL_T(KC_D)
#define MT_F LSFT_T(KC_F)

#define MT_J RSFT_T(KC_J)
#define MT_K RCTL_T(KC_K)
#define MT_L RALT_T(KC_L)
#define MT_SCL RGUI_T(KC_SCLN)

// Symbols mod-tap keys
#define MT_EXLM LGUI_T(KC_EXLM)
#define MT_MINS LALT_T(KC_MINS)
#define MT_PLUS LCTL_T(KC_PLUS)
#define MT_EQL LSFT_T(KC_EQL)

#define MT_AMPR RSFT_T(KC_AMPR)
#define MT_LPRN RCTL_T(KC_LPRN)
#define MT_RPRN RALT_T(KC_RPRN)
#define MT_QUES RGUI_T(KC_QUES)

// Shortcut keys
#define SCR_TOP C(KC_HOME)
#define SCR_BOT C(KC_END)

#define KC_BTAB S(KC_TAB)

#define TAB_NXT C(KC_PGDN)
#define TAB_PRV C(KC_PGUP)
#define TAB_1 C(KC_1)

enum layers { QWE, COL, NUM, FUN, NAV, MSE, SYM };

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    // Macros
    KC_DDS, // KC_DOT_DOT_SLASH
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

/* clang-format off */
const key_override_t *key_overrides[] = {
    &delete_key_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWE] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  MT_A,    MT_S2,   MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_SCL,  KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LCMD, KC_LALT, LA_MSE,  LA_NAV,  KC_SPC,  KC_BSPC, LA_NUM,  LA_FUN,  LA_NAV,  LA_COL,  XXXXXXX
    ),

    [COL] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_ESC,  MT_A,    MT_R,    MT_S,    MT_T,    KC_G,    KC_M,    MT_N,    MT_E,    MT_I,    MT_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [NUM] = LAYOUT_planck_grid(
        KC_TAB,  XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, KC_BSPC,
        KC_ESC,  KC_0,    KC_1,    KC_2,    KC_3,    KC_0,    XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXXXXX,
        CW_TOGG, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_GRV,  XXXXXXX, KC_DOT,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        _______, _______, _______, _______, _______, KC_MINS, _______, _______, _______, _______, _______, _______
    ),

    [FUN] = LAYOUT_planck_grid(
        KC_TAB,  KC_F10,  KC_F4,   KC_F5,   KC_F6,   KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, KC_BSPC,
        KC_ESC,  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F11,  XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXXXXX,
        KC_CAPS, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_planck_grid(
        KC_TAB,  QK_BOOT, XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX, XXXXXXX, KC_BTAB, KC_UP,   KC_TAB,  KC_INS,  KC_DEL,
        KC_ESC,  OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PSCR,
        KC_LSFT, XXXXXXX, TAB_1,   TAB_PRV, TAB_NXT, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, KC_PGUP, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, _______, _______
    ),

    [MSE] = LAYOUT_planck_grid(
        KC_TAB,  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SCR_TOP, KC_MS_U, SCR_BOT, XXXXXXX, KC_DEL,
        KC_ESC,  OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, XXXXXXX, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, XXXXXXX,
        KC_LSFT, XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, KC_WH_U, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______
    ),

    [SYM] = LAYOUT_planck_grid(
        KC_TAB,  XXXXXXX, KC_LABK, KC_RABK, KC_HASH, KC_DDS,  KC_CIRC, KC_PIPE, KC_LBRC, KC_RBRC, XXXXXXX, KC_BSPC,
        KC_ESC,  MT_EXLM, MT_MINS, MT_PLUS, MT_EQL,  KC_PERC, KC_GRV,  MT_AMPR, MT_LPRN, MT_RPRN, MT_QUES, XXXXXXX,
        KC_LSFT, KC_DDS,  KC_SLSH, KC_ASTR, KC_AT,   KC_BSLS, KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_CIRC, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

};
/* clang-format on */

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_NUM:
        case LA_NAV:
        case LA_FUN:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        // Layers
        case LA_NUM:
        case LA_NAV:
        case LA_FUN:
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

    if (!process_achordion(keycode, record)) {
        return false;
    }

    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

    uint16_t kc = KC_NO;
    switch (keycode) {
        case KC_DDS:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                clear_mods();
                SEND_STRING("../");
                set_mods(mods);
            }
            break;

        case MT_T:
        case MT_F:
        case MT_N:
        case MT_J:
            // Enable caps word if both mod shift keys are pressed
            if (record->event.pressed && !record->tap.count && get_mods() & MOD_MASK_SHIFT) {
                caps_word_on();
                return false;
            }
            break;

        case MT_EXLM:
            kc = KC_EXLM;
            break;
        case MT_PLUS:
            kc = KC_PLUS;
            break;
        case MT_AMPR:
            kc = KC_AMPR;
            break;
        case MT_LPRN:
            kc = KC_LPRN;
            break;
        case MT_RPRN:
            kc = KC_RPRN;
            break;
        case MT_QUES:
            kc = KC_QUES;
            break;

        case KC_ESC:
            // Disable caps lock if enabled
            if (record->event.pressed && host_keyboard_led_state().caps_lock) {
                tap_code(KC_CAPS);
                return false;
            }
            break;
    }

    if (record->tap.count && kc) {
        if (record->event.pressed) {
            register_code16(kc);
        } else {
            unregister_code16(kc);
        }
        return false;
    }

    return true;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Consider these chords as holds, even though they are on the same hand
    switch (tap_hold_keycode) {
        case MT_D: // Left ctrl (QWERTY)
        case MT_S: // Left ctrl (Colemak)
            switch (other_keycode) {
                case KC_Z: // Undo
                case KC_X: // Cut
                case KC_C: // Copy
                case KC_V: // Paste
                    return true;
            }
            break;
    }

    // Also allow same-hand holds when the other key is in the bottom row
    if (other_record->event.key.row % (MATRIX_ROWS / 2) == 3) {
        return true;
    }

    // Otherwise, follow the opposite hands rule
    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    // No timeout for shift mod-tap
    uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
    if ((mod & MOD_LSFT) != 0) {
        return 0;
    }

    // Default timeout
    return 200;
}

void matrix_scan_user(void) {
    achordion_task();
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    uint8_t col = record->event.key.col;
    if (record->event.key.row < MATRIX_ROWS / 2) {
        col = MATRIX_COLS - col - 1;
    }

    return TAPPING_TERM + MAX(0, 20 * (col - 2));
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Disable permissive hold for pinkie mod-tap keys to prevent accidental
    // triggers. Pinkies tend to stay pressed for longer due to their reduced
    // dexterity, enabling another key to be pressed and released within the
    // tapping term. For example, trying to type the common bigram 'al' on
    // QWERTY with permissive hold frequently triggers LGUI+L which locks the
    // computer. >:(
    switch (keycode) {
        case MT_A:    // QWE/COL layers
        case MT_SCL:  // QWE layer
        case MT_O:    // COL layer
        case MT_EXLM: // SYM layer
        case MT_QUES: // SYM layer
            return false;
        default:
            return true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, NAV) || IS_LAYER_ON_STATE(state, MSE)) {
        caps_word_off();
    }

    return update_tri_layer_state(state, NAV, NUM, SYM);
}

void caps_word_set_user(bool active) {
    if (active && host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}
