TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM program1
  VAR
    EStop : BOOL;
    Bottle_Jam : BOOL;
    Speed_Encoder : BOOL;
    Speed_Control : BOOL;
    Conveyor_Enable : BOOL;
    Conveyor_Motor : BOOL;
    Alarm_Jam : BOOL;
    Conveyor_Speed_Command : BOOL;
    Line_Light_Tower : BOOL;
  END_VAR

  Conveyor_Enable := NOT(EStop);
  Alarm_Jam := Bottle_Jam AND Conveyor_Enable;
  Conveyor_Motor := NOT(Bottle_Jam) AND Conveyor_Enable;
  Conveyor_Speed_Command := Speed_Control AND Speed_Encoder;
  Line_Light_Tower := Conveyor_Enable;
END_PROGRAM

PROGRAM program2
  VAR
    Switch_Conveyor : BOOL;
    Bottle_Presence_Fill : BOOL;
    Bottle_Presence_Cap : BOOL;
    Bottle_Presence_Label : BOOL;
    Stop_Conveyor_Fill : BOOL;
    Stop_Conveyor_Cap : BOOL;
    Stop_Conveyor_Label : BOOL;
    Conveyor_Enable : BOOL;
  END_VAR

  Stop_Conveyor_Cap := Bottle_Presence_Cap;
  Stop_Conveyor_Fill := Bottle_Presence_Fill;
  Stop_Conveyor_Label := Bottle_Presence_Label;
  IF Stop_Conveyor_Cap OR Stop_Conveyor_Fill OR Stop_Conveyor_Label THEN
    Conveyor_Enable := FALSE; (*reset*)
  END_IF;
  IF Switch_Conveyor THEN
    Conveyor_Enable := TRUE; (*set*)
  END_IF;
  IF NOT(Switch_Conveyor) THEN
    Conveyor_Enable := FALSE; (*reset*)
  END_IF;
END_PROGRAM

PROGRAM program3
  VAR
    Bottle_Presence_Fill : BOOL;
    Optical_Neck_Sensor : BOOL;
    Fill_Timer : BOOL;
    Fill_Flowrate : BOOL;
    Fill_Temperature : BOOL;
    Fill_Enable : BOOL;
    Fill_Valve : BOOL;
    Fill_Pump_Speed : BOOL;
    Fill_Alarm : BOOL;
  END_VAR

  Fill_Enable := Optical_Neck_Sensor AND Bottle_Presence_Fill;
  Fill_Valve := Fill_Timer AND Fill_Enable;
  Fill_Pump_Speed := Fill_Flowrate AND Fill_Enable;
  Fill_Alarm := Fill_Temperature;
END_PROGRAM

PROGRAM program4
  VAR
    Min_Tank_Level : BOOL;
    Prssure_Pump : BOOL;
    Pump_Enable : BOOL;
    Fill_Pump_Speed : BOOL;
    Tank_Alarm : BOOL;
  END_VAR

  Pump_Enable := NOT(Min_Tank_Level);
  Fill_Pump_Speed := Prssure_Pump AND Pump_Enable;
  Tank_Alarm := Min_Tank_Level;
END_PROGRAM

PROGRAM program5
  VAR
    Min_Cap_Hopper_Level : BOOL;
    Cap_Presence_Hopper : BOOL;
    Min_Cap_Torque_Sensor : BOOL;
    Max_Cap_Torque_Sensor : BOOL;
    Capping_Enable : BOOL;
    Alarm_Caps : BOOL;
    Cap_Bottle : BOOL;
    Actuator_Alarm : BOOL;
  END_VAR

  Cap_Bottle := Cap_Presence_Hopper;
  Capping_Enable := NOT(Min_Cap_Hopper_Level);
  Alarm_Caps := Min_Cap_Hopper_Level;
  Actuator_Alarm := Max_Cap_Torque_Sensor AND Min_Cap_Hopper_Level;
END_PROGRAM

PROGRAM program6
  VAR
    Bottle_Presence_Label : BOOL;
    Label_Presence : BOOL;
    Label_Positioning : BOOL;
    Label_Applicator : BOOL;
    Actuator_Alarm : BOOL;
  END_VAR

  Label_Applicator := Bottle_Presence_Label AND Label_Presence;
  Actuator_Alarm := Label_Positioning;
END_PROGRAM

PROGRAM program7
  VAR
    Fill_Level_Detect : BOOL;
    Optical_Neck_sensor : BOOL;
    Bottle_Weight : BOOL;
    Cap_Torque_Sensor : BOOL;
    Reject_Bottle : BOOL;
  END_VAR

  Reject_Bottle := Fill_Level_Detect;
  Reject_Bottle := Optical_Neck_sensor;
  Reject_Bottle := Bottle_Weight;
  Reject_Bottle := Cap_Torque_Sensor;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task1(INTERVAL := T#20ms,PRIORITY := 0);
    TASK task2(INTERVAL := T#20ms,PRIORITY := 0);
    TASK task3(INTERVAL := T#20ms,PRIORITY := 0);
    TASK task4(INTERVAL := T#20ms,PRIORITY := 0);
    TASK task5(INTERVAL := T#20ms,PRIORITY := 0);
    TASK task6(INTERVAL := T#20ms,PRIORITY := 0);
    TASK task7(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance1 WITH task1 : program1;
    PROGRAM instance2 WITH task2 : program2;
    PROGRAM instance3 WITH task3 : program3;
    PROGRAM instance4 WITH task4 : program4;
    PROGRAM instance5 WITH task5 : program5;
    PROGRAM instance6 WITH task6 : program6;
    PROGRAM instance7 WITH task7 : program7;
  END_RESOURCE
END_CONFIGURATION
