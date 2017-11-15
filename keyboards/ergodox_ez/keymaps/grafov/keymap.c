/*
This is the keymap for the keyboard
Keymacs + Control layer + QWERTY + Emacs macros + misc experiments

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// #include "keymap_german.h"
// #include "keymap_nordic.h"

// Just for aesthetics
#define _____ KC_TRANSPARENT
#define XXXXX KC_NO

// Switchers
#define RUS KC_SCROLLLOCK
#define LAT KC_SCROLLLOCK
#define MRUS SCROLLLOCK
#define MLAT SCROLLLOCK
#define LV3 KC_CAPSLOCK
#define MLV3 CAPSLOCK
#define XKBSTR "setxkbmap -layout \"us,ru(typewriter)\" -option grp:sclk_toggle -option lv3:caps_switch -option misc:typo"

#define TAP(kc) register_code(kc);unregister_code(kc)

// Layer names
enum {
  LAYER_KEYMACS = 0,
  LAYER_AUXCHARS,
  LAYER_RUSSIAN,
  LAYER_AUXCHARS_RU,
  LAYER_MOUSE,
  LAYER_QWERTY,
  LAYER_NUMPAD,
  LAYER_CONTROL,
  LAYER_FN,
  LAYER_MEDIA,
  LAYER_SYMBOLS,
  LAYER_WM
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  XKBHELP,
  RGB_SLD,
  RGB_0000FF,
  RGB_008000,
  RGB_FFA500,
  RGB_800080,
  RGB_FF0000
};

// Macros IDs
enum {
  M_EMACS_SELECT = 0,
  M_RUASTR,
  ACCENT,
  RU_NOSIGN,
  KEYNAV,
  M_WMDOWN,
  M_WMUP,
  M_LAYER_IS_KEYMACS,
  M_LAYER_IS_AUXCHARS,
  M_LAYER_IS_RUSSIAN,
  M_LAYER_IS_AUXCHARS_RU,  
  M_LAYER_IS_CONTROL,
  M_LAYER_IS_MOUSE,
  M_LAYER_IS_QWERTY,
  M_LAYER_IS_NUMPAD,
  M_LAYER_IS_FN,
  M_LAYER_IS_MEDIA,
  M_LAYER_IS_SYMBOLS,
  M_LAYER_IS_WM,
};

//Tap Dance Declarations
enum {
  TD_DASH = 0,
  TD_GRAVEACCENT,
  TD_SHSIG,
  TD_LELKILAPKI,
  TD_RELKILAPKI,
  TD_CHE,
  TD_HE,
  TD_YUCOLON,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default layer based on Keymacs layout
 * This is the adaptation of the layout for common keyboards for Ergodox EZ
 * https://github.com/keyboard-ergonomics/keymacs
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   `  |   ;  |   -  |   !  |   +  |      |           |      |   *  |   ?  |   "  |   :  |   =  |   BSP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Alt  |   q  |   b  |   p  |   f  |   g  |      |           |      |   v  |   w  |   l  |   y  |   '  |   Alt  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Ctl  |   r  |   a  |   e  |.  n  |   s  |------|           |------|   d  |.  o  |   t  |   i  |   h  |   Ctl  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Shift |   z  |   ,  |   u  |   k  |   j  |      |           |      |   m  |   c  |   x  |   .  |   /  |  Shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAT  |      |      |   _  |      |                                       |      |      |      |      |  RUS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | Back |       | Frwd | CtlW |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | CtlV |       | CtlR |      |      |
 *                                 |  SPC |  Ret |------|       |------| Tab  | SPC  |
 *                                 |      |      | CtlC |       | AltX |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [LAYER_KEYMACS] \
  = KEYMAP( // left fingers
		   KC_ESCAPE,KC_GRAVE,KC_SCOLON,KC_MINUS,KC_EXLM,KC_PLUS,M(M_LAYER_IS_KEYMACS),
		   KC_LALT,KC_Q,KC_B,KC_P,KC_F,ALGR_T(KC_G),OSL(LAYER_FN),
		   KC_LCTL,LT(LAYER_NUMPAD,KC_R),KC_A,KC_E,KC_N,RCTL_T(KC_S),
		   KC_LSHIFT,LT(LAYER_AUXCHARS,KC_Z),KC_COMMA,KC_U,KC_K,LT(LAYER_AUXCHARS,KC_J),M(M_EMACS_SELECT),
		   TG(LAYER_KEYMACS),_____,_____,KC_UNDS,MO(LAYER_MOUSE),
		   // left thumb
		   LCTL(KC_G),KC_WWW_BACK,LCTL(KC_V),
		   LT(LAYER_CONTROL,KC_SPACE),KC_ENTER,LCTL(KC_C),
		   // right fingers 
		   TG(LAYER_NUMPAD),KC_ASTR,KC_QUES,KC_DQUO,KC_COLON,KC_EQUAL,KC_BSPACE,
		   OSL(LAYER_FN),ALT_T(KC_V),KC_W,KC_L,KC_Y,KC_QUOTE,KC_RALT,
		   CTL_T(KC_D),KC_O,KC_T,KC_I,LT(LAYER_NUMPAD,KC_H),KC_RCTL,
		   OSL(LAYER_WM),LT(LAYER_AUXCHARS,KC_M),KC_C,KC_X,KC_DOT,LT(LAYER_AUXCHARS,KC_SLASH),KC_RSHIFT,
		   M(KEYNAV),KC_UNDS,_____,_____,TT(LAYER_RUSSIAN),
		   // right thumb
		   KC_WWW_FORWARD,RCTL(KC_W),KC_WWW_REFRESH,
		   ALT_T(KC_APPLICATION),KC_TAB,LT(LAYER_CONTROL,KC_SPACE)),

/* Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   `  |   ;  |   -  |   !  |   +  |      |           |Numpad|   *  |   ?  |   "  |   :  |   =  |   BSP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   &  |   $  |   ^  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   _  |   (  |.  )  |      |------|           |------|      |.  {  |   }  |   #  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   <  |   @  |   ~  |      |      |           |      |      |   =  |   \  |   >  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |   _  |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [LAYER_AUXCHARS] \
  = KEYMAP(
		   // left fingers
		   VRSN,KC_GRAVE,KC_EXLM,KC_MINUS,KC_SCOLON,KC_PLUS,M(M_LAYER_IS_AUXCHARS),
		   KC_LALT,M(ACCENT),KC_PERC,KC_LBRACKET,KC_RBRACKET,XXXXX,_____,
		   KC_LCTL,XXXXX,KC_UNDS,KC_LPRN,KC_RPRN,XXXXX,
		   KC_LSHIFT,XXXXX,KC_LABK,KC_AT,KC_TILD,KC_TAB,_____,
		   _____,_____,_____,_____,_____,
		   // left thumb
		   _____,_____,_____,
		   LT(LAYER_CONTROL,KC_SPACE),_____,_____,
		   // right fingers
		   _____,KC_ASTR,KC_QUES,KC_DQUO,KC_COLON,KC_EQUAL,_____,
		   _____,KC_PIPE,KC_AMPR,KC_DLR,KC_CIRC,KC_NO,KC_RALT,
		   KC_NO,KC_LCBR,KC_RCBR,KC_HASH,XXXXX,KC_RCTRL,
		   _____,KC_ENTER,KC_EQUAL,KC_BSLASH,KC_RABK,XXXXX,KC_RSHIFT,
		   _____,_____,_____,_____,_____,
		   // right thumb
		   _____,_____,_____,
		   _____,_____,LT(LAYER_CONTROL,KC_SPACE)),
  
/* Russian layout with Keymacs compatible punctuatitons
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  «/„ |  ч/; |   -  |   !  |  ё/+ |      |           |      |   *  |   ?  |  х/" |  ю/: |  »/“ |   BSP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   й  |   ц  |   у  |   к  |   е  |      |           |      |   н  |   г  |   ш  |   щ  |   з  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   ф  |   ы  |   в  |.  а  |   п  |------|           |------|   р  |.  о  |   л  |   д  |   ж  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   я  |   ,  |   с  |   м  |   и  |      |           |      |   т  |  ь/ъ |   б  |   .  |   э  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAT  |      |      |   _  |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */    
  /* QWERTY for Russian Typewriter layout adapted for Ergodox */
  /* -------------------------------------------------------- */
  /* Х moved to top for right index finger */
  /* Э moved to down for right pinky */
  /* Tap dance: */
  /* - double-tap for Ь produces Ъ */
  /* - unresovled because RCTL_T: double-tap for Е should produce Ё but not yet */
  
  /* It has used shift-shift switcher (https://github.com/grafov/shift-shift). */
  [LAYER_RUSSIAN] \
  = KEYMAP(
		   // left fingers
		   KC_ESCAPE,TD(TD_LELKILAPKI),TD(TD_CHE),TD(TD_DASH),KC_MINUS,KC_SLASH,M(M_LAYER_IS_RUSSIAN),
		   KC_LALT,KC_Q,KC_W,KC_E,KC_R,RALT_T(KC_T),_____,
		   KC_LCTL,LT(LAYER_NUMPAD,KC_A),KC_S,KC_D,KC_F,RCTL_T(KC_G),
		   KC_LSHIFT,LT(LAYER_AUXCHARS_RU,KC_Z),KC_6,KC_C,KC_V,LT(LAYER_AUXCHARS_RU,KC_B),_____,
		   TO(LAYER_KEYMACS),_____,_____,KC_9,_____,
		   // left thumb
		   LCTL(KC_G),KC_WWW_BACK,KC_PLUS,
		   LT(LAYER_CONTROL,KC_SPACE),_____,_____,
		   // right fingers
		   _____,_____,KC_9,TD(TD_HE),TD(TD_YUCOLON),TD(TD_RELKILAPKI),_____,
		   _____,LALT_T(KC_Y),KC_U,KC_I,KC_O,KC_P,KC_RALT,
		   LCTL_T(KC_H),KC_J,KC_K,KC_L,LT(LAYER_NUMPAD,KC_COLON),KC_RCTL,
		   OSL(LAYER_WM),LT(LAYER_AUXCHARS_RU,KC_N),TD(TD_SHSIG),KC_COMMA,KC_7,LT(LAYER_AUXCHARS_RU,KC_QUOTE),KC_RSHIFT,
		   _____,_____,_____,_____,_____,
		   // right thumb
		   KC_WWW_FORWARD,RCTL(KC_W),KC_WWW_REFRESH,
		   ALT_T(KC_APPLICATION),_____,LT(LAYER_CONTROL,KC_SPACE)),

