#ifndef MG996R_DRIVER_HPP
#define MG996R_DRIVER_HPP

#include "Particle.h"

class MG996R_Driver {
public:
    MG996R_Driver(int pwmPin);
    void attach();
    void setServoAngle(int angle);

private:
    int _pwmPin;
    int _minPulseWidth;
    int _maxPulseWidth;
};

int pulseWidthToDutyCycle(int pulseWidth);

#endif