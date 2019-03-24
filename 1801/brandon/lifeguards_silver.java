import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;

/*
ID: fireblaze
LANG: JAVA
TASK: lifeguards
 */

//Name: Brandon Zhang
//Time: 60-90 minutes
//10/10 Passed

public class lifeguards {
	public static void main(String[] args) throws IOException{
		Scanner input = new Scanner(new File("lifeguards.in"));
		FileWriter fileWriter = new FileWriter(new File("lifeguards.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		int N = input.nextInt();
		Shift[] shifts = new Shift[2*N];
		for(int i=0; i<N; i++) {
			int beg = input.nextInt();
			int end = input.nextInt();
			shifts[2*i] = new lifeguards.Shift(beg, i);
			shifts[2*i+1] = new lifeguards.Shift(end, i);
			//shifts[i][0] = input.nextInt();
			//shifts[i][1] = input.nextInt();
		}
		//sort based on time
		Arrays.sort(shifts);
		
		TreeSet<Integer> cowsWorking = new TreeSet<Integer>();
		int[] timesAlone = new int[N]; //how much time each cow works alone is recorded here
		int last = 0; //last cow's time is recorded for the next iteration
		int actualTimeCovered = 0; //records the total time covered by each cow
		for(Shift s : shifts) {
			if(cowsWorking.size() == 1) { //if the cow is alone log its time working
				timesAlone[cowsWorking.first()] += s.time - last;
			}
			if(!cowsWorking.isEmpty()) { //if there is any cow working add its time, for finding total work time
				actualTimeCovered += s.time - last;
			}
			if(cowsWorking.contains(s.index)) { //if the log already contains the same cow, remove it because it's done
				cowsWorking.remove(s.index);
			}
			else { //otherwise add it on the list
				cowsWorking.add(s.index);
			}
			last = s.time;
		}
		
		int result = Integer.MIN_VALUE;
		for(int t : timesAlone) {
			result = Math.max(result, actualTimeCovered - t);
		}
		
		printWriter.println(result);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
	private static class Shift implements Comparable<Shift>{
		int time, index;
		public Shift(int time, int index) {
			this.time = time;
			this.index = index;
		}
		public int compareTo(Shift s) {
			return time - s.time;
		}
	}
}
