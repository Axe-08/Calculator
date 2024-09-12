package com.simpleCalculator.app;

import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import com.simpleCalculator.ui.CalculatorDisplay;
import com.simpleCalculator.ui.CalculatorButtonPanel;
import javax.swing.*;
import java.awt.*;

public class CalculatorGUI extends JFrame {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public CalculatorGUI() {	
        setTitle("Simple Calculator");
        setSize(400, 600);		//create window
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); // Centers the window

        // Set layout manager
        setLayout(new GridBagLayout());			//one of the better layout for current functionality
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.BOTH;
        gbc.insets = new Insets(10, 10, 10, 10);

        // Initialize display
        CalculatorDisplay display = new CalculatorDisplay();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.weightx = 1;
        gbc.weighty = 0.3;
        gbc.gridwidth = 4;
        add(display, gbc);	

        // Initialize controller
        CalculatorController controller = new CalculatorController(display);

        // Initialize buttons
        CalculatorButtonPanel buttonPanel = new CalculatorButtonPanel(controller);
        gbc.gridy = 1;
        gbc.weighty = 0.7;
        add(buttonPanel, gbc);

        // KeyPressHandler for keyboard support
        KeyPressHandler keyPressHandler = new KeyPressHandler(controller);
        addKeyListener(keyPressHandler);
        setFocusable(true);
        requestFocus(); // Request focus to ensure keyboard input is captured
        
        addFocusListener(new FocusListener() {
            @Override
            public void focusGained(FocusEvent e) {
                // Optionally handle focus gained
            }

            @Override
            public void focusLost(FocusEvent e) {
                // Request focus again when the window loses focus
                SwingUtilities.invokeLater(() -> requestFocus());
            }
        });

        
        // Make the frame visible
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(CalculatorGUI::new);
    }
}