#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); //(Tx, Rx)
int relayPin = 7;
int buttenPin = 8;
int shat = 0;
void setup() {
  BTSerial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(buttenPin, INPUT);
}

void loop() {
  if(digitalRead(buttenPin) == HIGH){
    if(shat == 0){
        digitalWrite(relayPin, HIGH);
        shat = 1;
        delay(500);
      }else{
        digitalWrite(relayPin, LOW);
        shat = 0;
        delay(500);
      }
  }
  if(BTSerial.available()){
    char bt;
    bt = BTSerial.read();
    if(bt == '1'){
      if(shat == 0){
        digitalWrite(relayPin, HIGH);
        shat = 1;
      }else{
        digitalWrite(relayPin, LOW);
        shat = 0;
      }
  }
}
}
