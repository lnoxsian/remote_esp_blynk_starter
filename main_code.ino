#define BLYNK_TEMPLATE_ID "template_id" // set the sample temlpate id
#define BLYNK_TEMPLATE_NAME "template_name" // set the sameple template name

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial

#define APP_DEBUG

#include "BlynkEdgent.h"

int wait_time = 1500;

BLYNK_WRITE(V0) // on relay is V0
{
  int virtual_pin0  = param.asInt();
  if(virtual_pin0 == 1) // button press is 1
  { // toggle the on relay on then off
    digitalWrite(12, LOW);
    Serial.println("on relay is on for 1.5s");
    delay(wait_time);
    Serial.println("on relay is off now!!");
    digitalWrite(12, HIGH);
  }
  else // othertimes this is off
  {
    digitalWrite(12, HIGH);
  }
}

BLYNK_WRITE(V1) // off relay is V1
{
  int virtual_pin1  = param.asInt();
  if(virtual_pin1 == 1) // button press is 1
  { // toggle the off relay on then off  
    digitalWrite(14, LOW);
    Serial.println("off relay is on for 1.5s");
    delay(wait_time);
    Serial.println("off relay is off now!!");
    digitalWrite(14, HIGH);
  }
  else // othertimes this is off
  {
    digitalWrite(14, HIGH);
  }
}

void setup()
{ 
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH); // setting the on relay to off
  digitalWrite(14, HIGH); // setting the off relay to off
  delay(2000); // set delay of 2s
  /*
  the below code is for toggleing the off relay
  after a power cut
  */ 
  digitalWrite(14, LOW); // set the off relay on
  delay(1500); // set delay of 1.5s
  digitalWrite(14, HIGH); // set the relay to on
  Serial.begin(115200); // serial baud rate config
  Serial.println("Serial has .. started"); // init message
  delay(100); 
  BlynkEdgent.begin();
  Serial.println("BlynkEdgent has .. finished init");
}

void loop() 
{
  BlynkEdgent.run();
}
