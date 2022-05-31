package smartCoffeeMachineManager.model;

import java.util.HashSet;
import java.util.Set;

public class CoffeeMachineImpl implements CoffeeMachine {
	
	private Modalities mode;
	private Set<Product> products;
	private int nSelfTests;
	
	public CoffeeMachineImpl() {
		this.mode = Modalities.WORKING;
		final ProductFactory factory = new ProductFactoryImpl();
		this.products = new HashSet<>();
		this.products.add(factory.createChocolateProduct());
		this.products.add(factory.createTeaProduct());
		this.products.add(factory.createCoffeeProduct());
		this.products.add(factory.createSugarProduct());
		this.nSelfTests = 0;
	}

	@Override
	public Modalities getMode() {
		return this.mode;
	}

	@Override
	public Set<Product> getProducts() {
		return this.products;
	}

	@Override
	public int getNSelfTests() {
		return this.nSelfTests;
	}

	@Override
	public void setMode(final Modalities mode) {
		this.mode = mode;
	}

	@Override
	public void setNSelfTests(final int n) {
		this.nSelfTests = n;
	}
	
}
