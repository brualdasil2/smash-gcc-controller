#include "ControllerButton.h"

enum ActionType { NORMAL, END, LOOP };

class Action {
    private:
        ControllerButtons* buttons;
        int amtButtons;
        int frames;
        ActionType type;
    public:
        Action(ControllerButtons* buttons, int amtButtons, int frames);
        Action(ActionType type);
        ControllerButtons* getButtons();
        int getAmtButtons();
        int getFrames();
        ActionType getType();
};