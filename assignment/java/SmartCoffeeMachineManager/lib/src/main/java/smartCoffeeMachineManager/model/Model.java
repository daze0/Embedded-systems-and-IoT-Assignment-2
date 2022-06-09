package smartCoffeeMachineManager.model;

/**
 * Responsible of the model contract 
 * of the program.
 */
public interface Model {
	/**
	 * Chocolate getter.
	 * 
	 * @return n of chocolate.
	 */
	int getChocolate();
	/**
	 * Tea getter.
	 * 
	 * @return n of tea.
	 */
	int getTea();
	/**
	 * Coffee getter.
	 * 
	 * @return n of coffee.
	 */
	int getCoffee();
	/**
	 * Sugar getter.
	 * 
	 * @return n of sugar.
	 */
	int getSugar();
	/**
	 * Sets the quantity(n) of chocolate.
	 * 
	 * @param n
	 */
	void setChocolate(int n);
	/**
	 * Sets the quantity(n) of Tea.
	 * 
	 * @param n
	 */
	void setTea(int n);
	/**
	 * Sets the quantity(n) of coffee.
	 * 
	 * @param n
	 */
	void setCoffee(int n);
	/**
	 * Sets the quantity(n) of sugar.
	 * 
	 * @param n
	 */
	void setSugar(int n);
	/**
	 * Fully refills the machine.
	 */
	void refill();
	/**
	 * Checks whether refill is needed or not.
	 * 
	 * @return true if refill is needed, false if not.
	 */
	boolean needRefill();
	/**
	 * Makes the machine recover.
	 */
	void recover();
	/**
	 * Checks whether recover is needed or not.
	 * 
	 * @return true if recover is needed, false if not.
	 */
	boolean needRecover();
	/**
	 * Retrieves current mode.
	 * 
	 * @return current modality, check {@link Modalities} for more infos about modes.
	 */
	Modalities getMode();
	/**
	 * Sets a new mode.
	 * 
	 * @param mode to set.
	 */
	void setMode(Modalities mode);
	/**
	 * Returns n self test executed.
	 * 
	 * @return the number of self-tests executed by the smart coffee machine. 
	 */
	int getNSelfTests();
	/**
	 * Sets n as the number of self tests made.
	 * 
	 * @param n of self tests.
	 */
	void setNSelfTests(int n);
}
