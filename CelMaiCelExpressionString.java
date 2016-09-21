/**
* CelMaiCelExpressionString class implements a written function
*
* @author Dan Andrei Iliescu
*/

public class CelMaiCelExpressionString
{
  
  private String [] expression;
  
  private int evaluationIndex;
  
  // Constructor
  public CelMaiCelExpressionString(String requiredExpression)
  {
    expression = requiredExpression.split("_");
  }
  
  public double interpret(double argument)
  {
    // Reinitialise evaluation index;
    evaluationIndex = 0;
    
    // Return result
    return evaluate(argument);
  }
  
  public double evaluate(double argument)
  { 
    switch(expression[evaluationIndex])
    {
      // Variable
      case "x":
      {
        // Update evaluation index
        evaluationIndex ++;
        
        // Return argument
        return argument;
      }
      // Addition
      case "add":
      {
        // Update evaluation index
        evaluationIndex ++;
        
        // Evaluate first term
        double term1 = evaluate(argument);
      
        // Evaluate second term
        double term2 = evaluate(argument);
      
        // Return their sum
        return term1 + term2;
      }
      // Subtraction
      case "sub":
      {
        // Update evaluation index
        evaluationIndex ++;
      
        // Evaluate first term
        double term1 = evaluate(argument);
      
        // Evaluate second term
        double term2 = evaluate(argument);
      
        // Return their difference
        return term1 - term2;
      }
      // Multiplication
      case "mul":
      {
        // Update evaluation index
        evaluationIndex ++;
      
        // Evaluate first term
        double term1 = evaluate(argument);
      
        // Evaluate second term
        double term2 = evaluate(argument);
      
        // Return their product
        return term1 * term2;
      }
      // Double Division
      case "div":
      {
        // Update evaluation index
        evaluationIndex ++;
      
        // Evaluate first term
        double term1 = evaluate(argument);
      
        // Evaluate second term
        double term2 = evaluate(argument);
      
        // Return their ratio
        return (double) term1 / term2;
      }
      // Power
      case "pow":
      {
        // Update evaluation index
        evaluationIndex ++;
      
        // Evaluate first term
        double term1 = evaluate(argument);
      
        // Evaluate second term
        double term2 = evaluate(argument);
      
        // Return their power
        return Math.pow(term1, term2);
      }
      // Logarithm
      case "log":
      {
        // Update evaluation index
        evaluationIndex ++;
      
        // Evaluate first term
        double term1 = evaluate(argument);
      
        // Evaluate second term
        double term2 = evaluate(argument);
        
        // Return their log
        return Math.log(term2) / Math.log(term1);
      }
      // Square root
      case "sqr":
      {
        // Update evaluation index
        evaluationIndex ++;
      
        // Evaluate first term
        double term1 = evaluate(argument);
      
        // Return square root
        return Math.sqrt(term1);
      }
      // Pi
      case "pi":
      {
        // Update evaluation index
        evaluationIndex ++;
        
        return Math.PI;
      }
      // Euler's number
      case "e":
      {
        // Update evaluation index
        evaluationIndex ++;
        
        return Math.E;
      }
    } // switch
    
    // Update evaluation index
    evaluationIndex ++;
    
    // Return double form of number
    return Double.parseDouble(expression[evaluationIndex - 1]);
  }
} // class

