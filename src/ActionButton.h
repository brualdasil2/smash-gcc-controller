#include "ControllerButton.h"


/*
neutral: 0,3V -> 61
right: 0V
left: 0,1 V -> 20
*/

class ActionButton {
    private:
        ControllerButtonsEnum buttonCode;
        int value;
        bool analog;
    public:
        ActionButton(ControllerButtonsEnum buttonCode);
        ActionButton(ControllerButtonsEnum buttonCode, int value);
        ControllerButtonsEnum getButtonCode();
        int getValue();
        bool isAnalog();
};

typedef struct s_actionButtonArray {
    ActionButton* actionButtons;
    int amtButtons;
} ActionButtonArray;