#include <ESP32Servo.h>
#include "ESC.h"

ESC esc(ESC::MODE_FORWARD_BACKWARD);

void setup() 
{
  Serial.begin(9600);
  esc.attach(14);
} 
 
void loop() 
{ 
    esc.setSpeed(0);
    esc.setDirection(ESC::FORWARD);
    esc.setSpeed(30);
    delay(1000);
    esc.setSpeed(0);
    esc.setDirection(ESC::BACKWARD);
    esc.setSpeed(30);
    delay(1000);
} 