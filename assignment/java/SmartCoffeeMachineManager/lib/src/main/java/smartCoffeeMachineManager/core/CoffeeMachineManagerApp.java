package smartCoffeeMachineManager.core;

import smartCoffeeMachineManager.comm.CommManagerImpl;
import smartCoffeeMachineManager.model.CoffeeMachineImpl;
import smartCoffeeMachineManager.model.ModelImpl;
import smartCoffeeMachineManager.view.View;
import smartCoffeeMachineManager.view.ViewImpl;
import smartCoffeeMachineManager.view.ViewObserver;

public class CoffeeMachineManagerApp {
	
	private static final int COMM_BAUD_RATE = 9600;
	
	public static void main(final String[] args) throws Exception {
		final Controller controller = new Controller(
				new ModelImpl(new CoffeeMachineImpl()),
				new CommManagerImpl(args[0], CoffeeMachineManagerApp.COMM_BAUD_RATE)
		);
		final View view = new ViewImpl((ViewObserver) controller);
		controller.attachView(view);
		view.init();
		final boolean mainLoopFlag = true;
		while (mainLoopFlag) {
			/*
			 * It is better to check for incoming messages
			 * in order to modify model(and view) accordingly 
			 * to the ARDUINO state, without compromising the model
			 * by means of checkEvents() method.
			 */
			controller.handleIncomingMessages();
			controller.checkEvents();
		}
	}
}
