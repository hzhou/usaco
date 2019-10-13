package com.bronze.dec2017;

/*
 * Harrison Zhang
 * Tests passed: all of them
 * Time: 53:26.10
 */
import java.util.*;
import java.io.*;
public class measurement {
	public static void main(String[] args) throws IOException {
//		Scanner scan = new Scanner(System.in);
		Scanner scan = new Scanner(new File("measurement.in"));
		int N = scan.nextInt();
		List<Integer> day = new ArrayList<>();
		List<String> name = new ArrayList<>();
		List<String> change = new ArrayList<>();
		
		int mildred = 7, bessie = 7, elsie = 7;
		boolean m = true, b = true, e = true;
		
		for(int i = 0; i < N; i++) {
			day.add(scan.nextInt());
			name.add(scan.next());
			change.add(scan.next());
		}
		
		scan.close();
		
		List<Integer> daySort = new ArrayList<>();
		for(int i = 0; i < N; i++) {
			daySort.add((day.get(i)));
		}
		Collections.sort(daySort);

		int index = 0;
		int changeCount = 0;
		for(int i = 0; i < N; i++) {
			int time = daySort.get(i);
			for(int j = 0; j < N; j++) {
				if((day.get(j)) == time) {
					index = j;
					break;
				}
			}
			boolean mOld = m, bOld = b, eOld = e;
			if((name.get(index)).equals("Mildred")) {
				if(((change.get(index)).substring(0, 1)).equals("+")) {
					mildred += Integer.valueOf((change.get(index)).substring(1));
				} else if(((change.get(index)).substring(0, 1)).equals("-")) {
					mildred -= Integer.valueOf((change.get(index)).substring(1));
				}
			} else if((name.get(index)).equals("Bessie")) {
				if(((change.get(index)).substring(0, 1)).equals("+")) {
					bessie += Integer.valueOf((change.get(index)).substring(1));
				} else if(((change.get(index)).substring(0, 1)).equals("-")) {
					bessie -= Integer.valueOf((change.get(index)).substring(1));
				}
			} else if((name.get(index)).equals("Elsie")) {
				if(((change.get(index)).substring(0, 1)).equals("+")) {
					elsie += Integer.valueOf((change.get(index)).substring(1));
				} else if(((change.get(index)).substring(0, 1)).equals("-")) {
					elsie -= Integer.valueOf((change.get(index)).substring(1));
				}
			}
			
			
			if(mildred >= bessie && mildred >= elsie) {
				m = true;
			} else if(mildred <= bessie || mildred <= elsie) {
				m = false;
			}
			
			if(bessie >= mildred && bessie >= elsie) {
				b = true;
			} else if(bessie <= mildred || bessie <= elsie) {
				b = false;
			}
			
			if(elsie >= bessie && elsie >= mildred) {
				e = true;
			} else if(elsie <= bessie || elsie <= mildred) {
				e = false;
			}
			
			if(m != mOld || b != bOld || e != eOld) {
				changeCount++;
			}
			
		}
		
//		System.out.println(changeCount);
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("measurement.out")));
		out.print(changeCount);
		out.close();
		
	}
}
