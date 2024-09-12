package com.simpleCalculator.backup;


import javax.swing.*;
import java.awt.*;

public class CalculatorGUI extends JFrame {
    public CalculatorGUI() {
        setTitle("Calculator");
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create display area
        JTextArea display = new JTextArea(2, 20);
        display.setFont(new Font("Arial", Font.PLAIN, 20));
        display.setEditable(false);
        display.setLineWrap(true);
        display.setWrapStyleWord(true);

        JScrollPane scrollPane = new JScrollPane(display);
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 4;
        gbc.gridheight = 2;
        gbc.weightx = 1;
        gbc.weighty = 0.3;
        gbc.fill = GridBagConstraints.BOTH;

        // Create backend and controller
        BackendCalculator backend = new BackendCalculator();
        CalculatorController controller = new CalculatorController(display, backend);

        // Create button panel
        CalculatorButtonPanel buttonPanel = new CalculatorButtonPanel(controller);

        // Add components to the main frame
        setLayout(new GridBagLayout());
        add(scrollPane, gbc);

        gbc.gridy = 2;
        gbc.gridwidth = 4;
        gbc.gridheight = 4;
        gbc.weighty = 0.7;
        add(buttonPanel, gbc);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            CalculatorGUI calc = new CalculatorGUI();
            calc.setVisible(true);
        });
    }
}