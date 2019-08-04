/**
 * Christopher Li
 * Time:
 * Notes:
 */
import java.io.*;
import java.util.Scanner;
public class billboard3 {
	public static void main(String[] args) throws IOException{
		Scanner s = new Scanner(new File("billboard.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("billboard.out"));
		
		Rectangle l = new Rectangle(s.nextInt(),s.nextInt(), s.nextInt(), s.nextInt());
		Rectangle c = new Rectangle(s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt());
		if(Rectangle.coversFully(l,c)) {
			pw.println(l.getArea() - l.intersection(c).getArea());
		}else pw.println(l.getArea());
		pw.close();
	}

	static class Rectangle{
		int x1;
		int x2;
		int y1;
		int y2;
		public Rectangle(int x1, int y1, int x2, int y2) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}
		public Rectangle intersection(Rectangle other) {
			int newX1 = Math.max(this.getX1(), other.getX1());
			int newY1 = Math.max(this.getY1(), other.getY1());
			int newX2 = Math.min(this.getX2(), other.getX2());
			int newY2 = Math.min(this.getY2(), other.getY2());
			return new Rectangle(newX1, newY1, newX2, newY2);
		}
		public static boolean coversFully(Rectangle l, Rectangle c) {
			if(((l.getX1()>=c.getX1() &&l.getX1() <=c.getX2())||l.getX2() >=c.getX1()&&l.getX2()<=c.getX2())&&(l.getY1()>=c.getY1()&&l.getY2()<=c.getY2()))return true;
			else if(((l.getY1()>=c.getY1() &&l.getY1() <=c.getY2())||l.getY2() >=c.getY1()&&l.getY2()<=c.getY2())&&(l.getX1()>=c.getX1()&&l.getX2()<=c.getX2()))return true;
			else return false;
			
		}
		public int getArea() {
			if(this.x2<this.x1)return 0;
			if(this.y2<this.y2)return 0;
			int L = this.x2 - this.x1;
			int W = this.y2 - this.y1;
			return L*W;
			
		}
		public int getX1() {
			return x1;
			
		}
		public int getX2() {
			return x2;
		}
		public int getY1() {
			return y1;
		}
		public int getY2() {
			return y2;
		}
		
	}
}
