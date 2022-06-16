#include "Controller.h"


#define FIRST_LEDGE_NOTHING 11
#define TECH_OPTION 10
#define MISTECH_WAIT 11
#define MISTECH_OPTION 12

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

/*
mytha at 0 in sbf
down 2
nothing 5
down 2
nothing 40
left 2
nothing 40
down 2
nothing 40
right 40
TECH option 10
shield 120


///

down 2
nothing 5
down 2
nothing 40
left 2
nothing 40
down 2
nothing 40
right 40
nothing 30
nothing (1 - 120)
GETUP OPTION

*/
Action downThrowTechActions[] = {
  Action(nothing, 0, 120),
  Action(down, 1, 3),
  Action(nothing, 0, 4),
  Action(down, 1, 2),
  Action(nothing, 0, 40),
  Action(left, 1, 2),
  Action(nothing, 0, 40),
  Action(down, 1, 2),
  Action(nothing, 0, 40),
  Action(right, 1, 40),
  Action(rightShield, 2, 10),
  Action(shield, 1, 60),
  Action(END)
};
Action downThrowMistechActions[] = {
  Action(nothing, 0, 120),
  Action(down, 1, 3),
  Action(nothing, 0, 4),
  Action(down, 1, 2),
  Action(nothing, 0, 40),
  Action(left, 1, 2),
  Action(nothing, 0, 40),
  Action(down, 1, 2),
  Action(nothing, 0, 40),
  Action(right, 1, 40),
  Action(nothing, 0, 30),
  Action(nothing, 0, 1),  //waitFrames
  Action(nothing, 0, 1),  //getup option
  Action(shield, 1, 600),
  Action(END)
};

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