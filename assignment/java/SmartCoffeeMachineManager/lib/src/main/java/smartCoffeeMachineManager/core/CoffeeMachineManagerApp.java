package smartCoffeeMachineManager.core;

import smartCoffeeMachineManager.model.CoffeeMachine;
import smartCoffeeMachineManager.model.CoffeeMachineImpl;
import smartCoffeeMachineManager.model.Model;
import smartCoffeeMachineManager.model.ModelImpl;
import smartCoffeeMachineManager.view.View;
import smartCoffeeMachineManager.view.ViewImpl;
import smartCoffeeMachineManager.view.ViewObserver;

public class CoffeeMachineManagerApp {
	
	private static final int COMM_BAUD_RATE = 9600;
	
	public static void main(final String[] args) throws Exception {
		final CoffeeMachine machine = new CoffeeMachineImpl();
		final Model model = new ModelImpl(machine);
		final Controller controller = new Controller(model);
		final View view = new ViewImpl((ViewObserver) controller);
		controller.attachView(view);
		view.init();
		//final CommManager commManager = new CommManagerImpl(args[0], CoffeeMachineManagerApp.COMM_BAUD_RATE);
		final boolean mainLoopFlag = true;
		while (mainLoopFlag) {
			controller.checkEvents();
		}
	}
}
