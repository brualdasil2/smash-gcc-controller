#include "ControllerButton.h"

ControllerButton::ControllerButton(int pin, int index) {
    ControllerButton::pin = pin;
    ControllerButton::index = index;
    ControllerButton::analog = false;
    ControllerButton::inverted = false;
    ControllerButton::pressed = false;
    ControllerButton::reading = false;
}
ControllerButton::ControllerButton(int pin, int index, bool inverted) {
    ControllerButton::pin = pin;
    ControllerButton::index = index;
    ControllerButton::analog = false;
    ControllerButton::inverted = inverted;
    ControllerButton::pressed = false;
    ControllerButton::reading = false;
}
int ControllerButton::getPin() {
    return pin;
}
int ControllerButton::getIndex() {
    return index;
}
bool ControllerButton::isPressed() {
    return pressed;
}
bool ControllerButton::isInverted() {
    return inverted;
}
bool ControllerButton::isReading() {
    return reading;
}
bool ControllerButton::isAnalog() {
    return analog;
}
void ControllerButton::press() {
    pressed = true;
}
void ControllerButton::unpress() {
    pressed = false;
}

DigitalControllerButton::DigitalControllerButton(int pin, int index) : ControllerButton(pin, index) {
    return;
}
DigitalControllerButton::DigitalControllerButton(int pin, int index, bool inverted) : ControllerButton(pin, index, inverted) {
    return;
}
void DigitalControllerButton::setAnalogValue(int value) {
    return;
}
void DigitalControllerButton::sendSignal() {
    if (pressed) {
        if (inverted) {
            digitalWrite(pin, HIGH);
        }
        else {
            digitalWrite(pin, LOW);
        }
    }
    else {
        if (inverted) {
            digitalWrite(pin, LOW);
        }
        else {
            digitalWrite(pin, HIGH);
        }
    }
}

AnalogControllerButton::AnalogControllerButton(int pin, int index, int neutralValue, int minValue, int maxValue) : ControllerButton(pin, index) {
    analog = true;
    AnalogControllerButton::neutralValue = neutralValue;
    AnalogControllerButton::minValue = minValue;
    AnalogControllerButton::maxValue = maxValue;
    AnalogControllerButton::analogValue = neutralValue;
}
// AnalogControllerButton::getAnalogValue() {
//     return analogValue;
// }
void AnalogControllerButton::setAnalogValue(int analogValue) {
    AnalogControllerButton::analogValue = analogValue;
}
void AnalogControllerButton::sendSignal() {
    if (pressed) {
        analogWrite(pin, analogValue);
    }
    else {
        analogWrite(pin, neutralValue);
    }
}
// int AnalogControllerButton::getAnalogValue() {
//     return analogValue;
// }
