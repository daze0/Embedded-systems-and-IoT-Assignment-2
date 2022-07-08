package smartCoffeeMachineManager.model;

public enum Modalities {
	IDLE("IDLE"),
	WORKING("WORKING"),
	ASSISTANCE("ASSISTANCE");
	
	private final String name;
	
	private Modalities(final String name) {
		this.name = name;
	}
	
	public final String getName() {
		return this.name;
	}
}
