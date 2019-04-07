
/*
Bill Zheng
// 1 hour
// I tried to work inside out by seeing if she could break the haybale to the right or left of her and then moving on from there.
 * Didn't have a lot of time to debug my code. I don't know why my solution doesn't fully work.
Trials: **xxxxxxxxxxxx
 */

import java.io.*;
import java.util.*;

class Haybales implements Comparable <Haybales>{
	public int size, pos;
	public Haybales(int s, int p) {
		this.size = s;
		this.pos = p;
	}
	public int compareTo(Haybales h) {
		return this.pos - h.pos;
	}
}

public class trapped {
	public static void main(String[] args) throws IOException {
		//Scanner scan = new Scanner(new File("D:\\eclipse-workspace\\USACO\\Silver\\testSilver.txt"));
		Scanner scan = new Scanner (new File ("trapped.in"));
//--------------------------------------------------------------------------------------------------------------------------
		int N = scan.nextInt();
		int B = scan.nextInt();
		Haybales[] H = new Haybales[N];
		for (int i = 0; i < N; i++) {
			H[i] = new Haybales(scan.nextInt(),scan.nextInt());
		}
		Arrays.sort(H);
//-----------Find right and left haybales to Bessie---------------------------------------------------------------------------------------------------
		int left = 0;
		int right = 0;
		int ret = Integer.MAX_VALUE;
		for (int i = 0; i < N; i++) {
			if (B - H[i].pos >= 0) {
				left = i;
			} else if (B - H[i].pos < 0) {
				right = i;
				break;
			}
		}
		System.out.println("Left: " + left + "; Right: " + right);
		//see if left and right are breakable
		boolean lbreak = false;
		boolean rbreak = false;
		while (true) {
			lbreak = false;
			rbreak = false;
			int D = H[right].pos - H[left].pos;
			if (D > H[right].size) {
				rbreak = true;
			}
			if (D > H[left].size) {
				lbreak = true;
			}
			//if both are breakable, move over one haybale.
			if (rbreak == true && lbreak == true) {
				if (left == 0 && right == N-1) {
					ret = -1;
					break;
				}
				if (H[right].size > H[left].size) {
					if (left-1 < 0) {
						right ++;
					} else {
						left--;
					}
				} else {
					if (right + 1 > N-1) {
						left --;
					} else {
						right++;
					}
				}
			} else { //if they are not breakable, find the return value and move over haybales respectively
 				if (lbreak == false && rbreak == false) {
					//ret = 0;
					break;
				}
				if (lbreak == true) {
					ret = Math.min(D - H[left].size, ret);
					if (left-1 < 0) {
						break;
					} else {
						left--;
					}
				}
				if (rbreak == true) {
					ret = Math.min(D - H[right].size, ret);
					if (right+1 > N-1) {
						break;
					} else {
						right++;
					}
				}
			}
			System.out.println(ret);
			System.out.println("Left: " + left + "; Right: " + right);
		}
//--------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------------
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("trapped.out")));
		System.out.println(ret);
		out.println(ret);

		out.close();
		scan.close();
	}
}
