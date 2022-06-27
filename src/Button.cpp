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
ClickButton::ClickButton(int pin, FUNCTION onClick, FUNCTION onDoubleClick) : Button(pin, onClick) {
    ClickButton::clicked = false;
    ClickButton::onDoubleClick = onDoubleClick;
}

void ClickButton::checkClick() {
    if (digitalRead(pin) == HIGH) {
        if (!clicked) {
            clicked = true;
            if (doubleClickFrameCounter == 0) {
                doubleClickFrameCounter = DOUBLE_CLICK_FRAME_WINDOW;
            }
            else {
                onDoubleClick();
                doubleClickFrameCounter = 0;
            }
        }
    }
    else {
        clicked = false;
    }
    if (doubleClickFrameCounter > 0) {
        doubleClickFrameCounter--;
        if (doubleClickFrameCounter == 0) {
            onClick();
        }
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
