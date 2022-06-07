#include <Arduino.h>
#include "Action.h"

class Controller {
    private:
        void clearPressedButtons();
        int frame;
        int step;
        ControllerButton r = ControllerButton(R_PIN, R);
        ControllerButton l = ControllerButton(L_PIN, L);
        ControllerButton z = ControllerButton(Z_PIN, Z);
        ControllerButton buttons[AMT_CONTROLLER_BUTTONS] = { r, l, z };
        void setPressedButtons(ControllerButtons* pressedButtons, int amtButtons);
        void sendButtons();
    public:
        Controller();
        void tick(Action actions[]);
        void reset();
        unsigned int getFrame();
        
};
