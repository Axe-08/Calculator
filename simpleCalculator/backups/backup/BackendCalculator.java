package com.simpleCalculator.backup;
import com.simpleCalculator.math.Evaluator;

public class BackendCalculator {
    public String evaluate(String input) {
    	try {
			Evaluator ev = new Evaluator(input);
			return Float.toString(ev.answer);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	return "ERROR at back";
 
    }
}
