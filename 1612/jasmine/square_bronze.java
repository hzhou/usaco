//Jasmine Zhang
//All cases passed, 5 minutes
import java.util.*;
import java.io.*;
public class square {
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("square.in"));
		int [] x = new int [4];
		int [] y = new int [4];
		
		for (int i = 0; i < 4; i++) {
			x[i] = scan.nextInt();
			y[i] = scan.nextInt();
		}
		
		Arrays.sort(x);
		Arrays.sort(y);
		int side = Math.max(x[3]-x[0],y[3]- y[0]);
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("square.out")));
		out.println(side*side);
		
		out.close();
		scan.close();
	}
}
