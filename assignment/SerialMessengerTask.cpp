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
      }
      if (this->getMachine()->isInAssistanceMode()) {
        MsgService.sendMsg("need-recover");
        this->state = RECV;
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