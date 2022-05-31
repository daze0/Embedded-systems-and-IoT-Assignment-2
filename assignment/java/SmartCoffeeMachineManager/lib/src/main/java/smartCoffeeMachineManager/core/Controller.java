package smartCoffeeMachineManager.core;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import smartCoffeeMachineManager.comm.CommManager;

public class Controller implements ViewObserver {

	private final Optional<Model> model;
	private final Optional<View> view;
	private final List<ViewEvent> eventQueue;
	
	public Controller() {
		this.eventQueue = new ArrayList<>(); 
		this.model = Optional.empty();
		this.view = Optional.empty();
	}
	
	@Override
	public void notifyEvent(final ViewEvent e) {
		this.eventQueue.add(e);
	}
	
	//NOTE: view events 
	public void checkEvents() {
		for (final ViewEvent e : this.eventQueue) {
			final ViewEvents eventId = e.getId();
			if (eventId == ViewEvents.MONITOR_EVENT) {
				if (this.view.isPresent()) {
					this.view.get().showMonitorMode();
				}
			} else if (eventId == ViewEvents.REFILL_EVENT) {
				if (this.view.isPresent()) {
					this.view.get().showRefill();
				}
			} else if (eventId == ViewEvents.RECOVER_EVENT) {
				if (this.view.isPresent()) {
					this.view.get().showRecover();
				}
			}
		}
	}
	
	public void handle(final CommManager m) {
		
	}

}
