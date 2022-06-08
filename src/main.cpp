#include <Arduino.h>
#include "Button.h"
#include "Actions.h"

enum Mode { NOTHING, DI_RIGHT_AD, DI_LEFT_AD, RANDOM_DI_AD, LEDGE_N, LEDGE_NR, LEDGE_NRA, LEDGE_ALL };
#define MAX_MODE 7
enum RandomLedge { NEUTRAL_GETUP, ROLL_GETUP, GETUP_ATTACK, JUMP, DROP_FAIR };
enum RandomDI { NO_DI, DI_RIGHT, DI_LEFT };

Controller controller = Controller();

Mode mode = NOTHING;
void changeMode() {
  int tempMode = mode;
  tempMode++;
  mode = (Mode)tempMode;
  if (mode > MAX_MODE) {
    mode = NOTHING;
  }
  controller.reset();
}
bool aux = false;
void activateAux() {
  aux = true;
}
ClickButton modeButton = ClickButton(3, &changeMode);
ClickButton auxButton = ClickButton(2, &activateAux);

Button buttons[] = {
  modeButton,
  auxButton
};
RandomDI randDi;
int randLedgeGenerator;
int randomLedgeTime;


void initRandomVals() {
  int di = random(0, 5);
  if (di == 0) {
    randDi = NO_DI;
  }
  else if (di <= 2) {
    randDi = DI_RIGHT;
  }
  else {
    randDi = DI_LEFT;
  }
  randLedgeGenerator = random(0, 1000);
  randomLedgeTime = random(20, 150);
}



Action* getRandomLedgeRoutine(RandomLedge option, int waitFrames) {
    ledgeRoutineRightActions[FIRST_LEDGE_NOTHING] = Action(nothing, 0, waitFrames);
    Action ledgeAction = Action(nothing, 0, 1);
    switch(option) {
      case NEUTRAL_GETUP:
        ledgeAction = Action(left, 1, 2);
        break;
      case ROLL_GETUP:
        ledgeAction = Action(shield, 1, 2);
        break;
      case GETUP_ATTACK:
        ledgeAction = Action(attack, 1, 2);
        break;
      case JUMP:
        ledgeAction = Action(up, 1, 2);
        break;
      case DROP_FAIR:
        ledgeAction = Action(down, 1, 2);
        break;
    }
    ledgeRoutineRightActions[FIRST_LEDGE_NOTHING + 1] = ledgeAction;
    if (option == DROP_FAIR) {
      ledgeRoutineRightActions[FIRST_LEDGE_NOTHING + 2] = Action(up, 1, 2);
      ledgeRoutineRightActions[FIRST_LEDGE_NOTHING + 3] = Action(leftAttack, 2, 30);
    }
    Serial.println(option);
    return ledgeRoutineRightActions;
}

void ledgeOptions(int amtOptions) {
  if (aux) {
    initRandomVals();
    controller.reset();
  }
  RandomLedge randLedge = (RandomLedge)(randLedgeGenerator%amtOptions);
  Action* randomLedgeRoutine = getRandomLedgeRoutine(randLedge, randomLedgeTime);
  controller.tick(randomLedgeRoutine);
}
void doNothing() {
  controller.tick(nothingActions);
}
void diRightAd() {
  controller.tick(diRightActions);
}
void diLeftAd() {
  controller.tick(diLeftActions);
}
void randomDiAd() {
  if (aux) {
    initRandomVals();
    controller.reset();
  }
  switch (randDi) {
    case NO_DI:
      controller.tick(adActions);
      break;
    case DI_RIGHT:
      controller.tick(diRightActions);
      break;
    case DI_LEFT:
      controller.tick(diLeftActions);
      break;
  }
}



void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  for (Button button : buttons) {
    pinMode(button.getPin(), INPUT);
  }
  Serial.begin(9600);
  Serial.println("Serial monitor on");
  randomSeed(analogRead(A0));
  initRandomVals();
}

void loop() {
  modeButton.checkClick();
  auxButton.checkClick();
  Serial.println(mode);
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
    case RANDOM_DI_AD:
      randomDiAd();
      break;
    case LEDGE_N:
      ledgeOptions(1);
      break;
    case LEDGE_NR:
      ledgeOptions(2);
      break;
    case LEDGE_NRA:
      ledgeOptions(3);
      break;
    case LEDGE_ALL:
      ledgeOptions(5);
      break;
  }

  aux = false;

  delay(16);
  
}