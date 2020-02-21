//
// Heartbeat
// Stepper.cpp
// by Joseph Zawisa
//

#include "Arduino.h"
#include "Stepper.h"

// Constructor
Stepper::Stepper(const int _StepsPerRevolution, const int _StepsPerMM, const int _PinA, const int _PinB, const int _PinC, const int _PinD) : PinA(_PinA), PinB(_PinB), PinC(_PinC), PinD(_PinD), StepsPerRevolution(_StepsPerRevolution), StepsPerMM(_StepsPerMM) {
    // Configure I/O pins
    pinMode(PinA, OUTPUT);
    pinMode(PinB, OUTPUT);
    pinMode(PinC, OUTPUT);
    pinMode(PinD, OUTPUT);
    
    // Start on step 0
    set(step = 0);
    
    // Set delay
    pause = 10;
}

// Set the motor to a particular stepping sequence
void Stepper::set(const int sequence) {
    switch(sequence) {
        case 0: { // Step 0
            digitalWrite(PinA, HIGH);
            digitalWrite(PinB, LOW);
            digitalWrite(PinC, HIGH);
            digitalWrite(PinD, LOW);
            break;
        }
        case 1: { // Step 1
            digitalWrite(PinA, LOW);
            digitalWrite(PinB, HIGH);
            digitalWrite(PinC, HIGH);
            digitalWrite(PinD, LOW);
            break;
        }
        case 2: { // Step 2
            digitalWrite(PinA, LOW);
            digitalWrite(PinB, HIGH);
            digitalWrite(PinC, LOW);
            digitalWrite(PinD, HIGH);
            break;
        }
        case 3: { // Step 3
            digitalWrite(PinA, HIGH);
            digitalWrite(PinB, LOW);
            digitalWrite(PinC, LOW);
            digitalWrite(PinD, HIGH);
            break;
        }
        default: { // Invalid sequence
            // TODO: Throw an exception
            break;
        }
    }
}

// Set the motor's speed
void Stepper::setSpeed(int mmPerSecond) {
    if(mmPerSecond > 31) mmPerSecond = 31; // Max is 31 mm/s
    pause = 1000 / (mmPerSecond * StepsPerMM);
}

// Rotate a specified number of steps
void Stepper::rotate(const int numberOfSteps) {
    // Count up to the right number of steps
    for(int i = 0; i < abs(numberOfSteps); ++i) {
        // Update the current step
        if(numberOfSteps > 0) {
            ++step;
            if(step == StepsPerRevolution) step = 0;
        } else {
            --step;
            if(step < 0) step = StepsPerRevolution - 1;
        }
        
        // Set the motor to the right sequence
        set(step % 4);
        
        // Keep the right speed
        delay(pause);
    }
}

// Rotate the motor a specified number of revolutions
void Stepper::revolve(const double numberOfRevs) {
    rotate(floor(numberOfRevs * StepsPerRevolution));
}

// Rotate the motor a specified number of mm
void Stepper::move(const double distance) {
    rotate(floor(distance * StepsPerMM));
}

// Power the motor with a square wave
void Stepper::square(const double distance, const unsigned long int hold, const unsigned long int cycles) {
    for(unsigned long int i = 0; i < cycles; ++i) {
        move(distance);
        delay(hold);
        move(-distance);
        delay(hold);
    }
}

// Power the motor at a specified frequency
void Stepper::frequency(const double distance, const double frequency, const double hours) {
  const double hold = 1; // Hold for 1 ms
  double period = 1000 / frequency; // Period for back/forth movement
  double moveTime = (period - (2 * hold)) / 2; // Time to move each direction
  double speed = distance / moveTime * 1000; // Speed at which to move
  setSpeed(speed); // Set the speed
  double cycles = frequency * 3600 * hours; // 3600 seconds/hour * hours

  // Start a square wave
  square(distance, hold, cycles);
}
