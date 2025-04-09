#include QMK_KEYBOARD_H

/* ============================== */
/* ========== FEATURES ========== */
/* ============================== */

#include "features/achordion.h"

/* =============================== */
/* ========== CONSTANTS ========== */
/* =============================== */

// Layers
#define LA_COL TG(COL)
#define LA_NUM MO(NUM)
#define LA_NAV MO(NAV)
#define LA_FUN MO(FUN)
#define LA_MSE MO(MSE)

// QWERTY mod-tap keys
#define MT_A LGUI_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LCTL_T(KC_D)
#define MT_F LSFT_T(KC_F)

#define MT_J RSFT_T(KC_J)
#define MT_K RCTL_T(KC_K)
#define MT_L RALT_T(KC_L)
#define MT_SCLN RGUI_T(KC_SCLN)

// Colemak-DH mod-tap keys
#define MT2_A LGUI_T(KC_A)
#define MT2_R LALT_T(KC_R)
#define MT2_S LCTL_T(KC_S)
#define MT2_T LSFT_T(KC_T)

#define MT2_N RSFT_T(KC_N)
#define MT2_E RCTL_T(KC_E)
#define MT2_I RALT_T(KC_I)
#define MT2_O RGUI_T(KC_O)

// Symbol mod-tap keys
#define MT_EXLM LGUI_T(KC_EXLM)
#define MT_MINS LALT_T(KC_MINS)
#define MT_PLUS LCTL_T(KC_PLUS)
#define MT_EQL LSFT_T(KC_EQL)

#define MT_AMPR RSFT_T(KC_AMPR)
#define MT_LPRN RCTL_T(KC_LPRN)
#define MT_RPRN RALT_T(KC_RPRN)
#define MT_QUES RGUI_T(KC_QUES)

// Oneshot keys
#define OS_SHFT OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)

// Shortcut keys
#define SCR_TOP C(KC_HOME)
#define SCR_BOT C(KC_END)

#define KC_BTAB S(KC_TAB)

#define TAB_NXT C(KC_PGDN)
#define TAB_PRV C(KC_PGUP)
#define TAB_1 C(KC_1)

/* =========================== */
/* ========== ENUMS ========== */
/* =========================== */

enum layers { QWE, COL, NUM, FUN, NAV, MSE, SYM };

enum keycodes {
    // Macros
    KC_DDS = SAFE_RANGE, // KC_DOT_DOT_SLASH
};

/* ============================ */
/* ========== KEYMAP ========== */
/* ============================ */

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWE] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, LA_MSE,  LA_NAV,  KC_SPC,  KC_BSPC, LA_NUM,  LA_FUN,  LA_NAV,  LA_COL,  XXXXXXX
    ),

    [COL] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_ESC,  MT2_A,   MT2_R,   MT2_S,   MT2_T,   KC_G,    KC_M,    MT2_N,   MT2_E,   MT2_I,   MT2_O,   KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [NUM] = LAYOUT_planck_grid(
        KC_TAB,  XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, KC_BSPC,
        KC_ESC,  KC_0,    KC_1,    KC_2,    KC_3,    KC_0,    XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  XXXXXXX,
        CW_TOGG, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_GRV,  XXXXXXX, KC_DOT,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        _______, _______, _______, _______, _______, KC_MINS, _______, _______, _______, _______, _______, _______
    ),

    [FUN] = LAYOUT_planck_grid(
        KC_TAB,  KC_F10,  KC_F4,   KC_F5,   KC_F6,   KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, KC_BSPC,
        KC_ESC,  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F11,  XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  XXXXXXX,
        KC_CAPS, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_planck_grid(
        KC_TAB,  QK_BOOT, KC_INS,  KC_BTN4, KC_BTN5, XXXXXXX, XXXXXXX, KC_BTAB, KC_UP,   KC_TAB,  XXXXXXX, KC_DEL,
        KC_ESC,  OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PSCR,
        KC_LSFT, XXXXXXX, TAB_1,   TAB_PRV, TAB_NXT, XXXXXXX, KC_PGDN, KC_HOME, KC_WH_D, KC_WH_U, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, _______, _______
    ),

    [MSE] = LAYOUT_planck_grid(
        KC_TAB,  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_MS_U, KC_BTN5, XXXXXXX, KC_DEL,
        KC_ESC,  OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT, XXXXXXX, SCR_TOP, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
        KC_LSFT, XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, XXXXXXX, SCR_BOT, KC_WH_D, KC_WH_U, KC_WH_U, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______
    ),

    [SYM] = LAYOUT_planck_grid(
        KC_TAB,  XXXXXXX, KC_LABK, KC_RABK, KC_HASH, KC_DDS,  KC_CIRC, KC_PIPE, KC_LBRC, KC_RBRC, XXXXXXX, KC_BSPC,
        KC_ESC,  MT_EXLM, MT_MINS, MT_PLUS, MT_EQL,  KC_PERC, KC_GRV,  MT_AMPR, MT_LPRN, MT_RPRN, MT_QUES, XXXXXXX,
        KC_LSFT, KC_DDS,  KC_BSLS, KC_ASTR, KC_SLSH, KC_AT,   KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_CIRC, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

};
/* clang-format on */

/* ======================================= */
/* ========== UTILITY FUNCTIONS ========== */
/* ======================================= */

uint16_t get_modtap_keycode(uint16_t keycode) {
    // Mod-tap is limited to the basic keycode set. The mod-tap keys defined
    // below are those that are not in the basic keycode set. See:
    // https://docs.qmk.fm/mod_tap#caveats

    switch (keycode) {
        case MT_EXLM:
            return KC_EXLM;
        case MT_PLUS:
            return KC_PLUS;
        case MT_AMPR:
            return KC_AMPR;
        case MT_LPRN:
            return KC_LPRN;
        case MT_RPRN:
            return KC_RPRN;
        case MT_QUES:
            return KC_QUES;
        default:
            return KC_NO;
    }
}

/* ====================================== */
/* ========== PROCESSING STEPS ========== */
/* ====================================== */

bool process_modtap(uint16_t keycode, keyrecord_t *record) {
    uint16_t modtap_keycode = get_modtap_keycode(keycode);

    if (modtap_keycode && record->tap.count) {
        if (record->event.pressed) {
            register_code16(modtap_keycode);
        } else {
            unregister_code16(modtap_keycode);
        }
        return false;
    }

    return true;
}

bool process_macros(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_DDS:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                clear_mods();
                SEND_STRING("../");
                set_mods(mods);
            }
            break;
    }

    return true;
}

