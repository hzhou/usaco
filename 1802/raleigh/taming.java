import java.util.*;
import java.io.*;

public class taming{
    public static void main(String[] args) throws IOException{
	Scanner scan = new Scanner(new File("taming.in"));
	int N = scan.nextInt();
	int[] log = new int[N];
	int maxbreak=1, minbreak=1;
	int lastbreak=0;

	for(int i=0; i<N; i++){
	    log[i] = scan.nextInt();
	}

	for(int j=0; j<N; j++){
	    if(log[j] == -1){
		int k = 0;
		while(log[j+k] == -1){
		    k++;
		}
		if(log[j+k] < lastbreak){
		    maxbreak++;
		}
		
	    }
	    else if(log[j] == 0){
	    	maxbreak++;
		minbreak++;
		lastbreak = log[j];
	    }
	    else if(log[j] > lastbreak){
		lastbreak = log[j];
	    }
	    else if(log[j] < lastbreak){
	    	minbreak++;
		maxbreak++;
	    }
	}
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("taming.out")));
    	out.println(minbreak + " " + maxbreak);
	scan.close();
	out.close();
	
   }
    
}
