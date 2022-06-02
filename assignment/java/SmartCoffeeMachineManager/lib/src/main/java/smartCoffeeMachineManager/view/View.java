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
	void showMonitorMode(String mode, String productsAvailable, int nSelfTests);
	/**
	 * Shows the refill panel that generates a message for
	 * the physical machine.
	 */
	void showRefill(boolean needRefill);
	/**
	 * Shows the recover panel that generates a resume 
	 * message for the physical machine.
	 */
	void showRecover(boolean needRecover);
}