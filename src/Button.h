typedef void (*FUNCTION)();

class Button {
  protected:
    int pin;
    FUNCTION onClick;
    FUNCTION onRelease;
  public:
    Button(int pin, FUNCTION onClick);
    void checkClick();
    int getPin();
};

class ClickButton : public Button {
  private:
    bool clicked;
  public:
    ClickButton(int pin, FUNCTION onClick);
    void checkClick();
};

class HoldButton : public Button {
  private:
    FUNCTION onRelease;
  public:
    HoldButton(int pin, FUNCTION onClick, FUNCTION onRelease);
    void checkClick();
};