/* Symbol Layer for Russian layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   `  |   ;  |   -  |   !  |   +  |      |           |      |   *  |   ?  |   "  |   :  |   =  |   BSP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   &  |   ^  |   $  |   №  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   _  |   (  |.  )  |      |------|           |------|      |.  {  |   }  |   #  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   <  |   @  |   ~  |      |      |           |      |      |   =  |   \  |   >  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |   _  |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [LAYER_AUXCHARS_RU] \
  = KEYMAP(// left fingers
	   XKBHELP,KC_GRAVE,KC_SCOLON,KC_MINUS,KC_EXLM,KC_PLUS,M(M_LAYER_IS_AUXCHARS_RU),
	   KC_LALT,M(ACCENT),KC_PERC,KC_LBRACKET,KC_RBRACKET,KC_NO,_____,
	   KC_LCTL,KC_NO,KC_UNDS,KC_LPRN,KC_RPRN,KC_NO,
	   KC_LSHIFT,KC_NO,KC_LABK,KC_AT,KC_TILD,KC_TAB,_____,
	   _____,_____,_____,SFT_T(KC_9),_____,
	   // left thumb
	   _____,_____,_____,
	   LT(LAYER_CONTROL,KC_SPACE),_____,_____,
	   // right fingers
	   _____,KC_ASTR,KC_QUES,KC_LBRACKET,KC_COLON,KC_EQUAL,_____,
	   _____,KC_PIPE,KC_AMPR,KC_CIRC,KC_DLR,M(RU_NOSIGN),KC_RALT,
	   KC_NO,KC_LCBR,KC_RCBR,KC_HASH,KC_NO,KC_RCTRL,
	   _____,KC_ENTER,KC_EQUAL,KC_BSLASH,KC_RABK,KC_NO,KC_RSHIFT,
	   _____,_____,_____,_____,_____,
	   // right thumb
	   _____,_____,_____,
	   _____,_____,LT(LAYER_CONTROL,KC_ENTER)),

  // Mouse control
  [LAYER_MOUSE] \
  = KEYMAP(// left fingers
	   _____,_____,_____,_____,_____,_____,M(M_LAYER_IS_MOUSE),
	   _____,_____,KC_MS_BTN3,_____,_____,_____,_____,
	   _____,_____,KC_MS_BTN1,KC_MS_UP,KC_MS_DOWN,_____,
	   _____,_____,KC_MS_BTN2,KC_MS_WH_UP,KC_MS_WH_DOWN,_____,_____,
	   _____,TO(LAYER_KEYMACS),KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN1,
	   // left thumb
	   _____,_____,_____,_____,_____,_____,
	   // right fingers
	   KC_MS_ACCEL2,_____,_____,_____,_____,_____,_____,
	   KC_MS_ACCEL1,_____,_____,_____,KC_MS_BTN3,_____,_____,
	   _____,KC_MS_LEFT,KC_MS_RIGHT,KC_MS_BTN1,_____,_____,
	   KC_MS_ACCEL0,KC_ENTER,KC_MS_WH_LEFT,KC_MS_WH_RIGHT,KC_MS_BTN2,_____,_____,
	   _____,KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2,_____,
	   // right thumb
	   _____,_____,_____,_____,_____,_____),

  // QWERTY for reference and for guests 
  [LAYER_QWERTY] \
  = KEYMAP(// left fingers
	   KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,M(M_LAYER_IS_QWERTY),
	   KC_LALT,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TAB,
	   KC_LCTL,KC_A,KC_S,KC_D,KC_F,KC_G,
	   KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,_____,
	   _____,_____,_____,KC_LGUI,KC_LALT,
	   // left thumb
	   _____,_____,_____,
	   KC_SPACE,KC_ENTER,_____,
	   // right fingers
	   TO(LAYER_KEYMACS),KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPACE,
	   KC_TAB,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LALT,
	   KC_H,KC_J,KC_K,KC_L,KC_QUES,KC_LCTL,
	   _____,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,
	   _____,KC_LEFT,KC_UP,KC_DOWN,KC_RIGHT,
	   // right thumb
	   _____,_____,_____,
	   _____,KC_ENTER,KC_SPACE),

/* Numpad for the right hand (left hand the same as for Symbols layer)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   `  |   ;  |   -  |   !  |   +  |      |           |      |   *  |   7  |   8  |   9  |   =  |   BSP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   _  |   (  |.  )  |      |------|           |------|      |.  1  |   2  |   3  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   ,  |   @  |   ~  |      |      |           |      |      |   =  |   0  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |   _  |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [LAYER_NUMPAD] \
  = KEYMAP(// left fingers
		   KC_NUMLOCK,TD(TD_GRAVEACCENT),KC_SCOLON,TD(TD_DASH),KC_EXLM,KC_PLUS,M(M_LAYER_IS_NUMPAD),
		   KC_LALT,M(ACCENT),KC_PERC,KC_LBRACKET,KC_RBRACKET,KC_NO,_____,
		   KC_LCTL,KC_NO,KC_UNDS,KC_LPRN,KC_RPRN,KC_NO,
		   KC_LSHIFT,KC_NO,KC_LABK,KC_AT,KC_TILD,KC_TAB,_____,
		   _____,_____,_____,_____,_____,
		   // left thumb
		   _____,_____,_____,
		   LT(LAYER_CONTROL,KC_SPACE),LT(LAYER_WM,KC_ENTER),_____,
		   // right fingers
		   _____,KC_KP_ASTERISK,KC_KP_7,KC_KP_8,KC_KP_9,KC_EQUAL,KC_BSPACE,
		   KC_TAB,KC_PIPE,KC_KP_4,KC_KP_5,KC_KP_6,KC_KP_PLUS,KC_RALT,
		   KC_KP_MINUS,KC_KP_1,KC_KP_2,KC_KP_3,KC_KP_MINUS,KC_RCTRL,
		   KC_KP_SLASH,KC_KP_ENTER,KC_KP_EQUAL,KC_KP_0,KC_KP_DOT,_____,KC_RSHIFT,
		   _____,_____,_____,_____,_____,
		   // right thumb
		   _____,_____,_____
		   ,_____,LT(LAYER_WM,KC_TAB),LT(LAYER_CONTROL,KC_SPACE)),

/* Control layer for line and page navigation
 * based on https://github.com/keyboard-ergonomics/control-layer.
 * Copypaste keys for Emacs (Alt+W,Ctl+W,Ctl+Y) and WordStar-like (Ctl+C,Ctl+X,Ctl+V) bindinds.
 * Copypaste keys for right hand because I'm using trackball by left hand.
 * 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |      |      |      |      |      |      |           |      |      |      |      |      |      |   BSP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Alt   |      |      |      |      | Esc  |      |           |      | CtlV | AltW | CtlW | CtlY |      | Alt    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  | CtlR | Home |  Up  |. Down| End  |------|           |------|  Del |. Left| Right|  BSP |  Tab | Ctrl   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  |      |SftTab| PgUp | PgDn | Tab  |      |           |      | Enter| CtlC | CtlX | CtlV | Ctl/ | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | Back |       | Fwd  |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |Reload|      |      |
 *                                 | SPC  | Enter|------|       |------| Enter| SPC  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */  
  [LAYER_CONTROL] \
  = KEYMAP(// left fingers
  		   TO(LAYER_MEDIA),XXXXX,XXXXX,XXXXX,LGUI(KC_F10),LGUI(KC_F11),M(M_LAYER_IS_CONTROL),
  		   _____,XXXXX,KC_LEFT,KC_UP,KC_RIGHT,KC_ESCAPE,XXXXX,
  		   _____,RCTL(KC_R),KC_HOME,KC_UP,KC_DOWN,KC_END,
  		   _____,RCTL(KC_Z),RSFT(KC_TAB),KC_PGUP,KC_PGDOWN,KC_TAB,XXXXX,
  		   TO(LAYER_KEYMACS),XXXXX,XXXXX,XXXXX,XXXXX,
  		   // left thumb
  		   KC_SPACE,KC_ENTER,_____,_____,_____,_____,
  		   // right fingers
  		   LGUI(KC_F5),RGUI(KC_F6),RGUI(KC_F12),XXXXX,XXXXX,XXXXX,_____,
  		   XXXXX,LCTL(KC_V),LALT(KC_W),LCTL(KC_W),LCTL(KC_Y),XXXXX,_____,
  		   KC_DELETE,KC_LEFT,KC_RIGHT,KC_BSPACE,KC_TAB,_____,
  		   XXXXX,KC_ENTER,LCTL(KC_C),LCTL(KC_X),LCTL(KC_V),LCTL(KC_SLASH),_____,
  		   XXXXX,XXXXX,XXXXX,XXXXX,XXXXX,
  		   // right thumb
  		   _____,_____,_____,_____,KC_TAB,KC_SPACE),

