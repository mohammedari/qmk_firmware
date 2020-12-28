// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#include "keymap_jp.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum thumbsplit58_layers
{
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,---------------------------------------------------------------------.                    .-------------------------------------------------------.
   * | ZHTG(GUI) |   1  |   2  |    3  |          4  |           5  |   6  |                    |         7  |    8  |   9  |   0  |   -  |   ^  |   \  |
   * |-----------+------+------+-------+-------------+--------------+------.      |-------------+------------+-------+------+------+------+------+------.
   * | Tab       |   Q  |   W  |    E  |          R  |           T  |             |          Y  |         U  |    I  |   O  |   P  |   @  |   [  |
   * |-----------+------+------+-------+-------------+--------------|             |-------------+------------+-------+------+------+------+------|
   * | Esc(Ctrl) |   A  |   S  |    D  |          F  |           G  |             |          H  |         J  |    K  |   L  |   ;  |   :  |   ]  |
   * |-----------+------+------+-------+-------------+--------------|             |-------------+------------+-------+------+------+------+------.
   * | Shift     |   Z  |   X  |    C  |          V  |           B  |             |          N  |         M  |    ,  |   .  |   /  |   \  |
   * .-----------+------+------+-------+-------------+--------------|             |-------------+------------+-------+------+------+------.
   *                           | LALT  | Bksp(Lower) | Space(Shift) |             | Enter(Ctrl) | Del(Raise) | PrtSc |
   *                           .------------------------------------.             .----------------------------------.
   */
  [_QWERTY] = LAYOUT(
    GUI_T(JP_ZHTG), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,           KC_7, KC_8   , KC_9  , KC_0   , JP_MINS, JP_CIRC, JP_YEN,
    KC_TAB        , KC_Q, KC_W, KC_E, KC_R, KC_T,           KC_Y, KC_U, KC_I   , KC_O  , KC_P   , JP_AT  , JP_LBRC,
    LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,           KC_H, KC_J, KC_K   , KC_L  , KC_SCLN, JP_COLN, JP_RBRC,
    KC_LSFT       , KC_Z, KC_X, KC_C, KC_V, KC_B,           KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, JP_BSLS,
    KC_LALT, LT(_LOWER, KC_BSPC), LSFT_T(KC_SPC),           RCTL_T(KC_ENT), LT(_RAISE, KC_DEL), KC_PSCR
  ),

  /* Lower
   * ,-----------------------------------------+ -----+             +------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|------.
   * |      |      |  Up  |      |      |      |             |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+             +------+------+------+------+------+------+------|
   * |      | Left | Down | Right|      |      |             |      | RClk | LClk |      |      |      |      |
   * |------+------+------+------+------+------+             +------+------+------+------+------+-------------.
   * |      |      |      |      |      |      |             |      | WhUp | WhDn |      |      |      |
   * |------+------+------+------+------+------+             +------+------+------+------+------+------.
   *                      |      |      |      |             |      |      |      |
   *                      +--------------------/             \--------------------+
   */
  [_LOWER] = LAYOUT(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
    _______, _______, KC_MS_U, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                 _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                 _______, KC_WH_D, KC_WH_U, _______, _______, _______,
                               _______, _______, _______,                 _______, _______, _______
  ),

  /* Raise
   * ,-----------------------------------------+ -----+             +------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+             +------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |             | Left | Down |  Up  | Right|      |      |      |
   * |------+------+------+------+------+------+             +------+------+------+------+------+-------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+             +------+------+------+------+------+------.
   *                      |      |      |      |             |      |      |      |
   *                      +--------------------/             \--------------------+
   */
  [_RAISE] = LAYOUT(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
    _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,                 _______, _______, _______
  ),

  /* Adjust
   * ,-----------------------------------------+ -----+             +------------------------------------------------.
   * |      |      |      |      |      |      |      |             |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+             +------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+             +------+------+------+------+------+-------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+             +------+------+------+------+------+------.
   *                      |      |      |      |             |      |      |      |
   *                      +--------------------/             \--------------------+
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,                 _______, _______, _______
  )
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// You need to add source files to SRC in rules.mk when using OLED display functions
void set_keylog(uint16_t keycode);
const char *read_keylog(void);
const char *read_modifier_state(void);
const char *read_host_led_state(void);

void matrix_init_user(void) {
  iota_gfx_init(false);   // turns on the display
}

void matrix_scan_user(void) {
  iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void render_status(struct CharacterMatrix *matrix) {
  // Layer state
  char layer_str[22];
  matrix_write(matrix, "Layer: ");
  uint8_t layer = biton32(layer_state);
  uint8_t default_layer = biton32(eeconfig_read_default_layer());
  switch (layer) {
    case _QWERTY:
      switch (default_layer) {
        case _QWERTY:
          snprintf(layer_str, sizeof(layer_str), "Qwerty");
          break;
        default:
          snprintf(layer_str, sizeof(layer_str), "Undef-%d", default_layer);
          break;
      }
      break;
    case _RAISE:
      snprintf(layer_str, sizeof(layer_str), "Raise");
      break;
    case _LOWER:
      snprintf(layer_str, sizeof(layer_str), "Lower");
      break;
    case _ADJUST:
      snprintf(layer_str, sizeof(layer_str), "Adjust");
      break;
    default:
      snprintf(layer_str, sizeof(layer_str), "Undef-%d", layer);
  }
  matrix_write_ln(matrix, layer_str);
  // Last entered keycode
  matrix_write_ln(matrix, read_keylog());
  // Modifier state
  matrix_write_ln(matrix, read_modifier_state());
  // Host Keyboard LED Status
  matrix_write(matrix, read_host_led_state());
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  render_status(&matrix);
  matrix_update(&display, &matrix);
}

#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef SSD1306OLED
    if (record->event.pressed) {
      set_keylog(keycode);
    }
  #endif
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
  }
  return true;
}
