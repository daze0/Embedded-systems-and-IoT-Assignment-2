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
			AppLogger.getAppLogger().debug("Inside checkEvents() loop");
			final ViewEvents eventId = e.getId();
			if (eventId == ViewEvents.MONITOR_EVENT) {
				if (this.view.isPresent()) {
					AppLogger.getAppLogger().event("MonitorEvent");
					this.view.get().showMonitorMode(
							this.model.getMode().getName(),
							this.computeAvailableProducts(),
							this.model.getNSelfTests()
					);
				}
			} else if (eventId == ViewEvents.REFILL_EVENT) {
				if (this.commManager.refillNeeded()) {
					this.commManager.setNextMsg("refill");
					this.commManager.sendMsg();
					/*
					 *  TODO: decide if refill by monitor mode or
					 *  		refill by message acknowledgement
					 */
					final String response = this.commManager.receiveMsg();
					if (response.equals("refill-done")) {
						this.model.refill();                    // ???
					}
				}
				if (this.view.isPresent()) {
					this.view.get().showRefill(this.model.needRefill());
				}
			} else if (eventId == ViewEvents.RECOVER_EVENT) {
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
			if (msg == "needRefill") {
				this.commManager.setRefillRequest(true); 
			} else if (msg == "needRecover") {
				this.commManager.setRecoverRequest(true); 
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
