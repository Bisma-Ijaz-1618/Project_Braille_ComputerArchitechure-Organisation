
void setup() 
{
  // ISD1820 Arduino Voice Recorder for Robojax.com 
  pinMode(REC,OUTPUT);// set the REC pin as output
  pinMode(PLAY_L,OUTPUT);// set the PLAY_L pin as output
  pinMode(PLAY_E,OUTPUT);// set the PLAY_e pin as output
  pinMode(FT,OUTPUT);// set the FT pin as output  
  Serial.begin(9600);// set up Serial monitor   
}

void loop() {
  // ISD1820 Arduino Voice Recorder for Robojax.com 
    while (Serial.available() > 0) {
          char inChar = (char)Serial.read();
            if(inChar =='p' || inChar =='P'){
            digitalWrite(PLAY_E, HIGH);
            delay(50);
            digitalWrite(PLAY_E, LOW);  
              Serial.println("Playbak Started");  
            delay(playTime);
            
              Serial.println("Playbak Ended");
            break; 
            }// if          
            else if(inChar =='r' || inChar =='R'){
              digitalWrite(REC, HIGH);
              Serial.println("Recording started");
              delay(recordTime);
              digitalWrite(REC, LOW);
              Serial.println("Recording Stopped ");              
            } 
            else if(inChar =='l' || inChar =='L'){
            digitalWrite(PLAY_L, HIGH); 
              Serial.println("Playbak L Started");  
            delay(playLTime);
            digitalWrite(PLAY_L, LOW);
              Serial.println("Playbak L Ended");            
            }             
    // ISD1820 Arduino Voice Recorder for Robojax.com         
      Serial.println("**** Serial Monitor Exited");      
    }// wihile
Serial.println("**** Enter r to record, p to play");

  delay(500);
}
