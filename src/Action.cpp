#include "Action.h"

Action::Action(ActionButtonArray actionButtons, int frames) {
    Action::actionButtons = actionButtons;
    Action::frames = frames;
    Action::type = NORMAL;
}
Action::Action(ActionType type) {
    Action::type = type;
}
Action::Action(Action* nextActions) {
    type = NEXT;
    Action::nextActions = nextActions;
}
ActionButtonArray Action::getButtons() {
    return actionButtons;
}
int Action::getFrames() {
    return frames;
}
ActionType Action::getType() {
    return type;
}
Action* Action::getNextActions() {
    return nextActions;
}