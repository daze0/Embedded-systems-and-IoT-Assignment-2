package smartCoffeeMachineManager.view.test;

import org.junit.Test;

import smartCoffeeMachineManager.core.Controller;
import smartCoffeeMachineManager.view.View;
import smartCoffeeMachineManager.view.ViewImpl;

public class ViewImplTest {

	@Test
	public void test() {
		final View view = new ViewImpl("title", new Controller());
		view.init();
	}

}
