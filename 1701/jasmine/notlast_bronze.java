//Jasmine Zhang
//All cases passed in 40 minutes 

import java.util.*;
import java.io.*;
public class notlast {
	
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("notlast.in"));
		int n = scan.nextInt();
		
		String [] names = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
		HashMap <String, Integer> NameToIndex = new HashMap <String, Integer> ();
		Cow [] milkTotals = new Cow [7];
		for (int i = 0; i < 7; i++) {
			NameToIndex.put(names[i], i);
			milkTotals[i] = new Cow (names[i]);
		}
		
		for(int i = 0; i < n; i++) {
			String name = scan.next();
			int milk = scan.nextInt();
			int index = NameToIndex.get(name);
			milkTotals[index].milk += milk;
		}
		
		
	
		
		Arrays.sort(milkTotals, new Comparator <Cow> () {
			public int compare (Cow c1, Cow c2) {
				return c2.milk-c1.milk;
			}
		});
		//System.out.println(Arrays.toString(milkTotals));
		
		int totalCows = 7;
		int smallest = milkTotals[totalCows-1].milk;
		int i = totalCows-2;
		
		while (i > 0 && milkTotals[i].milk == smallest)
			i--;
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("notlast.out")));

		if((i == 0 && milkTotals[i].milk == milkTotals[i+1].milk)||(i != 0 && milkTotals[i-1].milk == milkTotals[i].milk)) 
			out.println("Tie");
		else
			out.println(milkTotals[i].name);
		
		out.close();
		scan.close();
		
	}

}
class Cow {
	String name;
	int milk;
	Cow (String n) {
		name = n;
		milk = 0;
	}
	public String toString () {
		return name + " " + milk;
	}
}
