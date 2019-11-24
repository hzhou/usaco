//Raleigh
//15 minutes (debugging)
//10/10 passed

import java.util.*;
import java.io.*;

public class crossroad{
    public static void main(String[] args) throws IOException{
	Scanner scan = new Scanner(new File("crossroad.in"));
	int N = scan.nextInt();
	int[][] cow = new int[N][2];
	for(int i=0; i<N; i++){
	    for(int j=0; j<2; j++){
	    	cow[i][j] = scan.nextInt();
	    }
	}
	
	int crosses=0;
	for(int i=0; i<N; i++){
	    for(int k=i+1; k<N; k++){
	    	if(cow[i][0] == cow[k][0]){
		
		    if(cow[i][1] != cow[k][1]){
		       	crosses++;
		    }
		    break;
		}

	    }
	}

	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("crossroad.out")));
	out.println(crosses);
	out.close();
	scan.close();
    }
}
