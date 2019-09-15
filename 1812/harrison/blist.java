/*
 * Harrison Zhang
 * bucketCount won't work
 * Time: 3.5 hrs
 * 
 * */
package com.bronze.dec2018;

import java.util.*;

public class blist {
	public static void main(String[] args) {
		String inputN, placeholder;
		int firstSpace, secondSpace;
		
		int smallSi = 1001, bigTi = 0;
		int clock = 0, index = 0, time = 0, bucketCount = 0, removeCount = 0;
		
		Scanner keyboard = new Scanner(System.in);
		String input = keyboard.nextLine();
		int N = Integer.valueOf(input);

		List<Integer> listSi = new ArrayList<Integer>();
		List<Integer> listTi = new ArrayList<Integer>();
		List<Integer> listBi = new ArrayList<Integer>();
		List<Integer> listBiClone = new ArrayList<Integer>();
		List<Integer> endTimes = new ArrayList<Integer>();

		for(int i = 0; i < N; i++) {
			inputN = keyboard.nextLine();
			firstSpace = inputN.indexOf(" ");
			placeholder = inputN.substring(0, firstSpace);
			listSi.add(Integer.valueOf(placeholder));
			
			secondSpace = inputN.indexOf(" ", firstSpace+1);
			placeholder = inputN.substring(firstSpace+1, secondSpace);
			listTi.add(Integer.valueOf(placeholder));
			
			placeholder = inputN.substring(secondSpace + 1);
			listBi.add(Integer.valueOf(placeholder));
		}
		
		listBiClone.addAll(listBi);
		
		for(int i = 0; i < N; i++) {
			if(smallSi > listSi.get(i)) {
				smallSi = listSi.get(i);
			}
			if(bigTi < listTi.get(i)) {
				bigTi = listTi.get(i);
			}
		}

		while(clock <= bigTi) {
			if(!listSi.isEmpty()) {
				for(int j = 0; j < N; j++) {
					System.out.println(smallSi + " | " + listSi);
					index = listSi.indexOf(smallSi);
					bucketCount += listBi.get(index);
				}
	
				endTimes.add(listTi.get(index));
			}
			
			clock += 1;
			for(int i = 0; i < endTimes.size(); i++) {
				System.out.println(endTimes + "endtimes" + " clock "+ clock);
				if(clock == endTimes.get(i)) {
					bucketCount -= listBiClone.get(i);
					System.out.println("dkfd"+bucketCount);
				}
			}
			
			removeCount += 1;
			if(!listSi.isEmpty()) {
				listSi.remove(index);
				listTi.remove(index);
				listBi.remove(index);
				
				smallSi = 1001;

			}
			
			for(int i = 0; i < N-removeCount; i++) {
				if(smallSi > listSi.get(i)) {
					smallSi = listSi.get(i);
				}
			}
			System.out.println("clock of loop" + clock);
		}
		
		System.out.println(bucketCount);
		keyboard.close();
		
	}
}
