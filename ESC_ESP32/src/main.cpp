#include <Arduino.h>
#include <WiFi.h>
#include <DabbleESP32.h>
#include <ESP32Servo.h>
#include "ESC.h"

ESC L_motor;
ESC R_motor;

void _setup() {
  L_motor.attach(14);
  R_motor.attach(15);

  Dabble.begin("UDAY_UGV");
}

void _loop() {
  Dabble.processInput();
}

void setup() {
  Serial.begin(9600);
  _setup();
}

void loop() {
  _loop();
  if (GamePad.isPressed(0)) {
    Serial.println("FORWARD");
    L_motor.setDirection(ESC::FORWARD);
    L_motor.setSpeed(30);

    R_motor.setDirection(ESC::FORWARD);
    R_motor.setSpeed(30);
    
  }
  else if (GamePad.isPressed(1)){
    Serial.println("REVERSE");
    L_motor.setDirection(ESC::FORWARD);
    L_motor.setSpeed(30);

    R_motor.setDirection(ESC::FORWARD);
    R_motor.setSpeed(0);
  }
  else if (GamePad.isPressed(3)) {
   Serial.println("RIGHT");
  
    L_motor.setDirection(ESC::FORWARD);
    L_motor.setSpeed(30);

    R_motor.setDirection(ESC::FORWARD);
    R_motor.setSpeed(0);
  }
  else if (GamePad.isPressed(2)) {
    Serial.println("LEFT");
    L_motor.setDirection(ESC::FORWARD);
    L_motor.setSpeed(30);

    R_motor.setDirection(ESC::FORWARD);
    R_motor.setSpeed(30);
  }
}