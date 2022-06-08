enum ControllerButtons { R, L, Z, S, U, D, A };
#define AMT_CONTROLLER_BUTTONS 7
#define R_PIN 5
#define L_PIN 4
#define Z_PIN 6
#define S_PIN 7
#define D_PIN 9
#define U_PIN 8
#define A_PIN 10

class ControllerButton {
    private:
        int pin;
        int index;
        bool pressed;
        bool inverted;
    public:
        ControllerButton(int pin, int index);
        ControllerButton(int pin, int index, bool inverted);
        int getPin();
        int getIndex();
        bool isPressed();
        bool isInverted();
        void press();
        void unpress();
};