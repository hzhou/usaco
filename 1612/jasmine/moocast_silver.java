// Jasmine Zhang
// 1 hour, used 2 extra test cases

import java.util.*;
import java.io.*;
public class moocast {
	static GraphMoo g;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("moocast.in"));
		int n = scan.nextInt();
		
		
		int [] power = new int [n];
		int [][] coord = new int [n][2];
		for (int i = 0; i < n;i++) {
			coord[i][0] = scan.nextInt();
			coord[i][1] = scan.nextInt();
			power[i] = scan.nextInt();
		}
		
		g = new GraphMoo (n);
		
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				double distance = distance(coord[i][0], coord[i][1], coord[j][0], coord[j][1]);
				if (distance <= power[i])
					g.addEdge(i, j);
				if (distance <= power[j])
					g.addEdge(j, i);
			}
		}
		
		
		
		int largest = 0;
		for (int i = 0; i < n; i++) {
			HashSet<Integer> used = new HashSet <Integer> ();
			Iterator <Integer> it = g.adj.get(i).iterator();
			while (it.hasNext()) {
				
				int in = it.next();
				if (used.contains(in))
					continue;
				
				g.adj.get(i).addAll(g.adj.get(in));
				//g.adj.get(in).clear();
				used.add(in);
				it = g.adj.get(i).iterator();
				//g.adj.get(in)
				
			}
			int x = g.adj.get(i).size();
			if (!g.adj.get(i).contains(i))
				x++;
			if (x > largest)
				largest = x;
		}
		
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("moocast.out")));
		
		out.println(largest);
		
		
		
		
		out.close();
		scan.close();
	}
	public static double distance (int x1, int y1, int x2, int y2) {
		double x = x1-x2;
		double y = y1-y2;
		return  Math.sqrt(Math.pow(x, 2)+Math.pow(y, 2));
	}
	
}
class GraphMoo
{
	int V, E;
	ArrayList <TreeSet <Integer>> adj;
	ArrayList <Integer> vertices;
	
	GraphMoo(int V)
	{
		this.V = V;
		vertices = new ArrayList <Integer> ();
		adj = new ArrayList<TreeSet <Integer>> ();
		for (int i = 0; i < V; i++)
		{
			vertices.add(i);
			adj.add( new TreeSet <Integer> ());
		}
		E = 0;
	}
	void addEdge(int u, int v)
	{
		adj.get(u).add(v);
		E++;
		
	}
}
