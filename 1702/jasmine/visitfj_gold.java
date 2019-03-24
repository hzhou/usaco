//Jasmine Zhang
//All cases passed in 2 hours
//I was being stupid with debugging
//I spent a lot of time figuring why I wasn't visited enough fields or why I was visiting too many fields
//All cases passed
import java.util.*;
import java.io.*;
public class visitfj {
	static int [] fields;
	//static int [] sP;
	static int n,t;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("visitfj.in"));
		n = scan.nextInt();
		t = scan.nextInt();
		
		fields = new int [n*n];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				fields[i*n+j] = scan.nextInt();
		}
		
		int answer = BFS();
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("visitfj.out")));
		System.out.println(answer);
		out.println(answer);
	
		out.close();
		scan.close();
	}
	public static int BFS () {
		//key to this problem was figuring out that approaching a field on a different numbers of times mod 3
		//is a different state 
		int [][] sPath = new int [n*n][3];
		
		
		for (int i = 0; i < n*n; i++)
			Arrays.fill(sPath[i], -1);
		int min = -1;
		PriorityQueue <State> pq = new PriorityQueue <State> (new Comparator <State> () {
			public int compare (State s1, State s2) {
				return s1.cost-s2.cost;
			}
		});
		int [] add = {1,-1,n,-n};
		int [] bound = {n-1,0,n-1,0};
		pq.add(new State (0, 0, 0));
		while (!pq.isEmpty()) {
			State s = pq.poll();
			if (s.times % 3 == 0 && s.times != 0) {
				s.cost += fields[s.index];
				//System.out.println("hit");
			}
			
			if (sPath[s.index][s.times%3] != -1 && sPath[s.index][s.times%3] <= s.cost) {
				//System.out.println("hit");
				continue;
			}
			
			
			if (s.index == n*n-1) {
				//System.out.println(s.cost + "hasf");
				if (min == -1 || s.cost < min)
					min = s.cost;
			}
			
			int newCost = s.cost + t;
			//System.out.println(s.times);
			//System.out.println(s.times%3);
			
			
			for (int i = 0; i < 4; i++) {
				if (i < 2 && (s.index%n) == bound[i] || i >= 2 && (s.index/n) == bound[i]) {
					continue;
				}
				int newIndex = s.index+add[i];
				
				pq.add(new State(newIndex, (s.times+1), newCost));
			}
			sPath[s.index][s.times%3] = s.cost;
		
			//System.out.println(pq);
		}
		return min;
	}

}
class State {
	int index; 
	int times;
	int cost;
	public State (int i, int t, int c) {
		index = i;
		times = t;
		cost = c;
	}
	public String toString() {
		return index + " " + times + " " + cost;
	}
	
	//Hashing didn't work
	@Override
	public boolean equals (Object o) {
		State s = (State) o;
		return (index == s.index && times == s.times && cost == s.cost );
	}
	
	@Override
	public int hashCode () {
		return index*times*cost;
	}
}
