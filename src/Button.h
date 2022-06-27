typedef void (*FUNCTION)();

#define DOUBLE_CLICK_FRAME_WINDOW 15

class Button {
  protected:
    int pin;
    FUNCTION onClick;
    int doubleClickFrameCounter;
  public:
    Button(int pin, FUNCTION onClick);
    void checkClick();
    int getPin();
};

class ClickButton : public Button {
  private:
    bool clicked;
    FUNCTION onDoubleClick;
  public:
    ClickButton(int pin, FUNCTION onClick);
    ClickButton(int pin, FUNCTION onClick, FUNCTION onDoubleClick);
    void checkClick();
};

class HoldButton : public Button {
  private:
    FUNCTION onRelease;
  public:
    HoldButton(int pin, FUNCTION onClick, FUNCTION onRelease);
    void checkClick();
};