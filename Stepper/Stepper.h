//
// California
// Stepper.h
// by Joe Zawisa
//

#ifndef JZ_CALIFORNIA
#define JZ_CALIFORNIA

class Stepper {
public:
    // Constructor
    Stepper(const int _StepsPerRevolution, const int _PinA, const int _PinB, const int _PinC, const int _PinD);
    
    // Rotate a specified number of steps
    void rotate(const int numberOfSteps);
    
private:
    const int PinA, PinB; // Pins A and B are on the same coil
    const int PinC, PinD; // Pins C and D are on the same coil
    const int StepsPerRevolution; // Steps Per Revolution
    
    int current; // Current Step
    int pause; // Milliseconds to pause between each step
    
    // Set the motor to a particular stepping sequence
    void set(const int sequence);
};

#endif
