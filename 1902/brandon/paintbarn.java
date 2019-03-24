package competitionProblems;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/*
ID: fireblaze
LANG: JAVA
TASK: paintbarn
 */

public class paintbarn {
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\paintbarn.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\paintbarn.out.txt"));
		Scanner input = new Scanner(new File("paintbarn.in"));
		FileWriter fileWriter = new FileWriter(new File("paintbarn.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
	
		int n = input.nextInt();
		int k = input.nextInt();
		ArrayList<Rectangle> points = new ArrayList<Rectangle>();
		for(int i=0; i<n; i++) {
			int x1 = input.nextInt();
			int y1 = input.nextInt();
			int x2 = input.nextInt();
			int y2 = input.nextInt();
			points.add(new Rectangle(x1, y1, x2, y2, (x2-x1) * (y2-y1), 1));
		}
		
		//too slow, find a faster solution
		for(int p=1; p<=k; p++) {
			//find overlapping points and turn them into new rectangles
			for(int i=0; i<points.size()-1; i++) {
				for(int j=i+1; j<points.size(); j++) {
					Rectangle r1 = points.get(i);
					Rectangle r2 = points.get(j);
					if(r1.paint == p && r2.paint == p) { 
						if(r1.x1 < r2.x1 && r1.x2 > r2.x2 && r1.y2 > r2.y2 && r2.y1 > r1.y1) {//if r2 is inside r1
							int area = r2.area;
							r2.paint++;
							r1.area -= area;
						}
						else if(r2.x1 < r1.x1 && r2.x2 > r1.x2 && r2.y2 > r1.y2 && r2.y1 < r1.y1) {//if r1 is inside r2
							int area = r1.area;
							r1.paint++;
							r2.area -= area;
						}
						else if((r1.x2 > r2.x1) && (r1.y2 > r2.y1)) { //if they intersect normally
							int area = ((r1.x2 - r2.x1) * (r1.y2 - r2.y1));
							points.add(new Rectangle(r2.x1, r2.y1, r1.x2, r1.y2, area, p+1));
							r1.area -= area;
							r2.area -= area;
						}
					}
				}
			}
		}
		
		int result = 0;
		for(int i=0; i<points.size(); i++) {
			if(points.get(i).paint == k) {
				result += points.get(i).area;
			}
		}
		
		System.out.println(result);
		//printWriter.println(result);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
	
	private static class Rectangle {
		int x1, y1, x2, y2, area;
		int paint;
		public Rectangle(int x1, int y1, int x2, int y2, int a, int p) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
			area = a;
			paint = p;
		}
	}
}