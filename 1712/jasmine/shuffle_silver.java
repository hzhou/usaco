import java.util.*;
import java.io.*;
public class shuffle {
	//static Graph g;
	static boolean [] cont;
	static int count = 0;
	static int [] shuffle;
	static boolean [] searched;
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner (new File ("shuffle.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("shuffle.out")));
		int n = scan.nextInt();
		shuffle = new int [n];
		cont = new boolean [n];
		searched = new boolean [n];
		for (int i = 0; i < n; i++)
		{
			shuffle[i] = scan.nextInt()-1;
			if (shuffle[i] == i)
			{
				cont[i] = true;
				searched[i] = true;
				count++;
				//System.out.println(i);
			
				
				
			}
			//System.out.println(i + " " + shuffle[i]);
		}
		//int count = 0;
		
		
		/*
		for (int i = 0; i < n; i++)
		{
			int move = shuffle[i];
			if (move -1 == i)
			{
				cont[i] = true;
				count++;
			}
			else
			{
				g.addEdge(i, move);
			}
		}
		*/
		//System.out.println(Arrays.toString(shuffle));
		for (int i = 0; i < n; i++)
		{
			
			shuf(i,new LinkedHashSet<Integer> ());
		}
		
		out.println(count);
		scan.close();
		out.close();
	}
	public static void shuf (int pos, LinkedHashSet <Integer> path)
	{
            while(true){
		if (path.contains(pos))
		{
			Iterator <Integer> it = path.iterator();
			boolean partOf = false;
			//System.out.println(pos);
			//System.out.println(path);
			int x = it.next();
			int c = 0;
			while (x!= pos)
			{
				x = it.next();
				c++;
			}
			//System.out.println(path.size() + " "  + c);
			count += path.size()-c;
			return;
		}
		else if (searched[pos])
			return;
		
		else
		{
			//System.out.println(pos);
			path.add(pos);
			searched[pos] = true;
			// shuf(shuffle[pos], path);
                        pos = shuffle[pos];
		}
            }
	}
	

}
/*
class Graph
{
	int V;
	int E;
	ArrayList <Integer> vertices;
	ArrayList <TreeSet <Integer>> adj;
	public Graph (int V)
	{
		vertices = new ArrayList <Integer> ();
		adj = new ArrayList <TreeSet <Integer>> ();
		this.V = V;
		for (int i = 0; i < V; i++)
		{
			vertices.add(i);
			adj.add(new TreeSet <Integer> ());
		}
	}
	void addEdge (int point, int v)
	{
		adj.get(point).add(v);
	}
}
*/
