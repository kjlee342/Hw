import java.util.Scanner;

public class LeapYear {

	public static void main(String[] args) {
		int year;
		
		Scanner sin = new Scanner(System.in);
		System.out.print("연도를 입력해주세요.>>");
		year = sin.nextInt();
		
//	윤년 :서력 기원 연수가 4로 나누어 떨어지는 해는 우선 윤년으로 하고,
//	그 중에서 100으로 나누어 떨어지는 해는 평년으로 하며,
//	다만 400으로 나누어 떨어지는 해는 다시 윤년이다
		
		if (year % 4 == 0){
			if (year % 400 == 0)
				System.out.println("윤년입니다.");
			//400으로 나누어 떨어지는 해는 윤년
			
			else if (year % 100 == 0)
				System.out.println("평년입니다.");
			//그 중에서 100으로 나누어 떨어지는 해는 평년
			
			else 
				System.out.println("윤년입니다.");
			//연수가 4로 나누어 떨어지는 해는 우선 윤년
		
		}
		else
			System.out.println("평년입니다.");
		//연수가 4로 나누어 떨어지지 않으면 평년
	}
}
