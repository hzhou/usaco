import java.util.*;
import java.io.*;
import java.lang.Math;

public class cowqueue{
    public static void main(String[] args) throws IOException{
	Scanner scan = new Scanner(new File("cowqueue.in"));
	int N = scan.nextInt();
	int[][] coword = new int[N][2];

	for(int i=0; i<N; i++){
	    for(int j=0; j<2; j++){
		coword[i][j] = scan.nextInt();	
	    }
	}

	Arrays.sort(coword, new Comparator<int[]>() {
	    public int compare(int[] a, int[] b){
		return Integer.compare(a[0],b[0]); //compare the left column in the 2d array
	    }
	});

	int lagtime = 0;
	for(int i=0; i<N-1; i++){
	    int tdiff = coword[i+1][0] - coword[i][0];
	    tdiff -= coword[i][1] - lagtime;
	    if(tdiff<0){
		lagtime = Math.abs(tdiff);
	    }
	}

	int totalwait = lagtime + coword[N-1][0] + coword[N-1][1];


	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowqueue.out")));
	out.println(totalwait);
	out.close();
	scan.close();


    }
}
