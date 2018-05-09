/*
 * 기능:	인접 비용 행렬을 통하여 최소 비용 거리 계산.
 * 알고리즘:	처음에는 인접 비용 행렬의 비용들을 기본으로 하여
 * 			우회할 시 드는 비용과 비교하여 더 비용이 적은 방법을 선택.
 * 			
 * 변수설명
 * 			p: 최단 거리를 계산하기 위한 인스턴스 변수.
 */
public class test {

	public static void main(String[] args) {
		ShortestPath p = new ShortestPath(7);
		p.insertCost(0, 1, 2); p.insertCost(0, 2, 4);
		p.insertCost(0, 3, 5);
		
		p.insertCost(1, 3, 2); p.insertCost(1, 4, 7);
		
		p.insertCost(2, 3, 1); p.insertCost(2, 5, 4);
		
		p.insertCost(3, 1, 2); p.insertCost(3, 2, 1);
		p.insertCost(3, 4, 4); p.insertCost(3, 5, 3);
		
		p.insertCost(4, 1, 7); p.insertCost(4, 3, 4);
		p.insertCost(4, 5, 1); p.insertCost(4, 6, 5);
		
		p.insertCost(5, 2, 4); p.insertCost(5, 3, 3);
		p.insertCost(5, 4, 1); p.insertCost(5, 6, 7);
		
		p.insertCost(6, 4, 7); p.insertCost(6, 5, 5);
		
		p.printCost();
		System.out.println();
		
		for(int i=0; i<7; i++){
			System.out.println("vertex " + "\'" + i + "\'" + " shrotest path");
			p.path(i);
			System.out.println();
		}
	}

}
