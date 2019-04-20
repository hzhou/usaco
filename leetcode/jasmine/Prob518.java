class Prob518 {
    //classic dynamic programming problem 
    public int change(int amount, int[] coins) {
        int [] total = new int [amount+1];
        total[0] = 1;
        for (int i = 0; i < coins.length; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                total[j] += total[j-coins[i]];
            }
            //System.out.println(Arrays.toString(total));
        }
        return total[amount];
    }
}