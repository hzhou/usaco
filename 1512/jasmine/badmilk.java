//Jasmine Zhang
//All cases passed in 30 minutes
import java.util.*;
import java.io.*;
public class badmilk {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("badmilk.in"));
		
		int n = scan.nextInt();
		int m = scan.nextInt();
		int d = scan.nextInt();
		int s = scan.nextInt();
		
		//number of people who drank the certain type of milk
		int [] numDrank = new int [m];
		
		//records earliest time each person drank each type of milk
		int [] [] [] data = new int [n][m][1];
		
		for (int i = 0; i < d; i++) {
			int p = scan.nextInt() - 1;
			int milk = scan.nextInt() - 1;
			int t = scan.nextInt();
			
			if (data[p][milk][0] == 0) {
				numDrank[milk] += 1;
				data[p][milk][0] = t;
			}
			else {
				data[p][milk][0] = Math.min(data[p][milk][0], t);
			}
			
			
		}
		
		
		System.out.println(Arrays.toString(numDrank));
		
		boolean [] notBad = new boolean [m];
		
		for (int i = 0; i < s; i++) {
			int p = scan.nextInt()-1;
			int t = scan.nextInt();
			System.out.println(p + " " + t);
			
			for (int j = 0; j < m; j++) {
				System.out.println(p + " " + j + " " + data[p][j][0]);
											//Strictly earlier
				if (data[p][j][0] == 0 ||  data[p][j][0] >= t) {
					
					notBad[j] = true;
				}
			}
			
		}
		
		System.out.println(Arrays.toString(notBad));
		int largest = 0;
		for (int i = 0; i < m; i++) {
			if (!notBad[i])
				largest = Math.max(numDrank[i],largest);
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("badmilk.out")));
		System.out.println(largest);
		out.println(largest);
	
		out.close();
		scan.close();
	}
	

}
