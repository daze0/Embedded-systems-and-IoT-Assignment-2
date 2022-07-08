package smartCoffeeMachineManager.comm;

/**
 * This class describes the contract of a 
 * serial communication manager.
 */
public interface CommManager {
	/**
	 * Gets next message set to be delivered.
	 * 
	 * @return a string that contains the next message.
	 */
	String getNextMsg();
	/**
	 * Sets next message to be delivered.
	 * 
	 * @param msg is the message to set.
	 */
	void setNextMsg(String msg);
	/**
	 * Sends the set message to be delivered.
	 */
	void sendMsg();
	/**
	 * Gets a messsage from the serial messages queue.
	 * 
	 * @return a message.
	 * @throws InterruptedException ex.: in case of USB cable disconnection.
	 */
	String receiveMsg() throws InterruptedException;
	/**
	 * Checks if there's a message on the serial line.
	 * 
	 * @return true if there's a message, false if not.
	 */
	boolean isMsgAvailable();
	/**
	 * Sets the refillRequest field according to the given value.
	 * 
	 * @param value will be refillRequest's value.
	 */
	void setRefillRequest(boolean value);
	/**
	 * Sets the recoverRequest field according to the given value.
	 * 
	 * @param value will be recoverRequest's value.
	 */
	void setRecoverRequest(boolean value);
	/**
	 * It checks if a refill request has been sent from the ARDUINO.
	 * 
	 * @return true if refillRequest is true, false otherwise.
	 */
	boolean refillNeeded();
	/**
	 * It checks if a recover request has been sent from the ARDUINO.
	 * 
	 * @return true if recoverRequest is true, false otherwise.
	 */
	boolean recoverNeeded();
}
