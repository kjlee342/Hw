/* Stack:	자료구조 스택을 구현.
 * 변수설명
 * 		head: 스택의 가장 상위 노드를 가리킬 변수.
 */
public class Stack {
	Node head;
	
	public Stack(){
		head = null;
	}
	
	//push:	스택에 행,열,방향을 저장하는 함수.
	public void push(int row, int col, int dir){
		Node temp = new Node(row, col, dir);
		
		if(head == null){
			head = temp;
		}
		else{
			temp.next = head;
			head = temp;
		}
	}
	//pop:	스택에서 데이타를 가져오는 함수.
	//변수설명
	//		temp:	임시적으로 스택의 가장 상위 노드를 저장할 변수.
	public Node pop(){
		Node temp;
		
		temp = head;
		head = head.next;
		
		return temp;
	}
	
	//isEmpty:	스택이 비었는지 확인하는 함수.
	public boolean isEmpty(){
		if(head == null){
			return true;
		}
		return false;
	}
	
	//invert:	스택의 순서를 역순으로 바꾸는 함수.
	//변수설명:
	//		middle: head의 전 순서 노드를 저장할 변수.
	//		trail:	middle의 전 순서 노드를 저장할 변수.
	public void invert(){
		Node middle = null;
		Node trail = null;
		while(head != null){
			trail = middle;
			middle = head;
			head = head.next;
			middle.next = trail;
		}
		head = middle;
	}
}
