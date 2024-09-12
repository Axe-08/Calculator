package com.simpleCalculator.backup;


import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;

public class KeyBinding {
    @SuppressWarnings("serial")
	public static void bindKeys(CalculatorDisplay display, CalculatorOperations operations) {
        InputMap inputMap = display.getInputMap(JComponent.WHEN_IN_FOCUSED_WINDOW);
        ActionMap actionMap = display.getActionMap();

        inputMap.put(KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0), "calculate");
        actionMap.put("calculate", new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                operations.calculate();
            }
        });

        inputMap.put(KeyStroke.getKeyStroke(KeyEvent.VK_ESCAPE, 0), "clear");
        actionMap.put("clear", new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                operations.clear();
            }
        });

        // Additional keybindings for numbers and operators can be added here
        for (int i = KeyEvent.VK_0; i <= KeyEvent.VK_9; i++) {
            int key = i;
            inputMap.put(KeyStroke.getKeyStroke(key, 0), "appendNumber" + key);
            actionMap.put("appendNumber" + key, new AbstractAction() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    operations.appendNumber(Character.forDigit(key - KeyEvent.VK_0, 10));
                }
            });
        }

        String[] operators = {"+", "-", "*", "/"};
        for (String op : operators) {
            inputMap.put(KeyStroke.getKeyStroke(op), "appendOperator" + op);
            actionMap.put("appendOperator" + op, new AbstractAction() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    operations.appendOperator(op);
                }
            });
        }
    }
}
