
import java.util.*;
import java.io.*;
import javafx.util.Pair;

public class shortcut {
	static int N, M, K;
	static int[] sp;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("shortcut.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("shortcut.out")));
		//Scanner scan = new Scanner (new File ("test.in"));
		//PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
		//read in input
		N = scan.nextInt();
		M = scan.nextInt();
		K = scan.nextInt();
		sp = new int[N];
		Arrays.fill(sp, Integer.MAX_VALUE);
		int [] cows = new int[N];
		int[] dist = new int[N]; //distance so far
		int[] dist2 = new int[N]; //distance so far
		ArrayList<Integer>[] adj = new ArrayList[M];
		ArrayList<Integer>[] adj2 = new ArrayList[M];
		Map <Pair<Integer, Integer>, Integer> edge = new HashMap();
		Map <Pair<Integer, Integer>, Integer> edge2 = new HashMap();
		Arrays.fill(dist, Integer.MAX_VALUE);
		Arrays.fill(dist2, Integer.MAX_VALUE);
		int i, j, u, v, t;
		for (i = 0; i < N; i++) {
			cows[i] = scan.nextInt();
		}
		
		for (i = 0; i < M; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		
		for (i = 0; i < M; i++) {
			u = scan.nextInt()-1;
			v = scan.nextInt()-1;
			t = scan.nextInt();
			adj[u].add(v);
			adj[v].add(u);
			edge.put(new Pair(u, v), t);
			edge.put(new Pair(v, u), t);
		}
		
		dijkstra(0, dist, sp, edge, adj);
		//System.out.println(Arrays.toString(dist));
		//System.out.println(Arrays.toString(sp));
		int total = 0;
		for (i = 0; i < N; i++)
			total += dist[i] * cows[i];
		//System.out.println(total);
		int max = 0;
		int [] sp2 = new int[N];
		for (i = 1; i < N; i++) {
			//create a new graph
			for (j = 0; j < N; j++) {
				adj2[j] = new ArrayList<Integer>();
				dist2[j] = Integer.MAX_VALUE;
				sp2[j] = 0;
			}
			edge2.clear(); 
			for (j = 1; j < N; j++) {
				//System.out.println(j+" " +sp[j]);
				adj2[j].add(sp[j]);
				//System.out.println(adj2[j]);
				adj2[sp[j]].add(j);
				//System.out.println(adj2[sp[j]]);
				edge2.put(new Pair(j, sp[j]), edge.get(new Pair(j, sp[j])) );
				edge2.put(new Pair(sp[j], j), edge.get(new Pair(j, sp[j])) );
			}
			adj2[i].add(0);
			adj2[0].add(i);
			edge2.put(new Pair(0, i), K );
			edge2.put(new Pair(i, 0), K );
			
			dijkstra(0, dist2, sp2, edge2, adj2);
			//System.out.println(Arrays.toString(dist2));
			//System.out.println(Arrays.toString(sp2));
			
			int total2 = 0;
			for (j = 0; j < N; j++)
				total2 += dist2[j] * cows[j];
			//System.out.println(i+" " +total2);
			if (max < total - total2) {
				max = total - total2;
			}
		}
		System.out.println(max);
		out.println(max);
		out.close();
		scan.close();
	}

	public static void dijkstra(int s, int[] dist, int[] sp,
			Map <Pair<Integer, Integer>, Integer> edge, 
			ArrayList<Integer>[] adj) {
		dist[s] = 0;
		sp[s] = s;
		PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(new Comparator<Pair<Integer, Integer>>() {
            @Override
            public int compare(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {
                //sort using distance values
                int key1 = p1.getKey();
                int key2 = p2.getKey();
                return key1-key2;
            }
        });
		pq.add(new Pair(0, s));
		while (!pq.isEmpty()) {
			int u = (pq.remove()).getValue();
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u].get(i);
				Integer k = edge.get(new Pair(u, v));
				if (k == null) {
					System.out.println(u+" "+v);
					return;
				}
				if (dist[u] + k  <  dist[v]) {
					dist[v] = dist[u] + k;
					pq.add(new Pair(dist[v],v));
				}
				if (dist[u] + k  ==  dist[v] && sp[v] > u)
					sp[v] = u; //break ties
			}
		}
	}
}


