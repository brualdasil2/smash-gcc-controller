enum ControllerButtons { R, L, Z };
#define AMT_CONTROLLER_BUTTONS 3
#define R_PIN 4
#define L_PIN 5
#define Z_PIN 6

class ControllerButton {
    private:
        int pin;
        int index;
        bool pressed;
    public:
        ControllerButton(int pin, int index);
        ControllerButton();
        int getPin();
        int getIndex();
        bool isPressed();
        void press();
        void unpress();
};