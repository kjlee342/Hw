/* Node:	스택에 저장될 자료형을 구현.
 * 변수설명
 * 		row:	행을 나타내는 변수.
 * 		col:	열을 나타내는 변수.
 * 		dir:	방향을 나타내는 변수.
 * 		next:	다음 순서의 노드를 저장할 변수.
 */
public class Node {
	public int row;
	public int col;
	public int dir;
	public Node next;
		
	public Node(int row, int col, int dir){
		this.row = row;
		this.col = col;
		this.dir = dir;
		this.next = null;
	}
}
