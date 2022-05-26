#include "Scheduler.h"
#include "SmartCoffeeMachine.h"
#include "Screen.h"
#include "Sensor.h"
#include "LCDScreen.h"
#include "PirSensor.h"
#include "Task.h"
#include "InitializeTask.h"
#include "SleepTask.h"
#include "ServoMotor.h"
#include "Servo2MotorImpl.h"
#include "TemperatureSensor.h"
#include "SelfTestTask.h"

#define LCD_RS 12
#define LCD_ENABLE 11
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 6
#define PIR_PIN 2
#define MOTOR_PIN 8
#define TMP_PIN A0

/* MCD between each task's period */
#define SCHEDULER_PERIOD 250
/*********************************
* 3000 = Twelcome = Time that it *
* takes to transition from not   *
* ready to ready.                *
********************************/
#define INITIALIZE_TASK_PERIOD 3000
/******************************** 
* Sleep task period is based on *
* and determines pir sensor     *
* measurements frequency        *
*******************************/
#define SLEEP_TASK_PERIOD 250
/*
* 
*/
#define SELF_TEST_TASK_PERIOD 250

Scheduler sched;

void setup() {
  Serial.begin(9600);
  sched.init(SCHEDULER_PERIOD);
  SmartCoffeeMachine* coffeeMachine = new SmartCoffeeMachine();
  Screen* lcd = new LCDScreen(LCD_RS, LCD_ENABLE, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
  Sensor* pir = new PirSensor(PIR_PIN);
  ServoMotor* motor = new Servo2MotorImpl(MOTOR_PIN);
  Sensor* tempSensor = new TemperatureSensor(TMP_PIN);
  Task* t0 = new InitializeTask(coffeeMachine, lcd);
  Task* t1 = new SleepTask(coffeeMachine, pir);
  Task* t2 = new SelfTestTask(coffeeMachine, tempSensor, motor, lcd);
  t0->init(INITIALIZE_TASK_PERIOD);
  t1->init(SLEEP_TASK_PERIOD);
  t2->init(SELF_TEST_TASK_PERIOD);
  sched.addTask(t0);
  //sched.addTask(t1);
  sched.addTask(t2);
}

void loop() {
  sched.schedule();
}