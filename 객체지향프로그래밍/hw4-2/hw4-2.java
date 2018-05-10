
public class HW4_2 {

	public static void main(String[] args){
		String s;
		
		for(int i=1; i<100; i++){
			int clap = 0;
			s = String.valueOf(i);
			for(int j=0; j<s.length(); j++){
				if (s.charAt(j) == '3' || s.charAt(j) == '6' || s.charAt(j) == '9')
					clap++;	//스트링에 3,6,9의 글자가 있다면 clap의 값을 증가시킴
				
				if(clap == 1)
					System.out.println(i + " 박수 한번");
				//박수를 한번 이상 쳐야하면 값을 프린트
				else if(clap == 2)
					System.out.println(i + " 박수 두번");
			}		
		}
	}
}
