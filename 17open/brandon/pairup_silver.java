import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/*
ID: fireblaze
LANG: JAVA
TASK: pairup
 */

//Name: Brandon Zhang
//10/10 passed
//Time: 90-120 minutes

public class pairup {
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\pairup.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\pairup.out.txt"));
		Scanner input = new Scanner(new File("pairup.in"));
		FileWriter fileWriter = new FileWriter(new File("pairup.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		int N = input.nextInt();
		//[0] is the amount of cows, [1] is how much they produce
		int[][] milkOutputs = new int[N][2];
		int M = 0;
		for(int i=0; i<N; i++) {
			int amount = input.nextInt();
			M += amount;
			int output = input.nextInt();
			milkOutputs[i][0] = amount;
			milkOutputs[i][1] = output;
		}
		//sorts them by the milk produced first then their amounts
		Arrays.sort(milkOutputs, new Comparator<int[]>() { 
	          @Override              
	          public int compare(final int[] entry1,  
	                             final int[] entry2) { 
	  
	            // To sort in descending order revert  
	            // the '>' Operator 
	            if (entry1[1] < entry2[1]) 
	                return -1; 
	            else if(entry1[1] == entry2[1]) {
	            	if(entry1[0] < entry2[0]) 
	            		return -1;
	            	else if(entry1[0] == entry2[0])
	            		return 0;
	            	else
	            		return 1;
	            }
	            else
	                return 1; 
	          } 
	        }); 
		
		int max = Integer.MIN_VALUE;
		int i=0, j=N-1;
		while(i<=j) {
			//pairs up the least and greatest possible cows together, considers duplicates
			int cowsPaired = Math.min(milkOutputs[i][0], milkOutputs[j][0]);
			if(i == j) {
				cowsPaired /= 2; //compensate for the subtraction of cows paired if they're the same
			}
			max = Math.max(max, milkOutputs[i][1] + milkOutputs[j][1]);
			milkOutputs[i][0] -= cowsPaired;
			milkOutputs[j][0] -= cowsPaired;
			if(milkOutputs[i][0] == 0) i++;
			if(milkOutputs[j][0] == 0) j--;
		}
		
		printWriter.println(max);
		//System.out.print();
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
}
