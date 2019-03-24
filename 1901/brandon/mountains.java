package competitionProblems;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/*
ID: fireblaze
LANG: JAVA
TASK: mountains
 */

public class mountains {
	public static void main(String[] args) throws IOException{
//		Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\mountains.in.txt"));
//		FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\mountains.out.txt"));
		Scanner input = new Scanner(new File("mountains.in"));
		FileWriter fileWriter = new FileWriter(new File("mountains.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		int n = input.nextInt();
		//[0] is x, [1] is y
		//int[][] peaks = new int[n][2];
		ArrayList<int[]> peaks = new ArrayList<int[]>();
		for(int i=0; i<n; i++) {
			int x = input.nextInt();
			int y = input.nextInt();
			peaks.add(new int[]{x, y}); 
		}
		//sorts based on y axis, highest to lowest
		Collections.sort(peaks, new Comparator<int[]>() { 
	          @Override              
	          public int compare(final int[] entry1,  
	                             final int[] entry2) { 
	  
	            // To sort in descending order revert  
	            // the '>' Operator 
	            if (entry1[1] > entry2[1]) 
	                return -1; 
	            else
	                return 1; 
	          } 
	        }); 
		
		for(int i=0; i<peaks.size(); i++) {
			for(int j=i+1; j<peaks.size(); j++) {
				int x1 = peaks.get(i)[0];
				int y1 = peaks.get(i)[1];
				int x2 = peaks.get(j)[0];
				int y2 = peaks.get(j)[1];
				if(-Math.abs(x2-x1) + y1 >= y2) {
					peaks.remove(j);
					j--;
				}
			}
		}
		
		printWriter.println(peaks.size());
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
}