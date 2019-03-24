//Jasmine Zhang
//13/15 first submission - missed two due to a small bug
//Got the last two cases after using additional test case
//Got a little slow towards the end
//45 minutes 
import java.util.*;
import java.io.*;
public class lightson {
	static int n;
	static boolean [] on;
	static boolean [] visited;
	static Stack <Integer> walk;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("lightson.in"));
		
		n = scan.nextInt();
		int m = scan.nextInt();
		
		on = new boolean [n*n];
		on[0] = true;
		
		HashMap <Integer, ArrayList<Integer>> switches = new HashMap <Integer, ArrayList<Integer>> ();
		for (int i = 0; i < m; i++) {
			int sw = hash(scan.nextInt()-1, scan.nextInt()-1);
			int lit = hash(scan.nextInt()-1, scan.nextInt()-1);
			
			if (!switches.containsKey(sw))
				switches.put(sw, new ArrayList <Integer> ());
			switches.get(sw).add(lit);
		}
		//Hash
		
		int totalLit = 1;
		walk = new Stack <Integer> ();
		walk.push(0);
		visited = new boolean [n*n];
		visited[0] = true;
		while (!walk.isEmpty()) {
			int loc = walk.pop();
			
			//light rooms
			if (switches.containsKey(loc)) {
				ArrayList <Integer> rooms = switches.get(loc);
				for (int i = 0; i < rooms.size(); i++) {
					//probably have to reset visited every time a new room is lit
					if (!on[(rooms.get(i))]) {
						on[rooms.get(i)] = true;
						Arrays.fill(visited, false);
						totalLit++;
					}
				}
			}
			
			nextLoc(loc);
			
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lightson.out")));
		System.out.println(totalLit);
		out.println(totalLit);
	
		out.close();
		scan.close();
	}
	public static int hash (int i, int j) {
		return i * n + j;
	}
	public static void nextLoc (int loc) {
		int [] directions = {1,-1,n,-n}; 
		ArrayList <Integer> add  = new ArrayList <Integer> ();
		//need parantheses for the loc + 1
		if ((loc + 1) % n != 0) 
			add.add(1);
		if (loc%n != 0)
			add.add(-1);
		if (loc-n >= 0)
			add.add(-n);
		if (loc+n < n*n)
			add.add(n);
		
		for (int i = 0; i < add.size(); i++) {
			int newLoc = loc + add.get(i);
			//System.out.println(newLoc + " " + loc + " " + add);
			if (on[newLoc] && !visited[newLoc]) {
				walk.push(loc+add.get(i));
				visited[newLoc] = true;
			}
		}
	}

}
