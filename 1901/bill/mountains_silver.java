
/*
ID: ml2963
Tests: **********x
Had to do this in two tries (two times writing the code), so I need to spend more time on the drawing board at
	the start.
 */

import java.io.*;
import java.util.*;

class mountains {
	public static void main(String[] args) throws IOException {
		// BufferedReader f = new BufferedReader(new
		// FileReader("D:\\eclipse-workspace\\USACO\\Silver\\testSilver.txt"));
		BufferedReader f = new BufferedReader(new FileReader("mountains.in"));

		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("mountains.out")));

		StringTokenizer st = new StringTokenizer(f.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = 2;
		int[] grid = new int[n * m];
		int k = 0;

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(f.readLine());
			for (int j = 0; j < m; j++) {
				grid[k] = Integer.parseInt(st.nextToken());
				k++;
			}
		}

		int ret = n;
		int max = 0;
		int maxx;
		int maxy = -1;
		int d = 0;
		while (maxy != 0) {
			maxx = 0;
			maxy = 0;
			for (int i = 0; i < n * m; i += 2) {
				if (grid[i] == -1) {
					continue;
				}
				if (grid[i + 1] > maxy) {
					maxy = grid[i + 1];
					maxx = grid[i];
					d = i;
				}
			}
			for (int i = 0; i < n * m; i += 2) {
				if (grid[i] == -1) {
					continue;
				}
				if (grid[i] < maxx) {
					int diff = maxx - grid[i];
					if ((maxx + maxy) - 2 * diff > grid[i] + grid[i + 1]) {
						ret--;
						grid[i] = -1;
						grid[i + 1] = -1;
					}
				} else {
					if (maxx + maxy > grid[i] + grid[i + 1]) {
						ret--;
						grid[i] = -1;
						grid[i + 1] = -1;
					}
				}
			}
			grid[d] = -1;
			grid[d + 1] = -1;
		}

		System.out.println(ret);

		out.println(ret);
		out.close();
	}
}
