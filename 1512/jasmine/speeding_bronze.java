//Jasmine Zhang
//All cases passed 40 minutes 
//Lost time overcomplicating the problem and trying to solve in in n+m times, not 100 
import java.util.*;
import java.io.*;
public class speeding {
	static int [] changes;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("speeding.in"));
		int n = scan.nextInt();
		int m = scan.nextInt();
		
		int [] roadChanges= new int [n];
		int [] bessieChanges = new int [m];
		int [] roadSpeeds = new int [n];
		int [] bessieSpeeds = new int [m];
		
		int roadL = 0;
		for (int i = 0; i < n; i++) {
			int r = scan.nextInt();
			roadChanges[i] = roadL;
			roadL += r;
			roadSpeeds[i] = scan.nextInt();
		}
		roadL = 0;
		for (int i = 0; i < m; i++) {
			int r = scan.nextInt();
			bessieChanges[i] = roadL;
			roadL += r;
			bessieSpeeds[i] = scan.nextInt();
		}
		
		int besSpeed = bessieSpeeds[0];
		int rSpeed = roadSpeeds[0];
		int besIn = 1;
		int rIn = 1;
		int largest = besSpeed - rSpeed;
		int besC = bessieChanges[1];
		int rC = roadChanges[1];
		
		//Algorithm: only points of interest is
		//when the road speed changes or when bessie's speed changes
		for (int i = 2; i < n+m; i++) {
			if (besIn == m)
				besC = 101;
			else 
				besC = bessieChanges[besIn];
			if (rIn == n)
				rC = 101;
			else
				rC = roadChanges[rIn];
			
			if (besC < rC) {
				besSpeed = bessieSpeeds[besIn];
				besIn++;
			}
			else if (rC < besC ) {
				rSpeed = roadSpeeds[rIn];
				rIn++;
			}
			else {
				besSpeed = bessieSpeeds[besIn];
				besIn++;
				rSpeed = roadSpeeds[rIn];
				rIn++;
				i++;
			}
			largest = Math.max(besSpeed - rSpeed, largest);
			
		}
	
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("speeding.out")));
		System.out.println(Math.max(0,largest));
		out.println(Math.max(0,largest));
	
		out.close();
		scan.close();
	}

}
