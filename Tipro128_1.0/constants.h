int Columns[] =
  {20,
  21,
  22,
  23,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12};

int Rows[] =
  {29,
  30,
  31,
  32,
  28,
  27,
  26,
  25};

bool KnownState[16][8] =
  {{false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false}};

int KeymapVIZ[8][16] =
  {
    {MODIFIERKEY_CTRL,MODIFIERKEY_GUI,MODIFIERKEY_ALT,KEY_A,KEY_A,KEY_A,KEY_A,KEY_A,MODIFIERKEY_CTRL,MODIFIERKEY_GUI,MODIFIERKEY_ALT,KEY_A,KEY_A,KEY_A,KEY_A,KEY_A},
    {MODIFIERKEY_CTRL,MODIFIERKEY_GUI,MODIFIERKEY_ALT,KEY_A,KEY_A,KEY_A,KEY_A,KEY_A,MODIFIERKEY_CTRL,MODIFIERKEY_GUI,MODIFIERKEY_ALT,KEY_A,KEY_A,KEY_A,KEY_A,KEY_A},
    {MODIFIERKEY_CTRL,MODIFIERKEY_GUI,MODIFIERKEY_ALT,KEY_A,KEY_A,KEY_A,KEY_A,KEY_A,MODIFIERKEY_CTRL,MODIFIERKEY_GUI,MODIFIERKEY_ALT,KEY_A,KEY_A,KEY_A,KEY_A,KEY_A},
    {KEY_ESC,KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEYPAD_7,KEYPAD_8,KEYPAD_9,KEY_6,KEY_7,KEY_8,KEY_9,KEY_0,KEY_BACKSPACE,KEY_DELETE},
    {KEY_TAB,KEY_Q,KEY_W,KEY_E,KEY_R,KEY_T,KEYPAD_4,KEYPAD_5,KEYPAD_6,KEY_Y,KEY_U,KEY_I,KEY_O,KEY_P,KEY_LEFT_BRACE,KEY_RIGHT_BRACE},
    {MODIFIERKEY_SHIFT,KEY_A,KEY_S,KEY_D,KEY_F,KEY_G,KEYPAD_1,KEYPAD_2,KEYPAD_3,KEY_H,KEY_J,KEY_K,KEY_L,KEY_SEMICOLON,KEY_QUOTE,KEY_ENTER},
    {KEY_TILDE,KEY_Z,KEY_X,KEY_C,KEY_V,KEY_B,KEYPAD_PERIOD,KEYPAD_0,KEY_EQUAL,KEY_N,KEY_M,KEY_COMMA,KEY_PERIOD,KEY_SLASH,KEY_BACKSLASH,MODIFIERKEY_SHIFT},
    {MODIFIERKEY_CTRL,MODIFIERKEY_GUI,MODIFIERKEY_ALT,KEY_SPACE,KEY_SPACE,KEY_MINUS,KEYPAD_SLASH,KEYPAD_ASTERIX,KEY_EQUAL,KEY_MINUS,KEY_SPACE,KEY_LEFT,KEY_DOWN,KEY_UP,KEY_RIGHT,MODIFIERKEY_SHIFT},
  };

int Keymap[16][8];
