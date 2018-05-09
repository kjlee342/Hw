/* Node:	트리에 저장될 자료형을 구현.
 * 변수설명
 * 	data:	숫자를 저장할 변수.
 * 	left:	왼쪽 노드를 저장할 변수.
 * 	right:	오른쪽 노드를 저장할 변수.
 */
public class Node {
	public int data;
	public Node left;
	public Node right;
	
	public Node(int data){
		this.data = data;
		this.left = null;
		this.right = null;
	}
}
