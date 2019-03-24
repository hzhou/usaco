//Jasmine Zhang
//All cases passed in 1 hour
//Most of the time was spent debugging 
//I need more practice with writing while loops for simulation problems 
import java.util.*;
import java.io.*;
public class angry {
	static int [] bales;
	static int n;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("angry.in"));
		n = scan.nextInt();
		
		bales = new int [n];
		for (int i = 0; i < n; i++) {
			bales[i] = scan.nextInt();
		}
		Arrays.sort(bales);
		System.out.println(Arrays.toString(bales));
		
		int largest = 1;
		
		for (int i = 0; i < n; i++) {
			System.out.println(explode(i));
			
			largest = Math.max(largest, explode(i));
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("angry.out")));
		System.out.println(largest);
		out.println(largest);
	
		out.close();
		scan.close();
	}
	public static int explode (int i) {
		int radius = 1;
		int currentI = i;
		int prevBale = bales[i];
		int exploded = 1;
		int hit = 0;
		
		
		
		int leftIn = i-1;
		int rightIn = i+1;
		int currentLeft = bales[i];
		int currentRight = bales[i];
		boolean left = true;
		boolean right = true;
		//>= or >, when to increment certain variables, adding or subtracting killed me 
		while (leftIn >= 0 || rightIn < n) {
			int newL = 0;
			if (left && leftIn >= 0) {
				
				System.out.println(currentLeft + " " + leftIn  + " " + radius);
				while (leftIn >= 0 &&currentLeft - bales[leftIn] <= radius ) {
					newL++;
					leftIn--;
				}
				
				if (newL == 0)
					left = false;
				currentLeft = bales[leftIn+1];
				
			}
			
			
			int newR = 0;
			if (right&& rightIn < n) {
				
				while (rightIn < n && bales[rightIn] - currentRight <= radius ) {
					newR++;
					rightIn++;
				}
				if (newR == 0)
					right = false;
				currentRight = bales[rightIn-1];
			}
			
			
			if (newL == 0 && newR == 0)
				break;
			exploded += newL + newR;
			radius++;
		}
		return exploded;
	}
	
	

}
