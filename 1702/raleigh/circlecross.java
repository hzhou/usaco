import java.util.*;
import java.io.*;

public class circlecross{
    public static void main(String[] args) throws IOException{
    	Scanner scan = new Scanner(new File("circlecross.in"));
	String crosses = scan.nextLine();
	char[] cow = new char[52];
	int[] repeat = new int[26];
	for(int i=0; i<52; i++){
	    cow[i] = crosses.charAt(i);
	}
    	
	int numcross=0;
	for(int i=1; i<52; i++){
	    if(cow[i] != cow[i-1]){
	    	char a = cow[i-1];
		char b = cow[i];
		for(int j=i+1; j<52; j++){
		    repeat[cow[j] - 'A'] += 1;
		    if(a == cow[j]){
			numcross++;
			break;
		    } 
		    if(b == cow[j]){
			break;
		    }
		}
		for(int k=0; k<26; k++){
		    if(repeat[k] == 1){
			numcross++;
		    }
		    repeat[k] = 0;
		}
	    }
	}

	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("circlecross.out")));
	out.println(numcross);
	out.close();
	scan.close();
    }
}
