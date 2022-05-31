package smartCoffeeMachineManager.view;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import smartCoffeeMachineManager.view.events.MonitorModeEvent;
import smartCoffeeMachineManager.view.events.RecoverEvent;
import smartCoffeeMachineManager.view.events.RefillEvent;
import smartCoffeeMachineManager.view.events.ViewEvents;

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
		final JPanel wrapperPanel = new JPanel(new BorderLayout());
		final JPanel btnPanel = new JPanel(new GridLayout(1, 3));
		final CardLayout cardLayout = new CardLayout();
		final JPanel cardPanel = new JPanel(cardLayout);
		final JButton monitorBtn = new JButton("Monitor");
		final JButton refillBtn = new JButton("Refill");
		final JButton recoverBtn = new JButton("Recover");
		final JPanel monitorPanel = new JPanel(new FlowLayout());
		monitorPanel.setBackground(Color.BLUE);
		final JPanel refillPanel = new JPanel(new FlowLayout());
		refillPanel.setBackground(Color.GREEN);
		final JPanel recoverPanel = new JPanel(new FlowLayout());
		recoverPanel.setBackground(Color.MAGENTA);
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
		btnPanel.add(monitorBtn);
		btnPanel.add(refillBtn);
		btnPanel.add(recoverBtn);
		cardPanel.add(monitorPanel, "Monitor");
		cardPanel.add(refillPanel, "Refill");
		cardPanel.add(recoverPanel, "Recover");
		wrapperPanel.add(cardPanel, BorderLayout.CENTER);
		wrapperPanel.add(btnPanel, BorderLayout.SOUTH);
		this.frame.getContentPane().add(wrapperPanel);
		this.frame.setVisible(true);
	}

	@Override
	public void showMonitorMode() {
		// TODO Auto-generated method stub
		controller.notifyEvent(new MonitorModeEvent());
	}

	@Override
	public void showRefill() {
		// TODO Auto-generated method stub
		controller.notifyEvent(new RefillEvent());
	}

	@Override
	public void showRecover() {
		// TODO Auto-generated method stub
		controller.notifyEvent(new RecoverEvent());
	}

}
