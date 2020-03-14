/*
 * Harrison Zhang
 * Time: 22:44.88
 * 2018-12 USACO OldCode.Bronze Test 1
 */

package com.bronze.dec2018;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class mixmilk {

	public static void main(String[] args) throws IOException {
		for (int j = 0; j < 10; j++) {
			int m1 = -1, m2 = -1, m3 = -1;
			try (BufferedReader br = new BufferedReader(new FileReader("/Users/hszhang/Downloads/mixmilk_bronze_dec18/" + (j+1) + ".in"))) {
	            	String quant1 = br.readLine();
	        		String quant2 = br.readLine();
	        		String quant3 = br.readLine();
	        		int space1 = quant1.indexOf(" ");
	        		int space2 = quant2.indexOf(" ");
	        		int space3 = quant3.indexOf(" ");
	        		
	        		int c1 = Integer.valueOf(quant1.substring(0,space1));
	        		int c2 = Integer.valueOf(quant2.substring(0,space2));
	        		int c3 = Integer.valueOf(quant3.substring(0,space3));
	        		
	        		m1 = Integer.valueOf(quant1.substring(space1+1));
	        		m2 = Integer.valueOf(quant2.substring(space2+1));
	        		m3 = Integer.valueOf(quant3.substring(space3+1));
	        		
	        		for(int i = 0; i < 100; i++) {
	        			if(i % 3 == 0) {
	        				if((c2 - m2) > m1) {
	        					m2 += m1;
	        					m1 = 0;
	        				} else {
	        					m1 -= (c2 - m2);
	        					m2 = c2;
	        				}
	        			}
	        			else if(i % 3 == 1) {
	        				if((c3 - m3) > m2) {
	        					m3 += m2;
	        					m2 = 0;
	        				} else {
	        					m2 -= (c3 - m3);
	        					m3 = c3;
	        				}
	        			} else {
	        				if((c1 - m1) > m3) {
	        					m1 += m3;
	        					m3 = 0;
	        				} else {
	        					m3 -= (c1 - m1);
	        					m1 = c1;
	        				}
	        			}
	        		}
	        		
			}
    			System.out.println("Output "+ (j+1) +"\n" + m1 + "\n" + m2 + "\n" + m3);
    			try (BufferedReader br = new BufferedReader(new FileReader("/Users/hszhang/Downloads/mixmilk_bronze_dec18/" + (j+1) + ".out"))){
    				int o1 = Integer.valueOf(br.readLine());
    				int o2 = Integer.valueOf(br.readLine());
    				int o3 = Integer.valueOf(br.readLine());
    				
//    				System.out.println("Output " + (j+1) + "\n" + br.readLine() +"\n"+ br.readLine() +"\n"+ br.readLine());
    				if (o1 != m1 || o2 != m2 || o3 != m3) {
    					System.out.println("Output " + (j+1) + " is wrong.");
    				}
    			}
			
		}
	}

}
