//Went down a completely wrong logical path
import java.util.*;
import java.io.*;
public class cbarn {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("cbarn.in"));
		int n = scan.nextInt();
		
		int [] cows = new int [n];
		for (int i = 0; i < n; i++)
			cows[i] = scan.nextInt();
		
		int lastZero = n-1;
		while (lastZero >= 0 && cows[lastZero]!= 0) 
			lastZero--;
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cbarn.out")));
		//logic got too complicated and messed up 
		if (lastZero == -1) {
			System.out.println(0);
			out.println(0);
		}
		else {
			//deal with going backwards through a noncircular array
			lastZero += n;
			int currentNum = lastZero - 1;
			int total = 0;
			int stop = lastZero - n;
			while (currentNum > stop) {
				while (currentNum > stop && cows[currentNum%n] == 0) {
					currentNum --;
				}
				int diff = lastZero - currentNum;
				//System.out.println(lastZero + " " + currentNum);
				int numCows = cows[currentNum%n];
				int dist = diff;
				
				
				if (diff+1 == numCows) {
					for (int i = 0; i < numCows-1; i++)  {
						cows[lastZero%n] = 1;
						total += dist*dist;
						System.out.println(Arrays.toString(cows) + " " + total);
						dist--;
						lastZero--;
						
					}
					cows[currentNum%n] = 1;
					currentNum--;
					lastZero--;
				}
				else if (diff < numCows) {
					for (int i = 0; i < numCows-1; i++)  {
						cows[lastZero%n] = 1;
						total += dist*dist;
						System.out.println(Arrays.toString(cows) + " " + total);
						dist--;
						lastZero--;
						
					}
					//cows[currentNum%n] = 1;
					
					lastZero--;
					for (int i = 0; i < numCows-diff-1;i++) {
						total += (stop-currentNum);
						cows[(stop+1)%n]++;
						cows[currentNum%n] = 0;
					}
					currentNum--;
				}
				else {
					for (int i = 0; i < numCows; i++)  {
						cows[lastZero%n] = 1;
						total += dist*dist;
						dist--;
						lastZero--;
						System.out.println(Arrays.toString(cows) + " " + total);
					}
					cows[currentNum%n] = 0;
				}
				//lastZero -= numCows;
				
				//if (cows[lastZero%n] == 1)
					//lastZero--;
				System.out.println(Arrays.toString(cows));
			}
			System.out.println(total);
			out.println(total);
		}
		
		
		
		
	
		out.close();
		scan.close();
	}

}
