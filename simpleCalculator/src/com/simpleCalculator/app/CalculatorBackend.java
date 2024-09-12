package com.simpleCalculator.app;

import com.simpleCalculator.math.Evaluator;

public class CalculatorBackend {

    public String evaluate(String expression) {
        try {	//execute evalutaor class to find answer for expression and return the string answer
            Evaluator evaluator = new Evaluator(expression);
            float result = evaluator.answer;
            return Float.toString(result);
        } catch (Exception e) {
            e.printStackTrace();
            return "Error";
        }
    }
}