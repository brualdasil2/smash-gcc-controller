#include <Arduino.h>
#include "Action.h"
typedef void (*FUNCTION)();

class Controller {
    private:
        void clearPressedButtons();
        int frame;
        int step;
        bool inputMode;
        Action* actions;
        DigitalControllerButton r = DigitalControllerButton(R_PIN, R, true);
        DigitalControllerButton l = DigitalControllerButton(L_PIN, L, true);
        DigitalControllerButton u = DigitalControllerButton(U_PIN, U, true);
        DigitalControllerButton d = DigitalControllerButton(D_PIN, D, true);
        DigitalControllerButton z = DigitalControllerButton(Z_PIN, Z, false);
        DigitalControllerButton s = DigitalControllerButton(S_PIN, S, true);
        DigitalControllerButton a = DigitalControllerButton(A_PIN, A, false);
        ControllerButton* buttons[AMT_CONTROLLER_BUTTONS] = {
            &r,
            &l,
            &u,
            &d,
            &z,
            &s,
            &a
        };
        void setPressedButtons(ActionButtonArray pressedButtons);
        void sendButtons();
    public:
        Controller();
        void tick();
        //void tick(FUNCTION onEnd);
        void reset();
        unsigned int getFrame();    
        void setActions(Action* actions);
        void inputModeOn();
        void inputModeOff();
};
