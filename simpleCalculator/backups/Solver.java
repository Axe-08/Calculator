
package com.simpleCalculator.math;

import java.util.Stack;
public class Solver {

	    public static String convertToPostfix(String infix) {
	        StringBuilder postfix = new StringBuilder();
	        Stack<Character> stack = new Stack<>();
	        stack.push('#');

	        for (int i = 0; i < infix.length(); i++) {
	            char c = infix.charAt(i);

	            if (isNumberOrDecimal(c) || c == '_') {
	                postfix.append(c);
	            } else if (isOperator(c)) {
	                while (precedence(c) <= precedence(stack.peek())) {
	                    postfix.append(stack.pop());
	                }
	                stack.push(c);
	            } else {
	              //  throw new IllegalArgumentException("Invalid character in input: " + c);
	            }
	        }

	        while (stack.peek() != '#') {
	            postfix.append(stack.pop());
	        }
	        return postfix.toString();
	    }

	    public static float evaluatePostfix(String postfix) {
	        Stack<Float> stack = new Stack<>();
	        int i = 0;

	        while (i < postfix.length()) {
	            char c = postfix.charAt(i);

	            if (c == '_') {
	                i++;
	                int v = i;
	                while (postfix.charAt(v) != '~') v++;
	                stack.push(-1 * Float.parseFloat(postfix.substring(i, v)));
	                i = v;
	            } else if (isNumberOrDecimal(c)) {
	                int v = i;
	                while (postfix.charAt(v) != '~') v++;
	                stack.push(Float.parseFloat(postfix.substring(i, v)));
	                i = v;
	            } else if (isOperator(c)) {
	                float operand1 = stack.pop();
	                float operand2 = stack.pop();
	                stack.push(performOperation(c, operand2, operand1));
	            }
	            i++;
	        }
	        return stack.pop();
	    }

	    private static float performOperation(char operator, float operand1, float operand2) {
	        switch (operator) {
	            case '^': return (float) Math.pow(operand1, operand2);
	            case '*': return operand1 * operand2;
	            case '/': return operand2 != 0 ? operand1 / operand2 : Float.NaN;
	            case '%': return operand1 % operand2;
	            case '+': return operand1 + operand2;
	            case '-': return operand1 - operand2;
	            default: throw new IllegalArgumentException("Unknown operator: " + operator);
	        }
	    }

	    private static boolean isNumberOrDecimal(char c) {
	        return (c >= '0' && c <= '9') || c == '.';
	    }

	    private static boolean isOperator(char c) {
	        return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
	    }

	    private static int precedence(char operator) {
	        switch (operator) {
	            case '^': return 3;
	            case '*': case '/': case '%': return 2;
	            case '+': case '-': return 1;
	            default: return 0;
	        }
	    }

	    private static boolean isOpenBracket(char c) {
	        return c == '(' || c == '[' || c == '{';
	    }

	    private static boolean isClosingBracket(char c) {
	        return c == ')' || c == ']' || c == '}';
	    }

	    private static int findMatchingClosingBracket(String line, int openBracketIndex) {
	        int level = 0;
	        for (int i = openBracketIndex + 1; i < line.length(); i++) {
	            if (isOpenBracket(line.charAt(i))) level++;
	            else if (isClosingBracket(line.charAt(i))) {
	                if (level == 0) return i;
	                level--;
	            }
	        }
	        return -1;
	    }

	    private static boolean validateBrackets(String line) {
	        int balance = 0;
	        for (char c : line.toCharArray()) {
	            if (isOpenBracket(c)) balance++;
	            if (isClosingBracket(c)) balance--;
	            if (balance < 0) return false;  // Early exit if closing bracket comes before an open one
	        }
	        return balance == 0;
	    }

	    public static void main(String[] args) {
	        String expression = "3 + 5 * 2 / ( 7 - 2 )";
	        
	        if (!validateBrackets(expression)) {
	            System.out.println("Invalid bracket placement");
	            return;
	        }

	        String postfixExpression = convertToPostfix(expression);
	        System.out.println("Postfix Expression: " + postfixExpression);
	        
	        float result = evaluatePostfix(postfixExpression);
	        System.out.println("Result: " + result);
	    }
}


