package smartCoffeeMachineManager.model;

public interface ProductFactory {
	Product createChocolateProduct();
	Product createTeaProduct();
	Product createCoffeeProduct();
	Product createSugarProduct();
}
