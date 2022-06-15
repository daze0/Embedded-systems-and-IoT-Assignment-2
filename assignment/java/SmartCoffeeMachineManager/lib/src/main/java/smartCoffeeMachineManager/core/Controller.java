package smartCoffeeMachineManager.core;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.JsonMappingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import smartCoffeeMachineManager.comm.CommManager;
import smartCoffeeMachineManager.comm.MonitorCommPacket;
import smartCoffeeMachineManager.logging.AppLogger;
import smartCoffeeMachineManager.model.Modalities;
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
				this.commManager.setNextMsg("monitor");
				this.commManager.sendMsg();
				if (this.view.isPresent()) {
					this.view.get().showMonitorMode(
							this.model.getMode().getName(),
							this.computeAvailableProducts(),
							this.model.getNSelfTests()
					);
				}
			} else if (eventId == ViewEvents.REFILL_EVENT) {
				AppLogger.getAppLogger().event("RefillEvent");
				AppLogger.getAppLogger().debug("refillNeeded: " + String.valueOf(this.commManager.refillNeeded()));
				if (this.commManager.refillNeeded()) {
					this.commManager.setNextMsg("refill");
					this.commManager.sendMsg();
					this.commManager.setRefillRequest(false);
					AppLogger.getAppLogger().event("Refill message sent from PC");
				}
				if (this.view.isPresent()) {
					this.view.get().showRefill(this.commManager.refillNeeded());
				}
			} else if (eventId == ViewEvents.RECOVER_EVENT) {
				AppLogger.getAppLogger().event("RecoverEvent");
				AppLogger.getAppLogger().debug("recoverNeeded: " + String.valueOf(this.commManager.recoverNeeded()));
				if (this.commManager.recoverNeeded()) {
					this.commManager.setNextMsg("recover");
					this.commManager.sendMsg();
					this.commManager.setRecoverRequest(false);
					AppLogger.getAppLogger().event("Recover message sent from PC");
				}
				if (this.view.isPresent()) {
					this.view.get().showRecover(this.commManager.recoverNeeded());
				}
			}
		}
		this.eventQueue.clear();
	}
	
	public void handleIncomingMessages() throws InterruptedException {
		if (this.commManager.isMsgAvailable()) {
			final String msg = this.commManager.receiveMsg();
			AppLogger.getAppLogger().event("Message on serial line: " + msg);	
			if (msg.equals("need-refill")) {										// Actions requests
				this.commManager.setRefillRequest(true); 
			} else if (msg.equals("need-recover")) {
				this.commManager.setRecoverRequest(true); 
			} else if (msg.equals("refill-done")) {							    // Actions done confirmation
				this.model.refill();
			} else if (msg.equals("recover-done")) {
				this.model.recover();
			} else if (msg.startsWith("{") && msg.endsWith("}")) {	
				AppLogger.getAppLogger().debug("JSON object detected!");
				/*
				final ObjectMapper mapper = new ObjectMapper();
				try {
					final MonitorCommPacket dataMap = mapper.readValue(msg, MonitorCommPacket.class);
					final String mode = (String) dataMap.getMode();
					if ((mode.equals(Modalities.IDLE.getName()))) {
						this.model.setMode(Modalities.IDLE);
					} else if (mode.equals(Modalities.ASSISTANCE.getName())) {
						this.model.setMode(Modalities.ASSISTANCE);
					} else if (mode.equals(Modalities.WORKING.getName())) {
						this.model.setMode(Modalities.WORKING);
					}
					this.model.setTea(dataMap.getTea());
					this.model.setCoffee(dataMap.getCoffee());
					this.model.setChocolate(dataMap.getChocolate());
					this.model.setSugar(dataMap.getSugar());
					this.model.setNSelfTests(dataMap.getNTests());
					AppLogger.getAppLogger().event("nTests received: " + dataMap.getNTests());
				} catch(final JsonMappingException e) {
					AppLogger.getAppLogger().error(e.getStackTrace().toString());
				} catch(final JsonProcessingException e) {
					AppLogger.getAppLogger().error(e.getStackTrace().toString());
				}*/
			} else {
				AppLogger.getAppLogger().debug("Strange message arrived: " + msg);
			}
		} else {
			//AppLogger.getAppLogger().debug("No message received");
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
