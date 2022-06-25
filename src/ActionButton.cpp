#include "ActionButton.h"

ActionButton::ActionButton(ControllerButtonsEnum buttonCode) {
    ActionButton::buttonCode = buttonCode;
    analog = false;
}
ActionButton::ActionButton(ControllerButtonsEnum buttonCode, int value) {
    ActionButton::buttonCode = buttonCode;
    ActionButton::value = value;
    analog = true;
}
int ActionButton::getValue() {
    return value;
}
bool ActionButton::isAnalog() {
    return analog;
}
ControllerButtonsEnum ActionButton::getButtonCode() {
    return buttonCode;
}