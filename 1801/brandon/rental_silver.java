import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;

/*
ID: fireblaze
LANG: JAVA
TASK: rental
 */

//Name: Brandon Zhang
//Time: 2 hours
//10/10 passed
//Notes: I used help from the official USACO solution and wrote my own code based on their explanation

public class rental {
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\rental.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\rental.out.txt"));
		Scanner input = new Scanner(new File("rental.in"));
		FileWriter fileWriter = new FileWriter(new File("rental.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		int N = input.nextInt();
		int M = input.nextInt(); //amount of stores
		int R = input.nextInt(); //amount of renters
		
		//collects data and sorts them all in highest to lowest order
		Integer[] gallonsProduced = new Integer[N];
		for(int i=0; i<N; i++) {
			gallonsProduced[i] = input.nextInt();
		}
		Arrays.sort(gallonsProduced, Collections.reverseOrder());
		Store[] stores = new Store[M];
		for(int i=0; i<M; i++) {
			int a = input.nextInt();
			int b = input.nextInt();
			stores[i] = new rental.Store(a, b);
		}
		Arrays.sort(stores, Collections.reverseOrder());
		Integer[] rentals = new Integer[R];
		for(int i=0; i<R; i++) {
			rentals[i] = input.nextInt();
		}
		Arrays.sort(rentals, Collections.reverseOrder());

		//selling milk to the stores
		long[] result = new long[N+1]; //value is how much you would earn by milking index cows
		int index = 0; //index is for looping through the stores
		for(int i=0; i<N; i++) {
			//carries previous purchases on for next loop
			result[i+1] = result[i];
			//loops until all the stores are taken up or cow runs out of milk
			while(index < M && gallonsProduced[i] > 0) {
				//chooses either the amount the cow can produce or how much the store wants, whichever one ends first
				int use = Math.min(gallonsProduced[i], stores[index].gallons);
				//adds the cost to result
				result[i+1] += use * (long)stores[index].centsPerGallon;
				//decrements both the cow's amount and the store's wanted amount
				gallonsProduced[i] -= use;
				stores[index].gallons -= use;
				//once the store is satisfied move on
				if(stores[index].gallons <= 0) {
					index++;
				}
			}
		}
		
		//renting cows
		int index2 = N-1; //for placing the sum in the result
		int rentalIndex = 0; //for looping through the rentals
		long sum = 0;
		//loops in reverse, n - index cows rented out at each index
		while(index2 >= 0 && rentalIndex < R) {
			sum += rentals[rentalIndex];
			result[index2] += sum;
			rentalIndex++;
			index2--;
		}
		
		//finds largest possible one
		long ret = 0;
		for(long out: result) {
			ret = Math.max(ret, out);
		}
		
		printWriter.println(ret);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
	private static class Store implements Comparable<Store>{
		int gallons;
		int centsPerGallon;
		public Store(int g, int c) {
			gallons = g;
			centsPerGallon = c;
		}
		//sorts stores based on price per gallon 
		public int compareTo(Store s) {
			return centsPerGallon - s.centsPerGallon;
		}
	}
}
