#define BLYNK_TEMPLATE_ID "template_id"
#define BLYNK_TEMPLATE_NAME "template_name"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial

#define APP_DEBUG

#include "BlynkEdgent.h"

int wait_time = 5000;

BLYNK_WRITE(V0) // on relay is V0
{
  int virtual_pin0  = param.asInt();
  if(virtual_pin0 == 1)
  {
    digitalWrite(12, HIGH);
    Serial.println("on relay is on for 10s");
    delay(wait_time);
    Serial.println("on relay is off now!!");
    digitalWrite(12, LOW);
  }
  else
  {
    digitalWrite(12, LOW);
  }
}

BLYNK_WRITE(V1) // off relay is V1
{
  int virtual_pin1  = param.asInt();
  if(virtual_pin1 == 1)
  {
    digitalWrite(14, HIGH);
    Serial.println("off relay is on for 10s");
    delay(wait_time);
    Serial.println("off relay is off now!!");
    digitalWrite(14, LOW);
  }
  else
  {
    digitalWrite(14, LOW);
  }
}

void setup()
{ 
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(115200);
  Serial.println("Serial has .. started");
  delay(100);
  BlynkEdgent.begin();
  Serial.println("BlynkEdgent has .. finished init");
}

void loop() 
{
  Serial.println("BlynkEdgent has .. started to run");
  BlynkEdgent.run();
}
