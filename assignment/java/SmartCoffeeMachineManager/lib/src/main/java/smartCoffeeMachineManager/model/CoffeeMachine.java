package smartCoffeeMachineManager.model;

import java.util.Map;

public interface CoffeeMachine {
	Modalities getMode();
	Map<Product, Integer> getProducts();
	int getNSelfTests();
}
