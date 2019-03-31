import java.util.*;
import java.io.*;
public class art2 {
	//General idea: 
	//If a color appears between the two occurences of another color, it must be painted on top
	//like 1 2 1 
	
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("art2.in"));
		int n = scan.nextInt();
		
		int [] beg = new int [n+1];
		Arrays.fill(beg, n+2);
		int [] end = new int [n+1];
		Arrays.fill(end, -1);
		
		//need to added 0s (blank) at the ends 
		//to account for initially painting over the blank canvas
		//also to catch cases like 2 0 0 2 
		int [] colors = new int [n+2];
		
		//Arrays.fill(colors, -1); //-1 if not a beginning or an end
		//acutally need to care about non first or last appearances of a color
		colors[0] = 0;
		colors[n+1] = 0;
		beg[0] = 0;
		end[0] = n+1;
		
		for (int i = 0; i < n; i++) {
			int c = scan.nextInt();
			if (c == 0)
				continue;
			if (i+1 < beg[c]) 
				beg[c] = i+1;
			if (i+1 > end[c]) 
				end[c] = i+1;
			
			colors[i+1] = c;
		}
		
		//boolean[] b = new boolean [n+1];
		
		//Stores current color layers 
		//0 - bottomost layer
		//n - top layer 
		ArrayList <Integer> a = new ArrayList <Integer> ();
		
		int max = 0;
		
		//--------------------------------------
		//When a color appears in Moonet's painting 
		//A. It's the first appearance, starting a new layer of color 
		//	 on top of any other colors 
		//B. It's the last occurence, any color painted after can't be on top of that color
		//   so remove from layer of colors 
		//C. Other - has to be from the top layer or else it can't be painted by Moonet
		
		//if the colors appear in 1 2 1 2 
		//then Moonet can't paint
		//if colors appear in 1 2 1 2 1
		//then Moonet can't paint
		//code fails if I only care about first and last appears of a color
		
		for (int i = 0; i < n+2; i++) {
			int c = colors[i];
			
			
			//Case A
			if (i == beg[c]) {
				a.add(c);
				//System.out.println(a);
				//System.out.println(a.size()-1);
				int l = a.size()-1;
				
				max = Math.max(max, l);
			
				
				
			}
			//Case C
			if (a.get(a.size()-1) != c) {
				//System.out.println(c + "-" + i);
				max = -1;
				break;
			}
			
			//Case B
			if (i == end [c]) {
				a.remove(a.size()-1);
				//continue;
			}
			//System.out.println(max + "?");
			//System.out.println(a);
			
			
		}
		//max = Math.max(max, a.size());
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("art2.out")));
		System.out.println(max);
		out.println(max);
		
	
		out.close();
		scan.close();
	}

}
