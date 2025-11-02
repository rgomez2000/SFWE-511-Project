void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM1_init__(PROGRAM1 *data__, BOOL retain) {
  __INIT_VAR(data__->ESTOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTTLE_JAM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SPEED_ENCODER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SPEED_CONTROL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONVEYOR_ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONVEYOR_MOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARM_JAM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONVEYOR_SPEED_COMMAND,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LINE_LIGHT_TOWER,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM1_body__(PROGRAM1 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,CONVEYOR_ENABLE,,!(__GET_VAR(data__->ESTOP,)));
  __SET_VAR(data__->,ALARM_JAM,,(__GET_VAR(data__->BOTTLE_JAM,) && __GET_VAR(data__->CONVEYOR_ENABLE,)));
  __SET_VAR(data__->,CONVEYOR_MOTOR,,(!(__GET_VAR(data__->BOTTLE_JAM,)) && __GET_VAR(data__->CONVEYOR_ENABLE,)));
  __SET_VAR(data__->,CONVEYOR_SPEED_COMMAND,,(__GET_VAR(data__->SPEED_CONTROL,) && __GET_VAR(data__->SPEED_ENCODER,)));
  __SET_VAR(data__->,LINE_LIGHT_TOWER,,__GET_VAR(data__->CONVEYOR_ENABLE,));

  goto __end;

__end:
  return;
} // PROGRAM1_body__() 





void PROGRAM2_init__(PROGRAM2 *data__, BOOL retain) {
  __INIT_VAR(data__->SWITCH_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTTLE_PRESENCE_FILL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTTLE_PRESENCE_CAP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTTLE_PRESENCE_LABEL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP_CONVEYOR_FILL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP_CONVEYOR_CAP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP_CONVEYOR_LABEL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONVEYOR_ENABLE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM2_body__(PROGRAM2 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP_CONVEYOR_CAP,,__GET_VAR(data__->BOTTLE_PRESENCE_CAP,));
  __SET_VAR(data__->,STOP_CONVEYOR_FILL,,__GET_VAR(data__->BOTTLE_PRESENCE_FILL,));
  __SET_VAR(data__->,STOP_CONVEYOR_LABEL,,__GET_VAR(data__->BOTTLE_PRESENCE_LABEL,));
  if (((__GET_VAR(data__->STOP_CONVEYOR_CAP,) || __GET_VAR(data__->STOP_CONVEYOR_FILL,)) || __GET_VAR(data__->STOP_CONVEYOR_LABEL,))) {
    __SET_VAR(data__->,CONVEYOR_ENABLE,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->SWITCH_CONVEYOR,)) {
    __SET_VAR(data__->,CONVEYOR_ENABLE,,__BOOL_LITERAL(TRUE));
  };
  if (!(__GET_VAR(data__->SWITCH_CONVEYOR,))) {
    __SET_VAR(data__->,CONVEYOR_ENABLE,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // PROGRAM2_body__() 





void PROGRAM3_init__(PROGRAM3 *data__, BOOL retain) {
  __INIT_VAR(data__->BOTTLE_PRESENCE_FILL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTICAL_NECK_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILL_TIMER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILL_FLOWRATE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILL_TEMPERATURE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILL_ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILL_VALVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILL_PUMP_SPEED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILL_ALARM,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM3_body__(PROGRAM3 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,FILL_ENABLE,,(__GET_VAR(data__->OPTICAL_NECK_SENSOR,) && __GET_VAR(data__->BOTTLE_PRESENCE_FILL,)));
  __SET_VAR(data__->,FILL_VALVE,,(__GET_VAR(data__->FILL_TIMER,) && __GET_VAR(data__->FILL_ENABLE,)));
  __SET_VAR(data__->,FILL_PUMP_SPEED,,(__GET_VAR(data__->FILL_FLOWRATE,) && __GET_VAR(data__->FILL_ENABLE,)));
  __SET_VAR(data__->,FILL_ALARM,,__GET_VAR(data__->FILL_TEMPERATURE,));

  goto __end;

__end:
  return;
} // PROGRAM3_body__() 





void PROGRAM4_init__(PROGRAM4 *data__, BOOL retain) {
  __INIT_VAR(data__->MIN_TANK_LEVEL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PRSSURE_PUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUMP_ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILL_PUMP_SPEED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TANK_ALARM,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM4_body__(PROGRAM4 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,PUMP_ENABLE,,!(__GET_VAR(data__->MIN_TANK_LEVEL,)));
  __SET_VAR(data__->,FILL_PUMP_SPEED,,(__GET_VAR(data__->PRSSURE_PUMP,) && __GET_VAR(data__->PUMP_ENABLE,)));
  __SET_VAR(data__->,TANK_ALARM,,__GET_VAR(data__->MIN_TANK_LEVEL,));

  goto __end;

__end:
  return;
} // PROGRAM4_body__() 





void PROGRAM5_init__(PROGRAM5 *data__, BOOL retain) {
  __INIT_VAR(data__->MIN_CAP_HOPPER_LEVEL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAP_PRESENCE_HOPPER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MIN_CAP_TORQUE_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAX_CAP_TORQUE_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAPPING_ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARM_CAPS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAP_BOTTLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ACTUATOR_ALARM,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM5_body__(PROGRAM5 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,CAP_BOTTLE,,__GET_VAR(data__->CAP_PRESENCE_HOPPER,));
  __SET_VAR(data__->,CAPPING_ENABLE,,!(__GET_VAR(data__->MIN_CAP_HOPPER_LEVEL,)));
  __SET_VAR(data__->,ALARM_CAPS,,__GET_VAR(data__->MIN_CAP_HOPPER_LEVEL,));
  __SET_VAR(data__->,ACTUATOR_ALARM,,(__GET_VAR(data__->MAX_CAP_TORQUE_SENSOR,) || __GET_VAR(data__->MIN_CAP_TORQUE_SENSOR,)));

  goto __end;

__end:
  return;
} // PROGRAM5_body__() 





void PROGRAM6_init__(PROGRAM6 *data__, BOOL retain) {
  __INIT_VAR(data__->BOTTLE_PRESENCE_LABEL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LABEL_PRESENCE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LABEL_POSITIONING,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LABEL_APPLICATOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ACTUATOR_ALARM,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM6_body__(PROGRAM6 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,LABEL_APPLICATOR,,(__GET_VAR(data__->BOTTLE_PRESENCE_LABEL,) && __GET_VAR(data__->LABEL_PRESENCE,)));
  __SET_VAR(data__->,ACTUATOR_ALARM,,__GET_VAR(data__->LABEL_POSITIONING,));

  goto __end;

__end:
  return;
} // PROGRAM6_body__() 





void PROGRAM7_init__(PROGRAM7 *data__, BOOL retain) {
  __INIT_VAR(data__->FILL_LEVEL_DETECT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTICAL_NECK_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTTLE_WEIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAP_TORQUE_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REJECT_BOTTLE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM7_body__(PROGRAM7 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,REJECT_BOTTLE,,__GET_VAR(data__->FILL_LEVEL_DETECT,));
  __SET_VAR(data__->,REJECT_BOTTLE,,__GET_VAR(data__->OPTICAL_NECK_SENSOR,));
  __SET_VAR(data__->,REJECT_BOTTLE,,__GET_VAR(data__->BOTTLE_WEIGHT,));
  __SET_VAR(data__->,REJECT_BOTTLE,,__GET_VAR(data__->CAP_TORQUE_SENSOR,));

  goto __end;

__end:
  return;
} // PROGRAM7_body__() 





