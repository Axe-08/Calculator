package com.simpleCalculator.backup;
import javax.swing.*;
public class CalculatorController {
    private JTextArea display;
    private BackendCalculator backend;
    private StringBuilder currentInput;

    public CalculatorController(JTextArea display, BackendCalculator backend) {
        this.display = display;
        this.backend = backend;
        this.currentInput = new StringBuilder();
    }

    // Method to handle input (e.g., when a number or operator button is pressed)
    public void handleInput(String input) {
        currentInput.append(input);
        display.setText(currentInput.toString());
    }

    public void handleDel() {
    	 if (currentInput.length() > 0) {
    	        currentInput.deleteCharAt(currentInput.length() - 1);
    	        display.setText(currentInput.toString());
    	    }
    }
    
    // Method to handle the '=' button press
    public void handleEquals() {
        try {
            String result = backend.evaluate(currentInput.toString());
            display.setText(currentInput.toString() + "\n" + result);  // Display both input and result
            currentInput.setLength(0);  // Clear current input
        } catch (Exception e) {
            display.setText("Error in Cont");
        }
    }

    // Method to reset the display (e.g., when 'C' button is pressed)
    public void handleClear() {
        currentInput.setLength(0);
        display.setText("");
    }
}