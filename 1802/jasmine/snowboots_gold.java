//Jasmine Zhang
// 1 hour 
// This week I was extremely busy - I was preparing for the robotics qualifiers 
// I never got to testing this problem 
import java.util.*;
import java.io.*;


import javafx.util.Pair;
public class snowboots {
	static ArrayList <Pair <Integer, Integer>> boots;
	static int [] depths;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("snowboots.in"));
		int n = scan.nextInt();
		int b = scan.nextInt();
		
		depths = new int [n];
		Integer [] pDep = new Integer [n];
		for (int i = 0; i < n; i++) {
			depths[i] = scan.nextInt();
			pDep[i] = i;
		}
		Arrays.sort(pDep, new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				return depths[i1] - depths[i2];
			}
		});
		
		boots = new ArrayList <Pair<Integer, Integer>> ();
		Integer [] pB = new Integer [b];
		for (int i = 0; i < b; i++) {
			boots.add(new Pair (scan.nextInt(), scan.nextInt()));
			pB[i] = i;
		}
		Arrays.sort(pB, new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				Pair <Integer, Integer> p1  = boots.get(i1);
				Pair <Integer, Integer> p2  = boots.get(i2);
				int depth1 = p1.getKey();
				int depth2 = p2.getKey();
				//reverse distance?
				if (depth1 == depth2)
					return p1.getValue() - p2.getValue();
				return depth1 - depth2;
			}
		});
		
		TreeMap <Integer, Integer> distBetween = new TreeMap <Integer,Integer> (Collections.reverseOrder());
		distBetween.put(n-1,1);
		ArrayList <Integer> canStep = new ArrayList <Integer> ();
		canStep.add(0);
		canStep.add(n-1);
		int [] solutions = new int [n-1];
		int iDep = 1;
		for (int i = 0; i < b; i++) {
			Pair <Integer, Integer> boot = boots.get(pB[i]);
			//System.out.println(boot);
			int depth = boot.getKey();
			int dist = boot.getValue();
			while (iDep < n && depths[pDep[iDep]] <= depth) {
				int key = pDep[iDep];
				if (key == n-1) {
					iDep++;
					continue;
				}
				
				int s = 0;
				int e = iDep-1;
				
				while (s <= e) {
					//System.out.println(s + " " + e);
					int m = (s + e)/2;
					if (key > canStep.get(m))
						s = m+1;
					else
						e = m-1;
				}
				//System.out.println(s + " " + e + " " + key);
				int prev = canStep.get(e);
				int aft = canStep.get(s);
				int pDist = aft - prev;
				System.out.println(pDist);
				int pTot = distBetween.get(pDist);
				if (pTot == 1)
					distBetween.remove(pDist);
				else 
					distBetween.put(pDist, pTot-1);
				
				int d1 = key-prev;
				Integer t1 = distBetween.get(d1);
				if (t1 == null)
					distBetween.put(d1, 1);
				else
					distBetween.put(d1, t1+1);
				
				int d2 = aft-key;
				Integer t2 = distBetween.get(d2);
				if (t2 == null)
					distBetween.put(d2, 1);
				else
					distBetween.put(d2, t2+1);
				
				canStep.add(s, key);
				
				
				
				iDep++;
				System.out.println(canStep);
				System.out.println(distBetween);
			}
			int maxDist = distBetween.keySet().iterator().next(); 
			if (maxDist <= dist)
				solutions[pB[i]] = 1;
		}
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("snowboots.out")));
		for (int i : solutions) {
			System.out.println(i);
		}
		
		
	
		out.close();
		scan.close();
	}

}
