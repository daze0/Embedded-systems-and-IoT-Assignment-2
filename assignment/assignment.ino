#include "Scheduler.h"
#include "SmartCoffeeMachine.h"
#include "Screen.h"
#include "Sensor.h"
#include "LCDScreen.h"
#include "Screen.h"
#include "PirSensor.h"
#include "Task.h"
#include "InitializeTask.h"
#include "SleepTask.h"
#include "ServoMotor.h"
#include "Servo2MotorImpl.h"
#include "TemperatureSensor.h"
#include "SelfTestTask.h"
#include "ServoMotorWithTimer.h"
#include "ServoMotorWithTimerImpl.h"
#include "MakeProductTask.h"
#include "ChooseProductTask.h"
#include "SonarSensor.h"
#include "PotentiometerSensor.h"
#include "SerialMessengerTask.h"
#include "ButtonImpl.h"

#define PIR_PIN 2
#define MOTOR_PIN 3
#define TMP_PIN A0
#define POT_PIN A1
#define UP_BTN_PIN 6
#define DOWN_BTN_PIN 5
#define MAKE_BTN_PIN 4

/* MCD between each task's period */
#define SCHEDULER_PERIOD 50
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
#define SELF_TEST_TASK_PERIOD 50
/*
*
*/
#define MAKE_PRODUCT_TASK_PERIOD 50
/*
*
*/
#define SERIAL_MESSENGER_TASK_PERIOD 250

/*
* I2C address of the LCD: 0x27
*/
#define LCD_ADDRESS 0x27

/*
* Number of columns of LCD
*/
#define LCD_COLS 20

/*
* Number of rows of LCD
*/
#define LCD_ROWS 4

Scheduler sched;


void setup() {
    Serial.begin(9600);
    sched.init(SCHEDULER_PERIOD);
    
    SmartCoffeeMachine* coffeeMachine = new SmartCoffeeMachine();
    Screen* lcd = new LCDScreen(LCD_ADDRESS, LCD_COLS, LCD_ROWS);
    Sensor* pir = new PirSensor(PIR_PIN);
    Servo2MotorImpl* motor = new Servo2MotorImpl(MOTOR_PIN);
    Sensor* tempSensor = new TemperatureSensor(TMP_PIN);
    Sensor* sonarSensor = new SonarSensor(1, 2); 
    Sensor* potSensor = new PotentiometerSensor(POT_PIN);
    Button* upBtn = new ButtonImpl(UP_BTN_PIN);
    Button* downBtn = new ButtonImpl(DOWN_BTN_PIN);
    Button* makeBtn = new ButtonImpl(MAKE_BTN_PIN);
  
    Task* t0 = new InitializeTask(coffeeMachine, lcd);
    Task* t1 = new SleepTask(coffeeMachine, pir);  
    Task* t2 = new SelfTestTask(coffeeMachine, tempSensor, motor, lcd);
    Task* t3 = new MakeProductTask(coffeeMachine, tempSensor, lcd, motor);
    Task* t4 = new SerialMessengerTask(coffeeMachine);
    Task* t5 = new ChooseProductTask(coffeeMachine, upBtn, downBtn, makeBtn, potSensor, lcd);

    t0->init(INITIALIZE_TASK_PERIOD);
    t1->init(SLEEP_TASK_PERIOD);
    t2->init(SELF_TEST_TASK_PERIOD);
    //t3->init(MAKE_PRODUCT_TASK_PERIOD);
    t4->init(SERIAL_MESSENGER_TASK_PERIOD);
  
    sched.addTask(t0);
    sched.addTask(t1);
    sched.addTask(t2); 
    sched.addTask(t3);
    sched.addTask(t4);

}

void loop() {
  sched.schedule();
}