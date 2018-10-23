#include <esp32-hal-ledc.h>


int IN1 = 23;
int IN2 = 22;
int incomingByte = 0;
int spee = 14;
const int freq = 3000;
const int pwmChannel = 0;
const int resolution = 8;
int test = 200;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(14, OUTPUT);
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(spee, pwmChannel);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    incomingByte = Serial.read();
    

    switch (incomingByte){
      case 'a':
         digitalWrite(IN1, HIGH);
         digitalWrite(IN2, LOW);
         ledcWrite(pwmChannel, 120);
         Serial.println("case a ");
         break;
      case 'b':
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, HIGH);
       ledcWrite(pwmChannel, 250);
       Serial.println("case b");  
       break;
      default:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        ledcWrite(pwmChannel, 0); 
        Serial.println("default switch");     
      }
  
 }
}
