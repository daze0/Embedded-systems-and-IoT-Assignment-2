package smartCoffeeMachineManager.model;

public class ProductImpl implements Product {

	public static final int N_MAX = 10;
	private final String name;
	private int quantity;
	
	public ProductImpl(final String name) {
		this.name = name;
		this.quantity = N_MAX;
	}
	
	@Override
	public final String getName() {
		return this.name;
	}
	
	@Override
	public final int getQuantity() {
		return this.quantity;
	}

	@Override
	public void setQuantity(int n) {
		this.quantity = n;
	}

}
