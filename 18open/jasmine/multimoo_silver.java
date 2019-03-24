//Jasmine Zhang
//All cases passed in 2 hours 
import java.util.*;
import java.io.*;
public class multimoo {
	static int [] board;
	static int n;
	static RegionGraph rGraph = new RegionGraph();
	static int [] regionID;
	static ArrayList <CowRegion> regions;
	
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("multimoo.in"));
		n = scan.nextInt();
		
		regionID = new int [n*n];
		board = new int [n*n];
		for (int i = 0; i < n*n; i++) {
				board[i] = scan.nextInt();
		}
		
		//find the largest region with one cow ID
		int V = 0;
		int largest = 1;
		boolean [] used = new boolean [n*n];
		regions = new ArrayList <CowRegion> ();
		for (int i = 0; i < n*n; i++) {
			if (used[i])
				continue;
			else {
				rGraph.addVertice();
				int size = DFS1 (used, i, board[i], V);
				if (size > largest)
					largest = size;
				regions.add(new CowRegion(size, board[i]));
				V++;
			}
		}
		System.out.println(largest);
		
		//generate neighbor list
		int [] adj = {n,-n,1,-1};
		for (int i = 0; i < n*n; i++) {
			int id = regionID[i];
			for (int j = 0; j < 4; j++) {
				if (j == 2 && i%n == n-1)
					continue;
				if (j==3 && i%n == 0)
					continue;
				int adjI = i + adj[j];
											//the neighbors had to go both ways 
				if (adjI >= 0 && adjI < n*n&& id != regionID[adjI])
					rGraph.addEdge(id, regionID[adjI]);
			}
		}
		
		//finds that largest region of 2 cows
		int largest2 = 2;
		for (int i = 0; i < V; i++) {
			int id1 = i;
			int val1 = regions.get(i).val;
			Iterator <Integer> it1 = rGraph.neighbors.get(i).iterator();
			
			while (it1.hasNext()) {
				int id2 = it1.next();
				int val2 = regions.get(id2).val;
				rGraph.neighbors.get(id1).remove(id2);
				//I need to add this to get under time
				rGraph.neighbors.get(id2).remove(id1);
				boolean [] marked = new boolean[V];
				int size = DFS2(id1, id2, val1, val2, marked);
				if (size > largest2) 
					largest2 = size;
				it1 = rGraph.neighbors.get(i).iterator();
			}
		}
		System.out.println(largest2);
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("multimoo.out")));
		out.println(largest);
		out.println(largest2);
	
		out.close();
		scan.close();
	}
	public static int DFS2 (int id1, int id2, int val1, int val2, boolean [] marked) {
		Stack <Integer> possID = new Stack <Integer> ();
		possID.push(id1);
		possID.push(id2);
		marked[id1] = true;
		marked[id2] = true;
		
		int total = 0;
		while (!possID.isEmpty()) {
			int id = possID.pop();
			adjacent2(id, possID, val1, val2, marked);
			total += regions.get(id).total;
		}
		return total;
	}
	//generates and add neighbors with the same values
	public static void adjacent2 (int id, Stack <Integer> possID, int val1, int val2, boolean [] marked) {
		Iterator <Integer> it = rGraph.neighbors.get(id).iterator();
		while (it.hasNext()) {
			int neighID = it.next();
			if (marked[neighID])
				continue;
			else if (regions.get(neighID).val == val1 || regions.get(neighID).val == val2) {
				possID.push(neighID);
				rGraph.neighbors.get(id).remove(neighID);
			}
			marked[neighID] = true;
			it = rGraph.neighbors.get(id).iterator();
		}
	}
	
	
	public static int DFS1 (boolean [] used, int i, int val, int V) {
		Stack <Integer> stack = new Stack<Integer> ();
		stack.push(i);
		used[i] = true;
		regionID[i] = V;
		
		int total = 1;
		while (!stack.isEmpty()) {
			int currentI = stack.pop();
			ArrayList <Integer> adj = adjacent1(currentI);
			for (int in : adj) {
				if (used[in])
					continue;
				else if (board[in] == val) {
					used[in] = true;
					total++;
					stack.push(in);
					regionID[in] = V;
				}
			}
		}
		return total;
	}
	//generates neighbors
	public static ArrayList <Integer> adjacent1 (int i) {
		ArrayList <Integer> adj = new ArrayList <Integer> ();
		
		int row = i/n;
		int col = i%n;
		
		if (row != 0)
			adj.add(i-n);
		if (row != n-1)
			adj.add(i+n);
		if (col != 0)
			adj.add(i-1);
		if (col != n-1)
			adj.add(i+1);
		
		return adj;
	}
}

class RegionGraph {
	int V = 0;
	//int E;
	ArrayList <HashSet <Integer>> neighbors = new ArrayList <HashSet <Integer>> ();
	RegionGraph () {
		
	}
	void addVertice() {
		V++;
		neighbors.add(new HashSet <Integer>());
	}
	void addEdge(int v, int n) {
		neighbors.get(v).add(n);
	}
	
	
}
class CowRegion {
	int total;
	int val;
	CowRegion (int t, int v) {
		total = t;
		val = v;
	}
	public String toString () {
		return total + " " + val;
	}
}


