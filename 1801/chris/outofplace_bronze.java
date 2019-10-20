import java.util.*;
import java.io.*;

public class outofplace {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("outofplace.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("outofplace.out"));
		int n = s.nextInt();
		int[] unsorted = new int[n];
		for (int i = 0; i < n; i++) {
			unsorted[i] = s.nextInt();
		}
		int incPos = incorrect(unsorted);
		int[] temp = unsorted.clone();
		Arrays.sort(unsorted);
		int[] sorted = unsorted;
		unsorted = temp;
		
		int steps = 0;
		if (incPos == -1)
			pw.println(steps);
		else {
			int corPos = Integer.MIN_VALUE; // used to be 0 but that would mean that the correct position would have to be closer to the incorrect position than the start which isnt always the case
			for (int i = n-1; i >=0; i--) {
				if (sorted[i] == unsorted[incPos]) {
					if(Math.abs(incPos-i)<Math.abs(incPos-corPos)) {// only change it if the resulting length is less because there is a chance the value has multiples in the correct spot already
																	// so you should choose the closer multiple
					corPos = i;}
				}
			}
			
			int temp1 = incPos;
			incPos = Math.min(incPos, corPos);
			corPos = Math.max(temp1, corPos);
			steps = corPos - incPos;
			for (int i = incPos; i < corPos; i++) {
				if (unsorted[i] == unsorted[i + 1])
					steps--;

			}
			pw.println(steps);
		}

		pw.close();
	}

	static int incorrect(int[] a) {
		for (int i = 1; i < a.length-1; i++) {
			if (a[i] < a[i - 1]) {// if current value is less than the previous value it has the be incorrect
				return i;
			}
			if(a[i]>a[i-1] && a[i]>a[i+1] && a[i+1]>a[i-1]) { // if the current value is larger than the previous theres a good chance its right, if it is also larger than the next theres a chance the next is the wrong one, 
															  //if the next is larger than the previous this one must be incorrect
				return i;
			}
		}
		if(a[a.length-1]<a[a.length-2])return a.length-1;// if you get through everything then there isn't a value then the last one must be the value
		return -1;
	}
}
