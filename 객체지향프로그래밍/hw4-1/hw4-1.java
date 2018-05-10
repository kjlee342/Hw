
public class HW4_1 {
	public static void main (String[] args) {
		
		int intArray[][] = new int[5][5];


		for(int cnt=0; cnt < 10;){
			int i= (int) Math.round(Math.random()*4),
					j = (int) Math.round(Math.random()*4); // 랜덤한 배열을 하나 선택
			
			if(intArray[i][j] == 0){	
				intArray[i][j] = (int) Math.round(Math.random()*9 + 1);
				cnt++;	//선택한 배열의 데이터값이 0이라면 1~10의 정수를 넣고 카운트 값을 증가시킴
			}
		}
		
		for (int i=0; i<intArray.length; i++) {
			for (int j=0; j<intArray[i].length; j++)
				System.out.print(intArray[i][j] + "\t");
			System.out.println();
		}
	}
}
