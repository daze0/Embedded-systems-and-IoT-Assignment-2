package smartCoffeeMachineManager.view;

/**
 * Exposes the view contract of
 * the bigger MVC pattern used in the project.
 */
public interface View {
	/**
	 * Initialize method.
	 */
	void init();
	/**
	 * Shows the monitor mode, all the physical machine's 
	 * attributes are exposed.
	 */
	void showMonitorMode();
	/**
	 * Shows the refill panel that generates a message for
	 * the physical machine.
	 */
	void showRefill();
	/**
	 * Shows the recover panel that generates a resume 
	 * message for the physical machine.
	 */
	void showRecover();
}