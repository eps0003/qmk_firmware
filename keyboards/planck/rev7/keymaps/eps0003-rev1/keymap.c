#include QMK_KEYBOARD_H

enum layers { DEF, NUM, NAV, SCR, TXT, SYM, ADJ };

enum tap_dance { TD_PLAY_NEXT, TD_MUTE_PREV };

// layers
#define LA_NUM MO(NUM)
#define LA_NAV MO(NAV)
#define LA_SCR MO(SCR)
#define LA_TXT MO(TXT)
#define LA_SYM MO(SYM)
#define LA_ADJ MO(ADJ)

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

// media keys
#define KC_MLFT TD(TD_MUTE_PREV)
#define KC_MRGT TD(TD_PLAY_NEXT)

// shortcuts
#define TAB_L G(S(KC_LEFT))
#define TAB_R G(S(KC_RIGHT))

/* clang-format off */
tap_dance_action_t tap_dance_actions[] = {
    [TD_PLAY_NEXT] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
    [TD_MUTE_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MPRV)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEF] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  MOD_A,   MOD_S,   MOD_D,   MOD_F,   KC_G,    KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SCL, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, LA_SYM,  LA_NUM,  KC_SPC,  KC_BSPC, LA_NAV,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [NUM] = LAYOUT_planck_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  MOD_1,   MOD_2,   MOD_3,   MOD_4,   KC_5,    KC_6,    MOD_7,   MOD_8,   MOD_9,   MOD_0,   XXXXXXX,
        KC_CAPS, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, _______,
        _______, _______, _______, _______, _______, _______, KC_DEL,  _______, KC_MLFT, KC_VOLD, KC_VOLU, KC_MRGT
    ),

    [NAV] = LAYOUT_planck_grid(
        _______, _______, KC_BTN4, KC_MS_U, KC_BTN5, _______, _______, _______, _______, _______, _______, _______,
        _______, LA_TXT,  KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, LA_SCR,  _______,
        _______, _______, _______, TAB_L,   TAB_R,   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [SCR] = LAYOUT_planck_grid(
        _______, _______, _______, KC_WH_U, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [TXT] = LAYOUT_planck_grid(
        _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [SYM] = LAYOUT_planck_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Adjust (Lower + Raise)
    *                      v------------------------RGB CONTROL--------------------v
    * ,-----------------------------------------------------------------------------------.
    * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [ADJ] = LAYOUT_planck_grid(
        _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
        _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
        _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )

};
/* clang-format on */

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, NUM, NAV, ADJ);
}
