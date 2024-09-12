package com.simpleCalculator.ui;

import com.simpleCalculator.app.CalculatorController;
import javax.swing.*;
import java.awt.*;
import java.util.HashMap;
import java.util.Map;

public class CalculatorButtonPanel extends JPanel {
    private CalculatorController controller;
    private Map<String, JButton> buttons;

    public CalculatorButtonPanel(CalculatorController controller) {
        this.controller = controller;
        buttons = new HashMap<>();
        setLayout(new GridLayout(5, 4, 5, 5));
        initializeButtons();
    }

    private void initializeButtons() {
        String[] buttonLabels = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", ".", "=", "+",
                "C", "DEL","(",")"
        };

        for (String label : buttonLabels) {
            JButton button = new JButton(label);
            button.setFont(new Font("Arial", Font.PLAIN, 24));
            button.addActionListener(e -> handleButtonPress(label));
            buttons.put(label, button);
            add(button);
        }
    }

    private void handleButtonPress(String label) {
        switch (label) {
            case "=":
                controller.handleEquals();
                break;
            case "C":
                controller.handleClear();
                break;
            case "DEL":
                controller.handleDelete();
                break;
            default:
                controller.appendToInput(label);
                break;
        }
    }
}