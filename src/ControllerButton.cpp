#include "ControllerButton.h"

ControllerButton::ControllerButton(int pin, int index) {
    ControllerButton::pin = pin;
    ControllerButton::index = index;
    ControllerButton::inverted = false;
}
ControllerButton::ControllerButton(int pin, int index, bool inverted) {
    ControllerButton::pin = pin;
    ControllerButton::index = index;
    ControllerButton::inverted = inverted;
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
void ControllerButton::press() {
    pressed = true;
}
void ControllerButton::unpress() {
    pressed = false;
}
