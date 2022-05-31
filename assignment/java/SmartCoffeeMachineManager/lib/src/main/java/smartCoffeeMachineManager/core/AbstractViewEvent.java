package smartCoffeeMachineManager.core;

/**
 * {@inheritDoc}
 */
public abstract class AbstractViewEvent implements ViewEvent {
	
	private final ViewEvents id;
	
	protected AbstractViewEvent(final ViewEvents id) {
		this.id = id;
	}
	
	@Override
	public ViewEvents getId() {
		return this.id;
	}

}
