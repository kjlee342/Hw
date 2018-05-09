/* BST:	binary search tree를 구현.
 * 변수설명
 * 	root: 트리의 가장 상위 노드를 가리킬 변수.
 */
public class BST {
	Node root;
	
	BST(){
		root = null;
	}
	//search:	트리에서 원하는 키 값의 노드를 찾는 함수.
	//변수설명
	//	ptr:	현재 입력받은 노드를 나타내며 루트 노드를 시작으로 한다.
	//	key:	찾고자 하는 숫자 변수.
	public Node search(Node ptr, int key){
		if(ptr == null){
			return null;
		}
		else{
			if(key == ptr.data){
				return ptr;
			}
			if(key < ptr.data){
				ptr = search(ptr.left, key);
			}
			else if(key > ptr.data){
				ptr = search(ptr.right, key);
			}
		}
		
		return ptr;
	}
	
	//insert:	트리에 숫자를 입력하는 함수.
	//변수설명
	//	ptr:	현재 입력받은 노드를 나타내며 루트 노드를 시작으로 한다.
	//	key:	입력하고자 하는 숫자 변수.	
	//	temp:	키 값의 노드를 임시적으로 저장할 변수.
	public Node insert(Node ptr, int key){
		if(root == null){
			Node temp = new Node(key);
			root = temp;
			return temp;
		}
		
		if(ptr == null){
			Node temp = new Node(key);
			return temp;
		}
		else if(key < ptr.data){
			ptr.left = insert(ptr.left, key);
		}
		else if(key > ptr.data){
			ptr.right = insert(ptr.right, key);
		}
		return ptr;
	}
	
	//delete:	트리에서 원하는 숫자를 지우는 함수.
	//변수설명
	//	ptr:	현재 입력받은 노드를 나타내며 루트 노드를 시작으로 한다.
	//	key:	삭제하고자 하는 숫자 변수.	
	//	temp:	노드를 임시적으로 저장할 변수.	
	public Node delete(Node ptr, int key){
		if(ptr == null){
			System.out.println("not found");
			return null;
		}
		
		if(key < ptr.data){
			ptr.left = delete(ptr.left, key);
		}
		else if(key > ptr.data){
			ptr.right = delete(ptr.right, key);
		}
		else if(ptr.left == null && ptr.right == null){
			ptr = null;
		}
		else if(ptr.left == null){
			ptr = ptr.right;
		}
		else if(ptr.right == null){
			ptr = ptr.left;
		}
		else{
			Node temp;
			temp = findMin(ptr.right);
			ptr.data = temp.data;
			ptr.right = delete(ptr.right, ptr.data);
		}
		
		return ptr;
	}
	
	//findMin:	가장 작은 숫자를 가진 노드를 찾는 함수. 
	//		delete 시 지워진 노드를 대체할 노드를 찾기위해 사용한다.
	//변수설명
	//	ptr:	현재 입력받은 노드를 나타내며 지워진 노드의 오른쪽 노드를 시작으로 한다.	
	public Node findMin(Node ptr){
		if(ptr.left == null){
			return ptr;
		}
		else{
			return findMin(ptr.left);
		}
	}
	
	//drawTree:	트리를 루트 노드부터 그리게하는 함수.
	public void drawTree(){
		drawBST(root, 1);
	}
	
	//drawBST:	BST를 그리는 함수.
	//변수설명
	//	ptr:	현재 입력받은 노드를 나타내며 루트 노드를 시작으로 한다.
	//	level:	현재 입력받은 레벨을 나타내며 루트 노드의 레벨인 1로 시작한다.
	public void drawBST(Node ptr, int level){
		if(ptr != null && level <= 7){
			drawBST(ptr.right, level+1);
			for(int i=0; i<=(level-1); i++){
				System.out.print("\t");
			}
			System.out.print(ptr.data);
			if(ptr.left != null && ptr.right != null){
				System.out.println("<");
			}
			else if(ptr.right != null){
				System.out.println("/");
			}
			else if(ptr.left != null){
				System.out.println("\\");
			}
			else{
				System.out.println();
			}
			drawBST(ptr.left, level+1);
		}
	}
	
}
