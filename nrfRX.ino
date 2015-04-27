#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
#include<SoftwareSerial.h>

int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int lastmsg = 1;
String theMessage = "";

SoftwareSerial mySerial(3, 4);

void setup(void){
 Serial.begin(9600);
 mySerial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}
void loop(void){
  if (radio.available()){
    bool done = false;  
      radio.read(msg, 1); 
      char theChar = msg[0];
      if (msg[0] != 2){
        theMessage.concat(theChar);
        }
      else {
       Serial.println(theMessage);
       mySerial.print(theMessage);
       theMessage= ""; 
      }
   }
}
