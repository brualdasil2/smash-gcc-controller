#include <Arduino.h>
#include "Button.h"


Button::Button(int pin, FUNCTION onClick) {
    Button::pin = pin;
    Button::onClick = onClick;
}

int Button::getPin() {
    return pin;
}



ClickButton::ClickButton(int pin, FUNCTION onClick) : Button(pin, onClick) {
    ClickButton::clicked = false;
}

void ClickButton::checkClick() {
    if (digitalRead(pin) == HIGH) {
        if (!clicked) {
            onClick();
            clicked = true;
        }
    }
    else {
        clicked = false;
    }
}

HoldButton::HoldButton(int pin, FUNCTION onClick, FUNCTION onRelease) : Button(pin, onClick) {
    HoldButton::onRelease = onRelease;
}

void HoldButton::checkClick() {
    if (digitalRead(pin) == HIGH) {
        onClick();
    }
    else {
        onRelease();
    }
}
