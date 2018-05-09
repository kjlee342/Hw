/* ShortestPath:	최소 비용(거리) 계산.
 * 변수설명
 * 		V: 정점(vertex)의 갯수.
 * 		cost: 인접 비용 행렬.
 * 		distance: 비용(거리) 저장.
 * 		found: 최소 비용이 계산된 것을 확인.
 */

public class ShortestPath {
	static int V; 
	static int cost[][]; 
	static int distance[]; 
	static boolean found[];
	
	public ShortestPath(int v) {
		V = v;
		cost = new int[V][V];
		distance = new int[V];
		found = new boolean[V];
		initCostMatrix(cost);
	}
	
	//initCostMatrix:	비용 행렬 초기화.
	public void initCostMatrix(int cost[][]){
		for(int i=0; i<V; i++){
			for (int j=0; j<V; j++){
				cost[i][j] = 100;
			}
		}
	}
	//insertCost:	비용 행렬에 비용을 수정.
	void insertCost(int source, int dest, int weight){
		cost[source][dest] = weight;
	}
	
	//printCost: 비용 행렬을 출력.
	void printCost(){
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				System.out.print(cost[i][j] + "\t");
			}
			System.out.println();
		}
	}
	
	//choose:	가장 낮은 비용인 정점을 찾는다.
	//변수설명
	//		min:	최소 비용.
	//		index:	최소 비용을 가지는 정점.
	public static int choose(int[] distance, boolean[] found){
		int min = 100;
		int index = 0;
		for(int i=0; i<V; i++){
			if(distance[i] < min && !found[i]){
				min = distance[i];
				index = i;
			}
		}
		 return index;
	}
	//path:	인접 비용 행렬에서 최소 비용을 계산한다.
	//변수설명
	//		u:	최소 비용을 가지는 정점의 인덱스.
	void path(int v){
		int u;
		for(int i=0; i<V; i++){
			found[i] = false;
			distance[i] = cost[v][i];
		}
		
		found[v] = true;
		distance[v] = 0;
		
		for(int i=0; i<V-1; i++){
			u = choose(distance, found);
			found[u] = true;
			
			for(int w=0; w<V; w++){
				if(!found[w]){
					if(distance[u] + cost[u][w] < distance[w]){
						distance[w] = distance[u] + cost[u][w];
					}
				}
			}
			for(int j=0; j<V; j++){
				System.out.print(distance[j] + " ");
			}
			System.out.println();
		}
	}
}
