#include "../include/mg996r_driver.h"


Mg996rDriver::Mg996rDriver(int pwm_pin) : pwm_pin_(pwm_pin), min_pulse_width_(1000), max_pulse_width_(2000) {
    pinMode(pwm_pin_, OUTPUT);
}

void Mg996rDriver::Attach() {
    // Additional setup if needed, e.g., timer configuration
}

void Mg996rDriver::SetServoAngle(int angle) {
    angle = constrain(angle, 0, 180);  // Constrain angle to the servo's range

    int pulse_width = map(angle, 0, 180, min_pulse_width_, max_pulse_width_);

    // Convert pulse width to duty cycle (0-255) and write to PWM pin
    int duty_cycle = pulseWidthToDutyCycle(pulse_width);

    analogWrite(pwm_pin_, duty_cycle);
}

// Function to convert pulse width in microseconds to duty cycle (0-255)
int pulseWidthToDutyCycle(int pulseWidth) {
    int dutyCycle = map(pulseWidth, 1000, 2000, 128, 255);
    return dutyCycle;
}