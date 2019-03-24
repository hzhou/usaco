//Jasmine Zhang
// 1 case passed
// 1 hour 30 minutes
// spent most of my time trying to figure out why binary search wasn't returning the values I want
// always off by one, and not in consistent ways, so I had to add another boolean to the method
import java.util.*;
import java.io.*;

import javafx.util.*;
import javafx.util.Pair;
public class piepie {
	static ArrayList <ArrayList <Integer>> adj = new ArrayList <ArrayList<Integer>> ();
	static int [] bessie;
	static int [] elsie;
	static int n;
	static boolean [] end;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("piepie.in"));
		n = scan.nextInt();
		int d = scan.nextInt();
		
		bessie = new int [2*n];
		Integer [] pBes = new Integer [2*n];
		
		elsie = new int [2*n];
		Integer [] pEls = new Integer [2*n];
		
		end = new boolean[2*n];
		for (int i = 0; i < 2*n; i++) {
			bessie[i] = scan.nextInt();
			elsie[i] = scan.nextInt();
			pBes[i] = i;
			pEls[i] = i;
			adj.add(new ArrayList <Integer> ());
			
			if (bessie[i] == 0)
				end[i] = true;
			else if (elsie[i] == 0)
				end[i] = true;
		}
		
		//System.out.println(Arrays.toString(end));
		Arrays.sort(pBes,  new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				if (i1 >= n && i2 >= n)
					return i1 - i2;
				if (i1 >= n)
					return 1;
				if (i2 >= n)
					return -1;
				return bessie[i1]-bessie[i2];
			}
		});
		//System.out.println(Arrays.toString(bessie));
		
		Arrays.sort(pEls,  new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				if (i1 < n && i2 < n)
					return i1 - i2;
				if (i1 < n)
					return -1;
				if (i2 < n)
					return 1;
				return elsie[i1]-elsie[i2];
			}
		});
		//System.out.println(Arrays.toString(elsie));
		
		//bessie pie to elsie pie that can be given pack
		for (int i = 0; i < n; i++) {
			int eTasty = elsie[i];
			int low = binarySearch(n,2*n-1,eTasty,elsie,pEls,true);
			int high = binarySearch(n,2*n-1,eTasty+d,elsie,pEls,false);
			//System.out.println(low + " " + high);
			if (low == n-1)
				low = n;
			
			for (int j = low; j <= high; j++) 
				adj.get(i).add(j);
		}
		//System.out.println(adj);
		
		//elsie pie to bessie pie that can be given pack
		for (int i = n; i < 2*n; i++) {
			int bTasty = bessie[i];
			//System.out.println(bTasty);
			int low = binarySearch(0,n-1,bTasty,bessie,pBes,true);
			int high = binarySearch(0,n-1,bTasty+d,bessie,pBes,false);
			
			//System.out.println(low + " " + high);
			
			for (int j = low; j <= high; j++) 
				adj.get(i).add(j);
		}
		//System.out.println(adj);
		
		//System.out.println(BFS(0));
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("piepie.out")));
		for (int i = 0; i < n; i++) {
			System.out.println(BFS(i));
			out.println(BFS(i));
		}
	
		out.close();
		scan.close();
	}
	public static int BFS (int in) {
		
		Queue <Pair<Integer, Integer>> q = new LinkedList <Pair<Integer, Integer>> ();
		HashSet <Integer> visited = new HashSet <Integer> ();
		visited.add(in);
		Pair <Integer,Integer> pair = new Pair (in, 1);
		q.add(pair);
		while (!q.isEmpty()) {
			Pair <Integer, Integer>p = q.poll();
			Integer num = (Integer) p.getKey();
			Integer t = (Integer) p.getValue();
			if (end[(int) num])
				return t;
			for (int a : adj.get(num)) {
				if (visited.contains(a))
					continue;
				else
					q.add(new Pair (a,t+1));
			}
		}
		
		return -1;
	}
	

	public static int binarySearch(int b, int e, int key, int [] cow, Integer [] p, boolean low) {
		int m = (b+e)/2;
		int initialE = e;
		while (b <= e) {
			if (key < cow[p[m]])
				e = m-1;
			else if (key > cow[p[m]]) 
				b = m+1;
			else 
				return m; //shouldn't be here
			m = (b + e) / 2;
		}
		//System.out.println(b + " " + initialE);
		//if (b > initialE)
			//b = initialE;
		if (low)
			return b;
		return e;
	}

}
