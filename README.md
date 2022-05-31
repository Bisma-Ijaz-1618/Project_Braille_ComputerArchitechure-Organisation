
#include <Keypad.h>
#include <WiFi.h>
#include <ESP_Mail_Client.h>

//wifi connection
#define Wifi_SSID "Redmi9C"  
#define Wifi_PASS "bisma42001"

const char* ssid = Wifi_SSID; 
const char* passcode = Wifi_PASS;

//email
//host
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
//signin
#define AUTHOR_EMAIL "xzyrandom21@gmail.com"
#define AUTHOR_PASSWORD "ktpwcrfpjyjususu"
//receiver
#define RECIPIENT_EMAIL "bisma1ijaz1@gmail.com"
//SMTP Session object
SMTPSession smtp;
//Message object
SMTP_Message message;

//session config data
ESP_Mail_Session session;


//KeyPad Stuff
const byte ROW_L = 4; // four rows
const byte COLUMN_L =4; // four columns

//initializing keypad of lettrs
char letter_keypad[ROW_L][COLUMN_L] = {
  {'1','2','3','s'},
  {'4','5','6','m'},
  {'?','"','>','c'},
  {',','.','e','n'}
  //s=space, m = mode,c=clear last input, n=new new_message,>=new letter
  //e=send email
};
byte pin_rows_l[ROW_L] = {23,22,3,21};
byte pin_column_l[COLUMN_L] = {19,18,5,17};
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
String input_letter;
String control_keys;
String new_message = "";

//initializing keypad of numbers
#define ROW_N     4 // four rows
#define COLUMN_N  4 // three columns
char number_keypad[ROW_N][COLUMN_N] = {
 {'1','2','3','s'},
 {'4','5','6','m'},
 {'7','8','9','c'},
 {'*','0','#','n'}
};

byte pin_rows_n[ROW_N] = {23,22,3,21};
byte pin_column_n[COLUMN_N] = {19,18,5,17};
Keypad keypad_numbers = Keypad( makeKeymap(number_keypad), pin_rows_n, pin_column_n, ROW_N, COLUMN_N);

int trig = 27;
int echo = 26;
int buzz = 4;

