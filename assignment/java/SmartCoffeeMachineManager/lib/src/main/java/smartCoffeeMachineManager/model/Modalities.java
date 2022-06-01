package smartCoffeeMachineManager.model;

public enum Modalities {
	IDLE("Idle"),
	WORKING("Working"),
	ASSISTANCE("Assistance");
	
	private final String name;
	
	private Modalities(final String name) {
		this.name = name;
	}
	
	public final String getName() {
		return this.name;
	}
}
