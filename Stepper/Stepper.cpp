//
// California
// Stepper.cpp
// by Joseph Zawisa
//

#include "Arduino.h"
#include "Stepper.h"

// Constructor
Stepper::Stepper(const int _StepsPerRevolution, const int _PinA, const int _PinB, const int _PinC, const int _PinD) : PinA(_PinA), PinB(_PinB), PinC(_PinC), PinD(_PinD), StepsPerRevolution(_StepsPerRevolution) {
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

// Rotate the motor one revolution
void Stepper::revolve(const bool direction) {
    if(direction) {
        rotate(StepsPerRevolution);
    }
    else {
        rotate(-StepsPerRevolution);
    }
}
