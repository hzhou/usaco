//Jasmine Zhang
//February Bronze 2017 - circlecross
//20 minutes, all cases passed


import java.util.*;
import java.io.*;
public class circlecross {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner (new File ("circlecross.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("circlecross.out")));
		String s = scan.next();
		int i = 0;
		int count = 0;
		
		while (s.length() > 1)
		{
			char c = s.charAt(i);
			
			int begin = 0;
			int end = s.substring(1).indexOf(c)+1;
			
			String part = s.substring(begin+1, end);
			//System.out.println(part);
			count += cross(part);
			
			s = s.substring(1,s.substring(1).indexOf(c)+1) 
					+ s.substring(s.substring(1).indexOf(c)+2);
			//System.out.println(s + " " + c + " " + count);
		}
		
		//System.out.println(cross(s.substring(0, 5)));
		out.println(count);
		out.close();
		scan.close();
	}
	public static int cross (String s)
	{
		int i = 0;
		int count = 0;
		while (s.length() > 1)
		{
			char c = s.charAt(0);
			//System.out.println(s + " " + c);
			if (s.substring(1).indexOf(c) >= 0)
			{
				//System.out.println(s.substring(1).indexOf(c));
				s = s.substring(1,s.substring(1).indexOf(c)+1) 
						+ s.substring(s.substring(1).indexOf(c)+2);
				//System.out.println(s);
			}
			else
			{
				count++;
				s = s.substring(1);
			}
			//if ()
		}
		if (s.length() == 1)
			count++;
		return count;
	}
	public static String remove1 (String s, char c)
	{
		return "";
	}

}