/* Fn keys for the right hand (left hand the same as for Symbols layer)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   `  |   ;  |   -  |   !  |   +  |      |           |      |   *  |   F7 |   F8 |   F9 |   =  |   BSP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ́  |   %  |   [  |   ]  |      |      |           |      | Alt  |   F4 |   F5 |   F6 |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   _  |   (  |.  )  |      |------|           |------| Ctrl |.  F1 |   F2 |   F3 |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   ,  |   @  |   ~  |      |      |           |      | Shift|  F11 |  F10 |  F12 |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |   _  |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */  
  [LAYER_FN] \
  = KEYMAP(// left fingers
		   KC_NUMLOCK,TD(TD_GRAVEACCENT),KC_SCOLON,TD(TD_DASH),KC_EXLM,KC_PLUS,M(M_LAYER_IS_NUMPAD),
		   KC_LALT,M(ACCENT),KC_PERC,KC_LBRACKET,KC_RBRACKET,KC_NO,_____,
		   KC_LCTL,KC_NO,KC_UNDS,KC_LPRN,KC_RPRN,KC_NO,
		   KC_LSHIFT,KC_NO,KC_LABK,KC_AT,KC_TILD,KC_TAB,_____,
		   _____,_____,_____,_____,_____,
		   // left thumb 
		   _____,_____,_____,
		   LT(LAYER_CONTROL,KC_SPACE),LT(LAYER_WM,KC_ENTER),_____,
		   // right fingers
		   _____,KC_KP_ASTERISK,KC_F7,KC_F8,KC_F9,KC_EQUAL,KC_BSPACE,
		   KC_RALT,KC_PIPE,KC_F4,KC_F5,KC_F6,KC_KP_PLUS,KC_RALT,
		   KC_RCTL,KC_F1,KC_F2,KC_F3,KC_KP_MINUS,KC_RCTRL,
		   KC_RSHIFT,KC_KP_ENTER,KC_F11,KC_F10,KC_F12,_____,KC_RSHIFT,
		   _____,_____,_____,_____,_____,
		   // right thumb
		   _____,_____,_____
		   ,_____,LT(LAYER_WM,KC_TAB),LT(LAYER_CONTROL,KC_SPACE)),

  // Media controls and Colors
  // TODO adapt more for mpv
  [LAYER_MEDIA] \
  = KEYMAP(// left fingers
		   _____,_____,_____,_____,_____,_____,M(M_LAYER_IS_MEDIA),
	   _____,_____,_____,_____,_____,_____,_____,
	   _____,_____,_____,_____,_____,_____,
	   _____,_____,_____,_____,_____,_____,_____,
	   TO(LAYER_KEYMACS),_____,_____,_____,_____,
	   // left thumb
	   RGB_MOD,_____,_____,
	   RGB_VAD,RGB_VAI,_____,
	   // right fingers
	   _____,RGB_0000FF,RGB_008000,RGB_FFA500,RGB_800080,RGB_FF0000,_____,
	   _____,_____,_____,_____,_____,_____,_____,
	   _____,_____,_____,_____,_____,_____,
	   _____,_____,_____,_____,_____,_____,_____,
	   _____,_____,_____,_____,_____,
	   // right thumb
	   RGB_TOG,RGB_SLD,_____,
	   _____,RGB_HUD,RGB_HUI),

  // WIP! Experimental!
  // XXX Rare symbols Unicode input
  // TODO  ¹²³‰↑∞←→’‘≠ €®™¥§
  /* Rare symbols Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |   `  |   ¹  |   ²  |   ³  |   +  |      |           |      |   §  |   ;  |   ∞  |   !  |   ≠  |   BSP |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |   ‰ |      |      |      |      |           |      |      |      |  €/¥ |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |   ↑  |.     |      |------|           |------|      |.  ←  |   →  |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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
  [LAYER_SYMBOLS] \
  = KEYMAP(// left fingers
	   UC_LNX,UC(0x03a8),UC(0x0152),UC_A,_____,_____,M(M_LAYER_IS_SYMBOLS),
	   _____,UC(0x00E4), UC(0x00E5), UC(0x00E9), UC(0x00AE), UC(0x00FE), _____,			   
	   _____,_____,_____,_____,_____,_____,
	   _____,_____,_____,_____,_____,_____,_____,
	   TO(LAYER_KEYMACS),_____,_____,_____,_____,
	   // left thumb
	   RGB_MOD,_____,_____,RGB_VAD,RGB_VAI,_____,
	   // right fingers
	   _____,RGB_0000FF,RGB_008000,RGB_FFA500,RGB_800080,RGB_FF0000,_____,
	   _____,_____,_____,_____,_____,_____,_____,
	   _____,_____,_____,_____,_____,_____,
	   _____,_____,_____,_____,_____,_____,_____,
	   _____,_____,_____,_____,_____,
	   // right thumb
	   RGB_TOG,RGB_SLD,_____,_____,RGB_HUD,RGB_HUI),

  // Window manager control (for StumpWM)
  [LAYER_WM]					\
  = KEYMAP(// left fingers
	   KC_ESCAPE,KC_GRAVE,KC_SCOLON,KC_MINUS,KC_EXLM,KC_PLUS,M(M_LAYER_IS_CONTROL),
	   ALT_T(KC_TAB),KC_Q,KC_B,KC_P,KC_F,ALGR_T(KC_G),OSL(LAYER_FN),
	   KC_LCTL,LT(LAYER_NUMPAD,KC_R),KC_A,KC_E,KC_N,RCTL_T(KC_S),
	   KC_LSHIFT,KC_Z,KC_COMMA,KC_U,KC_K,SFT_T(KC_J),M(M_EMACS_SELECT),
	   TO(LAYER_KEYMACS),_____,_____,KC_UNDS,MO(LAYER_MOUSE),
	   // left thumb
	   LCTL(KC_G),KC_WWW_BACK,LCTL(KC_V),
	   LT(LAYER_CONTROL,KC_SPACE),_____,LCTL(KC_C),
	   // right fingers 
	   _____,KC_ASTR,KC_QUES,KC_DQUO,KC_COLON,KC_EQUAL,KC_BSPACE,
	   M(M_WMUP),ALT_T(KC_V),KC_W,KC_L,KC_Y,KC_QUOTE,KC_RALT,
	   CTL_T(KC_D),KC_O,KC_T,KC_I,LT(LAYER_NUMPAD,KC_H),KC_RCTL,
	   M(M_WMDOWN),SFT_T(KC_M),KC_C,KC_X,KC_DOT,KC_SLASH,KC_RSHIFT,
	   M(KEYNAV),KC_UNDS,_____,_____,TO(LAYER_RUSSIAN),
	   // right thumb
	   KC_WWW_FORWARD,RCTL(KC_W),KC_WWW_REFRESH,
	   ALT_T(KC_APPLICATION),_____,LT(LAYER_CONTROL,KC_SPACE)),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};


// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (record->event.pressed) {
  switch(id) {
  case ACCENT:
    return MACRO(D(CAPSLOCK), T(A), U(CAPSLOCK), END);
  case RU_NOSIGN:
	return MACRO(T(SCROLLLOCK), T(3), T(SCROLLLOCK), END);
  case KEYNAV: // run Keynav (it is non default keybinding)
	return MACRO(D(LCTL), D(LALT), T(N), U(LCTL), U(LALT), END);	
  case M_EMACS_SELECT: // Emacs: reset the selection and activate a new one
    return MACRO(D(LCTL),T(G),T(SPC),U(LCTL),END);
  case M_WMUP:
	return MACRO(D(LALT), T(UP), U(LALT), END);
  case M_WMDOWN:
	return MACRO(D(LALT), T(DOWN), U(LALT), END);
  case M_LAYER_IS_KEYMACS:
    SEND_STRING ("Layer is Keymacs [0]");
    break;
  case M_LAYER_IS_AUXCHARS:
    SEND_STRING ("Layer is Aux Chars [1]");
    break;
  case M_LAYER_IS_RUSSIAN:
    SEND_STRING ("Layer is Russian [2]");
    break;
  case M_LAYER_IS_AUXCHARS_RU:
    SEND_STRING ("Layer is Aux Chars Rus [3]");
    break;
  case M_LAYER_IS_MOUSE:
    SEND_STRING ("Layer is Mouse [4]");
    break;
  case M_LAYER_IS_QWERTY:
    SEND_STRING ("Layer is QWERTY [5]");
    break;
  case M_LAYER_IS_NUMPAD:
    SEND_STRING ("Layer is Numpad [6]");
    break;
  case M_LAYER_IS_CONTROL:
    SEND_STRING ("Layer is Control [7]");
    break;
  case M_LAYER_IS_MEDIA:
    SEND_STRING ("Layer is Media and Color [8]");
    break;
  case M_LAYER_IS_FN:
    SEND_STRING ("Layer is Function keys [9]");
    break;
  case M_LAYER_IS_SYMBOLS:
    SEND_STRING ("Layer is Symbols [A]");
    break;
  case M_LAYER_IS_WM:
    SEND_STRING ("Layer is WM [B]");
    break;
  }}
  return MACRO_NONE;
};

// implements user hook on the each key press/release
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t old_layer = 0xff; 
  static bool backrus;
  static uint8_t layer = 0xff;
  static bool shift_pressed;

  old_layer = layer;  
  layer = biton32(layer_state);

  if (old_layer != layer) {
	switch (layer) {
    case LAYER_CONTROL:
    case LAYER_KEYMACS:
    case LAYER_NUMPAD:
	case LAYER_AUXCHARS_RU:
	  if (old_layer == LAYER_RUSSIAN) {
		TAP(LAT); // switch to English
	  }
	  break;
    case LAYER_RUSSIAN:
	  if (old_layer != LAYER_MOUSE) {
        TAP(RUS); // switch to Russian
	  }
	  break;
    case LAYER_WM:
	  if (old_layer == LAYER_RUSSIAN) {
		TAP(LAT); // switch to English
	  }
	  // (set-prefix-key (kbd "C-s-t"))
	  register_code(KC_LCTL); register_code(KC_LGUI);
	  TAP(KC_T);
	  unregister_code(KC_LGUI); unregister_code(KC_LCTL);
	  break;
	}
  }

  switch (keycode) {
  case KC_LSHIFT:
  case KC_RSHIFT:
	if (record->event.pressed) {
	  shift_pressed=true;
	} else {
	  shift_pressed=false;
	}
	return true;
  case KC_LCTL: // when Ctl pressed in Russian layout temporary switch back to Latin layout
  case KC_RCTL:
  case KC_LALT: // when Alt pressed in Russian layout temporary switch back to Latin layout
  case KC_RALT: 
    if (backrus) {
      if (!record->event.pressed) {
		layer_on(LAYER_RUSSIAN);
		backrus = false;
      }
    } else {
      if (layer == LAYER_RUSSIAN) {
		layer_off(LAYER_RUSSIAN);
       	layer_on(LAYER_KEYMACS);
		backrus = true;
      }
    }
    return true;
  case KC_MINUS:
	if (shift_pressed && record->event.pressed) {
	  unregister_code(KC_LSHIFT); unregister_code(KC_RSHIFT);
	  register_code(LV3);
	}
	if (record->event.pressed) {
	  TAP(KC_MINUS);
	}
	if (shift_pressed && !record->event.pressed) {
	  unregister_code(LV3);
	}
	return false;
  case EPRM:
	if (record->event.pressed) {
	  eeconfig_init();
	}
	return false;
	break;
  case VRSN:
	if (record->event.pressed) {
	  SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
	}
	return false;
	break;
  case XKBHELP:
	if (record->event.pressed) {
	  SEND_STRING (XKBSTR);
	}
	return false;
	break;
  case RGB_SLD:
	if (record->event.pressed) {
	  rgblight_mode(1);
	}
	return false;
	break;    
  case RGB_0000FF:
	if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
	  rgblight_enable();
	  rgblight_mode(1);
	  rgblight_setrgb(0x00,0x00,0xff);
#endif
	}
	return false;
	break;    
  case RGB_008000:
	if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
	  rgblight_enable();
	  rgblight_mode(1);
	  rgblight_setrgb(0x00,0x80,0x00);
#endif
	}
	return false;
	break;    
  case RGB_FFA500:
	if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
	  rgblight_enable();
	  rgblight_mode(1);
	  rgblight_setrgb(0xff,0xa5,0x00);
#endif
	}
	return false;
	break;    
  case RGB_800080:
	if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
	  rgblight_enable();
	  rgblight_mode(1);
	  rgblight_setrgb(0x80,0x00,0x80);
#endif
	}
	return false;
	break;    
  case RGB_FF0000:
	if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
	  rgblight_enable();
	  rgblight_mode(1);
	  rgblight_setrgb(0xff,0x00,0x00);
#endif
	}
	return false;
	break;    
  }
  
  return true;
}


#define LEDOFF     ergodox_board_led_off(); \
  ergodox_right_led_1_off(); \
  ergodox_right_led_2_off(); \
  ergodox_right_led_3_off()

// implements scan hook
// use it only for fast actions!
void matrix_scan_user(void) {
	static uint32_t old_layer_state = 0xffff;	
	if (layer_state == old_layer_state) return;
	old_layer_state = layer_state;	
    uint8_t layer = biton32(layer_state);

    switch (layer) {
    case LAYER_KEYMACS:
	  LEDOFF;	  
      rgblight_show_solid_color(0,0,0);
      break;      
    case LAYER_CONTROL:
	  LEDOFF;
      ergodox_right_led_1_on();
      rgblight_show_solid_color(0xff,0x00,0x00);
      break;
    case LAYER_AUXCHARS:
	  LEDOFF;
      ergodox_right_led_3_on();
      rgblight_show_solid_color(0x00,0x00,0xff);      
      break;
    case LAYER_RUSSIAN:
	  LEDOFF;
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      rgblight_show_solid_color(0xff,0x00,0xff);
      break;
    case LAYER_AUXCHARS_RU:	  
	  LEDOFF;	  
      ergodox_right_led_3_on();
      rgblight_show_solid_color(0x00,0x00,0xff);      
	  break;
    case LAYER_MOUSE:
	  LEDOFF;	  
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_1_on();
      rgblight_show_solid_color(0x22,0x00,0x00);
      //rgblight_effect_christmas();
      break;
    case LAYER_NUMPAD:
	  LEDOFF;
      ergodox_right_led_2_on();
      rgblight_show_solid_color(0x00,0xff,0x00);
      break;
    case LAYER_FN:
	  LEDOFF;	  	  
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      rgblight_show_solid_color(0x00,0xff,0xff);
      break;
    case LAYER_WM:
	  LEDOFF;	  	  
      ergodox_right_led_1_on();
	  //      ergodox_right_led_2_on();
      //ergodox_right_led_3_on();
      // rgblight_effect_christmas();
      rgblight_show_solid_color(0x99,0x77,0x0A);
      break;
    default:
	  LEDOFF;	  	  
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();	    
      ergodox_right_led_3_on();
      rgblight_show_solid_color(0x20,0x20,0x10);
    }
};

// XXX I have stopped using it
// Grave vs accent sign
void dance_graveaccent (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
	  TAP(KC_GRAVE);
      break;
    case 2:
	  register_code(LV3);
	  TAP(KC_A);	  
	  unregister_code(LV3);	  	  
      break;
    default:
      reset_tap_dance(state);
  }
}

// -/— minus or emdash
void dance_dash (qk_tap_dance_state_t *state, void *user_data) {
  uint8_t layer = biton32(layer_state);  // get the current layer  
  switch (state->count) {
    case 1:
	  if (layer == LAYER_RUSSIAN) {
		TAP(LAT);
	  }
	  TAP(KC_MINUS);
	  if (layer == LAYER_RUSSIAN) {
		TAP(RUS);
	  }
      break;
    case 2:
	  register_code(LV3);
	  TAP(KC_MINUS);	  
	  unregister_code(LV3);	  
      break;
    default:
      reset_tap_dance(state);
  }
}

// «/„ для русской раскладки
void dance_elkilapki_left (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
	  register_code(LV3);
	  TAP(KC_COMMA);
	  unregister_code(LV3);	  	  
      break;
    case 2:
	  register_code(LV3);
	  TAP(KC_J);	  
	  unregister_code(LV3);	  	  
      break;
    default:
      reset_tap_dance(state);
  }
}

// »/“ для русской раскладки
void dance_elkilapki_right (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
	  register_code(LV3);
	  TAP(KC_DOT);
	  unregister_code(LV3);	  
      break;
    case 2:
	  register_code(LV3);
	  TAP(KC_K);	  
	  unregister_code(LV3);	  
      break;
    default:
      reset_tap_dance(state);
  }
}

// Ь/Ъ для русской раскладки
void dance_shsig (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      register_code(KC_M);
      unregister_code(KC_M);      
      break;
    case 2:
      register_code(KC_RBRACKET);
      unregister_code(KC_RBRACKET);      
      break;
    default:
      reset_tap_dance(state);
  }
}

// And finally the Dancings!
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_DASH]  = ACTION_TAP_DANCE_FN(dance_dash),
  [TD_GRAVEACCENT]  = ACTION_TAP_DANCE_FN(dance_graveaccent),  
  [TD_SHSIG] = ACTION_TAP_DANCE_FN(dance_shsig),
  [TD_LELKILAPKI] = ACTION_TAP_DANCE_FN(dance_elkilapki_left),
  [TD_RELKILAPKI] = ACTION_TAP_DANCE_FN(dance_elkilapki_right),
  [TD_CHE] = ACTION_TAP_DANCE_DOUBLE(KC_X,KC_EQUAL), // ч/;
  [TD_HE] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET,KC_4), // х/"
  [TD_YUCOLON] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,KC_5), // ю/:
};
