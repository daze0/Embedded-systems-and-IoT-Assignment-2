package smartCoffeeMachineManager.view;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import smartCoffeeMachineManager.view.events.MonitorModeEvent;
import smartCoffeeMachineManager.view.events.RecoverEvent;
import smartCoffeeMachineManager.view.events.RefillEvent;

public class ViewImpl implements View {
	
	private static final int SIZE = 300;
	private final String title;
	private final ViewObserver controller;
	private final JFrame frame;
	
	public ViewImpl(final String title, final ViewObserver observer) {
		this.title = title;
		this.controller = observer;
		this.frame = new JFrame();
		this.frame.setTitle(this.title);
		this.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.frame.setResizable(false);
		this.frame.setSize(ViewImpl.SIZE, ViewImpl.SIZE);
	}

	@Override
	public void init() {
		/*
		 * Various graphic components are being defined here.
		 * In top-down order, kinda.
		 */
		final JPanel wrapperPanel = new JPanel(new BorderLayout());
		final JPanel btnPanel = new JPanel(new GridLayout(1, 3));
		final CardLayout cardLayout = new CardLayout();
		final JPanel cardPanel = new JPanel(cardLayout);
		final JButton monitorBtn = new JButton("Monitor");
		final JButton refillBtn = new JButton("Refill");
		final JButton recoverBtn = new JButton("Recover");
		/*
		 * These are the panels within the CardLayout, notice that they all
		 * co-exist, one of them is visible the others are hidden.
		 */
		final JPanel monitorPanel = new JPanel(new GridLayout(3, 1));
		monitorPanel.setBackground(Color.CYAN);
		final JLabel modeLabel = new JLabel("Mode: ");
		final JLabel productsLabel = new JLabel("Products: ");
		final JLabel nTestsLabel = new JLabel("n of Self-Tests: ");
		monitorPanel.add(modeLabel);
		monitorPanel.add(productsLabel);
		monitorPanel.add(nTestsLabel);
		final JPanel refillPanel = new JPanel(new FlowLayout());
		refillPanel.setBackground(Color.GREEN);
		final JPanel recoverPanel = new JPanel(new FlowLayout());
		recoverPanel.setBackground(Color.MAGENTA);
		/*
		 * Buttons' action listeners declared/defined down here.
		 */
		monitorBtn.addActionListener(l -> {
			this.controller.notifyEvent(new MonitorModeEvent());
			cardLayout.show(cardPanel, "Monitor");
		});
		refillBtn.addActionListener(l -> {
			this.controller.notifyEvent(new RefillEvent());
			cardLayout.show(cardPanel, "Refill");
		});
		recoverBtn.addActionListener(l -> {
			this.controller.notifyEvent(new RecoverEvent());
			cardLayout.show(cardPanel, "Recover");
		});
		/*
		 * In the end everything is packed up into the main frame
		 * which is then set to visible.
		 */
		btnPanel.add(monitorBtn);
		btnPanel.add(refillBtn);	// Adding btns to btnPanel
		btnPanel.add(recoverBtn);
		cardPanel.add(monitorPanel, "Monitor");
		cardPanel.add(refillPanel, "Refill");	// Adding panels to cardPanel
		cardPanel.add(recoverPanel, "Recover");
		wrapperPanel.add(cardPanel, BorderLayout.CENTER); // wrapper/main panel wrapped up around the other two: btnPanel, cardPanel
		wrapperPanel.add(btnPanel, BorderLayout.SOUTH);		
		this.frame.getContentPane().add(wrapperPanel);
		this.frame.setVisible(true);
	}

	@Override
	public void showMonitorMode(/*final String mode, final String productsAvailable, final int nSelfTests*/) {
		/* 
		 * TODO: maybe try to update monitor panel labels 
		 * 		 with real-time values(computed when monitor button is clicked).
		 * 		 Possible problem: cannot access labels.
		 * 
		 * ^same in below methods (?)
		 */
		
	}

	@Override
	public void showRefill() {
		// TODO ^
		controller.notifyEvent(new RefillEvent());
	}

	@Override
	public void showRecover() {
		// TODO ^^
		controller.notifyEvent(new RecoverEvent());
	}

}
