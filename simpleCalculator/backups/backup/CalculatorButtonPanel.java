package com.simpleCalculator.backup;
import javax.swing.*;
import java.awt.*;

public class CalculatorButtonPanel extends JPanel {
	public CalculatorButtonPanel(CalculatorController controller) {
        setLayout(new GridLayout(5, 4));
        

        String[] buttonLabels = {
				"7","8","9","/",
				"4","5","6","*",
				"1","2","3","-",
				".","0","+",};
	
			for(String label: buttonLabels) {
				JButton button = new JButton(label);
				button.setFont(new Font("Ariel",Font.PLAIN,16));
				button.addActionListener(e -> controller.handleInput(button.getText()));
				add(button);
			}

        // Adding '=' button
        JButton equalsButton = new JButton("=");
        equalsButton.addActionListener(e -> controller.handleEquals());
        add(equalsButton);
        
        JButton delButton = new JButton("DEL");
        equalsButton.addActionListener(e -> controller.handleDel());
        add(delButton);
        

        // Adding 'C' button (Clear)
        JButton clearButton = new JButton("C");
        clearButton.addActionListener(e -> controller.handleClear());
        add(clearButton);
        
        
    }
}
