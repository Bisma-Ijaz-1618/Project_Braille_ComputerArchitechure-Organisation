# CAO-Project
98#include <Keypad.h>

#define ROW_NUM     3 // four rows
#define COLUMN_NUM  2 // three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2','*'},
  {'3', '4','#'},
  {'5', '6','0'}
};
//row and column pins
byte pin_rows[ROW_NUM] = {18, 5, 17, 16};
byte pin_column[COLUMN_NUM] = {4, 2, 15};  

Keypad keypad_letters = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const String A="1";
const String B="13";
const String C="12";
const String D="124";
const String E="14";
const String F="123";
const String G="1234";
const String H="134";
const String I="23";
const String J="234";
const String K="15";
const String L="135";
const String M="125";
const String N="1245";
const String O="145";
const String P="1235";
const String Q="12345";
const String R="1345";
const String S="235";
const String T="2345";
const String U="156";
const String V="1356";
const String W="2346";
const String X="1256";
const String Y="12456";
const String Z="1456";
String input_word;
String Message;
void setup() {
  Serial.begin(9600);
  input_word.reserve(32); // maximum input characters
}

void loop() {
  char key = keypad_letters.getKey();

  if (key) {
    Serial.println(key);

    if (key == '*') {
      input_word = ""; // clear input password
    } else if (key == '#') {
      if      (A == input_word) { Serial.println("A");} 
      else if (B == input_word) { Serial.println("B");}
      else if (C == input_word) { Serial.println("C");}
      else if (D == input_word) { Serial.println("D");}
      else if (E == input_word) { Serial.println("E");}
      else if (F == input_word) { Serial.println("F");}
      else if (G == input_word) { Serial.println("G");}
      else if (H == input_word) { Serial.println("H");}
      else if (I == input_word) { Serial.println("I");}
      else if (J == input_word) { Serial.println("J");}
      else if (K == input_word) { Serial.println("K");}
      else if (L == input_word) { Serial.println("L");}
      else if (M == input_word) { Serial.println("M");}
      else if (N == input_word) { Serial.println("N");}
      else if (O == input_word) { Serial.println("O");}
      else if (P == input_word) { Serial.println("P");}
      else if (Q == input_word) { Serial.println("Q");}
      else if (R == input_word) { Serial.println("R");}
      else if (S == input_word) { Serial.println("S");}
      else if (T == input_word) { Serial.println("T");}
      else if (U == input_word) { Serial.println("U");}
      else if (V == input_word) { Serial.println("V");}
      else if (W == input_word) { Serial.println("W");}
      else if (X == input_word) { Serial.println("X");}
      else if (Y == input_word) { Serial.println("Y");}
      else if (Z == input_word) { Serial.println("Z");}
      else{ //buzzer}
      
      input_word = ""; // clear input password
    } else {
      input_word += key; // append new character to input password string
    }
  }
}
