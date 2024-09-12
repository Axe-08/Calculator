package com.simpleCalculator.app;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import com.simpleCalculator.math.Utils;

public class KeyPressHandler extends KeyAdapter {
	private CalculatorController controller;

	public KeyPressHandler(CalculatorController controller) {
		this.controller = controller;
	}

	public void keyTyped(KeyEvent e) {
		char keyChar = e.getKeyChar();

		// Handle numeric input
		if (Character.isDigit(keyChar)) {
			controller.appendToInput(Character.toString(keyChar));
		}
		// Handle operators and decimal point
		else if (Utils.isOperator(keyChar) || keyChar == '.') {
			controller.appendToInput(Character.toString(keyChar));
		} else if (keyChar == '(' || keyChar == ')') {
			controller.appendToInput(Character.toString(keyChar));
		}
		// Handle Enter key
		else if (keyChar == KeyEvent.VK_ENTER) {
			controller.handleEquals();
		}
		// Handle Backspace
		else if (keyChar == KeyEvent.VK_BACK_SPACE) {
			controller.handleDelete();
		}
		// Handle Clear
		else if (keyChar == 'C') {
			controller.handleClear();
		} else if (keyChar == KeyEvent.VK_LEFT) {	//change caret position by keyboard
			int caretPosition = controller.getCaret();
			if (caretPosition > 0) {
				controller.setCaret(caretPosition - 1);
			}
		} else if (keyChar == KeyEvent.VK_RIGHT) {	//change caret position by keyboard
			int caretPosition = controller.getCaret();
			if (caretPosition < controller.getInputLength()) {
				controller.setCaret(caretPosition + 1);
			}
		}
		// Handle any other keys
		else {
			// Ignore or handle other keys if necessary
		}
	}
}