#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum macros {
  RUN
};

enum function_ids {
  EPRM,
  VRSN,
  RGB_SLD
};

enum progmem_ids {
  F_EPRM,
  F_VRSN,
  F_RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * Note swapping of Alt/Gui(cmd) to get desired result, other keys swapped to allow continued use of Dvorak software layout.
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Grv/L3 |   1  |   2  |   3  |   4  |   5  |  6   |           |  5   |   6  |   7  |   8  |   9  |   0  |  =/L3  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | \/LCtrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |'/RCtrl |
 * |--------+------+------+------+------+------| Hyper|           |  Meh |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L1  | LAlt |  Left| Right| LCmd |                                       | LCmd | Up   | Down | RCtrl|  ~L2 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  | Esc  |       | App  | Esc  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  _   |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  LAlt  |Enter |
 *                                 |      |ace   |  _   |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_MINS,
        CTL_T(KC_BSLS), KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSPO,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        MO(SYMB),       KC_LGUI,   KC_LEFT,KC_RGHT,KC_LALT,
                                                      KC_DELT,KC_ESC,
                                                              KC_DQT,
                                               KC_SPC,KC_BSPC,KC_DQT,
        // right hand
             KC_5,         KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_RBRC,
             KC_EQL,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_LBRC,
                           KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          CTL_T(KC_QUOT),
             MEH_T(KC_NO), KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSPC,
                                  KC_LALT,KC_UP,  KC_DOWN,KC_RCTRL,         MO(MDIA),
             KC_APP,      KC_ESC,
             KC_PGUP,
             KC_PGDN,     KC_LGUI, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
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
 *                                        |  Del | Ins  |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | End  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_DELT,KC_INS,
                                               KC_HOME,
                               KC_TRNS,KC_TRNS,KC_END,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_KP_7,   KC_KP_8,    KC_KP_9,    KC_KP_ASTERISK, KC_F12,
                KC_DOWN, KC_KP_4,   KC_KP_5,    KC_KP_6,    KC_KP_MINUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_KP_1,   KC_KP_2,    KC_KP_3,    KC_KP_PLUS, KC_TRNS,
                         KC_KP_0,   KC_KP_0,    KC_KP_DOT,  KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_KP_ENTER
),
/* Keymap 2: Media and mouse and RGB (shine) keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  Up  |      |      |      |           |      |      |      |      |      |      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Rght |      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |VolUp |VolDn | Mute |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Toggle|Animat|       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|Solid |       |      |      |      |
 *                                 |ness- |ness+ |------|       |------| Hue- | Hue+ |
 *                                 |      |      |      |       | EPRM |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP  , KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       RGB_TOG,RGB_MOD,
                                       F(F_RGB_SLD),
                               RGB_VAD,RGB_VAI,KC_TRNS,
    // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       F(F_EPRM), RGB_HUD, RGB_HUI
),
};

const uint16_t PROGMEM fn_actions[] = {
  [F_EPRM]        = ACTION_FUNCTION(EPRM),
  [F_VRSN]        = ACTION_FUNCTION(VRSN),
  [F_RGB_SLD]     = ACTION_FUNCTION(RGB_SLD),
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
