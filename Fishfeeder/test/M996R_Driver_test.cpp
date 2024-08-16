/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "../include/MG996R_Driver.hpp"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

MG996R_Driver servo(D0);

// setup() runs once, when the device is first turned on
void setup() {
  pinMode(D0, OUTPUT);
  //servo.attach();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  //analogWrite(D0, 64);
  //delay(2000);
  //analogWrite(D0, 128);
  //delay(2000);
  //analogWrite(D0, 192);
  //delay(2000);

  for (int i = 0; i <= 180; i++) {
    servo.setServoAngle(i);
    delay(10);
  }
  delay(1000);

  servo.setServoAngle(0);
  delay(2000);
}