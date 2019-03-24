//Jasmine Zhang
//All cases passed, looked at solution
//Time :(
import java.util.*;
import java.io.*;
public class haybales {
	static int [] bales;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("haybales.in"));
		int n = scan.nextInt();
		int q = scan.nextInt();
		
		bales = new int [n];
		for (int i = 0; i < n; i++) {
			int num = scan.nextInt();
			bales[i] = num;
		}
		Arrays.sort(bales);
		System.out.println(Arrays.toString(bales));
		
		
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("haybales.out")));
		//System.out.println(count);
		
		for (int i = 0; i < q; i++) {	
			int b = scan.nextInt();
			int e = scan.nextInt();
			int whole = binarySearch(e,0,n-1);
			int begin = binarySearch(b-1,0,n-1);
			
			out.println(whole-begin);
		}
		
		//System.out.println(binarySearch(6, 0, n-1));
		
		
		scan.close();
		out.close();
	
	}
	public static int binarySearch (int num, int b, int e) {
		int m = (b+e)/2;
		if (num < bales[0])
			return -1;
		if (num == bales[m])
			return m;
		if (b > e) {
			
			
			return e;
		}
		if (num < bales[m])
			return binarySearch(num,b,m-1);
		if (num > bales[m])
			return binarySearch(num,m+1,e);
		return -1;
	}
	
}

