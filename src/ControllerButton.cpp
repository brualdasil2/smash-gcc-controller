#include "ControllerButton.h"

ControllerButton::ControllerButton(int pin, int index) {
    ControllerButton::pin = pin;
    ControllerButton::index = index;
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
void ControllerButton::press() {
    pressed = true;
}
void ControllerButton::unpress() {
    pressed = false;
}
