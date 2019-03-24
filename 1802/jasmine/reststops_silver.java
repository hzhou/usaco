//Jasmine Zhang
//All cases passed in 50 minutes
//Needed the second test case to figure out that answers were really big
//needed to use long instead of int
//Overcame time issue by adding a continue statement to the while loop

import java.util.*;
import java.io.*;
public class reststops {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner (new File ("reststops.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("reststops.out")));
		
		int L = scan.nextInt();
		int n = scan.nextInt();
		int rF = scan.nextInt();
		int rB = scan.nextInt();
		
		
		ArrayList <rStop> stops = new ArrayList <rStop> ();
		TreeMap <Integer, Integer> mapStops = new TreeMap <Integer,Integer> ();
		for (int i = 0; i < n; i++)
		{
			stops.add(new rStop (scan.nextInt(), scan.nextInt()));
		}
		Collections.sort(stops);
		
		
		long total = 0;
		long d = 0;
		int i = 0;
		while (i < stops.size()&& d <= L && stops.size() > 0)
		{
			
			rStop stop = stops.get(i);
			if (stop.distance > d)
			{
				long distance = stop.distance - d;
				long x = ((distance*rF) - (distance*rB))*stop.tasty;
				total += x;
				if (x < 0)
				{
					System.out.println(x);
					//System.out.println(distanc);
					//System.out.println(d);
				}
				d = stop.distance;
			}
                        i++;
			// stops.remove(0);
			
		}
		out.println(total);
		scan.close();
		out.close();
	}

}

class rStop implements Comparable<rStop>{
	int distance;
	int tasty;
	rStop (int d, int t)
	{
		distance = d;
		tasty = t;
	}
	@Override
	public int compareTo(rStop r) {
		if (tasty == r.tasty)
		{
			return r.distance-distance;
		}
		return r.tasty-tasty;
	}
}
