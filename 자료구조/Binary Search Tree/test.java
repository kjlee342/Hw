/*
 * 기능:	Binary Search Tree 운용.
 * 알고리즘:	처음 받는 숫자를 루트 노드로 하여 트리를 구성한다.
 * 		이후의 숫자들은 루트 노드보다 클 경우 오른쪽 서브트리에, 작을 경우 왼쪽 서브트리에 구성된다.
 * 		루트 노드 이외의 각각 노드들 또한 자신의 숫자보다 큰 경우 오른쪽 서브트리에 구성하며, 작을 경우 왼쪽 서브트리에 구성한다.
 * 		또한 원하는 숫자를 지울 수 있으며 지워진 노드의 오른쪽 서브트리에서 가장 작은 값이 자리를 대체한다.
 * 변수설명
 * 		sc: 숫자를 입력받을 변수.
 * 		bst: BST를 운용하기 위한 인스턴스 변수.
 */
import java.util.Scanner;

public class test {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		BST bst = new BST();
		
		while(true){
			System.out.println("1.insert 2.delete 3.search 4.print 5.quit");
			switch(sc.nextInt()){
			case 1:
				System.out.println("enter number to insert: ");
				bst.insert(bst.root, sc.nextInt());
				break;
			case 2:
				System.out.println("enter number to delete: ");
				bst.delete(bst.root, sc.nextInt());
				break;
			case 3:
				System.out.println("enter number to search: ");
				int key = sc.nextInt();
				Node temp;
				temp = bst.search(bst.root, key);
				if(temp == null){
					System.out.println("not found");
				}
				else if(temp.data == key){
					System.out.println(key +" is found");
				}
				break;
			case 4:
				bst.drawTree();
				break;
			case 5:
				return;
			default:
				break;
			}
		}
		
	}

}
