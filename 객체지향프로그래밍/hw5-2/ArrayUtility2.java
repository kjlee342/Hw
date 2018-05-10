public class ArrayUtility2 {
	static int[] concat(int[] s1, int[] s2) {
		int merged[] = new int[s1.length + s2.length] ; // 인자로 넘어온 두 정수형 배열  크기의 합과 같은 정수형 배열 생성
		for (int i=0; i<s1.length; i++)
			merged[i] = s1[i] ;  // merged 배열 전반부에 s1 배열 복사
		for (int i=0; i<s2.length; i++)
			merged[i + s1.length] = s2[i];  // merged 배열 후반부에 s2 배열 복사
		return merged;
	}
	
	static int[] remove(int[] s1, int[] s2) {
		boolean mark[] = new boolean[s1.length]; // s1에서 s2 배열에 있는 숫자의 위치를 표시하기 위한 배열
		int count = 0; // s1에 있는 s2 배열의 숫자의 개수
		int removed[] = null;
		for (int i=0; i<s1.length; i++) mark[i] = false; // 배열 초기화
		for (int i=0; i<s1.length; i++) {
			for (int j=0; j<s2.length; j++) { 
                         // s1 배열의 원소와 s2 배열의 원소가 같은 값일 때의 s1배열의 index 위치를 표시함
				if (s1[i] == s2[j]) { 
					mark[i] = true; 
					count++;
					break;
				}
			}
		}
		if (s1.length - count > 0) {
			removed = new int[s1.length - count]; // s1에서 s2 배열에 있는 숫자를 삭제한 크기만큼의 배열 생성
			int index = 0;
			for (int i=0; i<s1.length; i++) // 마크된 원소는 건너뛰며 나머지는 removed배열에 복사
                        {
				if (mark[i] == true) continue;				
				else {
					removed[index] = s1[i];
					index++;
				}
					
				
			}
		}
		return removed;
	}
	
	public static void main (String args[])  {
		int i1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int i2[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
		
		int tmp_int[] = concat(i1, i2);
		for (int j=0; j<tmp_int.length; j++) System.out.println(tmp_int[j]);
		tmp_int = remove(i1, i2);
		for (int j=0; j<tmp_int.length; j++) System.out.println(tmp_int[j]);
	}
}
