package smartCoffeeMachineManager.view;

import smartCoffeeMachineManager.core.Controller;
import smartCoffeeMachineManager.view.events.ViewEvent;

/**
 * Single method interface needed to represent
 * those objects that have to respond to notifications of
 * events, just like the {@link Controller}.
 */
public interface ViewObserver {
	/**
	 * Notifies event e to the ViewObserver.
	 * @param e
	 */
	void notifyEvent(ViewEvent e);
}
