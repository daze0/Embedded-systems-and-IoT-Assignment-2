package smartCoffeeMachineManager.comm;

public interface CommManager {
	String getNextMsg();
	void setNextMsg(String msg);
	void sendMsg();
	String receiveMsg() throws InterruptedException;
	boolean isMsgAvailable();
}
