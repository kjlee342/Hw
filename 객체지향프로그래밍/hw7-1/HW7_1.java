import java.util.Scanner;

abstract class Setting{
	int a,b;
	abstract void setValue(int a, int b);
	abstract int calculate();
}

class Add extends Setting{
	public void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	public int calculate() {
		return a+b;
	}
}

class Sub extends Setting{
	public void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	public int calculate() {
		return a-b;
	}
}

class Mul extends Setting{
	public void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	public int calculate() {
		return a*b;
	}
}

class Div extends Setting{
	public void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	public int calculate() {
		return a/b;
	}
}
public class HW7_1 {
	public static void main (String args[])  {
		Scanner sin = new Scanner(System.in);
		System.out.print("두 정수와 연산자를 순서대로 입력하시오(ex: 1 6 +)>>");
		int a = sin.nextInt();
		int b = sin.nextInt();
		char operator = sin.next().charAt(0); // 연산자를 문자로 변환
		switch (operator) {
		case '+':
			Add add = new Add();
			add.setValue(a, b);
			System.out.println(add.calculate());
			break;
		case '-':
			Sub sub = new Sub();
			sub.setValue(a, b);
			System.out.println(sub.calculate());
			break;
		case '*':
			Mul mul = new Mul();
			mul.setValue(a, b);
			System.out.println(mul.calculate());
			break;
		case '/':
			Div div = new Div();
			div.setValue(a, b);
			System.out.println(div.calculate());
			break;
		default:
			System.out.println("잘못된 연산자입니다.");
		}
		
	}
}
