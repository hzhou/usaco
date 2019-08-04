import java.io.*;
import java.util.Scanner;

public class lifeguards {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("lifeguards.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("lifeguards.out"));
		int n = s.nextInt();
		Guard[] shifts = new Guard[n];
		for(int i=0; i<n; i++) {
			shifts[i] = new Guard(s.nextInt(), s.nextInt());
		}
		int highestSum =0;
		for(int i=0; i<n; i++) {
			int currentSum =0;
			for(int j=0; j<n; j++) {
				if(i==j)continue;
				currentSum+=shifts[j].length();
				for(int w=j-1; w>=0; w--) {
					if(i==w)continue;
					currentSum-= shifts[w].intersect(shifts[j]);
				}
			}
			highestSum = Math.max(highestSum,currentSum);
			
		}
		pw.println(highestSum);
		pw.close();
	}

	static class Guard {
		int start;
		int end;

		public Guard(int start, int end) {
			this.start = start;
			this.end = end;

		}
		int length() {
			return end-start;
		}
		int intersect(Guard other) {
			return Math.max(Math.min(other.end, this.end) - Math.max(other.start, this.start),0);

		}
		int getStart() {
			return start;
		}
		int getEnd() {
			return end;
		}
	}
}
