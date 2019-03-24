

import java.util.*;
import java.io.*;

import javafx.util.*;
import javafx.util.Pair;
public class mootube {
	static ArrayList <Pair <Integer,Integer>> queries;
	static int [] parent;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("mootube.in"));
		int n = scan.nextInt();
		int q = scan.nextInt();
		
		Edge [] edges = new Edge [n-1];
		for (int i = 0; i < n-1; i++) {
			edges[i] = new Edge (scan.nextInt()-1, scan.nextInt()-1, scan.nextInt());
		}
		Arrays.sort(edges);
		
		Integer [] pQue = new Integer[q];
		queries = new ArrayList <Pair <Integer,Integer>> ();
		for (int i = 0; i < q; i++) {
			queries.add(new Pair (scan.nextInt(), scan.nextInt()));
			pQue[i] = i;
		}
		Arrays.sort(pQue, new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				//decreasing order
				return queries.get(i2).getKey() - queries.get(i1).getKey();
			}
		});
		/*
		Collections.sort(queries, new Comparator <Pair <Integer, Integer>> () {
			public int compare (Pair <Integer, Integer> p1, Pair <Integer, Integer> p2) {
				return p1.getKey() - p2.getKey();
			}
		});
		*/
                /*
		System.out.println(Arrays.toString(edges));
		System.out.println(Arrays.toString(pQue));
		System.out.println(queries);
		*/
		parent = new int [n];
		int [] size = new int [n];
		
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
		
		int in = 0;
		int [] answer = new int [q];
		for (int i = 0; i < q; i++) {
			Pair <Integer, Integer> p = queries.get(pQue[i]);
			int k = p.getKey();
			int node = p.getValue()-1;
			
			//System.out.println(findParent(node));
			while (in < n-1 && edges[in].w >= k) {
				Edge e = edges[in];
				//System.out.println(e);
				int p1 = findParent(e.a);
				int p2 = findParent(e.b);
				// int union = Math.min(p1, p2);
				// parent[p1] = union;
				parent[p2] = p1;
				size[p1] = size[p1] + size[p2];
				in++;
			}
			int pNode = findParent(node);
			//System.out.println(pNode);
			answer[pQue[i]] = size[pNode]-1;
			//System.out.println(Arrays.toString(size));
			//System.out.println(Arrays.toString(answer));
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("mootube.out")));
		for (int i = 0; i < q; i++) {
			out.println(answer[i]);
		}
		/*
		for (int i = 0; i < 1; i++) {
			
			int k = p.getKey();
			int node = p.getValue();
		}

		*/
		ArrayList <ArrayList<Integer>> adj = new ArrayList <ArrayList <Integer>> ();
		
		
		
	
		out.close();
		scan.close();
	}
	public static int findParent (int n) {
		int p = parent[n];
		while (p != n) {
			n = p;
			p = parent[p];
		}
		return p;
	}

}
class Edge implements Comparable{
	int a;
	int b;
	int w;
	Edge (int a, int b, int w) {
		this.a = a;
		this.b = b;
		this.w = w;
	}
	@Override
	public int compareTo(Object o) {
		Edge e = (Edge) o;
		//sort in decreasing order
		return e.w - w;
	}
	public String toString () {
		return a + " " + b + " " + w;
	}
}

