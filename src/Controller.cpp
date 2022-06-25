#include "Controller.h"

Controller::Controller() {
    inputModeOff();
    clearPressedButtons();
    step = 0;
    frame = -1;
}
void Controller::clearPressedButtons() {
    for (int i = 0; i < AMT_CONTROLLER_BUTTONS; i++) {
        buttons[i]->unpress();
    }
}
void Controller::inputModeOn() {
    inputMode = true;
    for (ControllerButton* button : buttons) {
        pinMode(button->getPin(), INPUT);
    }
}
void Controller::inputModeOff() {
    inputMode = false;
    for (ControllerButton* button : buttons) {
        pinMode(button->getPin(), OUTPUT);
    }
}
void Controller::reset() {
    frame = -1;
    step = 0;
}
void Controller::sendButtons() {
    if (inputMode) return;
    for (ControllerButton* button : buttons) {
        button->sendSignal();
    }
}
void Controller::tick() {
    clearPressedButtons();
    if (frame > 0) {
        Action currentAction = actions[step];
        // TODO
        setPressedButtons(currentAction.getButtons());
        frame--;
        if (frame == 0) {
            step++;
            Action nextAction = actions[step];
            if (nextAction.getType() == END) {
                reset();
            }
            else if (nextAction.getType() == NEXT) {
                actions = nextAction.getNextActions();
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
        setPressedButtons(firstAction.getButtons());
        frame--;
    }
    sendButtons();
}
void Controller::setPressedButtons(ActionButtonArray pressedButtons) {
    for (int i = 0; i < pressedButtons.amtButtons; i++) {
        buttons[pressedButtons.actionButtons[i].getButtonCode()]->press();
        if (pressedButtons.actionButtons[i].isAnalog()) {
            buttons[pressedButtons.actionButtons[i].getButtonCode()]->setAnalogValue(pressedButtons.actionButtons[i].getValue());
        }
    }
}
unsigned int Controller::getFrame() {
    return frame;
}
void Controller::setActions(Action* actions) {
    Controller::actions = actions;
    reset();
}