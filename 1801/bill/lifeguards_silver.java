/*
Bill Zheng
~ 1 hour 20 min
***ttttttt
I wasn't able to figure out how to make it faster so I looked at the solution for inspiration
Afterwards ~ 2 hours
**********
I learned that for OldCode.Silver, time and complexity is much more important than in OldCode.Bronze
Almost all of my ideas to attack this problem from OldCode.Bronze didn't translate over which made it very hard to solve.
 */

import java.io.*;
import java.util.*;

class Guards implements Comparable <Guards>{
	public int time, num;
	public Guards(int t, int n) {
		this.time = t;
		this.num = n;
	}
	public int compareTo(Guards g) {
		return time - g.time;
	}
}

public class lifeguards {
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner (new File ("lifeguards.in"));
		
		int N = scan.nextInt();
		Guards[] A = new Guards[N*2];
		//ArrayList<Integer> list = new ArrayList<Integer>();
		TreeSet<Integer> list = new TreeSet<Integer>();
		
		for (int i = 0; i < N; i++) {
			//st = new StringTokenizer(f.readLine());
			A[i*2] = new Guards(scan.nextInt(),i);
			A[i*2+1] = new Guards(scan.nextInt(),i);
			//A[i*2] = new Guards(Integer.parseInt(st.nextToken()),i);
			//A[i*2+1] = new Guards(Integer.parseInt(st.nextToken()),i);
		}
		/*
		for (int i = 0; i < N*2; i++) {
			for (int j = 0; j < N*2-1; j++) {
				if (A[j].time > A[j+1].time) {
					Guards store = A[j];
					A[j] = A[j+1];
					A[j+1] = store;
				}
			}
		}
		 */
		Arrays.sort(A);
		int totaltime = 0;
		int lasttime = 0;
		int[] solo = new int[N];
		
		for (Guards g: A) {
			if (list.size() == 1) {
				//solo[list.get(0)] += (g.time - lasttime);
				solo[list.first()] += (g.time - lasttime);
			}
			if (!list.isEmpty()) {
				totaltime += (g.time - lasttime);
			}
			if (!list.contains(g.num)) {
				list.add(g.num);
			} else {
				//list.remove(Integer.valueOf(g.num));
				list.remove(g.num);
			}
			lasttime = g.time;
		}
		int ret = 0;
		for (int a: solo) {
			ret = Math.max(ret, totaltime-a);
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lifeguards.out")));
		System.out.println("Ret: " + ret);
		out.println(ret);

		out.close();
		scan.close();
	}
}
