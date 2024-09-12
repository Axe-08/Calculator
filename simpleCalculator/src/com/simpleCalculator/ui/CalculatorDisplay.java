package com.simpleCalculator.ui;


import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class CalculatorDisplay extends JPanel {
    private JTextField inputField;
    private JLabel resultLabel;
    private DefaultListModel<String> historyModel;
    private JList<String> historyList;


    public CalculatorDisplay() {
        setLayout(new BorderLayout(5, 5));

        // Input Field
        inputField = new JTextField();
        inputField.setFont(new Font("Arial", Font.PLAIN, 24));
        inputField.setEditable(true);
        inputField.setHorizontalAlignment(SwingConstants.RIGHT);

        // Result Label
        resultLabel = new JLabel("");
        resultLabel.setFont(new Font("Arial", Font.BOLD, 32));
        resultLabel.setHorizontalAlignment(SwingConstants.RIGHT);
        resultLabel.setForeground(Color.BLUE);

        historyModel = new DefaultListModel<>();
        historyList = new JList<>(historyModel);
        historyList.setFont(new Font("Arial", Font.PLAIN, 14));
        JScrollPane historyScrollPane = new JScrollPane(historyList);
        
        // Enable cursor movement with mouse
        inputField.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                // Set the cursor to the position of the mouse click
                int pos = inputField.viewToModel2D(e.getPoint());
                inputField.setCaretPosition(pos);
            }
        });
        

        // Adding components to the panel
        add(inputField, BorderLayout.NORTH);
        add(resultLabel, BorderLayout.CENTER);
        add(historyScrollPane, BorderLayout.SOUTH);
    }

    // Methods to update display
    public void setInputText(String text) {
        inputField.setText(text);
    }
    
    public void setCaret(int index) {
    	inputField.setCaretPosition(index);
    }
    
    public int getCaret() {
    	return inputField.getCaretPosition();
    }

    public void setResultText(String text) {
        resultLabel.setText(text);
    }

    public void clear() {
        inputField.setText("");
        resultLabel.setText("");
    }

    public String getInputText() {
        return inputField.getText();
    }
 
    // Method to add to history
    public void addHistory(String expression, String result) {
        historyModel.add(0,expression + " = " + result);
        
    }

    // Method to clear history
    public void clearHistory() {
        historyModel.clear();
    }
}