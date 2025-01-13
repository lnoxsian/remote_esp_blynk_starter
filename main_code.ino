#define BLYNK_TEMPLATE_ID "template_id" \\ set the sample temlpate id
#define BLYNK_TEMPLATE_NAME "template_name" \\ set the sameple template name

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial

#define APP_DEBUG

#include "BlynkEdgent.h"

int wait_time = 1500;

BLYNK_WRITE(V0) // on relay is V0
{
  int virtual_pin0  = param.asInt();
  if(virtual_pin0 == 1)
  {
    digitalWrite(12, LOW);
    Serial.println("on relay is on for 10s");
    delay(wait_time);
    Serial.println("on relay is off now!!");
    digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(12, HIGH);
  }
}

BLYNK_WRITE(V1) // off relay is V1
{
  int virtual_pin1  = param.asInt();
  if(virtual_pin1 == 1)
  {
    digitalWrite(14, LOW);
    Serial.println("off relay is on for 10s");
    delay(wait_time);
    Serial.println("off relay is off now!!");
    digitalWrite(14, HIGH);
  }
  else
  {
    digitalWrite(14, HIGH);
  }
}

void setup()
{ 
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  digitalWrite(14, HIGH);
  delay(2000);
  digitalWrite(14, LOW);
  delay(1500);
  digitalWrite(14, HIGH);
  Serial.begin(115200);
  Serial.println("Serial has .. started");
  delay(100);
  BlynkEdgent.begin();
  Serial.println("BlynkEdgent has .. finished init");
}

void loop() 
{
  BlynkEdgent.run();
}
