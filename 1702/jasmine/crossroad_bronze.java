//Jasmine Zhang
//February 2017 OldCode.Bronze - crossroad
//5 minutes to clear all cases


import java.io.*;
import java.util.*;
public class crossroad {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner (new File("crossroad.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("crossroad.out")));
		int n = scan.nextInt();
		int [] cow = new int [10];
		Arrays.fill(cow, -1);
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			int id = scan.nextInt()-1;
			int pos = scan.nextInt();
			if (cow[id] == -1)
			{
				cow[id] = pos;
				continue;
			}
			if (cow[id] != pos)
			{
				count++;
				cow[id] = pos;
			}
		}
		out.println(count);
		
		scan.close();
		out.close();

	}

}
