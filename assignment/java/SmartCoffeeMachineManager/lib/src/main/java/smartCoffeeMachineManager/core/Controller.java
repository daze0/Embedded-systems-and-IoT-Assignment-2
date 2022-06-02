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
	
	public Controller(final Model model) {
		this.eventQueue = new ArrayList<>(); 
		this.model = model;
		this.view = Optional.empty();
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
	
	//NOTE: view events 
	public void checkEvents() {
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
	
	public void handle(final CommManager m) {
		// TODO
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
