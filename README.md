
#include <Keypad.h>
#include <binary.h>

/*
  TaskHandle_t Task1;
  void loop2( void * parameter )
  {
  for (;;) {
      digitalWrite(trig,HIGH);
      delayMicroseconds(10);
      digitalWrite(trig,LOW);
      long duration = pulseIn(echo, HIGH);
      int distance = (duration * 0.034)/2;
      if(distance<=10){
        digitalWrite(buzz,HIGH);
      }
      else{
        digitalWrite(buzz,LOW);
      }
       Serial.println(distance);
  }
  }
*/

int trig = 4;
int echo = 23;
int buzz = 2;

#define ROW_L     3 // four rows
#define COLUMN_L  3 // three columns

//initializing keypad of lettrs
char letter_keypad[ROW_L][COLUMN_L] = {
  {'1', '2', '.'},
  {'3', '4', ','},
  {'5', '6', '>'}
  //>=next letter
};
byte pin_rows_l[ROW_L] = {13, 12, 14};
byte pin_column_l[COLUMN_L] = {27, 26, 25};
Keypad keypad_letters = Keypad( makeKeymap(letter_keypad), pin_rows_l, pin_column_l, ROW_L, COLUMN_L);
const String A = "1";
const String B = "13";
const String C = "12";
const String D = "124";
const String E = "14";
const String F = "123";
const String G = "1234";
const String H = "134";
const String I = "23";
const String J = "234";
const String K = "15";
const String L = "135";
const String M = "125";
const String N = "1245";
const String O = "145";
const String P = "1235";
const String Q = "12345";
const String R = "1345";
const String S = "235";
const String T = "2345";
const String U = "156";
const String V = "1356";
const String W = "2346";
const String X = "1256";
const String Y = "12456";
const String Z = "1456";
String input_word;
String control_keys;
String message = "";

//initializing keypad of numbers
#define ROW_N     3 // four rows
#define COLUMN_N  3 // three columns
char number_keypad[ROW_N][COLUMN_N] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};

byte pin_rows_n[ROW_N] = {13, 12, 14};
byte pin_column_n[COLUMN_N] = {27, 26, 25};
Keypad keypad_numbers = Keypad( makeKeymap(number_keypad), pin_rows_n, pin_column_n, ROW_N, COLUMN_N);

//initializing control keypad
#define ROW_C  1
#define COL_C  4
char control_keypad[ROW_C][COL_C] = {
  {'s', 'c', 'n', 'm'}
  //s=space, m = mode,c=clear last input, n=new message
};

byte rowPins_c[ROW_C] = {5}; //connect to the row pinouts of the keypad
byte colPins_c[COL_C] = {21, 3, 18, 19}; //connect to the column pinouts of the keypad
Keypad keypad_controls = Keypad( makeKeymap(control_keypad), rowPins_c, colPins_c, ROW_C, COL_C);

void setup() {
  Serial.begin(9600);
  input_word.reserve(6); // maximum input
  //ultrasonic sensor
  pinMode(trig, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(echo, INPUT);
  //dipswitch
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);

  /*
    xTaskCreatePinnedToCore(
    loop2,          // name of the task function
    "Ultrasonic sensor",  // name of the task
    1000,           // memory assigned for the task
    NULL,           // parameter to pass if any
    0,              // priority of task, starting from 0(Highestpriority) *IMPORTANT*( if set to 1 and there is no activity in your 2nd loop, it will reset the esp32)
    &Task1,         // Reference name of taskHandle variable
    0);             // choose core (0 or 1)
  */

}
//functions for letter keypad
void type_letters() {

}

//function for binary switch

