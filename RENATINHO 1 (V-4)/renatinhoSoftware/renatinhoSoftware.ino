/*-------------------------------------ROCKET V4 "RENATINHO-1"  SOFTWARE-------------------------------------------------------- 

30/12/2025
*/

#include "mpu6050.h"
#include <math.h>
#include <Servo.h>

Servo servoForParachute;
int degrees = 0;
int pos = 0;
bool parachuteState = false;

void setup() {

  servoForParachute.attach(9);
  Serial.begin(9600);

  mpu_begin();
  Serial.println("Calibrando, deixa parado!");
  delay(1000);
  mpu_calibrate(200);
  Serial.println("===== Calibrado! =====\n");

  mpu_reset();
}

void loop() {
  mpu_loop();
  //--- monitor serial configuration --- 

  // parachuteState  Zangle   Xangle 
  Serial.print(parachuteState);
  Serial.print(getAngleZ());
  Serial.println(getAngleX());

  if( abs(getAngleZ()) > 45 ){

    //parachute deployed
    parachuteState = true;
    servoForParachute.write(degrees);
  }

  if( abs(getAngleX()) > 45 ){

    //parachute deployed
    parachuteState = true;
    servoForParachute.write(degrees);
  }
}
//X AND Z
 //Serial.print("roll(x):");
  //Serial.print("pitch(y):");
  //Serial.println(getAngleY()); // EM TORNO DO PRÓPRIO EIXO NA VERTICAL
 // Serial.print("yaw(z):");


