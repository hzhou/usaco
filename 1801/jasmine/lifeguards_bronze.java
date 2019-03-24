//Jasmine Zhang
//All cases passed in 10 minutes
import java.util.*;
import java.io.*;
public class lifeguards {

	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("lifeguards.in"));
		int n = scan.nextInt();
		
		int [][] shifts = new int [n][2];
		int [] time = new int [1000];
		int total = 0;
		
		for (int i = 0; i < n; i++) {
			int start = scan.nextInt();
			int end = scan.nextInt();
			shifts[i][0] = start;
			shifts[i][1] = end;
			for (int j = start; j < end; j++) {
				if (time[j] == 0)
					total++;
				time[j]++;
			}
		}
		System.out.println(Arrays.toString(time));
		
		int max = 0;
		for (int i = 0; i < n; i++) {
			int start = shifts[i][0];
			int end = shifts[i][1];
			int timeLost = 0;
			for (int j = start; j < end; j++) {
				if (time[j] == 1)
					timeLost++;
			}
			int without =  total-timeLost;
			if (without > max)
				max = without;
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lifeguards.out")));
		out.println(max);
	
		out.close();
		scan.close();
	}

}
