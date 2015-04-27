
#include <SoftwareSerial.h>
#include <StackArray.h>
StackArray <String> stack;
SoftwareSerial mySerial(3, 4); // RX, TX
SoftwareSerial wifi(5, 6);
char msg='\0';
int i=0;
String complete="";
void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  mySerial.begin(9600);
  wifi.begin(9600);
}

void loop() // run over and over
{
  if(!mySerial.isListening())
  mySerial.listen();
  
  if (mySerial.available()){
    complete=mySerial.readStringUntil('.');
      
      
  }
  complete.trim();
  stack.push(complete);
  Serial.println(stack.pop());
  delay(1000);
   wifi.println("AT"); 
}

