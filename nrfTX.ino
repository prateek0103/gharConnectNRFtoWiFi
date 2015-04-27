#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
 
 int number;
int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
void setup(void){
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);}
void loop(void){
  number=random(3,500);
  String theMessage = String(number);
  int messageSize = theMessage.length();
  for (int i = 0; i < messageSize; i++) {
    int charToSend[1];
    charToSend[0] = theMessage.charAt(i);
    radio.write(charToSend,1);
  }  
//send the 'terminate string' value...  
  msg[0] = 2; 
  radio.write(msg,1);
 radio.powerDown(); 
 delay(1000);
  radio.powerUp();
}
