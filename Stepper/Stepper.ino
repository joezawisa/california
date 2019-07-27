#include "Stepper.h"

Stepper motor(200, 8, 5, 4, 2, 3);

void setup() {
  // Put you setup code here
  Serial.begin(9600);
}

void loop() {
  // If a command has been sent
  if(Serial.available() > 0) {
    char command = Serial.read();
    
    switch(command) {
      case 'S': { // Speed
        motor.speed(Serial.parseInt());
        Serial.println("OK");
        break;
      }
      case 'R': { // Rotate
        motor.rotate(Serial.parseInt());
        Serial.println("OK");
        break;
      }
      case 'V': { // Revolve
        motor.revolve(Serial.parseInt());
        Serial.println("OK");
        break;
      }
      case 'M': { // Move
        motor.move(Serial.parseFloat());
        Serial.println("OK");
        break;
      }
      case 'Q': { // Square
        double distance = Serial.parseFloat();
        int hold = Serial.parseInt();
        int cycles = Serial.parseInt();
        motor.square(distance, hold, cycles);
        Serial.println("OK");
        break;
      }
      case 'E': { // End Serial Communication
        Serial.end();
        break;
      }
    }
  }
}
