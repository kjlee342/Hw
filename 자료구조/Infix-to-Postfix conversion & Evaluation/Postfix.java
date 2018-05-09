 /* 	기능:		infix 수식을 넣으면 postfix 수식으로 변환 후 결과 값을 계산한다. 
 * 	알고리즘:	infix 수식의 길이만큼의 사이즈를 가지는 스택을 생성, infix 수식의 데이타를 하나 하나 읽어오면서
 * 			operand일 경우 아웃풋에 넣고 operator일 경우 더하기, 빼기, 곱하기, 나누기는 우선 순위를 가지고
 * 			판단하며 괄호의 경우 '('는 스택에 push하며 ')'일 경우는 스택에서 '('가 나오거나 빌 때까지 pop한다.
 * 			operator의 우선 순위의 경우 +, -는 1 *, /는 2를 가지며 우선 순위가 큰 것부터 계산한다.
 * 			이렇게 변환되어 postfix로 변환된 output의 길이만큼의 사이즈를 가지는 스택을 생성.
 * 			output 데이타를 하나 하나 읽어오면서 operand일 경우 스택에 push하며, operator일 경우
 * 			스택에서 pop을 두 번하여 두 수를 읽어오고 operator로 계산한 후 다시 스택에 push한다.
 * 			마지막에 스택에는 result만 남으며 읽어오면 끝이난다.
 * 	변수설명
 * 			theStack:	스택 이름
 * 			input:	infix 수식을 받아올 변수
 * 			output:	infix 수식을 postfix로 변환후 저장할 변수
 * 			stackSize: 스택의 길이를 정하기 위한 변수
 * 			ch:	string 데이타에서 한글자씩 읽어올 변수
 * 			opTop:	스택에서 operator를 읽어올 변수
 * 			prec:	operator의 우선 순위
 * 			chx:	스택에서 '('를 읽어올 변수
 * 			x, y:	스택에서 operand를 저장할 변수
 * 			result: postfix를 계산하고 결과를 저장할 변수
 * 			maxSize: 스택의 사이즈 변수
 * 			stackArray:	스택의 배열 변수
 * 			top:	스택의 index 변수
*/
import java.io.IOException;
import java.util.Scanner;

public class Postfix {
   Stack theStack;
   String input;
   String output = "";
   public Postfix(String in) {
      input = in;
      int stackSize = input.length();
      theStack = new Stack(stackSize);
   }
   //doTrans:	infix 수식을 읽어오면서 operator일 경우 스택에 저장
   //			operand일 경우 output에 이어 붙인다.
   public String doTrans() {
      for (int j = 0; j < input.length(); j++) {
         char ch = input.charAt(j);
         switch (ch) {
            case '+': 
            case '-':
               getOper(ch, 1); 
               break; 
            case '*': 
            case '/':
               getOper(ch, 2); 
               break; 
            case '(': 
               theStack.push(ch);
               break;
            case ')': 
               getParen(ch); 
               break;
            default: 
               output = output + ch; 
               break;
         }
      }
      while (!theStack.isEmpty()) {
         output = output + theStack.pop();
      }
      return output; 
   }
   //getOper:	스택의 데이타와 현재 읽어온 operator의 우선 순위를 비교한다.
   //			스택에서 불러온 opTop이 현재 읽어온 opThis보다 우선 순위가 높은 경우 opThis를 output에 이어 붙이며
   //			opTop이 순위가 낮은 경우는 opTop를 스택에 push하고 반복을 멈춘다.
   //			opTop이 '('일 경우는 opTop을 push하고 반복을 멈춘다.
   public void getOper(char opThis, int prec1) {
      while (!theStack.isEmpty()) {
         char opTop = theStack.pop();
         if (opTop == '(') {
            theStack.push(opTop);
            break;
         } else {
            int prec2;
            if (opTop == '+' || opTop == '-')
            prec2 = 1;
            else
            prec2 = 2;
            if (prec2 < prec1) { 
               theStack.push(opTop);
               break;
            } 
            else output = output + opTop;
         }
      }
      theStack.push(opThis);
   }
   //getParen:	')'를 받은 경우 '('가 나올때 까지 pop하며 나온 데이타들을 output에 붙여 넣는다
   public void getParen(char ch) { 
      while (!theStack.isEmpty()) {
         char chx = theStack.pop();
         if (chx == '(') 
         break; 
         else output = output + chx; 
      }
   }
   //calculate:	postfix로 변환된 수식을 가져와 result를 계산한다.
   public int calculate(String s){
	   int result = 0;
	   for (int j = 0; j < s.length(); j++){
		   char ch = s.charAt(j);
		   if(ch>='0' && ch <='9'){
			   theStack.push(ch);
		   }
		   else{
			   int x = theStack.pop() - '0';
			   int y = theStack.pop() - '0';
			   
			   switch(ch){
		           case '+':
		        	   result = x+y;
		              break;
		           case '-':
		        	   result = y-x;
		              break;
		           case '*':
		        	   result = x*y;
		              break;
		           case '/':
		        	   result = y/x;
		              break;
		           default:
		        	   result = 0;
			   }
			   theStack.push((char)(result+'0'));
		   }
		   
	   }
	   return result;
   }
   class Stack {
      private int maxSize;
      private char[] stackArray;
      private int top;
      
      public Stack(int max) {
         maxSize = max;
         stackArray = new char[maxSize];
         top = -1;
      }
      public void push(char j) {
         stackArray[++top] = j;
      }
      public char pop() {
         return stackArray[top--];
      }
      public boolean isEmpty() {
         return (top == -1);
      }
   }
}
