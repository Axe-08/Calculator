package com.simpleCalculator.app;

import com.simpleCalculator.ui.CalculatorDisplay;

public class CalculatorController {
	private CalculatorDisplay display;  // instance of display object
	private CalculatorBackend backend;	// instance to backend object
	private StringBuilder currentInput;	// running input on the display

	public CalculatorController(CalculatorDisplay display) {
		this.display = display;
		this.backend = new CalculatorBackend();
		this.currentInput = new StringBuilder();
	}
	
	public int getInputLength() {		//getter method for current working input string length
		return currentInput.length();
	}

	public void appendToInput(String text) {
		currentInput.append(text);					//write to the running input 
		display.setInputText(currentInput.toString());	//backend will handle the evaluation
	}

	public void handleEquals() {					//sends current input to backend for evaluation and returns the evaluated answer
		String expression = currentInput.toString();  
		String result = backend.evaluate(expression);

		// Add the input and result to history
		display.addHistory(expression, result);

		display.setResultText(result);
		currentInput.setLength(0); // Clear current input after evaluation
	}

	public void handleClear() {    //when user clicks C
		if (currentInput.length() == 0) { //reset the current input and clears the history if pressed the second time

			display.clearHistory();

		}
		currentInput.setLength(0);
		display.clear();
	}

	public void handleDelete() { //handles when user presses backspace or DEL.
		if (currentInput.length() > 0) {
			currentInput.deleteCharAt(currentInput.length() - 1);
			display.setInputText(currentInput.toString());
		}

	}
	
	public void setCaret(int index) {
		display.setCaret(index);	//set caret position
	}
	
	public int getCaret() {			//find caret position
		return display.getCaret();
	}
	
}