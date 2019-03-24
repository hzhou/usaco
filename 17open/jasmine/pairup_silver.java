//Jasmine Zhang
//All cases passed in 40 minutes 
import java.util.*;
import java.io.*;
public class pairup {
	static int [] mAmount;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("pairup.in"));
		int n = scan.nextInt();
	
		//need to do arrays, not arraylist of all cows 
		mAmount = new int [n];
		int [] xCows = new int [n];
		Integer [] p = new Integer [n];
		
		for (int i = 0; i < n; i++) {
			xCows[i] = scan.nextInt();
			mAmount[i] = scan.nextInt();
			p[i] = i;
		}
		
		Arrays.sort(p, new Comparator <Integer> (){
			public int compare (Integer i1, Integer i2) {
				return mAmount[i1]-mAmount[i2];
			}
		});
		Arrays.sort(mAmount);
		
		int [] temp = Arrays.copyOf(xCows,n);
		for (int i = 0; i < n; i++) {
			xCows[i] = temp[p[i]];
		}
		
		int maxTime = 0;
		int start = 0;
		int end = n-1;
		while (start < n && end >= 0 && start <= end) {
			if (start == end) {
				maxTime = Math.max(maxTime, mAmount[start]*2);
				break;
			}
			int maxPairs = Math.min(xCows[start], xCows[end]);
			int totalTime = mAmount[start] + mAmount[end];
			maxTime = Math.max(totalTime, maxTime);
			xCows[start] -= maxPairs;
			xCows[end] -= maxPairs;
			
			if (xCows[start] == 0)
				start++;
			if (xCows[end] == 0)
				end--;
		}
	
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("pairup.out")));
		System.out.println(maxTime);
		out.println(maxTime);
	
		out.close();
		scan.close();
	}

}
