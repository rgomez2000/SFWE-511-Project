#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM PROGRAM1
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,ESTOP)
  __DECLARE_VAR(BOOL,BOTTLE_JAM)
  __DECLARE_VAR(BOOL,SPEED_ENCODER)
  __DECLARE_VAR(BOOL,SPEED_CONTROL)
  __DECLARE_VAR(BOOL,CONVEYOR_ENABLE)
  __DECLARE_VAR(BOOL,CONVEYOR_MOTOR)
  __DECLARE_VAR(BOOL,ALARM_JAM)
  __DECLARE_VAR(BOOL,CONVEYOR_SPEED_COMMAND)
  __DECLARE_VAR(BOOL,LINE_LIGHT_TOWER)

} PROGRAM1;

void PROGRAM1_init__(PROGRAM1 *data__, BOOL retain);
// Code part
void PROGRAM1_body__(PROGRAM1 *data__);
// PROGRAM PROGRAM2
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,SWITCH_CONVEYOR)
  __DECLARE_VAR(BOOL,BOTTLE_PRESENCE_FILL)
  __DECLARE_VAR(BOOL,BOTTLE_PRESENCE_CAP)
  __DECLARE_VAR(BOOL,BOTTLE_PRESENCE_LABEL)
  __DECLARE_VAR(BOOL,STOP_CONVEYOR_FILL)
  __DECLARE_VAR(BOOL,STOP_CONVEYOR_CAP)
  __DECLARE_VAR(BOOL,STOP_CONVEYOR_LABEL)
  __DECLARE_VAR(BOOL,CONVEYOR_ENABLE)

} PROGRAM2;

void PROGRAM2_init__(PROGRAM2 *data__, BOOL retain);
// Code part
void PROGRAM2_body__(PROGRAM2 *data__);
// PROGRAM PROGRAM3
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,BOTTLE_PRESENCE_FILL)
  __DECLARE_VAR(BOOL,OPTICAL_NECK_SENSOR)
  __DECLARE_VAR(BOOL,FILL_TIMER)
  __DECLARE_VAR(BOOL,FILL_FLOWRATE)
  __DECLARE_VAR(BOOL,FILL_TEMPERATURE)
  __DECLARE_VAR(BOOL,FILL_ENABLE)
  __DECLARE_VAR(BOOL,FILL_VALVE)
  __DECLARE_VAR(BOOL,FILL_PUMP_SPEED)
  __DECLARE_VAR(BOOL,FILL_ALARM)

} PROGRAM3;

void PROGRAM3_init__(PROGRAM3 *data__, BOOL retain);
// Code part
void PROGRAM3_body__(PROGRAM3 *data__);
// PROGRAM PROGRAM4
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,MIN_TANK_LEVEL)
  __DECLARE_VAR(BOOL,PRSSURE_PUMP)
  __DECLARE_VAR(BOOL,PUMP_ENABLE)
  __DECLARE_VAR(BOOL,FILL_PUMP_SPEED)
  __DECLARE_VAR(BOOL,TANK_ALARM)

} PROGRAM4;

void PROGRAM4_init__(PROGRAM4 *data__, BOOL retain);
// Code part
void PROGRAM4_body__(PROGRAM4 *data__);
// PROGRAM PROGRAM5
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,MIN_CAP_HOPPER_LEVEL)
  __DECLARE_VAR(BOOL,CAP_PRESENCE_HOPPER)
  __DECLARE_VAR(BOOL,MIN_CAP_TORQUE_SENSOR)
  __DECLARE_VAR(BOOL,MAX_CAP_TORQUE_SENSOR)
  __DECLARE_VAR(BOOL,CAPPING_ENABLE)
  __DECLARE_VAR(BOOL,ALARM_CAPS)
  __DECLARE_VAR(BOOL,CAP_BOTTLE)
  __DECLARE_VAR(BOOL,ACTUATOR_ALARM)

} PROGRAM5;

void PROGRAM5_init__(PROGRAM5 *data__, BOOL retain);
// Code part
void PROGRAM5_body__(PROGRAM5 *data__);
// PROGRAM PROGRAM6
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,BOTTLE_PRESENCE_LABEL)
  __DECLARE_VAR(BOOL,LABEL_PRESENCE)
  __DECLARE_VAR(BOOL,LABEL_POSITIONING)
  __DECLARE_VAR(BOOL,LABEL_APPLICATOR)
  __DECLARE_VAR(BOOL,ACTUATOR_ALARM)

} PROGRAM6;

void PROGRAM6_init__(PROGRAM6 *data__, BOOL retain);
// Code part
void PROGRAM6_body__(PROGRAM6 *data__);
// PROGRAM PROGRAM7
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,FILL_LEVEL_DETECT)
  __DECLARE_VAR(BOOL,OPTICAL_NECK_SENSOR)
  __DECLARE_VAR(BOOL,BOTTLE_WEIGHT)
  __DECLARE_VAR(BOOL,CAP_TORQUE_SENSOR)
  __DECLARE_VAR(BOOL,REJECT_BOTTLE)

} PROGRAM7;

void PROGRAM7_init__(PROGRAM7 *data__, BOOL retain);
// Code part
void PROGRAM7_body__(PROGRAM7 *data__);
#endif //__POUS_H
