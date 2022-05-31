package smartCoffeeMachineManager.comm;

public interface CommManager {
	String getNextMsg();
	void setNextMsg();
	void sendMsg();
	String receiveMsg();
	boolean isMsgAvailable();
}
