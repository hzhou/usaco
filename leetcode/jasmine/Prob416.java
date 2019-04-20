class Prob416 {
    public boolean canPartition(int[] nums) {
        return recurs (nums[0], 0, 1, nums);
    }
    public boolean recurs (int sum1, int sum2, int n, int [] nums) {
        if (nums.length == n)
            return sum1 == sum2;
        else {
            if (!recurs (sum1+nums[n], sum2, n+1, nums))
                return recurs (sum1, sum2+nums[n], n+1, nums);
            return true;
        }
        
    }
}