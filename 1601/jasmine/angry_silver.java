//Looked at the solution
//First attempt was to split the cows among the biggest gaps in distances
//Realized it didn't work 

//Max radius that explodes every bale
//binary search among those bales to figure out when it explodes 
import java.util.*;
import java.io.*;
public class angry {
	static int [] bales;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("angry.in"));
		int n = scan.nextInt();
		int k = scan.nextInt();
		
		
		bales = new int [n];
		
		for (int i = 0; i < n; i++) {
			bales[i] = scan.nextInt();
		}
		Arrays.sort(bales);
		
		int maxR = (bales[n-1] - bales[0])/2+1;
		int min = 1;
						//+, not - 
		int currentR = (maxR+min)/2;
		int cUsed = explode (currentR);
		System.out.println(maxR);
		System.out.println(currentR);
		System.out.println(cUsed);
		
		int i = 0;
		while (cUsed != k && i < 10){
			if (cUsed > k) {
				min = currentR+1;
			}
			else {
				maxR = currentR-1;
			}
			currentR = (maxR+min)/2;
			cUsed = explode(currentR);
			//System.out.println(currentR + " " + cUsed);
			//System.out.println(min + " " + maxR);
			i++;
		}
		
		
				//needed a <
		while (explode(currentR) <= k) {
			currentR--;
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("angry.out")));
		System.out.println(currentR+1);
		out.println(currentR+1);
		
		out.close();
		scan.close();
	}
	public static int explode (int r) {

		int cowsUsed = 1;
		
		int left = bales[0];
		for (int i = 0; i < bales.length; i++) {
			if (bales[i] - left > r*2){
				left = bales[i];
				cowsUsed++;
			}
		}
		return cowsUsed;
	}
	

}
