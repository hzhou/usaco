
//Jasmine Zhang
//1 hour
//7 cases passed with easy solution 
import java.util.*;
import java.io.*;
public class bphoto {

	static int [] heights;
	static Integer [] p;
	static LinkedList <Integer> sorted = new LinkedList <Integer> ();
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("bphoto.in"));
		int n = scan.nextInt();
		int [] taller = new int[n];
		
		heights = new int [n];
		p = new Integer[n];
		Integer [] order = new Integer[n];
	
		for (int i = 0; i < n; i++) {
			heights[i] = scan.nextInt();
			p[i] = i;
			order[i] = i;
		}
		//Arrays.sort(heights);
		//System.out.println(Arrays.toString(heights));
		
		
		Arrays.sort(p, new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				return heights[i1] - heights[i2];
			}
		});
		//System.out.println(Arrays.toString(p));
		
		//height[i] should be at index order[i] in the sorted version
		Arrays.sort(order, new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				return p[i1] - p[i2];
			}
		});
		//System.out.println(Arrays.toString(order));
		
		int totalUn = 0;
		for (int i = 0; i < n; i++) {
			//caching wasn't really faster
			//int left = taller[i];
			//int right = n-order[i] - left -1;
			int left = 0;

			//:( makes the algorithm O(n2)
			//it's a fenwick tree again isn't it?
			for (int j = 0; j < i; j++) {
				if (heights[j] > heights[i])
					left++;
			}
			
			int right = n-order[i] - left-1;
			
			
			//System.out.println(heights[i]);
			//System.out.println(Arrays.toString(taller));
			//System.out.println(left + " " + right);
			if ((right > left && left*2 < right) || (left > right && right*2 < left)) {
				//System.out.println("--"+heights[i]);
				totalUn++;
			}
			
			//try caching, but honestly the same as O(n2)
			/*
			for (int j = 0; j < order[i]; j++) {
				taller[j]++;
			}
			*/
			
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bphoto.out")));
		System.out.println(totalUn);
		out.println(totalUn);
	
		out.close();
		scan.close();
	}

}
