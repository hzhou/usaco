class Prob300 {
    static int max = 0;
    public int lengthOfLIS(int[] nums) {
        max = 0;
        //int [] arr = {-2,-1};
        recur (0,0,nums,0);
        return max;
        /*
        int [][] sequence = new int [nums.length+1][nums.length+1];
        //int [][] maxV = new int [nums.length][nums.length];
        //[length][max value Index]
        //sequence[0][0] = 0;
        for (int i = 0; i < nums.length; i++) { 
            sequence[i][i] = 1;
        }
        
        for (int i = 0; i <= nums.length; i++) { 
            for (int j = 0; j <= i; j++) {
                if (nums[i] < )
            }
        }
        */
        
    }
    public void recur (int currentMax, int i, int [] nums, int l) {
       // System.out.println(-1<-2);
        if (i == nums.length) {
            //System.out.println(l);
            max = Math.max(max, l);
            return;
        }
        //System.out.println(currentMax + " " + nums[i]);
        if (i == 0 || nums[i] > currentMax) {
            //System.out.println(nums[i] + " " + l);
            recur(nums[i], i+1, nums, l+1);
        }
        recur(currentMax, i+1, nums, l);
    }
    
    /*
    public int lengthOfLIS(int[] nums) {
        Integer [] p = new Integer [nums.length];
        Integer [] p2 = new Integer [nums.length];
        for (int i = 0; i < nums.length; i++) {
            p[i] = i;
            p2[i] = i;
        }
        Arrays.sort(p, new Comparator <Integer> () {
            public int compare (Integer i1, Integer i2) {
                return nums[i1] - nums[i2];
            }
        });
        System.out.println(Arrays.toString(p));
        
        Arrays.sort(p2, new Comparator <Integer> () {
            public int compare (Integer i1, Integer i2) {
                return p[i1] - p[i2];
            }
        });
        System.out.println(Arrays.toString(p2));
        
        int [] BIT = new int [nums.length+1];
        int [] longest = new int [nums.length+1];
        for (int i = 0; i < nums.length; i++) {
            add(BIT, p2[i]+1, 1);
            longest[i] = sum(BIT, p[i]+1);
            System.out.println(Arrays.toString(BIT));
            System.out.println(Arrays.toString(longest));
        }
        
        Arrays.sort(longest);
        return longest[nums.length-1];
        //return -1;
    }
    public static void add(int [] BIT, int index, int v) {
		for (int i = index; i <= BIT.length; i+= i & -i) {
			BIT[i] += v;
		}
	}
	
	public static int sum (int [] BIT, int index) {
		int sum = 0;
		for (int i = index; i > 0; i -= i & -i) {
			sum += BIT[i];
		}
		return sum;
	}
    */
}