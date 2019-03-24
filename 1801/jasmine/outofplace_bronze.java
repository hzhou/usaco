//Jasmine Zhang
//All cases passed in 30 minutes
import java.util.*;
import java.io.*;
public class outofplace {
	static int [] original;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("outofplace.in"));
		int n = scan.nextInt();
		
		original = new int [n];
		Integer [] p = new Integer [n];
		for (int i = 0; i < n; i++) {
			original[i] = scan.nextInt();
			p[i] = i;
		}
		
		Arrays.sort(p, new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				return original[i1] - original[i2];
			}
		});
		System.out.println(Arrays.toString(original));
		System.out.println(Arrays.toString(p));
		
		int out = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				if (p[i] > p [i+1])  {
					out = 0;
					break;
				}
			}
			else if (i == n-1) {
				out = n-1;
				break;
			}
			else if ((p[i] > p[i+1] && p[i] > p[i-1] && p[i-1] < p[i+1])
					|| (p[i] < p[i+1] && p[i] < p[i-1] && p[i-1] < p[i+1])) {
				out = i;
				break;
			}
		}
		
		int switches = Math.abs(p[out] - out);
		for (int i = Math.min(p[out], out); i < Math.max(p[out], out); i++){
			if (original[i] == original[i+1])
				switches--;
		}
		
		
		PrintWriter pout = new PrintWriter(new BufferedWriter(new FileWriter("outofplace.out")));
		pout.println(switches);
	
		pout.close();
		scan.close();

	}

}
