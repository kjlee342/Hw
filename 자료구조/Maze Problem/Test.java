/* Test:	제시된 행렬의 길을 찾기 위한 main 구현.
 * 변수설명
 * 		maze:	제시된 미로를 나타내는 행렬.
 * 		m:	미로의 길을 찾기 위한 Maze 인스턴스 변수.
 */
public class Test {

	public static void main(String[] args) {
		int maze[][] = { {0,1,1,1,1,1}, {1,0,1,1,1,1}, {1,0,0,0,0,1}, {1,1,0,1,1,1}, {1,0,1,0,0,1}, {1,1,1,1,1,0} };
		Maze m = new Maze();
		m.mazeRun(maze);
		
		Node temp = m.path.pop();
		System.out.println("The path is");
		System.out.println("row" + "\t" + "col");
		while(temp != null){
			System.out.println(temp.row + "\t" + temp.col);
			temp = temp.next;
		}
		
		System.out.println("Marked matrix");
		for(int i=0; i<6; i++){
			for(int j=0; j<6; j++){
				System.out.print(m.mark[i][j] + " ");
			}
			System.out.println();
		}
	}

}
