
import java.util.*;
import java.io.*;

public class sleepy {
	static int N;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("sleepy.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sleepy.out")));
		//Scanner scan = new Scanner (new File ("10.in"));
		//PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
		//read in input
		N = scan.nextInt();
		int [] a = new int[N];
		LinkedList<Integer> sorted = new LinkedList<Integer>();
		int i, j, k;
		for (i = 0; i < N; i++)
			a[i] = scan.nextInt();
		sorted.add(a[N-1]);
		for (i = N-2; i >= 0; i--) {
			if (a[i] < a[i+1]) sorted.add(0,a[i]);
			else break;
		}
		//System.out.println(sorted);
		int min = N - sorted.size();
		int [] res = new int[min];
		j = 0;
		for (i = 0; i < min; i++) {
			k = binarySearch(a[i], sorted); //where to insert
			sorted.add(k, a[i]);
			res[j] = min - j + k - 1;
			j++;
		}
		out.println(min);
		
		for (i = 0; i < min; i++) {
			out.print(res[i]);
			if (i != min-1)
				out.print(" ");
		}
		for (;i < N-1; i++) {
			out.print(0);
			if (i != N-1)
				out.print(" ");
		}
		out.println();
		out.close();
	}
	
	public static int binarySearch(int v, LinkedList<Integer> list) {
		int i, low = 0, high = list.size()-1,mid = (low+high)/2;
		while (low <= high) {
			if (v < list.get(mid)) high = mid-1;
			else if ( v > list.get(mid)) low = mid+1;
			else return mid; //shouldn't be here
			mid = (low + high) / 2;
		}
		return low;
	}
}

