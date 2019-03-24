import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

/*
ID: fireblaze
LANG: JAVA
TASK: measurement
 */

//Brandon Zhang
//Time Spent: 1 hr
//7 Passed, 3 time exceeded, 1 wrong
//Notes: Need help with optimization strategies
//also the one wrong seems like it's a bad input from the tester, needs verification

public class measurement {
	public static void main(String[] args) throws IOException{
		Scanner input = new Scanner(new File("measurement.in"));
		FileWriter fileWriter = new FileWriter(new File("measurement.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);

		int n = input.nextInt();
		int g = input.nextInt();
		//key is cow number, value is milk amount	
		
		int[][] measurements = new int[n][3];
		TreeMap<Integer, Integer> log = new TreeMap<Integer, Integer>();
		TreeSet<Integer> top = new TreeSet<Integer>();
		int highestValue = g;
		for(int i=0; i<n; i++) {
			measurements[i][0] = input.nextInt();
			measurements[i][1] = input.nextInt();
			if(!log.containsKey(measurements[i][1])) {
				log.put(measurements[i][1], g);
				top.add(measurements[i][1]);
			}
			measurements[i][2] = input.nextInt();
		}
		
		//sort based on date
		Arrays.sort(measurements, new Comparator<int[]>() { 
	          @Override              
	          public int compare(final int[] entry1,  
	                             final int[] entry2) { 
	  
	            // To sort in descending order revert  
	            // the '>' Operator 
	            if (entry1[0] > entry2[0]) 
	                return 1; 
	            else
	                return -1; 
	          } 
	        }); 
		
		int result = 0;
		//loop through log
		for(int i=0; i<measurements.length; i++) {
			//updates log based on measurements
			log.put(measurements[i][1], log.get(measurements[i][1])+measurements[i][2]);
			//updates top list
			//updates highest value
			highestValue = Integer.MIN_VALUE;
			for(Map.Entry<Integer, Integer> m : log.entrySet()) {
				if(m.getValue() > highestValue) {
					highestValue = m.getValue();
				}
			}
			//queues the list for removal
			ArrayList<Integer> temp = new ArrayList<Integer>();
			for(Integer j : top) {
				if(log.get(j) < highestValue) {
					temp.add(j);
				}
			}
			//checks if the list actually changes
			boolean change1 = top.removeAll(temp);
			boolean change2 = false;
			//adds any ties to the top list
			for(Map.Entry<Integer, Integer> m : log.entrySet()) {
				if(m.getValue() == highestValue) {
					change2 = change2 || top.add(m.getKey());
				}
			}
			if(change1 || change2) {
				result++;
			}
		}
		
		//System.out.println(result);
		printWriter.println(result);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}

}
