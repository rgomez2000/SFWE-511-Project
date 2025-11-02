PROGRAM program1
  VAR
    EStop AT %IX1.0 : BOOL;
    Bottle_Jam AT %IX1.1 : BOOL;
    Speed_Encoder AT %IX1.2 : BOOL;
    Speed_Control AT %IX1.3 : BOOL;
    Conveyor_Enable AT %MX1.0 : BOOL;
    Conveyor_Motor AT %QX1.0 : BOOL;
    Alarm_Jam AT %QX1.1 : BOOL;
    Conveyor_Speed_Command AT %QX1.2 : BOOL;
    Line_Light_Tower AT %QX1.3 : BOOL;
  END_VAR

  Conveyor_Enable := NOT(EStop);
  Alarm_Jam := Bottle_Jam AND Conveyor_Enable;
  Conveyor_Motor := NOT(Bottle_Jam) AND Conveyor_Enable;
  Conveyor_Speed_Command := Speed_Control AND Speed_Encoder;
  Line_Light_Tower := Conveyor_Enable;
END_PROGRAM

PROGRAM program2
  VAR
    Switch_Conveyor AT %IX2.0 : BOOL;
    Bottle_Presence_Fill AT %IX2.1 : BOOL;
    Bottle_Presence_Cap AT %IX2.2 : BOOL;
    Bottle_Presence_Label AT %IX2.3 : BOOL;
    Stop_Conveyor_Fill AT %MX2.0 : BOOL;
    Stop_Conveyor_Cap AT %MX2.1 : BOOL;
    Stop_Conveyor_Label AT %MX2.2 : BOOL;
    Conveyor_Enable AT %QX2.0 : BOOL;
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
    Bottle_Presence_Fill AT %IX3.0 : BOOL;
    Optical_Neck_Sensor AT %IX3.1 : BOOL;
    Fill_Timer AT %IX3.2 : BOOL;
    Fill_Flowrate AT %IX3.3 : BOOL;
    Fill_Temperature AT %IX3.4 : BOOL;
    Fill_Enable AT %MX3.0 : BOOL;
    Fill_Valve AT %QX3.0 : BOOL;
    Fill_Pump_Speed AT %QX3.1 : BOOL;
    Fill_Alarm AT %QX3.2 : BOOL;
  END_VAR

  Fill_Enable := Optical_Neck_Sensor AND Bottle_Presence_Fill;
  Fill_Valve := Fill_Timer AND Fill_Enable;
  Fill_Pump_Speed := Fill_Flowrate AND Fill_Enable;
  Fill_Alarm := Fill_Temperature;
END_PROGRAM

PROGRAM program4
  VAR
    Min_Tank_Level AT %IX4.0 : BOOL;
    Prssure_Pump AT %IX4.1 : BOOL;
    Pump_Enable AT %MX4.0 : BOOL;
    Fill_Pump_Speed AT %QX4.0 : BOOL;
    Tank_Alarm AT %QX4.1 : BOOL;
  END_VAR

  Pump_Enable := NOT(Min_Tank_Level);
  Fill_Pump_Speed := Prssure_Pump AND Pump_Enable;
  Tank_Alarm := Min_Tank_Level;
END_PROGRAM

PROGRAM program5
  VAR
    Min_Cap_Hopper_Level AT %IX5.0 : BOOL;
    Cap_Presence_Hopper AT %IX5.1 : BOOL;
    Min_Cap_Torque_Sensor AT %IX5.2 : BOOL;
    Max_Cap_Torque_Sensor AT %IX5.3 : BOOL;
    Capping_Enable AT %MX5.0 : BOOL;
    Alarm_Caps AT %QX5.1 : BOOL;
    Cap_Bottle AT %QX5.2 : BOOL;
    Actuator_Alarm AT %QX5.3 : BOOL;
  END_VAR

  Cap_Bottle := Cap_Presence_Hopper;
  Capping_Enable := NOT(Min_Cap_Hopper_Level);
  Alarm_Caps := Min_Cap_Hopper_Level;
  Actuator_Alarm := Max_Cap_Torque_Sensor OR Min_Cap_Torque_Sensor;
END_PROGRAM

PROGRAM program6
  VAR
    Bottle_Presence_Label AT %IX6.0 : BOOL;
    Label_Presence AT %IX6.1 : BOOL;
    Label_Positioning AT %IX6.2 : BOOL;
    Label_Applicator AT %QX6.0 : BOOL;
    Actuator_Alarm AT %QX6.1 : BOOL;
  END_VAR

  Label_Applicator := Bottle_Presence_Label AND Label_Presence;
  Actuator_Alarm := Label_Positioning;
END_PROGRAM

PROGRAM program7
  VAR
    Fill_Level_Detect AT %IX7.0 : BOOL;
    Optical_Neck_sensor AT %IX7.1 : BOOL;
    Bottle_Weight AT %IX7.2 : BOOL;
    Cap_Torque_Sensor AT %IX7.3 : BOOL;
    Reject_Bottle AT %QX7.0 : BOOL;
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
