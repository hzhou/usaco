//Can't figure out why I'm not passing 3 cases
import java.util.*;
import java.io.*;
public class div7 {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("div7.in"));
		int n = scan.nextInt();
		
		long [] sums = new long [n+1];
		sums[0] = 0;
		int total = 0;
		for (int i = 0; i < n; i++) {
			total += scan.nextInt();
			sums[i+1] = total;
		}
		System.out.println(Arrays.toString(sums));
		
		int maxCow = 0;
		for (int i = n; i >= 1; i--) {
			int size = i;
			for (int j = 0; j < n-size+1; j++) {
				//System.out.println(size + "as");
				long begin = sums[j];
				long end = sums[j+size];
				System.out.println(begin + " " + end);
				if ((end - begin) % 7 == 0) {
					maxCow = size;
					break;
					
				}
				//System.out.println(end-begin);
			}
			if (maxCow != 0)
				break;
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("div7.out")));
		System.out.println(maxCow);
		out.println(maxCow);
	
		out.close();
		scan.close();
	}

}
