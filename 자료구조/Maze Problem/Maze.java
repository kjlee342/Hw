/* 기능:	주어진 행렬에서 스택을 이용하여 시작점에서 도착점까지의 길을 찾는 프로그램.
 * 알고리즘:	(0,0)은 시작점이며 (5,5)는 도착점이다.
 * 		시작점에서는 동쪽 방향부터 시계방향으로 갈 수 있는 길이 있는지 검색한다.
 * 		그 후 갈 수 있는 길이 있을 시 이동하여 스택에 저장. 
 * 	다시 북쪽 방향부터 시계방향으로 갈 수 있는 길이 있는지 검색하며 도착점을 찾을 때까지 반복한다.
* 	갈 수 있는 길이 없을 시 스택에서 데이타를 불러와 왔던 길로 되돌아가며 다시 검색한다.
 * 변수설명:
 * 		mark: 지나온 길을 표시할 행렬.
 * 		move: 북쪽부터 시계방향으로 북서쪽까지를 표시할 행렬.
 * 		path: 지나온 길의 행과 열을 저장해둘 스택.
 */
public class Maze {
	int mark[][] = { {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0} };
	int move[][] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
	Stack path = new Stack();
	
	/*mazeRun:	주어진 행렬에서 (0,0)에서 시작하여 (5,5)까지의 길을 찾을 함수.
	 * 변수설명
	 * 		s:	지나오는 길을 저장할 스택.
	 * 		temp:	지나온 길을 일시적으로 저장할 노드.
	 * 		fount:	(5,5)에 도달했는지를 판단할 플래그.
	 * 		row:	현재 도착해 있는 행 변수.
	 * 		col:	현재 도착해 있는 열 변수.
	 * 		dir:	move의 행을 결정할 방향 변수.
	 * 		nextRow:	다음 나아갈 행 변수.
	 * 		nextCol:	다음 나아갈 열 변수.
	 */
	
	public void mazeRun(int maze[][]){
		Stack s = new Stack();
		Node temp;
		boolean found = false;
		int row;
		int col;
		int dir;
		int nextRow;
		int nextCol;
		
		s.push(0, 0, 2);
		path.push(0, 0, 0);
		mark[0][0] = 1;
		
		while (!s.isEmpty() && !found) {
			temp = s.pop(); 
			row = temp.row; 
			col = temp.col; 
			dir = temp.dir;
			
			while (dir < 8) {
				nextRow = row + move[dir][0]; 
				nextCol = col + move[dir][1];
				
				if(nextRow == 5 && nextCol == 5) {
					found = true;
					mark[5][5] = 1;
					path.push(5, 5, 0);
					path.invert();
					break;
				}
				else if (maze[nextRow][nextCol] == 0 && mark[nextRow][nextCol] == 0) { 
					mark[nextRow][nextCol] = 1;
					s.push(row, col, ++dir);
					path.push(nextRow, nextCol, 0);
					row = nextRow; 
					col = nextCol; 
					dir = 0; 
				}
				else dir++;
			}
		}
	}
}
