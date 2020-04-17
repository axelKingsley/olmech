#include "keyboard.h"
#include "definitions.h"
#include <usb_keyboard.h>

/*//////////////////////////////////////////////////////////////////////////////
LAYER 0 MAPPING AND FUNCTIONS
//////////////////////////////////////////////////////////////////////////////*/
bool L0_ACTIVE = true;
KeyEventFN L0[KEY_COUNT] ={
  NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP,
  KAF1, KAF2, KAF3, KAF4, NOOP, NOOP, KAF5, KAF6, KAF7, KAF8, NOOP, NOOP, KAF9, KAF10, KAF11, KAF12,
  KAF1, KAF2, KAF3, KAF4, NOOP, NOOP, KAF5, KAF6, KAF7, KAF8, NOOP, NOOP, KAF9, KAF10, KAF11, KAF12,
  KATILDE, KA1, KA2, KA3, KA4, KA5, KAHOME, KAPAGE_UP,  KAPAGE_DOWN, KAEND, KA6, KA7, KA8, KA9, KA0, KABACKSLASH,
  KATAB, KAQ, KAW, KAE, KAR, KAT, KAQUOTE, KAPAD_7, KAPAD_8, KAPAD_9, KAY, KAU, KAI, KAO, KAP, KABACKSPACE,
  KAESC, KAA, KAS, KAD, KAF, KAG, KAPAD_PERIOD, KAPAD_4, KAPAD_5, KAPAD_6, KAH, KAJ, KAK, KAL, KASEMICOLON, KAQUOTE,
  KASHIFT, KAZ, KAX, KAC, KAV, KAB, KAPAD_0, KAPAD_1, KAPAD_2, KAPAD_3, KAN, KAM, KACOMMA, KAPERIOD, KASLASH, KAENTER,
  KACTRL, KAGUI, KAALT, SHIFT_L1, KASPACE, KAEQUAL, KAPAD_SLASH, KAPAD_ASTERIX, KAPLUS, KASHIFT, KAMINUS, KASPACE, KALEFT, KADOWN, KAUP, KARIGHT};
void layer0Handler(int keyNumber, bool pressedState, KeyEventFN eventStatus){
  if (!L0_ACTIVE) return;
  int colIndex = KeyCol(keyNumber);
  int rowIndex = KeyRow(keyNumber);

  L0[keyNumber](colIndex, rowIndex, pressedState);
}
void  SHIFT_L0(int colIndex, int rowIndex, bool currentState) {
  // L0 is prevented from being disabled
  L0_ACTIVE = true;
}
//////////////////////////////////////////////////////////////////////////////*/

/*//////////////////////////////////////////////////////////////////////////////
LAYER 1 MAPPING AND FUNCTIONS
//////////////////////////////////////////////////////////////////////////////*/
bool L1_ACTIVE = false;
KeyEventFN L1[KEY_COUNT] = {
  NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP, NOOP,
  KAF1, KAF2, KAF3, KAF4, NOOP, NOOP, KAF5, KAF6, KAF7, KAF8, NOOP, NOOP, KAF9, KAF10, KAF11, KAF12,
  KAF1, KAF2, KAF3, KAF4, NOOP, NOOP, KAF5, KAF6, KAF7, KAF8, NOOP, NOOP, KAF9, KAF10, KAF11, KAF12,
  KATILDE, KAEXCLAIM, KAAT, KAHASH, KADOLLAR, KAPERCENT, KAHOME, KAPAGE_UP,  KAPAGE_DOWN, KAEND, KA6, KA7, KA8, KA9, KA0, KABACKSLASH,
  KATAB, KACARROT, KAAMPER, KAASTERIX, KAOPAREN, KACPAREN, KAQUOTE, KAPAD_7, KAPAD_8, KAPAD_9, KAQUOTD, KAOCURLY, KACCURLY, KAO, KAP, KADELETE,
  KAESC, KAA, KAS, KAD, KAF, KAG, KAPAD_PERIOD, KAPAD_4, KAPAD_5, KAPAD_6, KAQUOTS, KAOPAREN, KACPAREN, KAL, KASEMICOLON, KAQUOTE,
  KACAPS_LOCK, KAZ, KAX, KAC, KAV, KAB, KAPAD_0, KAPAD_1, KAPAD_2, KAPAD_3, KAN, KAOBRACE, KACBRACE, KAPERIOD, KASLASH, KAENTER,
  KACTRL, KAGUI, KAALT, SHIFT_L1, KASPACE, KAEQUAL, KAPAD_SLASH, KAPAD_ASTERIX, KAPLUS, KASHIFT, KAMINUS, KASPACE, KARIGHT, KAUP, KADOWN, KALEFT};
void layer1Handler(int keyNumber, bool pressedState, KeyEventFN eventStatus){
  if (!L1_ACTIVE) return;
  int colIndex = KeyCol(keyNumber);
  int rowIndex = KeyRow(keyNumber);

  L1[keyNumber](colIndex, rowIndex, pressedState);
  setGlobalContext(STOP);
}
void  SHIFT_L1(int colIndex, int rowIndex, bool currentState) {
  if (currentState == PRESS) {
    L1_ACTIVE = true;
    }
  if (currentState == RELEASE) {
    L1_ACTIVE = false;
    }
}
//////////////////////////////////////////////////////////////////////////////*/

