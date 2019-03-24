//Jasmine Zhang
//All cases passed in 45 minutes
//Used 1 additional test case
import java.util.*;
import java.io.*;
public class hps {
	static int n;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("hps.in"));
		n = scan.nextInt();
		
		//total amount of wins
		int [] hTotal = new int [n];
		int [] pTotal = new int [n];
		int [] sTotal = new int [n];
		
		//record the wins
		boolean [] hWin = new boolean [n];
		boolean [] pWin = new boolean [n];
		boolean [] sWin = new boolean [n];
		
		for (int i = 0; i < n; i++) {
			String s = scan.next();
			if (s.equals("H")) {
				pWin[i] = true;
				if (i == 0)
					pTotal[0] = 1;
				else {
					pTotal[i] = pTotal[i-1]+1;
					hTotal[i] = hTotal[i-1];
					sTotal[i] = sTotal[i-1];
				}
			}
			else if (s.equals("P")) {
				sWin[i] = true;
				if (i == 0)
					sTotal[0] = 1;
				else {
					sTotal[i] = sTotal[i-1]+1;
					hTotal[i] = hTotal[i-1];
					pTotal[i] = pTotal[i-1];
				}
			}
			else if (s.equals("S")) {
				hWin[i] = true;
				if (i == 0)
					hTotal[0] = 1;
				else {
					hTotal[i] = hTotal[i-1]+1;
					pTotal[i] = pTotal[i-1];
					sTotal[i] = sTotal[i-1];
				}
			}
		}
		
		//had to check all cases
		//only checked the one with the largest amount of wins the first time
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("hps.out")));
		int a = bestCase(hTotal,pWin,sWin);
		int b = bestCase(pTotal,hWin,sWin);
		int c = bestCase(sTotal,hWin,pWin);
		out.println(Math.max(a, Math.max(b,c)));
		
		
		
		
		scan.close();
		out.close();
	}
	public static int bestCase (int [] mostWin, boolean [] other1, boolean [] other2)
	{
		int [] rOther1 = reverseWins(other1);
		int [] rOther2 = reverseWins(other2);
		int [] combine1 = new int [n+1];
		int [] combine2 = new int [n+1];
		for (int i = -1; i < n; i++) {
			if (i == -1) {
				combine1[i+1] =  rOther1[i+1];
				combine2[i+1] =  rOther2[i+1];
			}
			else if (i== n-1) {
				combine1[i+1] = mostWin[i];
				combine2[i+1] = mostWin[i];
			}
			else {
				combine1[i+1] = rOther1[i+1] + mostWin[i];
				combine2[i+1] = rOther2[i+1] + mostWin[i];
			}
		}
		Arrays.sort(combine1);
		Arrays.sort(combine2);
		return Math.max(combine1[n],combine2[n]);
	}
	public static int [] reverseWins (boolean [] wins) {
		int [] rWins = new int [n];
		int count = 0;
		for (int i = n-1; i >= 0; i--) {
			if (wins[i])
				count++;
			rWins[i] = count;
		}
		
		return rWins;
	}

}
