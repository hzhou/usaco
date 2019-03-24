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
TASK: convention2
 */

public class convention2 {

	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\convention2.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\convention2.out.txt"));
		Scanner input = new Scanner(new File("convention2.in"));
		FileWriter fileWriter = new FileWriter(new File("convention2.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		int n = input.nextInt();
		int[][] cowInfo = new int[n][3];
		//pos 0 is a
		//pos 1 is t
		//pos 2 is senority
		for(int i=0; i<n; i++) {
			cowInfo[i][0] = input.nextInt();
			cowInfo[i][1] = input.nextInt();
			cowInfo[i][2] = i;
		}
		
		//sorts the cows based on when they arrive
        Arrays.sort(cowInfo, new Comparator<int[]>() { 
            
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
        
        int result = Integer.MIN_VALUE;
        int currentlyEating = 0;
        int currentTime = cowInfo[currentlyEating][0];
        cowInfo[0][2] = -1; //prematurely sets the first cow to already eating so it doesn't get selected
        while(hasCows(cowInfo, n)) {
        	//adds the time the cow eats
        	currentTime += cowInfo[currentlyEating][1];
        	
        	int j = 1;
        	int maxIndex = -1;
        	int maxSenority = Integer.MAX_VALUE;
        	
        	//loops through all the waiting cows, beg to end
        	while(j < n && cowInfo[j][0] < currentTime) {
            	//finds the cow of highest senority that is waiting
        		if(cowInfo[j][2] != -1 && cowInfo[j][2] < maxSenority) {
        			maxIndex = j;
        			maxSenority = cowInfo[maxIndex][2];
        		}
        		j++;
        	}
        	
        	if(maxIndex != -1) {
	        	//timewaited is the other cow's time started and eating minus the second cow's start
	        	int timeWaited = currentTime - cowInfo[maxIndex][0];
	        	cowInfo[maxIndex][2] = -1; //current eating cow gets a senority of -1, signifies it's done and can't be selected
	        	currentlyEating = maxIndex; //makes that cow the current eater
	        	if(timeWaited > result)
	        		result = timeWaited;
        	}
        	else {
        		for(int i=1; i<n; i++) {
        			if(cowInfo[i][2] != -1) {
        				currentTime = cowInfo[i][0];
                		currentlyEating = i; //makes that cow the current eater
                		cowInfo[i][2] = -1;
        				break;
        			}
        		}
        	}
        }
        
        //System.out.println(result);
        printWriter.println(result);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}

	private static boolean hasCows(int[][] cowInfo, int n) {
		for(int i=0; i<n; i++) {
			if(cowInfo[i][2] != -1) {
				return true;
			}
		}
		return false;
	}
	
}
