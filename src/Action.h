#include "ActionButton.h"

enum ActionType { NORMAL, END, NEXT };

class Action {
    private:
        ActionButtonArray actionButtons;
        int frames;
        ActionType type;
        Action* nextActions;
    public:
        Action(ActionButtonArray actionButtons, int frames);
        Action(ActionType type);
        Action(Action* nextActions);
        ActionButtonArray getButtons();
        int getAmtButtons();
        int getFrames();
        Action* getNextActions();
        ActionType getType();
};