void setup() {
  Serial.begin(9600);
  input_letter.reserve(6); // maximum input

  //ultrasonic sensor
  pinMode(trig, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(echo, INPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, passcode);
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");}
  Serial.println("");
  Serial.println("WiFi connected");

  //email debug
  smtp.debug(1);
}

int type_mode = 0;
int input_num;
void loop() {
  
    if (type_mode == 0) {
        char key_l = keypad_letters.getKey();
        if (key_l) {
        Serial.println(key_l);
          if (key_l == 's') {
            Serial.println("adding space");
            new_message += " ";
          }
          else if (key_l == 'c') {
          Serial.println("removing last input");
            new_message = new_message.substring(0, new_message.length() - 2);
          Serial.println(new_message);
          }
          else if (key_l == 'n') {
            Serial.println(new_message);
            Serial.println("type new message");
            new_message = " ";
          }
          else if (key_l == 'm') {
            Serial.println("changing keypad mode");
            if (type_mode == 1) {
              type_mode = 0;
            }
            else {
              type_mode = 1;
            }
          }
          else if(key_l=='e'){
                        //session config
            session.server.host_name = SMTP_HOST;
            session.server.port = SMTP_PORT;
            session.login.email = AUTHOR_EMAIL;
            session.login.password = AUTHOR_PASSWORD;
            session.login.user_domain = "";

            //message
            message.sender.name = "ESP";
            message.sender.email = AUTHOR_EMAIL;
            message.subject = "Email";
            message.addRecipient("Bisma", RECIPIENT_EMAIL);

            //html message
            String htmlMsg = "<div style=\"color:blue;\"><h1>HELLO!</h1><p>"+new_message+"</p></div>";
            message.html.content = htmlMsg.c_str();
            message.text.charSet = "text here?";
            message.text.charSet = new_message;
            message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

            //server connection
            if (!smtp.connect(&session))
                              return;  
            //Start sending Email and close the session */
            if (!MailClient.sendMail(&smtp, &message))
                 Serial.println("Error sending Email, " + smtp.errorReason());
            //buzzer indication on email sent
            digitalWrite(buzz,HIGH);
          }
          else if (key_l == '.') {
            input_letter = ""; // clear input
            new_message += ". ";
          }
          else if (key_l == ',') {
            input_letter = "";
            new_message += ", ";
          }
          else if(key_l=='?'){
            input_letter = "";
            new_message += "?";
          }
          
          else if(key_l=='"'){
            input_letter = "";
            new_message += "\"";
          }
          else if (key_l == '>') {
            if      (A == input_letter) {
              Serial.println("A");
              new_message += "A";
              input_letter = "";
            }
            else if (B == input_letter) {
              Serial.println("B");
              new_message += "B";
              input_letter = "";
            }
            else if (C == input_letter) {
              Serial.println("C");
              new_message += "C";
              input_letter = "";
            }
            else if (D == input_letter) {
              Serial.println("D");
              new_message += "D";
              input_letter = "";
            }
            else if (E == input_letter) {
              Serial.println("E");
              new_message += "E";
              input_letter = "";
            }
            else if (F == input_letter) {
              Serial.println("F");
              new_message += "F";
              input_letter = "";
            }
            else if (G == input_letter) {
              Serial.println("G");
              new_message += "G";
              input_letter = "";
            }
            else if (H == input_letter) {
              Serial.println("H");
              new_message += "H";
              input_letter = "";
            }
            else if (I == input_letter) {
              Serial.println("I");
              new_message += "I";
              input_letter = "";
            }
            else if (J == input_letter) {
              Serial.println("J");
              new_message += "J";
              input_letter = "";
            }
            else if (K == input_letter) {
              Serial.println("K");
              new_message += "K";
              input_letter = "";
            }
            else if (L == input_letter) {
              Serial.println("L");
              new_message += "L";
              input_letter = "";
            }
            else if (M == input_letter) {
              Serial.println("M");
              new_message += "M";
              input_letter = "";
            }
            else if (N == input_letter) {
              Serial.println("N");
              new_message += "N";
              input_letter = "";
            }
            else if (O == input_letter) {
              Serial.println("O");
              new_message += "O";
              input_letter = "";
            }
            else if (P == input_letter) {
              Serial.println("P");
              new_message += "P";
              input_letter = "";
            }
            else if (Q == input_letter) {
              Serial.println("Q");
              new_message += "Q";
              input_letter = "";
            }
            else if (R == input_letter) {
              Serial.println("R");
              new_message += "R";
              input_letter = "";
            }
            else if (S == input_letter) {
              Serial.println("S");
              new_message += "S";
              input_letter = "";
            }
            else if (T == input_letter) {
              Serial.println("T");
              new_message += "T";
              input_letter = "";
            }
            else if (U == input_letter) {
              Serial.println("U");
              new_message += "U";
              input_letter = "";
            }
            else if (V == input_letter) {
              Serial.println("V");
              new_message += "V";
              input_letter = "";
            }
            else if (W == input_letter) {
              Serial.println("W");
              new_message += "W";
              input_letter = "";
            }
            else if (X == input_letter) {
              Serial.println("X");
              new_message += "X";
              input_letter = "";
            }
            else if (Y == input_letter) {
              Serial.println("Y");
              new_message += "Y";
              input_letter = "";
            }
            else if (Z == input_letter) {
              Serial.println("Z");
              new_message += "Z";
              input_letter = "";
            }
            else {
              input_letter = ""; // clear input
            }
        }
        else {
          input_letter += key_l; // append new character to input string
        }
      }
    }
    else {
      char key_n = keypad_numbers.getKey();
      if (key_n) {
        if (key_n == 's') {
          Serial.println("adding space");
          new_message += " ";
        }
          else if (key_n == 'c') {
          Serial.println("removing last input");
          new_message = new_message.substring(0, new_message.length() - 2);
          Serial.println(new_message);
        }
        else if (key_n == 'n') {
          Serial.println(new_message);
          Serial.println("type new message");
          new_message = " ";
        }
        else if (key_n == 'm') {
          Serial.println("changing keypad mode");
          if (type_mode == 1) {
            type_mode = 0;
          }
          else {
            type_mode = 1;
          }
        }
        else{
          Serial.println(key_n);
          new_message += key_n;
         }
      }
    }
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
  }
    
