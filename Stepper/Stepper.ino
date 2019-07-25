#include "Stepper.h"

Stepper motor(200, 25, 2, 3, 4, 5);

void setup() {
  // Put you setup code here
  Serial.begin(9600);
}

void loop() {
  // If a command has been sent
  if(Serial.available() > 0) {
    char command = Serial.read();
    
    switch(command) {
      case 'S': { // Rotate
        motor.rotate(Serial.parseInt());
        Serial.println("OK");
        break;
      }
      case 'V': { // Revolve
        motor.revolve(Serial.parseInt());
        Serial.println("OK");
        break;
      }
    }
  }
}
