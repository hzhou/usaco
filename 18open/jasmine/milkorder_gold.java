// Jasmine Zhang
// 2 hours
// Tried sorting the observations before realizing that order of observation takes priority
// Gave up and Looked at solution after one hour
// all cases passed, used one test case
import java.util.*;
import java.io.*;
import javafx.util.Pair;
public class milkorder {
	static Observation [] obs;
	static int n;
	static int answ [];
	static ArrayList <ArrayList<Integer>> hier = new ArrayList <ArrayList<Integer>> ();
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("milkorder.in"));
		n = scan.nextInt();
		int m = scan.nextInt();
		
		for (int i = 0; i < n; i++) 
			hier.add(new ArrayList <Integer> ());
		
		
		obs = new Observation[m];
		for (int i = 0; i < m; i++) {
			int num = scan.nextInt();
			int [] order = new int [num];
			for (int j = 0; j < num; j++) 
				order[j] = scan.nextInt()-1;
			obs[i] = new Observation(num,order);
		}
		
		int b = 0;
		int e = m-1;
		int mid = (b+e)/2;
		while (b <= e) {
			//System.out.println(mid);
			if (canOrder(mid,false)) 
				b = mid+1;
			else
				e = mid-1;
			mid = (b+e)/2;
		}
		//System.out.println(canOrder(3,false));
		//System.out.println(e);
		canOrder(e,true);
		
		//System.out.println(Arrays.toString(answ));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milkorder.out")));
		int count = 0;
		for (int i : answ) {
			out.print(i+1);
			count++;
			if (count < n)
				out.print(" ");
		}
		out.println();
		
		
	
		out.close();
		scan.close();
	}
	public static boolean canOrder (int x, boolean a) {
		int [] pred = new int [n];
		int [] answer = new int [n];
		//missed a bug here
		for (int i = 0; i < n; i++) 
			hier.get(i).clear();
		//PriorityQueue <Integer>
		//System.out.println(x);
		for (int i = 0; i <= x; i++) {
			for (int j = 0; j < obs[i].n-1; j++) {
				int first = obs[i].p[j];
				int second = obs[i].s[j];
				//System.out.println(first + " " + second);
				hier.get(first).add(second);
				pred[second]++;
			}
		}
		
		PriorityQueue <Integer> pq = new PriorityQueue <Integer> ();
		for (int i = 0; i < n; i++) {
			if (pred[i] == 0)
				pq.add(i);
		}
		//System.out.println(hier);
		for (int i = 0; i < n; i++) {
			//if the graph is cyclic, then the cyclic numbers never gets added on 
			//because they need the other number to be added on first
			//System.out.println(pq);
			if (pq.isEmpty())
				return false;
			int v = pq.poll();
			answer[i] = v;
			
			for (int succ : hier.get(v)) {
				pred[succ]--;
				if (pred[succ] == 0) {
					pq.add(succ);
				}
			}
			
		}
		if (a)
			answ = answer;
		return true;
	}

}

class Observation {
	int n;
	int [] p;
	int [] s;
	public Observation (int n, int [] o) {
		this.n = n;
		p = new int [n-1];
		s = new int [n-1];
		int last = o[0];
		for (int i = 1; i < n; i++) {
			p[i-1] = last;
			s[i-1] = o[i];
			last = o[i];
		}
		//System.out.println(Arrays.toString(p));
		//System.out.println(Arrays.toString(s));
	}
	
}
