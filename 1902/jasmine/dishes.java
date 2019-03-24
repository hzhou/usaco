import java.util.*;
import java.io.*;
public class dishes {
	static int [] dirty;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("dishes.in"));
		int n = scan.nextInt();
		dirty = new int [n];
		for (int i = 0; i < n; i++) {
			dirty[i] = scan.nextInt();
		}
		/*
		for (int i = 10; i <= n; i++) {
			System.out.println(simulate(i));
		}
		*/
		int b = 1; 
		int e = n;
		
		while (b <= e) {
			int m = (b+e)/2;
			//System.out.println(simulate(m));
			//System.out.println(m);
			if (!simulate(m)) 
				e = m-1;
			else
				b = m+1;
		}
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dishes.out")));
		System.out.println(e);
		out.println(e);
	
		out.close();
		scan.close();
	}
	public static boolean simulate (int length) { 
		
		Integer [] p = new Integer [length];
		for (int i = 0; i < length; i++) {
			p[i] = i;
		}
		Arrays.sort(p, new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				return dirty[i1] - dirty[i2];
			}
		});
		ArrayList <ArrayList <Integer>> soap = new ArrayList <ArrayList <Integer>> ();
		//ArrayList <Integer> top = new ArrayList <Integer> ();
		
		int i = 1;
	
		soap.add(new ArrayList <Integer> ());
		soap.get(0).add(dirty[0]);
		int clean = 0;
		
		//System.out.println(Arrays.toString(p));
		while (i < length && clean < length) {
			//System.out.println(dirty[p[clean]]);
			while (soap.size() > 0 && soap.get(0).get(0) == dirty[p[clean]]) {
				soap.get(0).remove(0);
				if (soap.get(0).size() == 0)
					soap.remove(0);
				clean++;
			}
			int current = dirty[i];
			int b = 0;
			int e = soap.size()-1;
			
			while (b <= e) {
				int m = (b+e)/2;
				int num = soap.get(m).get(0);
				if (num < current) 
					b = m+1;
				else
					e = m-1;
			}
			//System.out.println(current);
			//System.out.println(b + " " + e);
			//System.out.println(soap);
			
			
			if (e != -1 && soap.get(e).get(soap.get(e).size()-1) > current)
				return false;
			//System.out.println(soap);
			if (soap.size() <= b) {
				soap.add(new ArrayList <Integer> ());
			}
			soap.get(b).add(0, current);
			i++;
		}
		return true;
	}

}
