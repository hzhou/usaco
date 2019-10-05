//Jasmine Zhang
//Submission back in February, brute force
import java.util.*;
import java.io.*;
import javafx.util.Pair;
public class cowland {
	static int [] fun;
	static int [] sum;
	static int [] sum0;
	static int [] sum1;
	static int n;
	static int [] parent;
	//static int allAttract;
	static ArrayList <ArrayList <Integer>> adj;
	static HashMap <Pair <Integer, Integer>, Integer> hMap = new HashMap <Pair <Integer, Integer>, Integer> ();
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("cowland.in"));
		n = scan.nextInt();
		int q = scan.nextInt(); 
		fun = new int [n];
		sum = new int [n];
		parent = new int [n];
		
			
		//allAttract = 0;
		adj = new ArrayList <ArrayList <Integer> > ();
		for (int i = 0; i < n; i++)  {
			adj.add(new ArrayList <Integer> ());
			fun[i] = scan.nextInt();
			//allAttract += fun[i];
		}
		
		for (int i = 0; i < n-1; i++) {
			int a = scan.nextInt()-1;
			int b = scan.nextInt()-1;
			adj.get(a).add(b);
			adj.get(b).add(a);
		}
		
		sum();
		
		System.out.println(Arrays.toString(parent));
		System.out.println(Arrays.toString(fun));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowland.out"))); 
		for (int i = 0; i < q; i++) {
			int type = scan.nextInt();
			if (type == 2) {
				int a = scan.nextInt()-1;
				int b = scan.nextInt()-1;
				System.out.println(a + " " + b +"-----");
				int p = commonParent(a,b);
				if (p == a) {
					p = parent[a];
				
				}
				if (p == b) {
					p = parent[b];
				
				}

				System.out.println(Integer.toBinaryString(sum[a]));
				System.out.println(Integer.toBinaryString(sum[b]));
				System.out.println(Integer.toBinaryString(sum[p]));
				System.out.println(Integer.toBinaryString(sum[a]^sum[b]^sum[p]));
				//System.out.println(Integer.toBinaryString(sum[b]));
				out.println(DFS(a,b));
				//int path = sum[a]-sum[b];
				//System.out.println(sum[a] + " " + sum[b]);
				//System.out.println(allAttract);
				//System.out.println(allAttract);
			}
			else {
				int node = scan.nextInt()-1;
				int newV = scan.nextInt();
				//int diff = newV - fun[node];
				changeSum(node, fun[node], newV);
			
				//System.out.println("asdfklajsd");
				for (int a = 0; a < n; a++) {
					//System.out.println(Integer.toBinaryString(sum[a]));
				}
				//System.out.println("asdfklajsd");
				fun[node] = newV;
			}
		}
		
		//PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowland.out"))); 
		//System.out.println(adj);
		//System.out.println(Arrays.toString(fun));
		//System.out.println(Arrays.toString(sum));
	
		out.close();
		scan.close();
		
	}
	public static int commonParent (int a, int b) {
		boolean [] p = new boolean [n];
		p[a] = true;
		p[b] = true;
		while (true) {
			
			if ( p[parent[a]] == true)
				return parent[a];
			
			p[parent[a]] = true;
			a = parent[a];
			
			//System.out.println(parent[b]);
			//System.out.println(a + " " + b);
			
			if (p[parent[b]] == true) {
				//System.out.println(parent[b]+"s");
				return parent[b];
			}
			p[parent[b]] = true;
			b = parent[b];
			
			//System.out.println(a + " " + b);
		}
	}
	public static int DFS (int a, int b) {
		boolean [] visitedRoot = new boolean [n];
		Stack <Pair <Integer, Integer>> s = new Stack <Pair <Integer, Integer>> (); 
		s.add(new Pair(a,fun[a]));
		//parent[0] = 0;
		while (!s.isEmpty()) {
			Pair <Integer,Integer> current = s.pop();
			int i = current.getKey();
			int tot = current.getValue();
			if (i == b)
				return tot;
			
			visitedRoot[i] = true;
			for (int num : adj.get(i)) {
				//probaby don't need to check visisted
				
				if (visitedRoot[num])
					continue;
				s.add(new Pair(num,fun[num]^tot));
				//parent[num] = i;
			}
		}
		return -1;
	}
	public static void sum () {
		boolean [] visitedRoot = new boolean [n];
		Stack <Pair <Integer, Integer>> s = new Stack <Pair <Integer, Integer>> (); 
		s.add(new Pair(0,fun[0]));
		parent[0] = 0;
		while (!s.isEmpty()) {
			Pair <Integer,Integer> current = s.pop();
			int i = current.getKey();
			int tot = current.getValue();
			
			//System.out.println(tot + " " + Integer.toBinaryString(tot));
			//System.out.println(Integer.toBinaryString(sum[i]));
			sum[i] = tot;
			visitedRoot[i] = true;
		
			for (int num : adj.get(i)) {
				//probaby don't need to check visisted
				
				if (visitedRoot[num])
					continue;
				s.add(new Pair(num,fun[num]^tot));
				parent[num] = i;
			}
		}
		
	}
	public static void changeSum (int node, int prevFun, int nFun) {
		
		Stack <Integer> s = new Stack <Integer> (); 
		s.add(node);
		HashSet <Integer> visited = new HashSet <Integer> ();
		while (!s.isEmpty()) {
			int current = s.pop();
			sum[current] ^= prevFun;
			sum[current] ^= nFun;
			//System.out.println(current);
			//System.out.println(Integer.toBinaryString(sum[current]));
			visited.add(current);
			for (int num : adj.get(current)) {
				if (visited.contains(num))
					continue;
				s.add(num);
			}
		}
	}
	
	

}
