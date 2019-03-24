//Jasmine Zhang
//All cases passed in 15 minutes
import java.util.*;
import java.io.*;
public class lostcow {

	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("lostcow.in"));
		int x = scan.nextInt();
		int y = scan.nextInt();
		
		int dTravelled = 0;
		boolean found = false;
		int step = 1;
		int lastX = x;
		while (!found) {
			int newX = x + step;
			if ((newX <= y && lastX >= y)||(newX >= y && lastX <= y)) {
				found = true;
				dTravelled += Math.abs(lastX-y);
			}
			else {
				dTravelled += Math.abs(lastX-newX);
			}
			lastX = newX;
			step = step*2*-1;
			
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lostcow.out")));
		out.println(dTravelled);
	
		out.close();
		scan.close();
	}

}
