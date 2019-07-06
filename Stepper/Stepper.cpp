//
// California
// Stepper.cpp
// by Joseph Zawisa
//

#include "Arduino.h"
#include "Stepper.h"

Stepper::Stepper(const int _StepsPerRevolution, const int _PinA, const int _PinB, const int _PinC, const int _PinD) : PinA(_PinA), PinB(_PinB), PinC(_PinC), PinD(_PinD), StepsPerRevolution(_StepsPerRevolution) {
    // Configure I/O pins
    pinMode(PinA, OUTPUT);
    pinMode(PinB, OUTPUT);
    pinMode(PinC, OUTPUT);
    pinMode(PinD, OUTPUT);
    
    // Start on step 0
    step(current = 0);
    
    // Set delay
    pause = 3;
}

// Go to a step
void Stepper::step(const int sequence) {
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
    for(int i = 0; i < numberOfSteps; ++i) {
        step(++current % 4);
        delay(pause);
    }
}
