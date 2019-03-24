import java.util.*;
import java.io.*;
public class pails {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("pails.in"));
		int x = scan.nextInt();
		int y = scan.nextInt();
		int m = scan.nextInt();
		
		//certain combination of little and medium pails 
		//better variable names 
		int maxLittle = m/x;
		int little = x*maxLittle;
		int largest = little;
		int remain = m%x;
		int currentMed = 0;
		
		for (int i = maxLittle-1; i >= 0; i--) {
			if (largest == m)
				break;
			remain += x;
			little -= x;
			int med = remain / y;
			//System.out.println(little + " " + med);
			if (med == currentMed)
				continue;
			int currentVal = little + med*y;
			if (currentVal > largest)
				largest = currentVal;
			
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("pails.out")));
		System.out.println(largest);
		out.println(largest);
		
	
		out.close();
		scan.close();
	}

}
