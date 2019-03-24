import java.util.*;
import java.io.*;

import javafx.util.*;
import javafx.util.Pair;
public class atlarge {

	static int n,k;
	static int [] distRoot, distLeaf, parent;
	static ArrayList <ArrayList <Integer>> adj;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("atlarge.in"));
		n = scan.nextInt();
		k = scan.nextInt()-1;
		
		adj = new ArrayList <ArrayList <Integer>> ();
		for (int i = 0; i < n; i++)
			adj.add(new ArrayList <Integer> ());
		
		for (int i = 0; i < n-1; i++) {
			int a = scan.nextInt()-1;
			int b = scan.nextInt()-1;
			adj.get(a).add(b);
			adj.get(b).add(a);
		}
		
		
		distLeaf = new int [n];
		distRoot = new int [n];
		parent = new int [n];
		DFS();
		closestLeaf();
		System.out.println(Arrays.toString(distRoot));
		System.out.println(Arrays.toString(distLeaf));
		System.out.println(Arrays.toString(parent));
		
		int total = 0;
		for (int i = 0; i < n; i++) {
			int p = parent[i];
			int node = i;
			//System.out.println(p + "-" + node);
			if (p == -1)
				continue;
			//System.out.println(distLeaf[p] + " " + distRoot[p]);
			if (distLeaf[p] < distRoot[p])
				continue;
			//farmer can't reach this node in time to catch bessie
			//System.out.println(distLeaf[node] + "~" + distRoot[node]);
			if (distLeaf[node] > distRoot[node])
				continue;
			//System.out.println(total);
			total++;
			
		}
		
		//for (int i = 0; )
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("atlarge.out")));
		System.out.println(total);
		out.println(total);
	
		out.close();
		scan.close();
	}
	public static void DFS () {
		boolean [] visitedRoot = new boolean [n];

		ArrayList <tEdge> sRoot = new ArrayList <>();
		
		sRoot.add(new tEdge (k, 0, -1)); 
		while (!sRoot.isEmpty()) {
			tEdge current = sRoot.remove(0);
			//System.out.println(p);
			int node = current.n;
			int dist = current.total;
			distRoot[node] = dist;
			parent[node] = current.parent;
			for (int i : adj.get(node)) {
				
				if (visitedRoot[i])
					continue;
				
				tEdge next = new tEdge (i,dist+1,node);
				
				
				sRoot.add(next);
				
			}
			visitedRoot[node] = true;
			//System.out.println(sRoot);
		}
		
	}
	public static void closestLeaf () {
		boolean [] visited = new boolean [n];
		PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(new Comparator<Pair<Integer, Integer>>() {
            @Override
            public int compare(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {
                //sort using distance values
                int key1 = p1.getKey();
                int key2 = p2.getKey();
                return key1-key2;
            }
        });
		
		for (int i = 0; i < n; i++) {
			if (adj.get(i).size() == 1) {
				 pq.add(new Pair <Integer, Integer> (0,i));
			}
		}
		
		while (!pq.isEmpty()) {
			Pair <Integer,Integer> p = pq.poll();
			int dist = p.getKey();
			int node = p.getValue();
			distLeaf[node] = dist;
	
			for (int i : adj.get(node)) {
				 
				if (visited[i])
					continue;
				pq.add(new Pair <Integer, Integer> (dist+1, i));
			}
			visited[node] = true;
		}
	}

}
class tEdge {//implements Comparable{
	int n;
	int total;
	int parent; 
	tEdge (int n, int t, int p) {
		this.n = n;
		total = t;
		parent = p;
	}
	/*
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		tEdge t = (tEdge) o;
		return total - tEdge.total;
	}
	*/
	public String toString () {
		return n + " " + total + " " + parent;
	}
	
}