int bin2int(int numvalues, ...)
{
  int total = 0;
  va_list values;
  va_start(values, numvalues);

  for (; numvalues > 0; numvalues--)
    if (!(digitalRead(va_arg(values, int))) )
      total += powint(2, numvalues - 1);
  va_end(values);
  return total;
}
int powint(int base, int exponent)
{
  int result = 1;
  for (; exponent > 0; exponent--)
    result *= base;
  return result;
}
int switch_mode = 0;
int type_mode = 0;
int input_num;
void loop() {
  switch_mode = bin2int(2, 22, 23); //getting the status of two pins
  if (switch_mode == B00) {
    if (type_mode == 0) {
      char key_l = keypad_letters.getKey();
      if (key_l) {
        Serial.println(key_l);

        if (key_l == '.') {
          input_word = ""; // clear input
          message += ". ";
        }
        else if (key_l == ',') {
          input_word = "";
          message += ", ";
        }
        else if (key_l == '>') {
          if      (A == input_word) {
            Serial.println("A");
            message += "A";
            input_word = "";
          }
          else if (B == input_word) {
            Serial.println("B");
            message += "B";
            input_word = "";
          }
          else if (C == input_word) {
            Serial.println("C");
            message += "C";
            input_word = "";
          }
          else if (D == input_word) {
            Serial.println("D");
            message += "D";
            input_word = "";
          }
          else if (E == input_word) {
            Serial.println("E");
            message += "E";
            input_word = "";
          }
          else if (F == input_word) {
            Serial.println("F");
            message += "F";
            input_word = "";
          }
          else if (G == input_word) {
            Serial.println("G");
            message += "G";
            input_word = "";
          }
          else if (H == input_word) {
            Serial.println("H");
            message += "H";
            input_word = "";
          }
          else if (I == input_word) {
            Serial.println("I");
            message += "I";
            input_word = "";
          }
          else if (J == input_word) {
            Serial.println("J");
            message += "J";
            input_word = "";
          }
          else if (K == input_word) {
            Serial.println("K");
            message += "K";
            input_word = "";
          }
          else if (L == input_word) {
            Serial.println("L");
            message += "L";
            input_word = "";
          }
          else if (M == input_word) {
            Serial.println("M");
            message += "M";
            input_word = "";
          }
          else if (N == input_word) {
            Serial.println("N");
            message += "N";
            input_word = "";
          }
          else if (O == input_word) {
            Serial.println("O");
            message += "O";
            input_word = "";
          }
          else if (P == input_word) {
            Serial.println("P");
            message += "P";
            input_word = "";
          }
          else if (Q == input_word) {
            Serial.println("Q");
            message += "Q";
            input_word = "";
          }
          else if (R == input_word) {
            Serial.println("R");
            message += "R";
            input_word = "";
          }
          else if (S == input_word) {
            Serial.println("S");
            message += "S";
            input_word = "";
          }
          else if (T == input_word) {
            Serial.println("T");
            message += "T";
            input_word = "";
          }
          else if (U == input_word) {
            Serial.println("U");
            message += "U";
            input_word = "";
          }
          else if (V == input_word) {
            Serial.println("V");
            message += "V";
            input_word = "";
          }
          else if (W == input_word) {
            Serial.println("W");
            message += "W";
            input_word = "";
          }
          else if (X == input_word) {
            Serial.println("X");
            message += "X";
            input_word = "";
          }
          else if (Y == input_word) {
            Serial.println("Y");
            message += "Y";
            input_word = "";
          }
          else if (Z == input_word) {
            Serial.println("Z");
            message += "Z";
            input_word = "";
          }
          else {
            input_word = ""; // clear input
            digitalWrite(buzz, HIGH); //buzz sound on wrong buttons pressed.
          }
        }
        else {
          input_word += key_l; // append new character to input string
        }
      }
    }
    else {
      char key_n = keypad_numbers.getKey();
      if (key_n) {
        Serial.println(key_n);
        message += key_n;
      }

    }
  }
  else if (switch_mode == B10) {
    Serial.println("B10");
  }
  else if (switch_mode == B01) {
    Serial.println("B01");
  }
  else if (switch_mode == B11) {
    char key_c = keypad_controls.getKey();
    if (key_c) {
      if (key_c == 's') {
        Serial.println("adding space");
        message += " ";
      }
      else if (key_c == 'c') {
        Serial.println("removing last input");
        message = message.substring(0, message.length() - 2);
        Serial.println(message);
      }
      else if (key_c == 'n') {
        Serial.println(message);
        Serial.println("type new message");
        message = " ";
      }
      else if (key_c == 'm') {
        Serial.println("changing keypad mode");
        if (type_mode == 1) {
          type_mode = 0;
        }
        else {
          type_mode = 1;
        }
      }
    }

  }
}
