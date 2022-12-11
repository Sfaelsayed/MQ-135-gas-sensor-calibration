// The load resistance on the board
#define RLOAD 22.0
// Calibration resistance at atmospheric CO2 level
#define RZERO 879.13
#include "MQ135.h"
MQ135 gasSensor = MQ135(A6);
int val;
int gasPin = A6;
int sensorValue = 450;
void setup() {
  Serial.begin(9600);
  pinMode(gasPin, INPUT);
}

void loop() {
  val = analogRead(A6);
  // Serial.print ("raw = ");
  // Serial.println (val);
  float zero = gasSensor.getRZero();
  // Serial.print ("rzero: ");
  // Serial.println (zero);
  float ppt = gasSensor.getPPM();
  Serial.print("ppt: ");
  Serial.println(ppt);
  delay(2000);
}