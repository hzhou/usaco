import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/*
ID: fireblaze
LANG: JAVA
TASK: homework
 */

//Brandon Zhang
//Time Spent: 45 min - 1 hr
//9 Passed, 1 wrong
//Notes: 

public class homework_silver {
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\homework.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\homework.out.txt"));
		Scanner input = new Scanner(new File("homework.in"));
		FileWriter fileWriter = new FileWriter(new File("homework.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);

		int n = input.nextInt();
		int[] scores = new int[n];
		for(int i=0; i<n; i++) {
			scores[i] = input.nextInt();
		}
		
		int sum = scores[n-1];
		int lowest = scores[n-1];
		double questions = 0; //0 to compensate for -1 question
		double highestScore = 0;
		ArrayList<Integer> result = new ArrayList<Integer>();
		for(int k=n-2; k>0; k--) { //looping from n-2 to 1 instead of 1 to n-2 saves time 
								   //because we can update sum and lowest score without a loop
			sum += scores[k];
			if(scores[k] < lowest) {
				lowest = scores[k];
			}
			questions++;
			if((sum-lowest) / questions > highestScore) {
				highestScore = (sum-lowest) / questions;
				result = new ArrayList<Integer>(); //clears out arraylist because new value
				result.add(k);
			}
			else if((sum-lowest) / questions == highestScore) {
				result.add(k);
			}
		}
		
		for(int i=0; i<result.size(); i++) {
			printWriter.println(result.get(i));
		}
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}

}
