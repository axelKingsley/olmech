#include "definitions.h"

void layer3Handler(int keyNumber, bool pressedState, KeyEventFN eventStatus);
void layer2Handler(int keyNumber, bool pressedState, KeyEventFN eventStatus);
void layer1Handler(int keyNumber, bool pressedState, KeyEventFN eventStatus);
void layer0Handler(int keyNumber, bool pressedState, KeyEventFN eventStatus);

void KEYACTION(int keycode, bool currentState);

void NOOP(int colIndex, int rowIndex, bool currentState);
void SHIFT_L1(int colIndex, int rowIndex, bool currentState);
void KA0(int colIndex, int rowIndex, bool currentState);
void KA1(int colIndex, int rowIndex, bool currentState);
void KA2(int colIndex, int rowIndex, bool currentState);
void KA3(int colIndex, int rowIndex, bool currentState);
void KA4(int colIndex, int rowIndex, bool currentState);
void KA5(int colIndex, int rowIndex, bool currentState);
void KA6(int colIndex, int rowIndex, bool currentState);
void KA7(int colIndex, int rowIndex, bool currentState);
void KA8(int colIndex, int rowIndex, bool currentState);
void KA9(int colIndex, int rowIndex, bool currentState);
void KAA(int colIndex, int rowIndex, bool currentState);
void KAALT(int colIndex, int rowIndex, bool currentState);
void KAB(int colIndex, int rowIndex, bool currentState);
void KABACKSLASH(int colIndex, int rowIndex, bool currentState);
void KABACKSPACE(int colIndex, int rowIndex, bool currentState);
void KAC(int colIndex, int rowIndex, bool currentState);
void KACAPS_LOCK(int colIndex, int rowIndex, bool currentState);
void KACOMMA(int colIndex, int rowIndex, bool currentState);
void KACTRL(int colIndex, int rowIndex, bool currentState);
void KAD(int colIndex, int rowIndex, bool currentState);
void KADELETE(int colIndex, int rowIndex, bool currentState);
void KADOWN(int colIndex, int rowIndex, bool currentState);
void KAE(int colIndex, int rowIndex, bool currentState);
void KAEND(int colIndex, int rowIndex, bool currentState);
void KAENTER(int colIndex, int rowIndex, bool currentState);
void KAEQUAL(int colIndex, int rowIndex, bool currentState);
void KAESC(int colIndex, int rowIndex, bool currentState);
void KAF(int colIndex, int rowIndex, bool currentState);
void KAF1(int colIndex, int rowIndex, bool currentState);
void KAF10(int colIndex, int rowIndex, bool currentState);
void KAF11(int colIndex, int rowIndex, bool currentState);
void KAF12(int colIndex, int rowIndex, bool currentState);
void KAF2(int colIndex, int rowIndex, bool currentState);
void KAF3(int colIndex, int rowIndex, bool currentState);
void KAF4(int colIndex, int rowIndex, bool currentState);
void KAF5(int colIndex, int rowIndex, bool currentState);
void KAF6(int colIndex, int rowIndex, bool currentState);
void KAF7(int colIndex, int rowIndex, bool currentState);
void KAF8(int colIndex, int rowIndex, bool currentState);
void KAF9(int colIndex, int rowIndex, bool currentState);
void KAG(int colIndex, int rowIndex, bool currentState);
void KAGUI(int colIndex, int rowIndex, bool currentState);
void KAH(int colIndex, int rowIndex, bool currentState);
void KAHOME(int colIndex, int rowIndex, bool currentState);
void KAI(int colIndex, int rowIndex, bool currentState);
void KAINSERT(int colIndex, int rowIndex, bool currentState);
void KAJ(int colIndex, int rowIndex, bool currentState);
void KAK(int colIndex, int rowIndex, bool currentState);
void KAL(int colIndex, int rowIndex, bool currentState);
void KALEFT(int colIndex, int rowIndex, bool currentState);
void KALEFT_BRACE(int colIndex, int rowIndex, bool currentState);
void KAM(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_EJECT(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_FAST_FORWARD(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_MUTE(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_NEXT_TRACK(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_PAUSE(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_PLAY(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_PLAY_PAUSE(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_PLAY_SKIP(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_PREV_TRACK(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_RECORD(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_REWIND(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_STOP(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_VOLUME_DEC(int colIndex, int rowIndex, bool currentState);
void KAMEDIA_VOLUME_INC(int colIndex, int rowIndex, bool currentState);
void KAMINUS(int colIndex, int rowIndex, bool currentState);
void KAN(int colIndex, int rowIndex, bool currentState);
void KANUM_LOCK(int colIndex, int rowIndex, bool currentState);
void KAO(int colIndex, int rowIndex, bool currentState);
void KAP(int colIndex, int rowIndex, bool currentState);
void KAPAD_0(int colIndex, int rowIndex, bool currentState);
void KAPAD_1(int colIndex, int rowIndex, bool currentState);
void KAPAD_2(int colIndex, int rowIndex, bool currentState);
void KAPAD_3(int colIndex, int rowIndex, bool currentState);
void KAPAD_4(int colIndex, int rowIndex, bool currentState);
void KAPAD_5(int colIndex, int rowIndex, bool currentState);
void KAPAD_6(int colIndex, int rowIndex, bool currentState);
void KAPAD_7(int colIndex, int rowIndex, bool currentState);
void KAPAD_8(int colIndex, int rowIndex, bool currentState);
void KAPAD_9(int colIndex, int rowIndex, bool currentState);
void KAPAD_ASTERIX(int colIndex, int rowIndex, bool currentState);
void KAPAD_ENTER(int colIndex, int rowIndex, bool currentState);
void KAPAD_MINUS(int colIndex, int rowIndex, bool currentState);
void KAPAD_PERIOD(int colIndex, int rowIndex, bool currentState);
void KAPAD_PLUS(int colIndex, int rowIndex, bool currentState);
void KAPAD_SLASH(int colIndex, int rowIndex, bool currentState);
void KAPAGE_DOWN(int colIndex, int rowIndex, bool currentState);
void KAPAGE_UP(int colIndex, int rowIndex, bool currentState);
void KAPAUSE(int colIndex, int rowIndex, bool currentState);
void KAPERIOD(int colIndex, int rowIndex, bool currentState);
void KAPRINTSCREEN(int colIndex, int rowIndex, bool currentState);
void KAQ(int colIndex, int rowIndex, bool currentState);
void KAQUOTE(int colIndex, int rowIndex, bool currentState);
void KAR(int colIndex, int rowIndex, bool currentState);
void KARIGHT(int colIndex, int rowIndex, bool currentState);
void KARIGHT_ALT(int colIndex, int rowIndex, bool currentState);
void KARIGHT_BRACE(int colIndex, int rowIndex, bool currentState);
void KARIGHT_CTRL(int colIndex, int rowIndex, bool currentState);
void KARIGHT_GUI(int colIndex, int rowIndex, bool currentState);
void KARIGHT_SHIFT(int colIndex, int rowIndex, bool currentState);
void KAS(int colIndex, int rowIndex, bool currentState);
void KASCROLL_LOCK(int colIndex, int rowIndex, bool currentState);
void KASEMICOLON(int colIndex, int rowIndex, bool currentState);
void KASHIFT(int colIndex, int rowIndex, bool currentState);
void KASLASH(int colIndex, int rowIndex, bool currentState);
void KASPACE(int colIndex, int rowIndex, bool currentState);
void KASYSTEM_POWER_DOWN(int colIndex, int rowIndex, bool currentState);
void KASYSTEM_SLEEP(int colIndex, int rowIndex, bool currentState);
void KASYSTEM_WAKE_UP(int colIndex, int rowIndex, bool currentState);
void KAT(int colIndex, int rowIndex, bool currentState);
void KATAB(int colIndex, int rowIndex, bool currentState);
void KATILDE(int colIndex, int rowIndex, bool currentState);
void KAU(int colIndex, int rowIndex, bool currentState);
void KAUP(int colIndex, int rowIndex, bool currentState);
void KAV(int colIndex, int rowIndex, bool currentState);
void KAW(int colIndex, int rowIndex, bool currentState);
void KAX(int colIndex, int rowIndex, bool currentState);
void KAY(int colIndex, int rowIndex, bool currentState);
void KAZ(int colIndex, int rowIndex, bool currentState);
// Custom typers
void KAPLUS(int colIndex, int rowIndex, bool currentState);
void KAUNDERSCORE(int colIndex, int rowIndex, bool currentState);
void KAOPAREN(int colIndex, int rowIndex, bool currentState);
void KACPAREN(int colIndex, int rowIndex, bool currentState);
void KAOCURLY(int colIndex, int rowIndex, bool currentState);
void KACCURLY(int colIndex, int rowIndex, bool currentState);
void KAOBRACE(int colIndex, int rowIndex, bool currentState);
void KACBRACE(int colIndex, int rowIndex, bool currentState);
void KAQUOTS(int colIndex, int rowIndex, bool currentState);
void KAQUOTD(int colIndex, int rowIndex, bool currentState);
void  KAEXCLAIM(int             colIndex,  int  rowIndex,  bool  currentState)  ;
void  KAAT(int                  colIndex,  int  rowIndex,  bool  currentState)  ;
void  KAHASH(int                colIndex,  int  rowIndex,  bool  currentState)  ;
void  KADOLLAR(int              colIndex,  int  rowIndex,  bool  currentState)  ;
void  KAPERCENT(int             colIndex,  int  rowIndex,  bool  currentState)  ;
void  KACARROT(int              colIndex,  int  rowIndex,  bool  currentState)  ;
void  KAAMPER(int               colIndex,  int  rowIndex,  bool  currentState)  ;
void  KAASTERIX(int             colIndex,  int  rowIndex,  bool  currentState)  ;
