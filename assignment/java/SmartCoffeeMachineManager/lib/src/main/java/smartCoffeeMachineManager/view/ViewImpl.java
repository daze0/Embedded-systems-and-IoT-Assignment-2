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
import javax.swing.SwingUtilities;

import smartCoffeeMachineManager.logging.AppLogger;
import smartCoffeeMachineManager.view.events.MonitorModeEvent;
import smartCoffeeMachineManager.view.events.RecoverEvent;
import smartCoffeeMachineManager.view.events.RefillEvent;

public class ViewImpl implements View {
	
	private static final int SIZE_X = 1500;
	private static final int SIZE_Y = 500;
	private static final String TITLE = "SmartCoffeeMachineManager";
	
	private final ViewObserver controller;
	private final JFrame frame;
	private final JLabel modeLabel;
	private final JLabel productsAvailableLabel;
	private final JLabel nTestsLabel;
	private final JLabel refillLabel;
	private final JLabel recoverLabel;
	
	public ViewImpl(final ViewObserver observer) {
		this.controller = observer;
		this.frame = new JFrame();
		this.frame.setTitle(ViewImpl.TITLE);
		this.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.frame.setResizable(false);
		this.frame.setSize(ViewImpl.SIZE_X, ViewImpl.SIZE_Y);
		this.modeLabel = new JLabel();
		this.productsAvailableLabel = new JLabel();
		this.nTestsLabel = new JLabel();
		this.refillLabel = new JLabel();
		this.recoverLabel = new JLabel();
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
		this.modeLabel.setText("Mode: ");
		this.productsAvailableLabel.setText("Products available: ");
		this.nTestsLabel.setText("n of Self-Tests: ");
		monitorPanel.add(this.modeLabel);
		monitorPanel.add(this.productsAvailableLabel);
		monitorPanel.add(this.nTestsLabel);
		final JPanel refillPanel = new JPanel(new FlowLayout());
		refillPanel.setBackground(Color.GREEN);
		this.refillLabel.setText("Refill needed: ");
		refillPanel.add(this.refillLabel);
		final JPanel recoverPanel = new JPanel(new FlowLayout());
		recoverPanel.setBackground(Color.MAGENTA);
		this.recoverLabel.setText("Recover needed: ");
		recoverPanel.add(this.recoverLabel);
		/*
		 * Buttons' action listeners declared/defined down here.
		 */
		monitorBtn.addActionListener(l -> {
			this.controller.notifyEvent(new MonitorModeEvent());
			cardLayout.show(cardPanel, "Monitor");
			AppLogger.getAppLogger().debug("Notified MonitorModeEvent and shown Monitor card panel");
		});
		refillBtn.addActionListener(l -> {
			this.controller.notifyEvent(new RefillEvent());
			cardLayout.show(cardPanel, "Refill");
			AppLogger.getAppLogger().debug("Notified RefillEvent and shown Refill card panel");
		});
		recoverBtn.addActionListener(l -> {
			this.controller.notifyEvent(new RecoverEvent());
			cardLayout.show(cardPanel, "Recover");
			AppLogger.getAppLogger().debug("Notified RecoverEvent and shown Recover card panel");
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
	public void showMonitorMode(final String mode, final String productsAvailable, final int nSelfTests) {
		AppLogger.getAppLogger().debug("Inside showMonitorMode()");
		SwingUtilities.invokeLater(() -> {
			this.modeLabel.setText("Mode: " + mode);
			this.productsAvailableLabel.setText("Products available: " + productsAvailable);
			this.nTestsLabel.setText("n of Self-Tests: " + String.valueOf(nSelfTests));
		});
	}

	@Override
	public void showRefill(final boolean needRefill) {
		AppLogger.getAppLogger().debug("Inside showRefill()");
		SwingUtilities.invokeLater(() -> {
			this.refillLabel.setText("Refill needed: " + (needRefill ? "yes" : "no"));
		});
	}

	@Override
	public void showRecover(final boolean needRecover) {
		AppLogger.getAppLogger().debug("Inside showRecover()");
		SwingUtilities.invokeLater(() -> {
			this.recoverLabel.setText("Recover needed: " + (needRecover ? "yes" : "no"));
		});
	}

}
