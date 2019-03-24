import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
ID: fireblaze
LANG: JAVA
TASK: reststops
 */

//Name: Brandon Zhang
//Time: 60-90 minutes
//10/10 passed

public class reststops {
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\reststops.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\reststops.out.txt"));
		Scanner input = new Scanner(new File("reststops.in"));
		FileWriter fileWriter = new FileWriter(new File("reststops.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		int L = input.nextInt(); //length of trail
		int N = input.nextInt(); //rest stops
		int RF = input.nextInt(); //farmer sec/meter
		int RB = input.nextInt(); //bessie sec/meter
		int[] restLocation = new int[N];
		int[] restTaste = new int[N];
		//int[] farmerLocation = new int[n]; //time when farmer gets to rest location
		//int[] bessieLocation = new int[n]; //time when bessie gets to rest location
		for(int i=0; i<N; i++) {
			restLocation[i] = input.nextInt();
			restTaste[i] = input.nextInt();
			//farmerLocation[i] = rf * restLocation[i];
			//bessieLocation[i] = rb * restLocation[i];
		}
		
		//finds maximums from right to left, that way time isn't wasted
		//maximums are defined as greater than anything to its right
		//that way bessie stays at the best stops for the longest time
		boolean isMax[] = new boolean[N];
		int max = 0;
		for(int i=N-1; i>=0; i--) {
			if(restTaste[i] > max) {
				isMax[i] = true;
				max = restTaste[i];
			}
		}
		
		long tastiness = 0;
		long farmerTime = 0;
		long bessieTime = 0; 
		int lastStop = 0;
		for(int i=0; i<N; i++) {
			//moves them to their appropriate positions
			if(isMax[i]) {
				farmerTime += (restLocation[i]-lastStop) * (long)RF;
				bessieTime += (restLocation[i]-lastStop) * (long)RB;		
				//adds the tastiness
				tastiness += (farmerTime - bessieTime) * (long)restTaste[i];
				//catches up farmer to bessie
				farmerTime = bessieTime;
				//updates the last stop
				lastStop = restLocation[i];
			}
		}
		
		//System.out.println(tastiness-1);
		printWriter.println(tastiness);
		printWriter.close();
		fileWriter.close();
		input.close();
	}
}
