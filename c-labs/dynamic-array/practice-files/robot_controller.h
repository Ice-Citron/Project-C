#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

#include <stddef.h>

typedef struct MotorState MotorState;

int controller_init(MotorState *init_state);

#endif