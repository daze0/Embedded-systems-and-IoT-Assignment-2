#include "SerialMessengerTask.h"
#include "MsgService.h"

bool debugFlag = true;

SerialMessengerTask::SerialMessengerTask(SmartCoffeeMachine* machine): Task(machine) {}

void SerialMessengerTask::init(int period) {
  Task::init(period);
  MsgService.init();
  this->state = SEND;
}

void SerialMessengerTask::tick() {
  switch (this->state) {
    case SEND:
      //if (!this->getMachine()->productsAvailable()) {
      if (debugFlag) {
        debugFlag = false;
        MsgService.sendMsg("need-refill");
        this->state = RECV;
      } else if (this->getMachine()->isInAssistanceMode()) {
        MsgService.sendMsg("need-recover");
        this->state = RECV;
      } else if (MsgService.isMsgAvailable()) {
        // this handles the case in which monitor msg is sent from the PC
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "monitor") {
          MsgService.sendMsg("mode:" + String(this->getMachine()->getMode()) + ";" +
                             "tea:" + String(this->getMachine()->getTea()) + ";" +
                             "coffee:" + String(this->getMachine()->getCoffee()) + ";" +
                             "chocolate:" + String(this->getMachine()->getChocolate()) + ";" +
                             "sugar:" + String(this->getMachine()->getSugar()) + ";" +
                             "nTests:" + String(this->getMachine()->getNSelfTests()) + ";");
        }
        delete msg;
      }
      break;
    case RECV:
      // better analyze this: receiveMsg blocks the control flow (?)
      if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "refill-done") {
          this->getMachine()->refill();
        } else if (msg->getContent() == "recover-done") {
          this->getMachine()->setAssistance(false);
        }
        delete msg;
        this->state = SEND;
      }
  }
}