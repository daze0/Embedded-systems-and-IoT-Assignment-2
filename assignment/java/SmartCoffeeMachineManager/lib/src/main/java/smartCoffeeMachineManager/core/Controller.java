package smartCoffeeMachineManager.core;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;

import smartCoffeeMachineManager.comm.CommManager;
import smartCoffeeMachineManager.logging.AppLogger;
import smartCoffeeMachineManager.model.Model;
import smartCoffeeMachineManager.view.View;
import smartCoffeeMachineManager.view.ViewObserver;
import smartCoffeeMachineManager.view.events.ViewEvent;
import smartCoffeeMachineManager.view.events.ViewEvents;

public class Controller implements ViewObserver {

	private final Model model;
	private Optional<View> view;
	private final List<ViewEvent> eventQueue;
	private final CommManager commManager;
	
	public Controller(final Model model, final CommManager commManager) {
		this.eventQueue = new ArrayList<>(); 
		this.model = model;
		this.view = Optional.empty();
		this.commManager = commManager;
	}
	
	@Override
	public void notifyEvent(final ViewEvent e) {
		this.eventQueue.add(e);
	}
	
	private String computeAvailableProducts() {
		final Map<String, Integer> productsAvailable = new HashMap<>();
		productsAvailable.put("Chocolate", this.model.getChocolate());
		productsAvailable.put("Tea", this.model.getTea());
		productsAvailable.put("Coffee", this.model.getCoffee());
		productsAvailable.put("Sugar", this.model.getSugar());
		return productsAvailable.toString();
	}
	
	public void checkEvents() throws InterruptedException {
		for (final ViewEvent e : this.eventQueue) {
			final ViewEvents eventId = e.getId();
			if (eventId == ViewEvents.MONITOR_EVENT) {
				AppLogger.getAppLogger().event("MonitorEvent");
				if (this.view.isPresent()) {
					this.view.get().showMonitorMode(
							this.model.getMode().getName(),
							this.computeAvailableProducts(),
							this.model.getNSelfTests()
					);
				}
			} else if (eventId == ViewEvents.REFILL_EVENT) {
				AppLogger.getAppLogger().event("RefillEvent");
				if (this.commManager.refillNeeded()) {
					this.commManager.setNextMsg("refill");
					this.commManager.sendMsg();
					AppLogger.getAppLogger().event("Refill message sent from PC");
				}
				if (this.view.isPresent()) {
					this.view.get().showRefill(this.model.needRefill());
				}
			} else if (eventId == ViewEvents.RECOVER_EVENT) {
				AppLogger.getAppLogger().event("RecoverEvent");
				if (this.commManager.recoverNeeded()) {
					this.commManager.setNextMsg("recover");
					this.commManager.sendMsg();
					AppLogger.getAppLogger().event("Recover message sent from PC");
				}
				if (this.view.isPresent()) {
					this.view.get().showRecover(this.model.needRecover());
				}
			}
		}
		this.eventQueue.clear();
	}
	
	public void handleIncomingMessages() throws InterruptedException {
		if (this.commManager.isMsgAvailable()) {
			final String msg = this.commManager.receiveMsg();
			if (msg.equals("need-refill")) {										// Actions requests
				AppLogger.getAppLogger().event("need-refill received!");
				this.commManager.setRefillRequest(true); 
				// this.model.setRefillNeeded(true);
			} else if (msg.equals("need-recover")) {
				this.commManager.setRecoverRequest(true); 
				// this.model.setRecoverNeeded(true);
			} else if (msg.equals("refill-done")) {							    // Actions done confirmation
				this.model.refill();
			} else if (msg.equals("recover-done")) {
				this.model.recover();
			}
		}
	}
	
	public void attachView(final View view) {
		this.view = Optional.of(view);
	}
	
	public View detachView() {
		final View detachedView = this.view.get();
		this.view = Optional.empty();
		return detachedView;
	}

}
