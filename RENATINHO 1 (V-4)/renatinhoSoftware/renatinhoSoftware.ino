/*-------------------------------------ROCKET V4 "RENATINHO-1"  SOFTWARE-------------------------------------------------------- 

30/12/2025
*/

#include "mpu6050.h"
#include <math.h>
#include <Servo.h>

Servo servoForParachute;
int degrees = 0;
int enterDelay = 1200;
int pos = 0;

void setup() {

  servoForParachute.attach(9);
  Serial.begin(9600);

  mpu_begin();
  
  OnEnter();
  Serial.println("Calibrando, deixa parado!");
  delay(1000);
  mpu_calibrate(200);
  Serial.println("===== Calibrado! =====\n");

  mpu_reset();
}

void loop() {
  mpu_loop();
//X AND Z
 //Serial.print("roll(x):");
  //Serial.print("pitch(y):");
  //Serial.println(getAngleY()); // EM TORNO DO PRÓPRIO EIXO NA VERTICAL
 // Serial.print("yaw(z):");

  if( abs(getAngleZ()) > 45 ){
    Serial.println("parachute deployed");
    servoForParachute.write(degrees);
    Serial.print(" X :");
    Serial.println(getAngleZ());
  }

  if( abs(getAngleX()) > 45 ){
    Serial.println("parachute deployed");
    servoForParachute.write(degrees);
    Serial.print(" Y :");
    Serial.println(getAngleX());
  }
  else{
    Serial.println(".");
     // Serial.println(getAngleX());
  }
}

void OnEnter(){
  Serial.println("--------------- RocketParachuteSoftware ---------------");
  delay(enterDelay);
  Serial.println(" ");
   delay(enterDelay);
  Serial.println(" Welcome to Rocket Parachute Software Developed by Ian ");
   delay(enterDelay);
  Serial.println(" Souza Molina for the 'RENATINHO I'  project, part of the CVT-Space extension project");
   delay(enterDelay);
}


