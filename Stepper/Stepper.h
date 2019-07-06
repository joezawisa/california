//
// California
// Stepper.h
// by Joe Zawisa
//

#ifndef JZ_CALIFORNIA
#define JZ_CALIFORNIA

class Stepper {
public:
    Stepper(const int _StepsPerRevolution, const int _PinA, const int _PinB, const int _PinC, const int _PinD);
    
private:
    const int PinA, PinB; // Pins A and B are on the same coil
    const int PinC, PinD; // Pins C and D are on the same coil
    const int StepsPerRevolution; // Steps Per Revolution
    
    int current; // Current Step
};

#endif
