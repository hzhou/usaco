//Jasmine Zhang
//December OldCode.Silver 2017 - Milk Measurement
//1 hour, 5/11 cases passed, other 6 has incorrect answer 

import java.util.*;
import java.io.*;
public class measurement {

	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		HashSet <Integer> mot = new HashSet <Integer> ();
		ArrayList <Integer> id = new ArrayList<Integer> ();
		HashMap <Integer, Integer> milk = new HashMap <Integer, Integer> ();
		//milk.
		Scanner scan = new Scanner (new File ("measurement.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("measurement.out")));
		int n = scan.nextInt();
		int g = scan.nextInt();
		int largest = g;
		Entry [] en = new Entry[n];
		for (int i = 0; i < n; i++)
		{
			int day = scan.nextInt();
			int ID = scan.nextInt();
			String a = scan.next();
			en[i] = new Entry (day, ID, a);
			//System.out.println(day + " " + ID + " " + a);
			if (!mot.contains(ID))
				id.add(ID);
			mot.add(ID);
			milk.put(ID, g);
		}
		Arrays.sort(en);
		
		Entry e0 = en[0];
		//System.out.println(e0);
		if (e0.add > 0)
		{
			largest = g + e0.add;
			milk.replace(e0.ID, largest);
			mot.clear();
			mot.add(e0.ID);
			
		}
		else
		{
			milk.replace(e0.ID, g + e0.add);
			mot.remove(e0.ID);
		}
		int count = 1;
		for (int i = 1; i < n; i++)
		{
			//System.out.println(count);
			Entry e = en[i];
			int newMilk = milk.get(e.ID) + e.add;
			milk.replace(e.ID, newMilk);
			//System.out.println(e);
			if (newMilk > largest)
			{
				largest = newMilk;
				if (mot.size() == 1 && mot.contains(e.ID))
					continue;
				else
				{
					mot.clear();
					mot.add(e.ID);
					count++;
				}
			}
			else if (newMilk == largest)
			{
				if (!mot.contains(e.ID))
				{
					mot.add(e.ID);
					count++;
				}
			}
			else
			{
				if (!mot.contains((e.ID)))
					continue;	
				else if (mot.size() > 1)
				{
					mot.remove(e.ID);
				}
				else
				{
					count++;
					mot.clear();
					largest = milk.get(id.get(0));
					mot.add(id.get(0));
					for (int j = 1; j < id.size(); j++)
					{
						int x = milk.get(id.get(j));
						if (x > largest)
						{
							largest = x;
							mot.clear();
							mot.add(id.get(j));
						}
						else if (x == largest)
						{
							mot.add(id.get(j));
						}
					}
				}
			}
			
			
		}
		//System.out.println(count);
		out.println(count);
		out.close();
		scan.close();
	}

	
}
class Entry implements Comparable 
{
	int day;
	int ID;
	int add;
	public Entry (int day, int ID, String a)
	{
		this.day = day;
		this.ID = ID;
		int x = Integer.parseInt(a.substring(1));
		if (a.charAt(0) == '-')
			x *= -1;
		add = x;
	}
	@Override
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		Entry e = (Entry) o;
		return day - e.day;
	}
	public String toString ()
	{
		return day + " " + ID + " " + add;
	}
}
/*
class Cow implements Comparable 
{
	int ID;
	int milk;
	public cow (int ID, int milk)
	{
		
	}
	@Override
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		return 0;
	}
	
}
*/
