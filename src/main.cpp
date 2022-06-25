#include <Arduino.h>
#include "Button.h"
#include "Actions.h"
#include "RandomOptionManager.h"
#include "FrameDelayManager.h"

// enum Mode { NOTHING, DI_RIGHT_AD, SDI_RIGHT, TECHCHASE, DI_LEFT_AD, RANDOM_DI_AD, LEDGE };
enum Mode { NOTHING, DI_RIGHT_AD };
#define MAX_MODE 1
#define X_INPUT_PIN A0
#define Y_INPUT_PIN A1
enum RandomLedge { NEUTRAL_GETUP, ROLL_GETUP, GETUP_ATTACK, JUMP, DROP_FAIR };
enum RandomTech { NEUTRAL_TECH, TECHROLL_RIGHT, TECHROLL_LEFT };
enum RandomMistech { NEUTRAL_GETUP_MISTECH, ROLL_RIGHT_MISTECH, ROLL_LEFT_MISTECH, GETUP_ATTACK_MISTECH };
enum RandomDI { NO_DI, DI_RIGHT, DI_LEFT };

Controller controller = Controller();
FrameDelayManager delayManager = FrameDelayManager();

Mode mode = NOTHING;
Mode prevMode = NOTHING;
void setMode(Mode newMode) {
  prevMode = mode;
  mode = newMode;
  switch(mode) {
    case NOTHING:
      controller.inputModeOff();
      controller.setActions(nothingActions);
      break;
    case DI_RIGHT_AD:
      controller.inputModeOff();
      controller.setActions(allButtonsTestActions);
      break;
  }
}
void incrementMode() {
  int tempMode = mode;
  tempMode++;
  if (tempMode > MAX_MODE) {
    tempMode = NOTHING;
  }
  setMode((Mode)tempMode);
  controller.reset();
}
bool aux = false;
void activateAux() {
  aux = true;
}
ClickButton modeButton = ClickButton(3, &incrementMode);
ClickButton auxButton = ClickButton(2, &activateAux);

Button buttons[] = {
  modeButton,
  auxButton
};

OPTION diOptions[] = {{NO_DI, 1}, {DI_RIGHT, 2}, {DI_LEFT, 2}};
RandomOptionManager randomDiManager = RandomOptionManager(diOptions, 3);

OPTION ledgeOptions[] = {{NEUTRAL_GETUP, 2}, {ROLL_GETUP, 2}, {GETUP_ATTACK, 1}, {JUMP, 2}, {DROP_FAIR, 1}};
RandomOptionManager randomLedgeManager = RandomOptionManager(ledgeOptions, 5);

int randomLedgeTime;

OPTION doTechOptions[] = {{1, 2}, {0, 1}};
RandomOptionManager randomDoTechManager = RandomOptionManager(doTechOptions, 2);

int randomMistechTime;

OPTION techOptions[] = {{NEUTRAL_TECH, 1}, {TECHROLL_RIGHT, 1}, {TECHROLL_LEFT, 1}};
RandomOptionManager randomTechManager = RandomOptionManager(techOptions, 3);

OPTION mistechOptions[] = {{NEUTRAL_GETUP_MISTECH, 1}, {ROLL_RIGHT_MISTECH, 1}, {ROLL_LEFT_MISTECH, 1}, {GETUP_ATTACK_MISTECH, 1}};
RandomOptionManager randomMistechManager = RandomOptionManager(mistechOptions, 4);



void initRandomVals() {
  randomDiManager.randomizeOption();
  randomLedgeManager.randomizeOption();
  randomLedgeTime = random(20, 150);
  randomDoTechManager.randomizeOption();
  randomMistechTime = random(1, 121);
  randomTechManager.randomizeOption();
  randomMistechManager.randomizeOption();
}




void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  for (Button button : buttons) {
    pinMode(button.getPin(), INPUT);
  }
  Serial.begin(9600);
  Serial.println("Serial monitor on");
  randomSeed(analogRead(A5));
  initRandomVals();
  controller.setActions(nothingActions);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  modeButton.checkClick();
  auxButton.checkClick();

  controller.tick();
  if (aux) {
    Serial.println(analogRead(X_INPUT_PIN));
    Serial.println(analogRead(Y_INPUT_PIN));
  }
  /*
  RIGHT: X 0
  LEFT: X 600
  NEUTRAL: X 350

  UP: Y 0
  DOWN: Y 600
  NEUTRAL: Y 350
  */

  aux = false;

  delay(delayManager.getCurrentFrameDelay());
  
}