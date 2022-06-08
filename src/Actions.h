#include "Controller.h"


#define FIRST_LEDGE_NOTHING 11

ControllerButtons adRight[] = { R, Z };
ControllerButtons adLeft[] = { L, Z };
ControllerButtons right[] = { R };
ControllerButtons rightShield[] = { R, S };
ControllerButtons left[] = { L };
ControllerButtons leftShield[] = { L, S };
ControllerButtons shield[] = { S };
ControllerButtons ad[] = { Z };
ControllerButtons up[] = { U };
ControllerButtons down[] = { D };
ControllerButtons attack[] = { A };
ControllerButtons leftAttack[] = { L, A };
ControllerButtons leftRisingFair[] = { L, A };
ControllerButtons nothing[] = { };

Action singleJabActions[] = {
  Action(attack, 1, 2),
  Action(nothing, 0, 30),
  Action(END)
};
Action jumpJumpCrouchActions[] = {
  Action(up, 1, 5),
  Action(nothing, 0, 60),
  Action(up, 1, 1),
  Action(nothing, 0, 60),
  Action(down, 1, 40),
  Action(nothing, 0, 30),
  Action(END)
};
Action dashDanceShieldActions[] = {
  Action(right, 1, 20),
  Action(rightShield, 2, 10),
  Action(nothing, 0, 13),
  Action(left, 1, 20),
  Action(leftShield, 2, 10),
  Action(nothing, 0, 13),
  Action(END)
};
Action diRightActions[] = {
  Action(adRight, 2, 5),
  Action(right, 1, 5),
  Action(END)
};
Action diLeftActions[] = {
  Action(adLeft, 2, 5),
  Action(left, 1, 5),
  Action(END)
};
Action adActions[] = {
  Action(ad, 1, 5),
  Action(nothing, 0, 5),
  Action(END)
};
Action nothingActions[] = {
  Action(nothing, 0, 60),
  Action(END)
};

//Action* getRandomLedgeRoutine(RandomLedge optiom, int waitFrames);

Action ledgeRoutineRightActions[] {
  Action(nothing, 0, 90),
  Action(rightShield, 2, 5),
  Action(nothing, 0, 35),
  Action(rightShield, 2, 5),
  Action(nothing, 0, 35),
  Action (up, 1, 2),
  Action(nothing, 0, 5),
  Action(right, 1, 3),
  Action(nothing, 0, 25),
  Action(down, 1, 2),
  Action(nothing, 0, 20),
  Action(nothing, 0, 1), //waitFrames
  Action(nothing, 0, 1), //option
  Action(nothing, 0, 1),
  Action(nothing, 0, 1),
  Action(shield, 1, 150),
  Action(END)
};