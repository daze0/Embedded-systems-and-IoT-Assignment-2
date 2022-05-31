package smartCoffeeMachineManager.model;

import java.util.Iterator;
import java.util.Optional;

public class ModelImpl implements Model {

	private final CoffeeMachine machine;
	
	public ModelImpl(final CoffeeMachine machine) {
		this.machine = machine;
	}
	
	private Optional<Integer> getProductQuantity(final String productName) {
		final Iterator<Product> iter = this.machine.getProducts().iterator();
		while (iter.hasNext()) {
			final Product prod = iter.next();
			if (prod.getName().equals(productName)) {
				return Optional.of(prod.getQuantity());
			} 
		}
		return Optional.empty();
	}
	
	@Override
	public int getChocolate() {
		final Optional<Integer> chocolate = this.getProductQuantity("Chocolate");
		if (chocolate.isPresent()) {
			return this.getProductQuantity("Chocolate").get();
		}
		return -1;
	}

	@Override
	public int getTea() {
		final Optional<Integer> tea = this.getProductQuantity("Tea");
		if (tea.isPresent()) {
			return this.getProductQuantity("Tea").get();
		}		
		return -1;
	}

	@Override
	public int getCoffee() {
		final Optional<Integer> coffee = this.getProductQuantity("Coffee");
		if (coffee.isPresent()) {
			return this.getProductQuantity("Coffee").get();
		}		
		return -1;
	}

	@Override
	public int getSugar() {
		final Optional<Integer> sugar = this.getProductQuantity("Sugar");
		if (sugar.isPresent()) {
			return this.getProductQuantity("Sugar").get();
		}		
		return -1;
	}
	
	private void setProduct(final int n, final String productName) {
		final Iterator<Product> iter = this.machine.getProducts().iterator();
		while (iter.hasNext()) {
			final Product prod = iter.next();
			if (prod.getName().equals(productName)) {
				prod.setQuantity(n);
			}
		}
	}

	@Override
	public void setChocolate(int n) {
		this.setProduct(n, "Chocolate");
	}

	@Override
	public void setTea(int n) {
		this.setProduct(n, "Tea");
	}

	@Override
	public void setCoffee(int n) {
		this.setProduct(n, "Coffee");
	}

	@Override
	public void setSugar(int n) {
		this.setProduct(n, "Sugar");
	}

	@Override
	public void refill() {
		this.setChocolate(ProductImpl.N_MAX);
		this.setTea(ProductImpl.N_MAX);
		this.setCoffee(ProductImpl.N_MAX);
		this.setSugar(ProductImpl.N_MAX);
	}

	@Override
	public boolean needRefill() {
		if (this.getChocolate() == 0 && this.getTea() == 0 && this.getCoffee() == 0) {
			return true;
		}
		return false;
	}

	@Override
	public void recover() {
		this.machine.setMode(Modalities.WORKING);
	}

	@Override
	public boolean needRecover() {
		if (this.machine.getMode() == Modalities.ASSISTANCE && !this.needRefill()) {
			return true;
		}
		return false;
	}

}
