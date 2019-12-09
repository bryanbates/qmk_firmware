#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define UNI 3  // unicode 1
#define UNI2 4 // unicode 2

enum macros {
  RUN
};

enum function_ids {
  EMOJI,
  EMOJI2,
  EPRM,
  VRSN,
  RGB_SLD,
  RGB_STEP_REV,
  UC_MODE_OSX,
  UC_MODE_LNX,
};

/* opt can only be 0-15 */
enum emojis {
  SHRUG,
  YAY,
  HUG,
  SMILE,
  SMILE2,
  HMM1,
  HMM2,
  BEAR1,
  BEAR2,
  FUU,
  EGGY1,
  EGGY2,
  FACE1,
  FACE2,
  UHU,
  SMRK1
};

enum emojis2 {
  SMRK2,
  LOVE,
  HAPPY1,
  HAPPY2,
  HAPPY3,
  SING1,
  SING2,
  TABLE1,
  TABLE2,
  TABLE3,
  CONFUSED1,
};

enum progmem_ids {
  EMOJI_SHRUG,
  EMOJI_YAY,
  EMOJI_HUG,
  EMOJI_SMILE,
  EMOJI_SMILE2,
  EMOJI_HMM1,
  EMOJI_HMM2,
  EMOJI_BEAR1,
  EMOJI_BEAR2,
  EMOJI_FUU,
  EMOJI_EGGY1,
  EMOJI_EGGY2,
  EMOJI_FACE1,
  EMOJI_FACE2,
  EMOJI_UHU,
  EMOJI_SMRK1,
  EMOJI_SMRK2,
  EMOJI_LOVE,
  EMOJI_HAPPY1,
  EMOJI_HAPPY2,
  EMOJI_HAPPY3,
  EMOJI_SING1,
  EMOJI_SING2,
  EMOJI_TABLE1,
  EMOJI_TABLE2,
  EMOJI_TABLE3,
  EMOJI_CONFUSED1,
  F_EPRM,
  F_VRSN,
  F_RGB_SLD,
  F_RGB_STEP_REV,
  F_UC_MODE_OSX,
  F_UC_MODE_LNX,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Grv/L3 |   1  |   2  |   3  |   4  |   5  |  6   |           |  5   |   6  |   7  |   8  |   9  |   0  |  =/L3  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   '  |   ,  |   .  |   P  |   Y  |  [   |           |   ]  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | Ctrl/- |
 * |--------+------+------+------+------+------|  ~   |           |   \  |------+------+------+------+------+--------|
 * | LShift |   :  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L1  | LAlt |  Left| Right| LCmd |                                       | LCmd | Up   | Down | RCtrl|  ~L2 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  | Esc  |       | App  | Esc  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  _   |       | ~L1  |        |      |
 *                                 | Space|Backsp|------|       |------|  LAlt  |Enter |
 *                                 |      |ace   |  _   |       | Ctrl |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        LT(UNI, KC_GRV),         KC_1,        KC_2,    KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,         KC_QUOT,     KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_LBRC,
        CTL_T(KC_ESC),       KC_A,        KC_O,    KC_E,   KC_U,   KC_I,
        KC_LSPO,        KC_SCLN,     KC_Q,    KC_J,   KC_K,   KC_X,   KC_TILD,
        MO(SYMB),       KC_LALT,   KC_LEFT,KC_RGHT,KC_LGUI,
                                                      KC_DELT,KC_ESC,
                                                              KC_UNDS,
                                               KC_SPC,KC_BSPC,KC_UNDS,
        // right hand
             KC_5,         KC_6,   KC_7,   KC_8,   KC_9,   KC_0,            LT(UNI2, KC_EQL),
             KC_RBRC,      KC_F,   KC_G,   KC_C,   KC_R,   KC_L,            KC_SLSH,
                           KC_D,   KC_H,   KC_T,   KC_N,   KC_S,            CTL_T(KC_MINS),
             KC_BSLS,      KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,            KC_RSPC,
                                  KC_LGUI,KC_UP,  KC_DOWN,KC_RCTRL,         MO(MDIA),
             KC_APP,      KC_ESC,
             MO(SYMB),
             KC_RCTRL,     KC_LALT, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   +  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |    0 |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Del | Ins  |       | PgUp | PgDn |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | End  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_DELT,KC_INS,
                                               KC_HOME,
                               KC_TRNS,KC_TRNS,KC_END,
       // right hand
       KC_F5,   KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_KP_7,   KC_KP_8,    KC_KP_9,    KC_KP_ASTERISK, KC_F12,
                KC_DOWN, KC_KP_4,   KC_KP_5,    KC_KP_6,    KC_KP_MINUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_KP_1,   KC_KP_2,    KC_KP_3,    KC_KP_PLUS, KC_TRNS,
                         KC_KP_0,   KC_KP_0,    KC_KP_DOT,  KC_EQL,  KC_TRNS,
       KC_PGUP, KC_PGDN,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_KP_ENTER
),
/* Keymap 2: Media and mouse and RGB (shine) keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  Up  |      |      |      |           |      |MsAcl2|      | MsUp |      |MsWhUp|  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Rght |      |------|           |------|MsAcl1|MsLeft|MsDown|MsRght|MsWhDn|  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |MsAcl0| Prev | Rew  | FFwd | Next |  Stop  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |      |VolUp |VolDn | Mute |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Toggle|Animat|       | Ani- | Ani+ |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|Solid |       |      |      |      |
 *                                 |ness- |ness+ |------|       |------| Hue- | Hue+ |
 *                                 |      |      |      |       | EPRM |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP  , KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                       RGB_TOG,RGB_MOD,
                                       F(F_RGB_SLD),
                               RGB_VAD,RGB_VAI,KC_TRNS,
    // right hand
       KC_F5,    KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS,  KC_ACL2, KC_TRNS, KC_MS_U, KC_TRNS, KC_WH_U, KC_F12,
                 KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_MPLY,
       KC_TRNS,  KC_ACL0, KC_MPRV, KC_MRWD, KC_MFFD, KC_MNXT, KC_MSTP,
                          KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS,
       F(F_RGB_STEP_REV), RGB_MOD,
       KC_TRNS,
       F(F_EPRM), RGB_HUD, RGB_HUI
),
/* Keymap 3: Unicode
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  ┌   |  ┐   |  └   |  ┘   |  │   |  ─   |           |  ╔   |  ╗   |  ╚   |  ╝   |  ║   |  ═   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | shrug| yay  | hug  | smile|smile2| OSX  |           |  Λ   |  ℉   |  μ   |  ℃   |  ➙   |  ▻   |  ‽    |
 * |--------+------+------+------+------+------|Mode  |           |      |------+------+------+------+------+--------|
 * |        | hmm1 | hmm2 | gary1| gary2| gary3|------|           |------|  ☺   |  ☻   |  ☹   |  ♡   |  ♥   |  █    |
 * |--------+------+------+------+------+------|LINUX |           |  λ   |------+------+------+------+------+--------|
 * |        |table1|table2| sing1| sing2| cfzd1|Mode  |           |      |  ❤  |  ☐   |  ☑   |  ☒   |  ♫   |  ▄    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |table3| smrk2| love | VER  |                                       |  ⌘   |  ✔   |  ✘   |  ●   |  ▀   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |   ▒  |  ▓   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Unicode
[UNI] = LAYOUT_ergodox(
        KC_TRNS, UC(0x250c), UC(0x2510), UC(0x2514), UC(0x2518), UC(0x2502), UC(0x2500),
        KC_TRNS, F(EMOJI_SHRUG), F(EMOJI_YAY), F(EMOJI_HUG), F(EMOJI_SMILE), F(EMOJI_SMILE2), F(F_UC_MODE_OSX),
        KC_TRNS, F(EMOJI_HMM1), F(EMOJI_HMM2), F(EMOJI_HAPPY1), F(EMOJI_HAPPY2), F(EMOJI_HAPPY3),
        KC_TRNS, F(EMOJI_TABLE1), F(EMOJI_TABLE2), F(EMOJI_SING1), F(EMOJI_SING2), F(EMOJI_CONFUSED1), F(F_UC_MODE_LNX),
        KC_TRNS, F(EMOJI_TABLE3), F(EMOJI_SMRK2), F(EMOJI_LOVE), F(F_VRSN),
        KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       UC(0x2554),  UC(0x2557), UC(0x255a), UC(0x255d), UC(0x2551), UC(0x2550), KC_TRNS,
       UC(0x039b),  UC(0x2109), UC(0x03bc), UC(0x2103), UC(0x2799), UC(0x25bb), UC(0x203d),
                 UC(0x263a), UC(0x263b), UC(0x2639), UC(0x2661), UC(0x2665), UC(0x2588),
       UC(0x03bb),  UC(0x2764), UC(0x2610), UC(0x2611), UC(0x2612), UC(0x266b), UC(0x2584),
       UC(0x2318), UC(0x2714), UC(0x2718), UC(0x25cf), UC(0x2580),
        UC(0x2592), UC(0x2593),
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 4: Unicode 2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  ¹   |  ²   |  ³   |  ⁴   |  ⁵   |  ⁶   |           |  ⁶   |  ⁷   |  ⁸   |  ⁹   |  ⁰   |  ℃   |   ™    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  ₁   |  ₂   |  ₃   |  ₄   |  ₅   |  ₆   |           |  ₆   |  ₇   |  ₈   |  ₉   |  ₀   |  ⁄   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ⅞   |  ⅝   |  ⅜   |  ⅛   |  ⅚   |------|           |------|  ⅓   |  ⅒   |  ⅑   |  ⅐   |  ¾   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  ⅗   |  ⅖   |  ⅕   |  ⅔   |           |  ¼   |  ⅙   |  ⅘   |  ½   |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Unicode 2
[UNI2] = LAYOUT_ergodox(
        KC_TRNS, UC(0x00b9), UC(0x00b2), UC(0x00b3), UC(0x2074), UC(0x2075), UC(0x2076),
        KC_TRNS, UC(0x2081), UC(0x2082), UC(0x2083), UC(0x2084), UC(0x2085), UC(0x2086),
        KC_TRNS, UC(0x215e), UC(0x215d), UC(0x215c), UC(0x215b), UC(0x215a),
        KC_TRNS, KC_TRNS, KC_TRNS, UC(0x2157), UC(0x2156), UC(0x2155), UC(0x2154),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
        UC(0x2076),  UC(0x2077), UC(0x2078), UC(0x2079), UC(0x2070), UC(0x2103), UC(0x2122),
        UC(0x2086),  UC(0x2087), UC(0x2088), UC(0x2089), UC(0x2080), UC(0x2044), KC_TRNS,
        UC(0x2153), UC(0x2152), UC(0x2151), UC(0x2150), UC(0x00be), KC_TRNS,
        UC(0x00bc),  UC(0x2159), UC(0x2158), UC(0x00bd), KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
),

};

const uint16_t PROGMEM fn_actions[] = {
  [EMOJI_SHRUG]   = ACTION_FUNCTION_OPT(EMOJI, SHRUG),
  [EMOJI_YAY]     = ACTION_FUNCTION_OPT(EMOJI, YAY),
  [EMOJI_HUG]     = ACTION_FUNCTION_OPT(EMOJI,HUG),
  [EMOJI_SMILE]   = ACTION_FUNCTION_OPT(EMOJI,SMILE),
  [EMOJI_SMILE2]  = ACTION_FUNCTION_OPT(EMOJI,SMILE2),
  [EMOJI_HMM1]    = ACTION_FUNCTION_OPT(EMOJI,HMM1),
  [EMOJI_HMM2]    = ACTION_FUNCTION_OPT(EMOJI,HMM2),
  [EMOJI_BEAR1]   = ACTION_FUNCTION_OPT(EMOJI,BEAR1),
  [EMOJI_BEAR2]   = ACTION_FUNCTION_OPT(EMOJI,BEAR2),
  [EMOJI_FUU]     = ACTION_FUNCTION_OPT(EMOJI,FUU),
  [EMOJI_EGGY1]   = ACTION_FUNCTION_OPT(EMOJI,EGGY1),
  [EMOJI_EGGY2]   = ACTION_FUNCTION_OPT(EMOJI,EGGY2),
  [EMOJI_FACE1]   = ACTION_FUNCTION_OPT(EMOJI,FACE1),
  [EMOJI_FACE2]   = ACTION_FUNCTION_OPT(EMOJI,FACE2),
  [EMOJI_UHU]     = ACTION_FUNCTION_OPT(EMOJI,UHU),
  [EMOJI_SMRK1]   = ACTION_FUNCTION_OPT(EMOJI,SMRK1),
  [EMOJI_SMRK2]   = ACTION_FUNCTION_OPT(EMOJI2,SMRK2),
  [EMOJI_LOVE]    = ACTION_FUNCTION_OPT(EMOJI2,LOVE),
  [EMOJI_HAPPY1]  = ACTION_FUNCTION_OPT(EMOJI2,HAPPY1),
  [EMOJI_HAPPY2]  = ACTION_FUNCTION_OPT(EMOJI2,HAPPY2),
  [EMOJI_HAPPY3]  = ACTION_FUNCTION_OPT(EMOJI2,HAPPY3),
  [EMOJI_SING1]   = ACTION_FUNCTION_OPT(EMOJI2,SING1),
  [EMOJI_SING2]   = ACTION_FUNCTION_OPT(EMOJI2,SING2),
  [EMOJI_TABLE1]  = ACTION_FUNCTION_OPT(EMOJI2,TABLE1),
  [EMOJI_TABLE2]  = ACTION_FUNCTION_OPT(EMOJI2,TABLE2),
  [EMOJI_TABLE3]  = ACTION_FUNCTION_OPT(EMOJI2,TABLE3),
  [EMOJI_CONFUSED1]  = ACTION_FUNCTION_OPT(EMOJI2,CONFUSED1),
  [F_EPRM]        = ACTION_FUNCTION(EPRM),
  [F_VRSN]        = ACTION_FUNCTION(VRSN),
  [F_RGB_SLD]     = ACTION_FUNCTION(RGB_SLD),
  [F_RGB_STEP_REV]     = ACTION_FUNCTION(RGB_STEP_REV),
  [F_UC_MODE_OSX] = ACTION_FUNCTION(UC_MODE_OSX),
  [F_UC_MODE_LNX] = ACTION_FUNCTION(UC_MODE_LNX),
};

#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
    case EPRM:
      eeconfig_init();
      break;
    case VRSN:
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      break;
    case RGB_SLD:
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
#endif
      break;
    case RGB_STEP_REV:
#ifdef RGBLIGHT_ENABLE
        rgblight_step_reverse();
#endif
      break;
    case UC_MODE_OSX:
        set_unicode_input_mode(UC_OSX);
        break;
    case UC_MODE_LNX:
        set_unicode_input_mode(UC_LNX);
        break;
    case EMOJI:
      switch(opt) {
      case SHRUG:
    unicode_input_start(); register_hex(0xaf); unicode_input_finish();
    TAP_ONCE (KC_BSLS);
    register_code (KC_RSFT); TAP_ONCE (KC_MINS); TAP_ONCE (KC_9); unregister_code (KC_RSFT);
    unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
    register_code (KC_RSFT); TAP_ONCE (KC_0); TAP_ONCE (KC_MINS); unregister_code (KC_RSFT);
    TAP_ONCE (KC_SLSH);
    unicode_input_start (); register_hex(0xaf); unicode_input_finish();
    break;
      case YAY:
    SEND_STRING ("\\o/");
    break;
      case HUG:
    unicode_input_start(); register_hex(0x0f3c); unicode_input_finish();
    TAP_ONCE (KC_SPC);
    unicode_input_start(); register_hex(0x3064); unicode_input_finish();
    TAP_ONCE (KC_SPC);
    unicode_input_start(); register_hex(0x25d5); unicode_input_finish();
    unicode_input_start(); register_hex(0x005f); unicode_input_finish();
    unicode_input_start(); register_hex(0x25d5); unicode_input_finish();
    TAP_ONCE (KC_SPC);
    unicode_input_start(); register_hex(0x0f3d); unicode_input_finish();
    unicode_input_start(); register_hex(0x3064); unicode_input_finish();
    break;
      case SMILE:
    unicode_input_start(); register_hex(0x0298); unicode_input_finish();
    unicode_input_start(); register_hex(0x203f); unicode_input_finish();
    unicode_input_start(); register_hex(0x0298); unicode_input_finish();
    break;
      case SMILE2:
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x0298); unicode_input_finish();
    unicode_input_start(); register_hex(0x203f); unicode_input_finish();
    unicode_input_start(); register_hex(0x0298); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    break;
      case HMM1:
    unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
    unicode_input_start(); register_hex(0x005f); unicode_input_finish();
    unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
    break;
      case HMM2:
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
    unicode_input_start(); register_hex(0x005f); unicode_input_finish();
    unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    break;
      case BEAR1:
    unicode_input_start(); register_hex(0x0295); unicode_input_finish();
    unicode_input_start(); register_hex(0x2022); unicode_input_finish();
    unicode_input_start(); register_hex(0x1d25); unicode_input_finish();
    unicode_input_start(); register_hex(0x2022); unicode_input_finish();
    unicode_input_start(); register_hex(0x0294); unicode_input_finish();
    break;
      case BEAR2:
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x1d54); unicode_input_finish();
    unicode_input_start(); register_hex(0x1d25); unicode_input_finish();
    unicode_input_start(); register_hex(0x1d54); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    break;
      case FUU:
    unicode_input_start(); register_hex(0x256d); unicode_input_finish();
    unicode_input_start(); register_hex(0x2229); unicode_input_finish();
    unicode_input_start(); register_hex(0x256e); unicode_input_finish();
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x002d); unicode_input_finish();
    unicode_input_start(); register_hex(0x005f); unicode_input_finish();
    unicode_input_start(); register_hex(0x002d); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    unicode_input_start(); register_hex(0x256d); unicode_input_finish();
    unicode_input_start(); register_hex(0x2229); unicode_input_finish();
    unicode_input_start(); register_hex(0x256e); unicode_input_finish();
    break;
      case EGGY1:
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x256f); unicode_input_finish();
    unicode_input_start(); register_hex(0x00b0); unicode_input_finish();
    unicode_input_start(); register_hex(0x25a1); unicode_input_finish();
    unicode_input_start(); register_hex(0x00b0); unicode_input_finish();
    unicode_input_start(); register_hex(0xff09); unicode_input_finish();
    unicode_input_start(); register_hex(0x256f); unicode_input_finish();
    break;
      case EGGY2:
    unicode_input_start(); register_hex(0x30ce); unicode_input_finish();
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x309c); unicode_input_finish();
    unicode_input_start(); register_hex(0x002d); unicode_input_finish();
    unicode_input_start(); register_hex(0x309c); unicode_input_finish();
    unicode_input_start(); register_hex(0x30ce); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    break;
      case FACE1:
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x002d); unicode_input_finish();
    unicode_input_start(); register_hex(0x005f); unicode_input_finish();
    unicode_input_start(); register_hex(0x002d); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    break;
      case FACE2:
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x2022); unicode_input_finish();
    unicode_input_start(); register_hex(0x005f); unicode_input_finish();
    unicode_input_start(); register_hex(0x2022); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    break;
      case UHU:
    unicode_input_start(); register_hex(0x2299); unicode_input_finish();
    unicode_input_start(); register_hex(0xfe4f); unicode_input_finish();
    unicode_input_start(); register_hex(0x2299); unicode_input_finish();
    break;
      case SMRK1:
    unicode_input_start(); register_hex(0x005e); unicode_input_finish();
    unicode_input_start(); register_hex(0x032e); unicode_input_finish();
    unicode_input_start(); register_hex(0x005e); unicode_input_finish();
    break;
      }
      break;
    case EMOJI2:
      switch(opt) {
    case SMRK2:
      unicode_input_start(); register_hex(0x0028); unicode_input_finish();
      unicode_input_start(); register_hex(0x005e); unicode_input_finish();
      unicode_input_start(); register_hex(0x032e); unicode_input_finish();
      unicode_input_start(); register_hex(0x005e); unicode_input_finish();
      unicode_input_start(); register_hex(0x0029); unicode_input_finish();
      break;
      case LOVE:
    unicode_input_start(); register_hex(0x2665); unicode_input_finish();
    unicode_input_start(); register_hex(0x203f); unicode_input_finish();
    unicode_input_start(); register_hex(0x2665); unicode_input_finish();
    break;
      case HAPPY1:
    unicode_input_start(); register_hex(0x1555); unicode_input_finish();
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x141b); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    unicode_input_start(); register_hex(0x1557); unicode_input_finish();
    break;
      case HAPPY2:
    unicode_input_start(); register_hex(0x1555); unicode_input_finish();
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x1415); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    unicode_input_start(); register_hex(0x1557); unicode_input_finish();
    break;
      case HAPPY3:
    unicode_input_start(); register_hex(0x1566); unicode_input_finish();
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x141b); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    unicode_input_start(); register_hex(0x1564); unicode_input_finish();
    break;
      case SING1:
    unicode_input_start(); register_hex(0x266b); unicode_input_finish();
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x141b); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    unicode_input_start(); register_hex(0x266b); unicode_input_finish();
    break;
      case SING2:
    unicode_input_start(); register_hex(0x266b); unicode_input_finish();
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x1415); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    unicode_input_start(); register_hex(0x266b); unicode_input_finish();
    break;

      case TABLE1:
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x256f); unicode_input_finish();
    unicode_input_start(); register_hex(0x00b0); unicode_input_finish();
    unicode_input_start(); register_hex(0x25a1); unicode_input_finish();
    unicode_input_start(); register_hex(0x00b0); unicode_input_finish();
    unicode_input_start(); register_hex(0xff09); unicode_input_finish();
    unicode_input_start(); register_hex(0x256f); unicode_input_finish();
    unicode_input_start(); register_hex(0xfe35); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x253b); unicode_input_finish();
    unicode_input_start(); register_hex(0x2501); unicode_input_finish();
    unicode_input_start(); register_hex(0x253b); unicode_input_finish();
    break;

    case TABLE2:
    unicode_input_start(); register_hex(0x252c); unicode_input_finish();
    unicode_input_start(); register_hex(0x2500); unicode_input_finish();
    unicode_input_start(); register_hex(0x252c); unicode_input_finish();
    unicode_input_start(); register_hex(0xfeff); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x30ce); unicode_input_finish();
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x309c); unicode_input_finish();
    unicode_input_start(); register_hex(0x002d); unicode_input_finish();
    unicode_input_start(); register_hex(0x309c); unicode_input_finish();
    unicode_input_start(); register_hex(0x30ce); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    break;

    case TABLE3:
    unicode_input_start(); register_hex(0x252c); unicode_input_finish();
    unicode_input_start(); register_hex(0x2500); unicode_input_finish();
    unicode_input_start(); register_hex(0x252c); unicode_input_finish();
    unicode_input_start(); register_hex(0xfeff); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0xfe35); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x002f); unicode_input_finish();
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x002e); unicode_input_finish();
    unicode_input_start(); register_hex(0x25a1); unicode_input_finish();
    unicode_input_start(); register_hex(0x002e); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x005c); unicode_input_finish();
    unicode_input_start(); register_hex(0xff09); unicode_input_finish();
    break;

    case CONFUSED1:
    unicode_input_start(); register_hex(0x0028); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x29c9); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x29a3); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x29c9); unicode_input_finish();
    unicode_input_start(); register_hex(0x0020); unicode_input_finish();
    unicode_input_start(); register_hex(0x0029); unicode_input_finish();
    break;
      }
      break;
    }
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
      case RUN:
    return MACRO( D(LCTL), T(I), U(LCTL), T(R), END  );
      break;
    }
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
    }

};
