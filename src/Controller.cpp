#include "Controller.h"

Controller::Controller() {
    for (ControllerButton button : buttons) {
        pinMode(button.getPin(), OUTPUT);
    }
    clearPressedButtons();
    step = 0;
    frame = -1;
}
void Controller::clearPressedButtons() {
    for (int i = 0; i < AMT_CONTROLLER_BUTTONS; i++) {
        buttons[i].unpress();
    }
}
void Controller::reset() {
    frame = -1;
    step = 0;
}
void Controller::sendButtons() {
    for (ControllerButton button : buttons) {
        if (button.isPressed()) {
            if (button.isInverted()) {
                digitalWrite(button.getPin(), LOW);
            }
            else {
                digitalWrite(button.getPin(), HIGH);
            }
        }
        else {
            if (button.isInverted()) {
                digitalWrite(button.getPin(), HIGH);
            }
            else {
                digitalWrite(button.getPin(), LOW);
            }
        }
    }
}
void Controller::tick(Action actions[]) {
    clearPressedButtons();
    if (frame > 0) {
        Action currentAction = actions[step];
        setPressedButtons(currentAction.getButtons(), currentAction.getAmtButtons());
        frame--;
        if (frame == 0) {
            step++;
            Action nextAction = actions[step];
            if (nextAction.getType() == END) {
                reset();
            }
            else {
                frame = nextAction.getFrames();
            }
        }
    }
    else if (frame == -1) {
        Action firstAction = actions[step];
        frame = firstAction.getFrames();
        setPressedButtons(firstAction.getButtons(), firstAction.getAmtButtons());
        frame--;
    }
    sendButtons();
}
void Controller::tick(Action actions[], FUNCTION onEnd) {
    clearPressedButtons();
    if (frame > 0) {
        Action currentAction = actions[step];
        setPressedButtons(currentAction.getButtons(), currentAction.getAmtButtons());
        frame--;
        if (frame == 0) {
            step++;
            Action nextAction = actions[step];
            if (nextAction.getType() == END) {
                reset();
                onEnd();
            }
            else {
                frame = nextAction.getFrames();
            }
        }
    }
    else if (frame == -1) {
        Action firstAction = actions[step];
        frame = firstAction.getFrames();
        setPressedButtons(firstAction.getButtons(), firstAction.getAmtButtons());
        frame--;
    }
    sendButtons();
}
void Controller::setPressedButtons(ControllerButtons* pressedButtons, int amtButtons) {
    for (int i = 0; i < amtButtons; i++) {
        buttons[pressedButtons[i]].press();
    }
}
unsigned int Controller::getFrame() {
    return frame;
}
