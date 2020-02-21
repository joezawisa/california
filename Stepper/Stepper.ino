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
        motor.setSpeed(Serial.parseInt());
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
        Serial.read(); // Ignore a space
        unsigned long int hold = strtoul(Serial.readStringUntil(' ').c_str(), NULL, 10);
        unsigned long int cycles = strtoul(Serial.readStringUntil(' ').c_str(), NULL, 10);
        motor.square(distance, hold, cycles);
        Serial.println("OK");
        break;
      }
      case 'F': { // Frequency
        double distance = Serial.parseFloat();
        double frequency = Serial.parseFloat();
        double hours = Serial.parseFloat();
        
        motor.frequency(distance, frequency, hours);
      }
      case 'E': { // End Serial Communication
        Serial.end();
        break;
      }
    }
  }
}
