import java.io.IOException;
import java.util.Scanner;

public class Test {

	public static void main(String[] args) throws IOException {
		  Scanner sc = new Scanner(System.in);
		  System.out.print("Enter Data: ");
	      String input = sc.next();
	      System.out.println("Echo Data: " + input);
	      
	      String output;
	      Postfix theTrans = new Postfix(input);
	      output = theTrans.doTrans(); 
	      System.out.println("Conversion: " + output);
	      
	      Postfix theResult = new Postfix(output);
	      int result = theResult.calculate(output);
	      System.out.println("Result: " + result);
	   }

}
