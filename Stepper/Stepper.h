//
// Heartbeat
// Stepper.h
// by Joe Zawisa
//

#ifndef JZ_HEARTBEAT
#define JZ_HEARTBEAT

class Stepper {
public:
    // Constructor
    Stepper(const int _StepsPerRevolution, const int _StepsPerMM, const int _PinA, const int _PinB, const int _PinC, const int _PinD);
    
    // Set the motor's speed
    void setSpeed(const int mmPerSecond);
    
    // Rotate a specified number of steps
    void rotate(const int numberOfSteps);
    
    // Rotate the motor a specified number of revolutions
    void revolve(const double numberOfRevs);
    
    // Rotate the motor a specified number of mm
    void move(const double distance);
    
    // Power the motor with a square wave
    void square(const double distance, const unsigned long int hold, const unsigned long int cycles);

    // Power the motor at a specified frequency
    void frequency(const double distance, const double frequency, const double hours);
    
private:
    const int PinA, PinB; // Pins A and B are on the same coil
    const int PinC, PinD; // Pins C and D are on the same coil
    const int StepsPerRevolution; // Steps Per Revolution
    const int StepsPerMM; // Steps per mm
    
    int step; // Current Step
    int pause; // Milliseconds to pause between each step
    
    // Set the motor to a particular stepping sequence
    void set(const int sequence);
};

#endif
