#ifndef MG996R_DRIVER_H
#define MG996R_DRIVER_H

#include "Particle.h"

class Mg996rDriver {
public:
    Mg996rDriver(int pwm_pin);
    void Attach();
    void SetServoAngle(int angle);

private:
    int pwm_pin_;
    int min_pulse_width_;
    int max_pulse_width_;
};

int PulseWidthToDutyCycle(int pulse_width);

#endif