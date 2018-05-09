//기능:	입력받은 숫자(홀수)만큼의 행과 열을 가지는 Magic Square를 짜는 프로그램.
//알고리즘:	입력받은 숫자만큼의 행렬 배열을 만든 후 0으로 초기화
//		그 후 가장 맨 위 행의 가운데 배열을 1로 두고 좌상단 배열로 하나씩
//		이동하며 숫자를 1씩 높이고 입력해 나간다. 
//		현재 위치가 제일 윗 행이였을 경우 맨 아래 행으로 이동하며 제일            //		좌측 열이였다면 제일 우측 열로 이동한다.
//		현재 숫자를 입력한 배열의 좌상단 배열에 이미 값이 배정되어 있다면 현재         //		배열에서 한 행 내려간 후 숫자를 입력.
//		그 후 다시 좌상단 배열로 이동하며 계속 이어 나간다.
//변수설명
//	n:	유저에게 입력받는 숫자를 저장.
//	square:	입력받은 숫자의 제곱만큼 배열을 저장. 
//		2차원 배열로 행과 열을 표현한다.
//	row:	현재 배열의 행을 나타내는 변수.
//	col:	현재 배열의 열을 나타내는 변수.
//	nextRow:	다음 배열의 행을 나타내는 변수.
//	nextCol:	다음 배열의 열을 나타내는 변수.

import java.util.Scanner;

public class Magicsquare {

	public static void main(String[] args) { 
		Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while(n%2 == 0){	
        	System.out.println("홀수를 입력해 주세요.");
        	n = sc.nextInt();
        }

        int[][] square = new int[n][n];

        for (int i=0; i<n; i++) { 
            for (int j=0; j<n; j++) {
                square[i][j] = 0;
            }
        }
        
        int row = 0;
        int col = (n-1) / 2;
        square[row][col] = 1;
        int nextRow;
        int nextCol;

        for (int i=2; i<=n*n; i++) {
            if (row-1 < 0)
            	nextRow = n - 1;
            else
            	nextRow = row - 1;
            
            if(col-1 < 0)
            	nextCol = n - 1;
            else
            	nextCol = col - 1;
            
            if(square[nextRow][nextCol] > 0)
            	row = (row+1) % n;
            else{
            	row = nextRow;
            	col = nextCol;
            }
            
            square[row][col] = i;
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                System.out.print(square[i][j] + "\t");
            }
            System.out.println();
        }

    }
}
