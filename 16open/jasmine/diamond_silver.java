//Jasmine Zhang
//All cases passed in 30 minutes
//Seems to get pretty slow towards the end
import java.util.*;
import java.io.*;
public class diamond {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("diamond.in"));
		int n = scan.nextInt();
		int k = scan.nextInt();
		
		int [] diamonds = new int [n];
		for (int i = 0; i < n; i++)
			diamonds[i] = scan.nextInt();
		Arrays.sort(diamonds);
		System.out.println(Arrays.toString(diamonds));
		int most = 1;
		int smallest = diamonds[0];
		//int total = 1;
		Queue <Integer> q = new LinkedList <Integer> ();
		q.add(smallest);
		int s = 0;
		//rolling window(?) approach
		
		//starting from a ls[i]
		int [] largestSize = new int [n];
		for (int i = 1; i < n; i++) {
			int d = diamonds[i];
			if (d-smallest <= k) {
				q.add(d);
				continue;
			}
			else {
				if (q.size() > most)
					most = q.size();
				largestSize[s] = q.size();
				//System.out.println(s + " " + q.size());
				while (q.size() > 0 && d-q.peek()>k) {
					s++;
					q.remove();
					largestSize[s] = q.size();
					
					
					
				}
				q.add(d);
				smallest = q.peek();
			}
		}
		//gotta check the last time
		if (q.size() > most) {
			most = q.size();
		}
		while (q.size() > 0) {
			largestSize[s] = q.size();
			q.remove();
			
			s++;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i+largestSize[i]; j < n; j++) {
				int total = largestSize[i] + largestSize[j];
				//System.out.println(i + " " + j);
				if (total > most)
					most = total;
			}
		}
		System.out.println(Arrays.toString(largestSize));
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("diamond.out")));
		System.out.println(most);
		out.println(most);
		
		out.close();
		scan.close();
	}

}
