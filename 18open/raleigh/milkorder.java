import java.util.*;
import java.io.*;

//i dont know what i was doing but it took me an hour and a half

public class milkorder{
    public static void main(String[] args) throws IOException{
    	Scanner scan = new Scanner(new File("milkorder.in"));
	int N = scan.nextInt();
	int M = scan.nextInt();
	int K = scan.nextInt();
	int[] order = new int[N];
	int[] hierarchy = new int[M];
	int[] cow = new int[K];
	int[] pos  = new int[K];
	for(int i=0; i<M; i++){
	    hierarchy[i] = scan.nextInt();
	}
	for(int j=0; j<K; j++){
	    cow[j] = scan.nextInt();
	    pos[j] = scan.nextInt();
	    order[pos[j]] = cow[j];
	}
	int noroom = 0;
	for(int i=0; i<N; i++){
	    for(int j=0; j<M; j++){
	    	if(order[i] == hierarchy[j]){ //runs until the hierarchy list affects order
		    for(int k=0; k<j; k++){ //recycles all cows before order[i] in the hierarchy and
		    //fills up remaining 0 positions in the order list before i
		    	if(order[i-k-1] == 0){ //fills up previous positions until there is no room
			    order[i-k-1] = hierarchy[j];	    
			}
			else{ //when there is no room, it fills up positions after order[i]
			    noroom++;
			    order[i+noroom] = hierarchy[j]; 
			}
		    }
		}
	    }
	}
	int earlypos = 1;
	for(int z=0; z<N; z++){ //the first place where the order array has a value of 0 is
	//where the first cow can be milked
	    if(order[z] == 0){
		earlypos += z;
	    }
	}

	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milkorder.out")));
	out.println(earlypos);
	scan.close();
	out.close();

    }
    
}