bool process_misc(uint16_t keycode, keyrecord_t *record) {
    // Cancel oneshot mods when activating a layer
    if (record->event.pressed && IS_QK_MOMENTARY(keycode)) {
        clear_oneshot_mods();
    }

    switch (keycode) {
        // QWERTY shift mod-tap keys
        case MT_F:
        case MT_J:
        // Colemak-DH shift mod-tap keys
        case MT2_T:
        case MT2_N:
            // Enable caps word if both mod shift keys are pressed
            if (record->event.pressed && !record->tap.count && get_mods() & MOD_MASK_SHIFT) {
                caps_word_on();
                return false;
            }
            break;
    }

    return true;
}

/* ===================================== */
/* ========== CORE PROCESSING ========== */
/* ===================================== */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    if (!process_achordion(keycode, record)) {
        return false;
    }

    if (!process_modtap(keycode, record)) {
        return false;
    }

    if (!process_macros(keycode, record)) {
        return false;
    }

    if (!process_misc(keycode, record)) {
        return false;
    }

    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

/* =============================== */
/* ========== ACHORDION ========== */
/* =============================== */

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Disable default bilateral combinations behaviour
    return true;
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    // No timeout for shift and ctrl mod-tap keys
    if (QK_MOD_TAP_GET_MODS(tap_hold_keycode) & (MOD_LSFT | MOD_LCTL)) {
        return 0;
    }

    // No timeout for layer keys
    if (IS_QK_MOMENTARY(next_keycode)) {
        return 0;
    }

    // Default timeout
    return 200;
}

/* ======================================= */
/* ========== TAPPING & HOLDING ========== */
/* ======================================= */

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // Increase tapping term for outer columns because fingers are less dexterous
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
        // QWERTY pinky mod-tap keys
        case MT_A:
        case MT_SCLN:
        // Colemak pinky mod-tap keys
        // case MT2_A: // Duplicate of MT_A
        case MT2_O:
        // Symbol pinky mod-tap keys
        case MT_EXLM:
        case MT_QUES:
            return false;

        // Disable permissive hold for oneshot keys so they can be tapped
        // simultaneously
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
            return false;
    }

    return true;
}

/* ===================================== */
/* ========== STATE CALLBACKS ========== */
/* ===================================== */

layer_state_t layer_state_set_user(layer_state_t state) {
    // Disable caps word when switching to navigation-related layers
    if (IS_LAYER_ON_STATE(state, NAV) || IS_LAYER_ON_STATE(state, MSE)) {
        caps_word_off();
    }

    return update_tri_layer_state(state, NAV, NUM, SYM);
}

void caps_word_set_user(bool active) {
    // Disable caps lock when caps word is enabled
    if (active && host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}
