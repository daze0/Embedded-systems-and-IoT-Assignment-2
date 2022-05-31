package smartCoffeeMachineManager.model;

import java.util.Set;

public interface CoffeeMachine {
	Modalities getMode();
	void setMode(Modalities mode);
	Set<Product> getProducts();
	int getNSelfTests();
	void setNSelfTests(int n);
}
