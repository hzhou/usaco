
/*
ID: ml2963
Tests: *xxxxxxxxxx
First implementation of backtracking, definitely need to work more on it.
 */

import java.io.*;
import java.util.*;

public class perimeter {
	public static void main (String [] args) throws IOException {
		//BufferedReader f = new BufferedReader(new FileReader("D:\\eclipse-workspace\\USACO\\Silver\\testSilver.txt"));
	    BufferedReader f = new BufferedReader(new FileReader("perimeter.in"));
	    
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("perimeter.out")));
	    
	    StringTokenizer st = new StringTokenizer(f.readLine());
		
	    int n = Integer.parseInt(st.nextToken());  
	    
	    char[] grid = new char[n*n];
	    int k = 0;
	    String s;
	    char[] t;
	    for (int i = 0; i < n; i++) {
	    	st = new StringTokenizer(f.readLine());
	    	s = st.nextToken();
	    	t = s.toCharArray();
	    	for (int j = 0; j < n; j++) {
	    		grid[k] = t[j];
	    		k++;
	    	}
	    }
	    for (int i = 0; i < n*n; i++) {
	    	System.out.print(grid[i]);
	    }
	    System.out.println();
	    // reading input above
	    
	    //char[] visited = new char[n*n];
	    ArrayList<ArrayList<Integer>> a = new ArrayList<ArrayList<Integer>>();
	    //for (int i = 0; i < n*n; i++) {
	    //	visited[i] = grid[i];
	    //}
	    
	    for (int i = 0; i < n*n; i++) {
	    	if (grid[i] != '.') {
	    		floodFill(grid,n,i,a);
	    	}
	    }
	    
	    for (int i = 0; i < a.size(); i++) {
	    	System.out.println(a.get(i));
	    }
	    int max = 0;
	    int min = 0;
	    for (int i = 0; i < a.size(); i++) {
	    	
	    	if (a.get(i).get(0) > max) {
	    		max = a.get(i).get(0);
	    		min = a.get(i).get(1);
	    	}
	    }
	    System.out.println("Area: " + max);
	    System.out.println("Perim: " + (min+1));
	    
	    
	    out.println(max + " " + (min+1));
		out.close();
	}

	// flood fill
	public static void floodFill(char[] v, int n, int k, ArrayList<ArrayList<Integer>> a) {
		ArrayList<Integer> stack = new ArrayList<Integer>();
		stack.add(0, k);
		int total = 0;
		int perim = 4;
		int count = 0;
		while (stack.size() > 0) {
			count = 0;
			k = stack.get(0);
			stack.remove(0);
			int[] p = new int[4];
			int num = 0;
			int i = k / n;
			int j = k % n;
			if (i > 0) {
				p[num] = k - n;
				num++;
			}
			if (i < n - 1) {
				p[num] = k + n;
				num++;
			}
			if (j > 0) {
				p[num] = k - 1;
				num++;
			}
			if (j < n - 1) {
				p[num] = k + 1;
				num++;
			}
			
			for (int l = 0; l < num; l++) {
				if (v[p[l]] == '#') {
					v[p[l]] = '.';
					stack.add(0, p[l]);
					total ++;
					count ++;
				}
			}
			if (count == 4) {
				perim += 7;
			} else if (count == 3) {
				perim += 5;
			} else if (count == 2) {
				perim += 3;
			} else if (count == 1) {
				perim += 1;
			} else if (count == 0) {
				perim += 0;
			}
		}
		ArrayList<Integer> r = new ArrayList<Integer>();
		r.add(total);
		r.add(perim);
		a.add(r);
	}

}
