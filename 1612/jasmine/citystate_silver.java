//Jasmine Zhang
//All cases passed, looked at solution
import java.util.*;
import java.io.*;
public class citystate {
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("citystate.in"));
		int n = scan.nextInt();
		
		HashMap <String, Integer> map = new HashMap <String, Integer>();
		for (int i = 0; i < n; i++) {
			String citystate = scan.next().substring(0,2) + scan.next();
			if (citystate.substring(0, 2).equals(citystate.substring(2)))
				continue;
			if (map.containsKey(citystate)) 
				map.put(citystate, map.get(citystate)+1);
			else
				map.put(citystate, 1);
		}
		
		int count = 0;
		for (String key : map.keySet()) {
			String s = key.substring(2) + key.substring(0,2);
			if (map.containsKey(s))
				count += map.get(s)*map.get(key);
		}
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("citystate.out")));
		out.println(count/2);
		
		
		
		out.close();
		scan.close();
	}
	public static String hash (String s1, String s2) {
		if (s1.compareTo(s2) < 0)
			return s1 + s2;
		else
			return s2+ s1;
	}
}
