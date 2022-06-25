#include <Arduino.h>
enum ControllerButtonsEnum { R, L, U, D, Z, S, A };

#define AMT_CONTROLLER_BUTTONS 7
#define R_PIN 7
#define L_PIN 6
#define U_PIN 5
#define D_PIN 4
#define Z_PIN 8
#define S_PIN 9
#define A_PIN 10

class ControllerButton {
    protected:
        int pin;
        int index;
        bool pressed;
        bool inverted;
        bool reading;
        bool analog;
    public:
        ControllerButton(int pin, int index);
        ControllerButton(int pin, int index, bool inverted);
        int getPin();
        int getIndex();
        bool isPressed();
        bool isInverted();
        bool isReading();
        bool isAnalog();
        void press();
        void unpress();
        virtual void setAnalogValue(int value) = 0;
        virtual void sendSignal() = 0;
};

class DigitalControllerButton : public ControllerButton {
    public:
        DigitalControllerButton(int pin, int index);
        DigitalControllerButton(int pin, int index, bool inverted);
        void setAnalogValue(int value);
        void sendSignal();
};

class AnalogControllerButton : public ControllerButton {
    private:
        int analogValue;
        int neutralValue;
        int minValue;
        int maxValue;
    public:
        AnalogControllerButton(int pin, int index, int neutralValue, int minValue, int maxValue);
        void sendSignal();
        void setAnalogValue(int value);
        // void setAnalogValue(int analogValue);
        // int getAnalogValue();
};