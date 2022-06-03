package smartCoffeeMachineManager.comm;

public class CommManagerImpl implements CommManager {

	private final CommChannel commChannel;
	private String nextMsg;
	private boolean refillRequest;
	private boolean recoverRequest;
	
	public CommManagerImpl(final String port, final int rate) throws Exception {
		this.commChannel = new SerialCommChannel(port, rate);
		this.nextMsg = "";
		this.refillRequest = false;
		this.recoverRequest = false;
	}
	
	@Override
	public String getNextMsg() {
		return this.nextMsg;
	}

	@Override
	public void setNextMsg(final String msg) {
		this.nextMsg = msg;
	}

	@Override
	public void sendMsg() {
		this.commChannel.sendMsg(this.nextMsg);
	}

	@Override
	public String receiveMsg() throws InterruptedException {
		return this.commChannel.receiveMsg();
	}

	@Override
	public boolean isMsgAvailable() {
		return this.commChannel.isMsgAvailable();
	}

	@Override
	public void setRefillRequest(boolean value) {
		this.refillRequest = value;
	}

	@Override
	public void setRecoverRequest(boolean value) {
		this.recoverRequest = value;
	}

	@Override
	public boolean refillNeeded() {
		return this.refillRequest;
	}

	@Override
	public boolean recoverNeeded() {
		return this.recoverRequest;
	}

}
