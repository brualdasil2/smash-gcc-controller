#include <Arduino.h>
#include "Action.h"
typedef void (*FUNCTION)();

class Controller {
    private:
        void clearPressedButtons();
        int frame;
        int step;
        ControllerButton r = ControllerButton(R_PIN, R);
        ControllerButton l = ControllerButton(L_PIN, L);
        ControllerButton z = ControllerButton(Z_PIN, Z);
        ControllerButton s = ControllerButton(S_PIN, S, true);
        ControllerButton u = ControllerButton(U_PIN, U);
        ControllerButton d = ControllerButton(D_PIN, D);
        ControllerButton a = ControllerButton(A_PIN, A);
        ControllerButton buttons[AMT_CONTROLLER_BUTTONS] = { r, l, z, s, u, d, a };
        void setPressedButtons(ControllerButtons* pressedButtons, int amtButtons);
        void sendButtons();
    public:
        Controller();
        void tick(Action actions[]);
        void tick(Action actions[], FUNCTION onEnd);
        void reset();
        unsigned int getFrame();
        
};
