#include <Arduino.h>
#include "Button.h"
#include "Actions.h"

enum Mode { NOTHING, TECHCHASE, DI_RIGHT_AD, DI_LEFT_AD, RANDOM_DI_AD, LEDGE_N, LEDGE_NR, LEDGE_NRA, LEDGE_ALL };
#define MAX_MODE 7
enum RandomLedge { NEUTRAL_GETUP, ROLL_GETUP, GETUP_ATTACK, JUMP, DROP_FAIR };
enum RandomTech { NEUTRAL_TECH, TECHROLL_RIGHT, TECHROLL_LEFT };
enum RandomMistech { NEUTRAL_GETUP_MISTECH, ROLL_RIGHT_MISTECH, ROLL_LEFT_MISTECH, GETUP_ATTACK_MISTECH };
enum RandomDI { NO_DI, DI_RIGHT, DI_LEFT };

Controller controller = Controller();

Mode mode = NOTHING;
Mode prevMode = NOTHING;
void setMode(Mode newMode) {
  prevMode = mode;
  mode = newMode;
}
void incrementMode() {
  int tempMode = mode;
  tempMode++;
  setMode((Mode)tempMode);
  if (mode > MAX_MODE) {
    mode = NOTHING;
  }
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
RandomDI randDi;
int randLedgeGenerator;
int randomLedgeTime;
bool tech;
int randomMistechTime;
RandomTech randTech;
RandomMistech randMistech;


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
  tech = random(0, 2);
  randomMistechTime = random(1, 121);
  randTech = (RandomTech)random(0, 3);
  randMistech = (RandomMistech)random(0, 4);
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
Action* getRandomMistechActions(RandomMistech mistechOption, int waitFrames) {
    downThrowMistechActions[MISTECH_WAIT] = Action(nothing, 0, waitFrames);
    Action mistechAction = Action(nothing, 0, 1);
    switch(mistechOption) {
      case NEUTRAL_GETUP_MISTECH:
        mistechAction = Action(up, 1, 10);
        break;
      case ROLL_RIGHT_MISTECH:
        mistechAction = Action(right, 1, 10);
        break;
      case ROLL_LEFT_MISTECH:
        mistechAction = Action(left, 1, 10);
        break;
      case GETUP_ATTACK_MISTECH:
        mistechAction = Action(attack, 1, 10);
        break;
    }
    downThrowMistechActions[MISTECH_OPTION] = mistechAction;
    return downThrowMistechActions;
}
Action* getRandomTechActions(RandomTech techOption) {
    Action techAction = Action(nothing, 0, 1);
    switch(techOption) {
      case NEUTRAL_TECH:
        techAction = Action(left, 1, 2);
        break;
      case TECHROLL_RIGHT:
        techAction = Action(rightShield, 2, 10);
        break;
      case TECHROLL_LEFT:
        techAction = Action(leftShield, 2, 10);
        break;
    }
    downThrowTechActions[TECH_OPTION] = techAction;
    return downThrowTechActions;
}

Action* getRandomTechChaseRoutine(bool tech, RandomTech techOption, RandomMistech mistechOption, int waitFrames) {
    if (tech) {
      return getRandomTechActions(techOption);
    }
    else {
      return getRandomMistechActions(mistechOption, waitFrames);
    }
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
void onTechchaseEnd() {
  setMode(DI_RIGHT_AD);
}
void downThrowTechchase() {
  if (aux) {
    initRandomVals();
    controller.reset();
  }
  //controller.tick(getRandomTechChaseRoutine(tech, randTech, randMistech, randomMistechTime));
  //controller.tick(getRandomTechChaseRoutine(true, randTech, randMistech, randomMistechTime));
  controller.tick(getRandomTechChaseRoutine(true, randTech, randMistech, randomMistechTime), &onTechchaseEnd);
}
void diRightAd() {
  if (aux) {
    setMode(prevMode);
    initRandomVals();
    controller.reset();
  }
  else {
    controller.tick(diRightActions);
  }
  //downThrowTechchase();
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
    case TECHCHASE:
      downThrowTechchase();
      break;
  }

  aux = false;

  delay(16);
  
}