void layer3Handler(int keyNumber, bool pressedState, KeyEventFN eventStatus){
}

void layer2Handler(int keyNumber, bool pressedState, KeyEventFN eventStatus){
}

// Master Keypresser
void KEYACTION(int keycode, bool currentState) {
  if (currentState == PRESS) {
    Keyboard.press(keycode);
    }
  if (currentState == RELEASE) {
    Keyboard.release(keycode);
    }
}
// KEY FUNCTIONS
void  NOOP(int                  colIndex,  int  rowIndex,  bool  currentState)  {   }
void  KA0(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_0,                    currentState);}
void  KA1(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_1,                    currentState);}
void  KA2(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_2,                    currentState);}
void  KA3(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_3,                    currentState);}
void  KA4(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_4,                    currentState);}
void  KA5(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_5,                    currentState);}
void  KA6(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_6,                    currentState);}
void  KA7(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_7,                    currentState);}
void  KA8(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_8,                    currentState);}
void  KA9(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_9,                    currentState);}
void  KAA(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_A,                    currentState);}
void  KAALT(int                 colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(MODIFIERKEY_ALT,          currentState);}
void  KAB(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_B,                    currentState);}
void  KABACKSLASH(int           colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_BACKSLASH,            currentState);}
void  KABACKSPACE(int           colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_BACKSPACE,            currentState);}
void  KAC(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_C,                    currentState);}
void  KACAPS_LOCK(int           colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_CAPS_LOCK,            currentState);}
void  KACOMMA(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_COMMA,                currentState);}
void  KACTRL(int                colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(MODIFIERKEY_CTRL,         currentState);}
void  KAD(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_D,                    currentState);}
void  KADELETE(int              colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_DELETE,               currentState);}
void  KADOWN(int                colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_DOWN,                 currentState);}
void  KAE(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_E,                    currentState);}
void  KAEND(int                 colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_END,                  currentState);}
void  KAENTER(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_ENTER,                currentState);}
void  KAEQUAL(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_EQUAL,                currentState);}
void  KAESC(int                 colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_ESC,                  currentState);}
void  KAF(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F,                    currentState);}
void  KAF1(int                  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F1,                   currentState);}
void  KAF10(int                 colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F10,                  currentState);}
void  KAF11(int                 colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F11,                  currentState);}
void  KAF12(int                 colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F12,                  currentState);}
void  KAF2(int                  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F2,                   currentState);}
void  KAF3(int                  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F3,                   currentState);}
void  KAF4(int                  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F4,                   currentState);}
void  KAF5(int                  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F5,                   currentState);}
void  KAF6(int                  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F6,                   currentState);}
void  KAF7(int                  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F7,                   currentState);}
void  KAF8(int                  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F8,                   currentState);}
void  KAF9(int                  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_F9,                   currentState);}
void  KAG(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_G,                    currentState);}
void  KAGUI(int                 colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(MODIFIERKEY_GUI,          currentState);}
void  KAH(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_H,                    currentState);}
void  KAHOME(int                colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_HOME,                 currentState);}
void  KAI(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_I,                    currentState);}
void  KAINSERT(int              colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_INSERT,               currentState);}
void  KAJ(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_J,                    currentState);}
void  KAK(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_K,                    currentState);}
void  KAL(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_L,                    currentState);}
void  KALEFT(int                colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_LEFT,                 currentState);}
void  KALEFT_BRACE(int          colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_LEFT_BRACE,           currentState);}
void  KAM(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_M,                    currentState);}
void  KAMEDIA_EJECT(int         colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_EJECT,          currentState);}
void  KAMEDIA_FAST_FORWARD(int  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_FAST_FORWARD,   currentState);}
void  KAMEDIA_MUTE(int          colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_MUTE,           currentState);}
void  KAMEDIA_NEXT_TRACK(int    colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_NEXT_TRACK,     currentState);}
void  KAMEDIA_PAUSE(int         colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_PAUSE,          currentState);}
void  KAMEDIA_PLAY(int          colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_PLAY,           currentState);}
void  KAMEDIA_PLAY_PAUSE(int    colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_PLAY_PAUSE,     currentState);}
void  KAMEDIA_PLAY_SKIP(int     colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_PLAY_SKIP,      currentState);}
void  KAMEDIA_PREV_TRACK(int    colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_PREV_TRACK,     currentState);}
void  KAMEDIA_RECORD(int        colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_RECORD,         currentState);}
void  KAMEDIA_REWIND(int        colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_REWIND,         currentState);}
void  KAMEDIA_STOP(int          colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_STOP,           currentState);}
void  KAMEDIA_VOLUME_DEC(int    colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_VOLUME_DEC,     currentState);}
void  KAMEDIA_VOLUME_INC(int    colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MEDIA_VOLUME_INC,     currentState);}
void  KAMINUS(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_MINUS,                currentState);}
void  KAN(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_N,                    currentState);}
void  KANUM_LOCK(int            colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_NUM_LOCK,             currentState);}
void  KAO(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_O,                    currentState);}
void  KAP(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_P,                    currentState);}
void  KAPAD_0(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_0,                 currentState);}
void  KAPAD_1(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_1,                 currentState);}
void  KAPAD_2(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_2,                 currentState);}
void  KAPAD_3(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_3,                 currentState);}
void  KAPAD_4(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_4,                 currentState);}
void  KAPAD_5(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_5,                 currentState);}
void  KAPAD_6(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_6,                 currentState);}
void  KAPAD_7(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_7,                 currentState);}
void  KAPAD_8(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_8,                 currentState);}
void  KAPAD_9(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_9,                 currentState);}
void  KAPAD_ASTERIX(int         colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_ASTERIX,           currentState);}
void  KAPAD_ENTER(int           colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_ENTER,             currentState);}
void  KAPAD_MINUS(int           colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_MINUS,             currentState);}
void  KAPAD_PERIOD(int          colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_PERIOD,            currentState);}
void  KAPAD_PLUS(int            colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_PLUS,              currentState);}
void  KAPAD_SLASH(int           colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEYPAD_SLASH,             currentState);}
void  KAPAGE_DOWN(int           colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_PAGE_DOWN,            currentState);}
void  KAPAGE_UP(int             colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_PAGE_UP,              currentState);}
void  KAPAUSE(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_PAUSE,                currentState);}
void  KAPERIOD(int              colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_PERIOD,               currentState);}
void  KAPRINTSCREEN(int         colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_PRINTSCREEN,          currentState);}
void  KAQ(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_Q,                    currentState);}
void  KAQUOTE(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_QUOTE,                currentState);}
void  KAR(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_R,                    currentState);}
void  KARIGHT(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_RIGHT,                currentState);}
void  KARIGHT_ALT(int           colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(MODIFIERKEY_RIGHT_ALT,    currentState);}
void  KARIGHT_BRACE(int         colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_RIGHT_BRACE,          currentState);}
void  KARIGHT_CTRL(int          colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(MODIFIERKEY_RIGHT_CTRL,   currentState);}
void  KARIGHT_GUI(int           colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(MODIFIERKEY_RIGHT_GUI,    currentState);}
void  KARIGHT_SHIFT(int         colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(MODIFIERKEY_RIGHT_SHIFT,  currentState);}
void  KAS(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_S,                    currentState);}
void  KASCROLL_LOCK(int         colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_SCROLL_LOCK,          currentState);}
void  KASEMICOLON(int           colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_SEMICOLON,            currentState);}
void  KASHIFT(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(MODIFIERKEY_SHIFT,        currentState);}
void  KASLASH(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_SLASH,                currentState);}
void  KASPACE(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_SPACE,                currentState);}
void  KASYSTEM_POWER_DOWN(int   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_SYSTEM_POWER_DOWN,    currentState);}
void  KASYSTEM_SLEEP(int        colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_SYSTEM_SLEEP,         currentState);}
void  KASYSTEM_WAKE_UP(int      colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_SYSTEM_WAKE_UP,       currentState);}
void  KAT(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_T,                    currentState);}
void  KATAB(int                 colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_TAB,                  currentState);}
void  KATILDE(int               colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_TILDE,                currentState);}
void  KAU(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_U,                    currentState);}
void  KAUP(int                  colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_UP,                   currentState);}
void  KAV(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_V,                    currentState);}
void  KAW(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_W,                    currentState);}
void  KAX(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_X,                    currentState);}
void  KAY(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_Y,                    currentState);}
void  KAZ(int                   colIndex,  int  rowIndex,  bool  currentState)  {    KEYACTION(KEY_Z,                    currentState);}

void  KAPLUS(int                colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("+"); ;}
void  KAUNDERSCORE(int          colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("_"); ;}
void  KAOPAREN(int              colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("("); ;}
void  KACPAREN(int              colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print(")"); ;}
void  KAOCURLY(int              colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("{"); ;}
void  KACCURLY(int              colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("}"); ;}
void  KAOBRACE(int              colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("["); ;}
void  KACBRACE(int              colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("]"); ;}
void  KAQUOTS(int               colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("'"); ;}
void  KAQUOTD(int               colIndex,  int  rowIndex,  bool  currentState)  {   if                                      (!currentState)  Keyboard.print("\""); ;}
void  KAEXCLAIM(int             colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("!"); ;}
void  KAAT(int                  colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("@"); ;}
void  KAHASH(int                colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("#"); ;}
void  KADOLLAR(int              colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("$"); ;}
void  KAPERCENT(int             colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("%"); ;}
void  KACARROT(int              colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("^"); ;}
void  KAAMPER(int               colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("&"); ;}
void  KAASTERIX(int             colIndex,  int  rowIndex,  bool  currentState)  {   if                                       (!currentState)  Keyboard.print("*"); ;}
