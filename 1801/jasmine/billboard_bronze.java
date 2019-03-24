//Jasmine Zhang
//All cases passed, 30 minutes
//There's probably a better way 
import java.util.*;
import java.io.*;
public class billboard {
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("billboard.in"));
		int lawnx1 = scan.nextInt();
		int lawny1 = scan.nextInt();
		int lawnx2 = scan.nextInt();
		int lawny2 = scan.nextInt();
		
		int cowx1 = scan.nextInt();
		int cowy1 = scan.nextInt();
		int cowx2 = scan.nextInt();
		int cowy2 = scan.nextInt();
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));
		int max = (lawnx2-lawnx1)*(lawny2-lawny1);
		if (cowx2 < lawnx1 || lawnx2 < cowx1 || cowy2 < lawny1 || lawny2 < cowy1)
			out.println(max);
		else if (lawnx1 < cowx1 && cowx2 < lawnx2 || lawny1 < cowy1 && cowy2 < lawny2) 
			out.println(max);
		else if (lawnx1 > cowx1 && cowx2 > lawnx2 && lawny1 > cowy1 && cowy2 > lawny2) 
			out.println(0);
		else if (lawnx1 > cowx1 && cowx2 > lawnx2) {
			out.println(max-(Math.abs(Math.min(cowy2, lawny2)-Math.max(cowy1, lawny1))*(lawnx2-lawnx1)));
		}
		else if (lawny1 > cowy1 && cowy2 > lawny2) {
			out.println(max-(Math.abs(Math.min(cowx2, lawnx2)-Math.max(cowx1, lawnx1))*(lawny2-lawny1)));
		}
		else {
			out.println(max);
		}
		
		
		
		
			
		out.close();
		scan.close();
	}

}
