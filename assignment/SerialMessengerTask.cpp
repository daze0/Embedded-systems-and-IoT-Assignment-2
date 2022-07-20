#include "SerialMessengerTask.h"
#include "MsgService.h"
#include <ArduinoJson.h>
#include <Arduino.h>

SerialMessengerTask::SerialMessengerTask(SmartCoffeeMachine* machine): Task(machine) {}

void SerialMessengerTask::init(int period) {
  Task::init(period);
  MsgService.init();
  this->state = SEND;
}

void SerialMessengerTask::tick() {
  switch (this->state) {
    case SEND:
      if (!this->getMachine()->productsAvailable()) {
        MsgService.sendMsg("need-refill");
        this->state = RECV;
      } else if (this->getMachine()->isInAssistanceMode()) {
        MsgService.sendMsg("need-recover");
        this->state = RECV;
      } else if (MsgService.isMsgAvailable()) {
        // this handles the case in which monitor msg is sent from the PC
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "monitor") {
          StaticJsonDocument<200> doc;
          doc["mode"] = this->getMachine()->getMode();
          doc["tea"] = this->getMachine()->getTea()->getAvailability();
          doc["coffee"] = this->getMachine()->getCoffee()->getAvailability();
          doc["chocolate"] = this->getMachine()->getChocolate()->getAvailability();
          doc["sugar"] = this->getMachine()->getSugar()->getAvailability();
          doc["nTests"] = this->getMachine()->getNSelfTests();
          serializeJson(doc, Serial);
          Serial.println("");
        }
        delete msg;
      }
      break;
    case RECV:
      // better analyze this: receiveMsg blocks the control flow (?)
      if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "refill") {
          this->getMachine()->refill();
          MsgService.sendMsg("refill-done");
        } else if (msg->getContent() == "recover") {
          this->getMachine()->setAssistance(false);
          MsgService.sendMsg("recover-done");
        } else if (msg->getContent() == "monitor") {
          StaticJsonDocument<200> doc;
          doc["mode"] = this->getMachine()->getMode();
          doc["tea"] = this->getMachine()->getTea()->getAvailability();
          doc["coffee"] = this->getMachine()->getCoffee()->getAvailability();
          doc["chocolate"] = this->getMachine()->getChocolate()->getAvailability();
          doc["sugar"] = this->getMachine()->getSugar()->getAvailability();
          doc["nTests"] = this->getMachine()->getNSelfTests();
          serializeJson(doc, Serial);
          Serial.println("");
        }
        delete msg;
        this->state = SEND;
      }
  }
}