#include "Action.h"

Action::Action(ControllerButtons* buttons, int amtButtons, int frames) {
    Action::buttons = buttons;
    Action::amtButtons = amtButtons;
    Action::frames = frames;
    Action::type = NORMAL;
}
Action::Action(ActionType type) {
    Action::type = type;
}
ControllerButtons* Action::getButtons() {
    return buttons;
}
int Action::getAmtButtons() {
    return amtButtons;
}
int Action::getFrames() {
    return frames;
}
ActionType Action::getType() {
    return type;
}