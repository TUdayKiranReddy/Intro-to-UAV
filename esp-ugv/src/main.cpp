#include <Arduino.h>

#include <WiFi.h>
#include <esp32PWMUtilities.h>

#include <DabbleESP32.h>

Motor Motor1;
Motor Motor2;

int L_speed = 100;
int R_speed = 100;
int R_SENSOR_D0 = 34;
int L_SENSOR_D0 = 35;

int sample_interval = 1000;

void BLE_setup() {
  Motor1.attach(14, 17, 16);

  Motor2.attach(15, 19, 18);

  Dabble.begin("UDAY UGV");
}

void BLE_loop() {
  Dabble.processInput();
}

volatile unsigned int L_counter=0, R_counter=0;
double L_rpm, R_rpm;
uint32_t L_previousMillis=0, R_previousMillis=0;

void L_countpulse(){
  L_counter++;
}

void R_countpulse(){
  R_counter++;
}

void speedSensor_setup() {
  Serial.begin(9600);
  pinMode(R_SENSOR_D0, INPUT);
  pinMode(L_SENSOR_D0, INPUT);
  attachInterrupt(digitalPinToInterrupt(L_SENSOR_D0), L_countpulse, RISING);
  attachInterrupt(digitalPinToInterrupt(R_SENSOR_D0), R_countpulse, RISING);
}
 
void speedSensor_loop() {
  if(millis() - L_previousMillis >= sample_interval){
    // detachInterrupt(L_SENSOR_D0);
    L_rpm = (60*1000/20)/(millis()-L_previousMillis)*L_counter;
    L_previousMillis = millis();
    L_counter = 0;
  }

  if(millis() - R_previousMillis >= sample_interval){
    // detachInterrupt(R_SENSOR_D0);
    R_rpm = (60*1000/20)/(millis()-R_previousMillis)*R_counter;
    R_previousMillis = millis();
    R_counter = 0;
  }


  Serial.print("Left_Motor:");
  Serial.print(L_rpm);
  Serial.print(",");
  Serial.print("Right_Motor:");
  Serial.println(R_rpm);
   
}

void setup() {
  BLE_setup();
  speedSensor_setup();
}

void loop() {
  BLE_loop();

  if (GamePad.isPressed(0)) {
    Motor1.moveMotor(2.55 * L_speed);
    Motor2.moveMotor(2.55 * R_speed);
  }
  else {
    if (GamePad.isPressed(1)) {
      Motor1.moveMotor(-2.55 * L_speed);
      Motor2.moveMotor(-2.55 * R_speed);
    }
    else {
      if (GamePad.isPressed(3)) {
        Motor1.moveMotor(2.55 * L_speed);
        Motor2.moveMotor(-2.55 * R_speed);
      }
      else {
        if (GamePad.isPressed(2)) {
          Motor1.moveMotor(-2.55 * L_speed);
          Motor2.moveMotor(2.55 * R_speed);
        }
        else {
          Motor1.lockMotor();
          Motor2.lockMotor();
        }
      }
    }
  }

  speedSensor_loop();
}
