#include "Controller.h"

ControllerButtons adRight[] = { R, Z };
ControllerButtons adLeft[] = { L, Z };
ControllerButtons right[] = { R };
ControllerButtons left[] = { L };
ControllerButtons nothing[] = { };

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
Action nothingActions[] = {
  Action(nothing, 0, 60),
  Action(END)
};