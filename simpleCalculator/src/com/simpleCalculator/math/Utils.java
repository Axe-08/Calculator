package com.simpleCalculator.math;

public class Utils {
	//operator list
	private static Character[] operators= {'+','-','*','/','%','^'};
	
	//utility to check if character is number or a decimal point
	   public static boolean isNumberOrDecimal(char c) {
	        return (c >= '0' && c <= '9') || c == '.';
	    }
	 //utility to check if character is operator
	    public static boolean isOperator(char c) {
	    	  for (Character element : operators) {
	              if (element == c) {
	                  return true;
	              }
	          }
	          return false;
	    }
	    //utility to manage precedence
	    public static int precedence(char operator) {
	        switch (operator) {
	            case '^': return 3;
	            case '*': case '/': case '%': return 2;
	            case '+': case '-': return 1;
	            default: return 0;
	        }
	    }
}

