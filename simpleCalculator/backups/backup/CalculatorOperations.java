package com.simpleCalculator.backup;

public class CalculatorOperations {
    private CalculatorDisplay display;
    private BackendCalculator backend;

    public CalculatorOperations(CalculatorDisplay display) {
        this.display = display;
        this.backend = new BackendCalculator();
    }

    public void calculate() {
        String input = display.getInput();
        String result = backend.calculate(input);  // assuming this method returns a string
        display.setResult(result);
        display.moveInputToResult();
    }

    public void clear() {
        display.resetDisplay();
    }

    public void appendNumber(char number) {
        String currentText = display.getInput();
        display.updateDisplay(currentText + number, "");
    }

    public void appendOperator(String operator) {
        String currentText = display.getInput();
        display.updateDisplay(currentText + operator, "");
    }
}