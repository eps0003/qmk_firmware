#include QMK_KEYBOARD_H

enum layers { DEF, NUM, MSE, SCR, TXT };

// layers
#define LA_NUML LT(NUM, KC_TAB)
#define LA_NUMR LT(NUM, KC_ENT)
#define LA_MSE LT(MSE, KC_BSPC)
#define LA_MSE2 LT(MSE, KC_DEL)
#define LA_TXT LT(TXT, KC_SPC)
#define LA_SCR MO(SCR)

// home row mods
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

// shortcuts
#define SCR_TOP C(KC_HOME)
#define SCR_BOT C(KC_END)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEF] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  MOD_A,   MOD_S,   MOD_D,   MOD_F,   KC_G,    KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SCL, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,  LA_TXT,  LA_NUML, LA_NUMR, LA_MSE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [NUM] = LAYOUT_planck_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  MOD_1,   MOD_2,   MOD_3,   MOD_4,   KC_5,    KC_6,    MOD_7,   MOD_8,   MOD_9,   MOD_0,   KC_BSLS,
        KC_CAPS, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MRWD, KC_MFFD, KC_MNXT
    ),

    [MSE] = LAYOUT_planck_grid(
        QK_BOOT, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, LA_SCR,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [SCR] = LAYOUT_planck_grid(
        QK_BOOT, XXXXXXX, SCR_TOP, KC_WH_U, SCR_BOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, LA_SCR,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [TXT] = LAYOUT_planck_grid(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, KC_INS,  XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______, _______, LA_MSE2, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
    ),

};
/* clang-format on */
