#include "../include/MG996R_Driver.hpp"


MG996R_Driver::MG996R_Driver(int pwmPin) : _pwmPin(pwmPin), _minPulseWidth(1000), _maxPulseWidth(2000) {
    pinMode(_pwmPin, OUTPUT);
}

void MG996R_Driver::attach() {
    // Additional setup if needed, e.g., timer configuration
}

void MG996R_Driver::setServoAngle(int angle) {
    angle = constrain(angle, 0, 180);  // Constrain angle to the servo's range

    int pulseWidth = map(angle, 0, 180, _minPulseWidth, _maxPulseWidth);

    // Convert pulse width to duty cycle (0-255) and write to PWM pin
    int dutyCycle = pulseWidthToDutyCycle(pulseWidth);

    analogWrite(_pwmPin, dutyCycle);
}

// Function to convert pulse width in microseconds to duty cycle (0-255)
int pulseWidthToDutyCycle(int pulseWidth) {
    int dutyCycle = map(pulseWidth, 1000, 2000, 128, 255);
    return dutyCycle;
}