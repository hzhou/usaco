import java.util.*;
import java.io.*;
public class mowing {

	public static void main(String[] args) throws IOException{
		
		//had to be increased or else two test cases gave errors 
		int [] pasture = new int  [100000000]; //this is a very big pasture - 10000 by 10000
		Scanner scan = new Scanner (new File ("mowing.in"));
		int n = scan.nextInt();
		
		int max = -1;
		int currentT = 1;
		int currentPos = 5000*10000+5000; //middlish 
		for (int i = 0; i < n; i++){
			char dir = scan.next().charAt(0);
			int steps = scan.nextInt();
			
			int add = 0;
			if (dir == 'N')
				add = -10000;
			if (dir == 'E')
				add = 1;
			if (dir == 'S')
				add = 10000;
			if (dir == 'W')
				add = -1;
			
			for (int j = 0; j < steps; j++){
				currentPos+=add;
				if (pasture[currentPos] != 0) {
					int timePassed = currentT - pasture[currentPos];
					if (max == -1)
						max = timePassed;
					else
						max = Math.min(timePassed, max);
				}
				pasture[currentPos] = currentT;
				currentT++;
			}
		}
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("mowing.out")));
		System.out.println(max);
		out.println(max);
	
		out.close();
		scan.close();
	}

}
