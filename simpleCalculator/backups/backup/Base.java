/*package com.simpleCalculator.app;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import com.simpleCalculator.math.*;

public class Base extends JFrame implements ActionListener {
	
		private JTextField displayOutput;
		private JTextArea displayInput;
		
		public Base() {
			
			Font font = new Font("Ariel",Font.PLAIN,24);
					
			
			setTitle("Calculator");
			setSize(400,500);
			setDefaultCloseOperation(EXIT_ON_CLOSE);
			setLocationRelativeTo(null);
			
			  // Display for Input
	        displayInput = new JTextArea(3, 20);
	        displayInput.setLineWrap(true);
	        displayInput.setWrapStyleWord(true);
	        displayInput.setEditable(false);
	        displayInput.setFont(new Font("Arial", Font.PLAIN, 24));
	        
	        // Display for Output
	        displayOutput = new JTextField();
	        displayOutput.setEditable(false);
	        displayOutput.setFont(new Font("Arial", Font.PLAIN, 32));
			
	        JPanel panel = new JPanel();
	        panel.setLayout(new BorderLayout());
			panel.add(new JScrollPane(displayInput), BorderLayout.NORTH);
	        panel.add(displayOutput, BorderLayout.AFTER_LAST_LINE);
			
	        JPanel buttonPanel = new JPanel();
	        buttonPanel.setLayout(new GridLayout(5,4,10,10));
			String[] buttonLabels = {
				"7","8","9","/",
				"4","5","6","*",
				"1","2","3","-",
				".","0","+","=",
				"DEL","CLS"
			};
			
	
			for(String label: buttonLabels) {
				JButton button = new JButton(label);
				button.addActionListener(this);
				button.setFont(font);
				buttonPanel.add(button);
			}
	
			
			
			panel.add(buttonPanel,BorderLayout.AFTER_LAST_LINE);
			add(panel,BorderLayout.CENTER);
			//add(buttonPanel,BorderLayout.CENTER);
			
			
			
		}
	
		@Override
		public void actionPerformed(ActionEvent e) {
			  String command = e.getActionCommand();

		        switch (command) {
		            case "C":
		                display.setText("");
		                break;
		            case "=":
		                try {
		                    String input = display.getText();
		                    // Call your backend method here
		                    double result = evaluateExpression(input); // replace with your method
		                    display.setText(String.valueOf(result));
		                } catch (Exception ex) {
		                    display.setText("Error");
		                }
		                break;
		            default:
		                display.setText(display.getText() + command);
		                break;
		        }
		}
	
public static void main() {
		
	 SwingUtilities.invokeLater(() -> {
          Base calculator = new Base();
         calculator.setVisible(true);
     });
	}


@Override
public void actionPerformed(ActionEvent e) {
	// TODO Auto-generated method stub
	
}
}
*/
package com;

S