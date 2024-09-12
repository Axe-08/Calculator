package com.simpleCalculator.backup;
import javax.swing.*;
import java.awt.*;

@SuppressWarnings("serial")
public class CalculatorDisplay extends JPanel {
    private JTextField inputField;
    private JLabel resultLabel;

    public CalculatorDisplay() {
        setLayout(new GridBagLayout());
        
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.BOTH;
        
        //Display area
        JTextArea display = new JTextArea(2,20);
        display.setEditable(false);
        display.setLineWrap(true);
        display.setWrapStyleWord(true);
        display.setFont(new Font("Ariel",Font.PLAIN,20));
       
        
        //button area
        resultLabel = new JLabel(" ", SwingConstants.RIGHT);
        resultLabel.setFont(new Font("Arial", Font.PLAIN, 24));
        resultLabel.setForeground(Color.GRAY);

        add(inputField, BorderLayout.NORTH);
        add(resultLabel,));
    }
    
    void SetDisplayArea(JTextArea display)
    
    JTextField setUpInputArea(GridBagConstraints gbc) {
    	JTextField inputField = new JTextField();
        inputField.setFont(new Font("Arial", Font.PLAIN, 18));
        inputField.setHorizontalAlignment(SwingConstants.RIGHT);
        
        
    	
    	return inputField;
    }

    public void updateDisplay(String input, String result) {
        inputField.setText(input);
        resultLabel.setText(result);
    }

    public void setResult(String result) {
        resultLabel.setText(result);
    }

    public String getInput() {
        return inputField.getText();
    }

    public void clearInput() {
        inputField.setText("");
    }

    public void moveInputToResult() {
        resultLabel.setText(inputField.getText());
        resultLabel.setForeground(Color.GRAY);
        inputField.setText("");
    }

    public void resetDisplay() {
        resultLabel.setText(" ");
        inputField.setText("");
    }

    public void focusOnInput() {
        inputField.requestFocusInWindow();
    }
}