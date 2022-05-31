package smartCoffeeMachineManager.model;

public class ProductFactoryImpl implements ProductFactory {

	@Override
	public Product createChocolateProduct() {
		return new ProductImpl("Chocolate");
	}

	@Override
	public Product createTeaProduct() {
		return new ProductImpl("Tea");
	}

	@Override
	public Product createCoffeeProduct() {
		return new ProductImpl("Coffee");
	}

	@Override
	public Product createSugarProduct() {
		return new ProductImpl("Sugar");
	}

}
