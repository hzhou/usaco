import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Collections;

public class measurement {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("measurement.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("measurement.out"));
		int n = s.nextInt();
		int[] cows = new int[3];
		
		cows[0] = 7;
		cows[1] = 7;
		cows[2] = 7;
		boolean[] onTop = new boolean[3];
		onTop[0] = true;
		onTop[1] = true;
		onTop[2] = true;
		

		String[] names = new String[100];
		int[] values = new int[100];
		for (int i = 0; i < n; i++) {

			int day = s.nextInt()-1;
			names[day] = s.next();
			String value = s.next();
			values[day] = Integer.valueOf(value.substring(1, value.length()));
			if (value.charAt(0) == '-') {
				values[day] *= -1;
			}
		}
		
		int counter=0;
		
		for (int i = 0; i < 100; i++) {
			
			String currentName = names[i];
			int currentValue = values[i];
			if(currentName==null) {
				continue;
			}
			if (currentName.equals("Mildred")) {
				cows[0] += currentValue;

			} else if (currentName.equals("Elsie")) {
				cows[1] += currentValue;

			} else if (currentName.equals("Bessie")) {
				cows[2] += currentValue;

			}
			boolean[] temp = new boolean[3];
			int best = Math.max(cows[0],Math.max(cows[1], cows[2]));
			for (int j = 0; j < 3; j++) {
				if (cows[j] == best) {
					temp[j]=true;
				}
			}
			for(int j=0; j<3;j++) {
				if(onTop[j]!=temp[j]) {
					onTop = temp;
					counter++;
					break;
				}
			}
		}
		pw.println(counter);
		pw.close();
	}
}
