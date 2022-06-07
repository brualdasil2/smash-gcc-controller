#include <Arduino.h>
#include "Button.h"
#include "Actions.h"

enum Mode { NOTHING, DI_RIGHT_AD, DI_LEFT_AD };
#define MAX_MODE 2

Controller controller = Controller();

int mode = 0;
void changeMode() {
  mode++;
  if (mode > MAX_MODE) {
    mode = 0;
  }
  controller.reset();
}
ClickButton modeButton = ClickButton(2, &changeMode);

Button buttons[] = {
  modeButton
};



void doNothing() {
  controller.tick(nothingActions);
}

void diRightAd() {
  controller.tick(diRightActions);
}
void diLeftAd() {
  controller.tick(diLeftActions);
}



void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  for (Button button : buttons) {
    pinMode(button.getPin(), INPUT);
  }
  Serial.begin(9600);
  Serial.println("Serial monitor on");
}

void loop() {
  //digitalWrite(Z_PIN, HIGH);
  
  modeButton.checkClick();
  switch(mode) {
    case NOTHING:
      doNothing();
      break;
    case DI_RIGHT_AD:
      diRightAd();
      break;
    case DI_LEFT_AD:
      diLeftAd();
      break;
  }


  delay(16);
  
}