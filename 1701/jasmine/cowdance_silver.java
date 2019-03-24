//Jasmine Zhag
//All cases passed in 1 hour
//Needed one additional test case
import java.util.*;
import java.io.*;
public class cowdance {
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("cowdance.in"));
		int n = scan.nextInt();
		int maxT = scan.nextInt();
		
		int [] dances = new int [n];
		for (int i = 0; i < n; i++) {
			dances[i] = scan.nextInt();
		}
		
		
		ArrayList <Integer> stage = new ArrayList <Integer>();
		
	
		stage.add(dances[0]);
		for (int i = 1; i < n; i++) {
			int time = dances[i];
			int lowest = stage.get(0);
			if (time + lowest <= maxT) {
				stage.remove(0);
				int newTotal = time + lowest;
				int index = binarySearch (0, stage.size()-1, newTotal, stage);
				stage.add(index,newTotal);
			}
			else {
				
				int currentSize = stage.size();
				//forgot to reset the stage every time a current size doesn't work the first time
				stage.clear();
				for (int j = 0; j < currentSize+1; j++) {
					stage.add(dances[j]);
					
				}
				
				Collections.sort(stage);
				i = currentSize;
			}
			
		}
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowdance.out")));
		out.println(stage.size());
		
		out.close();
		scan.close();
		
	}
	
	public static int binarySearch (int b, int e, int num, ArrayList<Integer> array) {
		int m = (b+e)/2;
		if (b > e)
			return b;
		if (array.get(m) == num)
			return m;
		if (array.get(m) < num)
			return  binarySearch (m+1, e, num, array);
		if (array.get(m) > num)
			return  binarySearch (b, m-1, num, array);
		return -1;
	}
}
