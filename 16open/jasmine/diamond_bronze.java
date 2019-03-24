//Jasmine Zhang
//Completed in 14 minutes
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
		
		int most = 1;
		int smallest = diamonds[0];
		//int total = 1;
		Queue <Integer> q = new LinkedList <Integer> ();
		q.add(smallest);
		//rolling window(?) approach
		for (int i = 1; i < n; i++) {
			int d = diamonds[i];
			if (d-smallest <= k) {
				q.add(d);
				continue;
			}
			else {
				if (q.size() > most)
					most = q.size();
				while (q.size() > 0 && d-q.peek()>k)
					q.remove();
				q.add(d);
				smallest = q.peek();
			}
		}
		//gotta check the last time
		if (q.size() > most) {
			most = q.size();
		}
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("diamond.out")));
		System.out.println(most);
		out.println(most);
		
		out.close();
		scan.close();
	}

}
