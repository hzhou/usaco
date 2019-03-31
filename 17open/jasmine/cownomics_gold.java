import java.util.*;
import java.io.*;
public class cownomics {
	static int n,m;
	static String [] spotty, plain;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("cownomics.in"));
		n = scan.nextInt();
		m = scan.nextInt();
		scan.nextLine();
		
		spotty = new String [n];
		for (int i = 0; i < n; i++) 
			spotty[i] = scan.nextLine();
		
		plain = new String [n];
		for (int i = 0; i < n; i++) 
			plain[i] = scan.nextLine();
		
		int b = 1;
		int e = m;
		//System.out.println(canExplain(4));
		
		while (b <= e) {
			int l = (b+e)/2;
			if (canExplain(l)) 
				e = l -1;
			else
				b = l + 1;
		}
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cownomics.out")));
		System.out.println(b);
		out.println(b);
	
		out.close();
		scan.close();
	}
	public static boolean canExplain (int length) {
		for (int i = 0; i <= m-length; i++) {
			HashSet <String> s = new HashSet <String> ();
			String [] p = new String [n];
			for (int j = 0; j < n; j++) {
				p[j] = plain[j].substring(i, i+length);
				s.add(spotty[j].substring(i, i+length));
			}
			
			boolean b = true;
			for (String str : p) {
				//System.out.println(str +  "  " + s);
				if (s.contains(str)) {
					
					b = false;
				}
			}
			if (b)
				return true;
		}
		
		
		return false;
	}

}
