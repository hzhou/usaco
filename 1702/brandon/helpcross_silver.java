import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

/*
ID: fireblaze
LANG: JAVA
TASK: helpcross
 */

//Name: Brandon Zhang
//Passed 3 out of 10, 7 runtime error/memory limit exceeded
//Time: 2-3 hrs

public class helpcross {
	static ArrayList<Integer> chickenTimes;
	static int[] arrivalTimes;
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\helpcross.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\helpcross.out.txt"));
		Scanner input = new Scanner(new File("helpcross.in"));
		FileWriter fileWriter = new FileWriter(new File("helpcross.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		int C = input.nextInt();
		int N = input.nextInt();
		chickenTimes = new ArrayList<Integer>();
		CowShift[] cowTimes = new CowShift[N];
		for(int i=0; i<C; i++) {
			chickenTimes.add(input.nextInt());
		}
		for(int i=0; i<N; i++) {
			int beg = input.nextInt();
			int end = input.nextInt();
			cowTimes[i] = new CowShift(beg, end);
		}
		Collections.sort(chickenTimes);
		Arrays.sort(cowTimes);
		
		int total = 0;
		for(int i=0; i<N; i++) { //loops through cows
			int chicken = binarySearch(cowTimes[i].beg);
			if(!chickenTimes.isEmpty() && chicken <= cowTimes[i].end) {
				total++;
				chickenTimes.remove((Integer)chicken);
			}
		}
		
		printWriter.println(total);
		//System.out.print(total);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
	private static class CowShift implements Comparable<CowShift>{
		int beg;
		int end;
		public CowShift(int beg, int end) {
			this.beg = beg;
			this.end = end;
		}
		public int compareTo(CowShift s) {
			int temp = end - s.end;
			if(temp == 0) {
				return beg - s.beg;
			}
			return temp;
		}
	}
	private static int binarySearch(int search) {
		int l1 = 0;
		int l2 = chickenTimes.size()-1;
		while(l1 <= l2) {
			int l3 = (l1 + l2) / 2;
			if(chickenTimes.get(l3) < search) {
				l1 = l3+1;
			}
			else if(chickenTimes.get(l3) > search) {
				l2 = l3-1;
			}
			else if(chickenTimes.get(l3) == search){
				return search;
			}
		}
		return chickenTimes.get(l1);
	}
}
