#include "Controller.h"


ActionButton z = ActionButton(Z);
ActionButton a = ActionButton(A);
ActionButton s = ActionButton(S);
ActionButton r = ActionButton(R);
ActionButton l = ActionButton(L);
ActionButton u = ActionButton(U);
ActionButton d = ActionButton(D);


ActionButton nothingArray[] = { };
ActionButtonArray nothing = { nothingArray, 0 };

ActionButton shieldArray[] = { s };
ActionButtonArray shield = { shieldArray, 1 };

ActionButton adArray[] = { z };
ActionButtonArray ad = { adArray, 1 };

ActionButton attackArray[] = { a };
ActionButtonArray attack = { attackArray, 1 };

ActionButton adRightArray[] = { z, r };
ActionButtonArray adRight = { adRightArray, 2 };

ActionButton adLeftArray[] = { z, l };
ActionButtonArray adLeft = { adLeftArray, 2 };

ActionButton adUpArray[] = { z, u };
ActionButtonArray adUp = { adUpArray, 2 };

ActionButton adDownArray[] = { z, d };
ActionButtonArray adDown = { adDownArray, 2 };

ActionButton rightArray[] = { r };
ActionButtonArray right = { rightArray, 1 };

ActionButton leftArray[] = { l };
ActionButtonArray left = { leftArray, 1 };

ActionButton upArray[] = { u };
ActionButtonArray up = { upArray, 1 };

ActionButton downArray[] = { d };
ActionButtonArray down = { downArray, 1 };

ActionButton customDiArray[] = { r, u };
ActionButtonArray customDi = { customDiArray, 0 };

ActionButton customAdArray[] = { z, s, a };
ActionButtonArray customAd = { customAdArray, 1 };


Action nothingActions[] = {
  Action(nothing, 60),
  Action(END)
};
Action customDiActions[] = {
  Action(customDi, 5),
  Action(customAd, 5),
  Action(END)
};

Action adRightActions[] = {
  Action(adRight, 5),
  Action(right, 5),
  Action(END)
};
Action adLeftActions[] = {
  Action(adLeft, 5),
  Action(left, 5),
  Action(END)
};
Action adUpActions[] = {
  Action(adUp, 5),
  Action(up, 5),
  Action(END)
};
Action adDownActions[] = {
  Action(adDown, 5),
  Action(down, 5),
  Action(END)
};
Action adActions[] = {
  Action(ad, 5),
  Action(nothing, 5),
  Action(END)
};

Action allButtonsTestActions[] = {
  Action(right, 20),
  Action(shield, 20),
  Action(left, 20),
  Action(shield, 20),
  Action(nothing, 60),
  Action(up, 10),
  Action(nothing, 60),
  Action(up, 2),
  Action(nothing, 60),
  Action(attack, 5),
  Action(nothing, 30),
  Action(down, 2),
  Action(nothing, 10),
  Action(down, 2),
  Action(nothing, 10),
  Action(down, 2),
  Action(END)
};









/*
Action sdiRightActions[] = {
  Action(adRight, 2, 2),
  Action(nothing, 0, 2),
  Action(END)
};
Action sdiUpActions[] = {
  Action(adUp, 2, 2),
  Action(nothing, 0, 2),
  Action(END)
};
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
};*/