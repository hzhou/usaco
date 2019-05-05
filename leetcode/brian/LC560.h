/*
25 mins
##################
#Python attempt 1: (TIMES OUT)
##################
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        N = len(nums)
        sums = N*[0,]
        sums[0] = nums[0]
        for i in range(1,N,1):
            sums[i] = nums[i]+sums[i-1]
        count = 0
        for i in range(0,N+1,1):
            for j in range(0,N-i,1):
                if k == sums[j+i]-sums[j]+nums[j]:
                    count+=1
        return count
		
Runtime: 1212 ms, faster than 5.01% of C++ online submissions for Subarray Sum Equals K.
Memory Usage: 10.3 MB, less than 98.81% of C++ online submissions for Subarray Sum Equals K.

Ran into a heap buffer overflow that miraculously fixed itself? I should start directly writing C++...
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> sums(N,0);
        sums[0] = nums[0];
        for (int i = 1; i < N; i++) {
            sums[i] = nums[i]+sums[i-1];
        }
        int count = 0;
        for (int i = 0; i < N+1; i++) {
            for (int j = 0; j < N-i; j++) {
                if (k == sums[j+i]-sums[j]+nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};