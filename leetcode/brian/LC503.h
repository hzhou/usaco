/*
30 mins
##################
#Python attempt 1: (TIMES OUT)
##################
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        N=len(nums)
        ans=[0,]*N
        for i in range(N):
            flag = True
            for j in range(N):
                if nums[(i+j)%N] > nums[i]:
                    flag=False
                    ans[i]=nums[(i+j)%N]
                    break
            if flag:
                ans[i]=-1
        return ans
##################
#Python attempt 2: (NOTHING ACTUALLY CHANGED IT'S JUST CLEANUP)
##################
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        N=len(nums)
        ans=[-1,]*N
        for i in range(N):
            for j in range(N):
                if nums[(i+j)%N] > nums[i]:
                    ans[i]=nums[(i+j)%N]
                    break
        return ans
		
Runtime: 288 ms, faster than 11.01% of C++ online submissions for Next Greater Element II.
Memory Usage: 12 MB, less than 100.00% of C++ online submissions for Next Greater Element II.

Interestingly both Python programs didn't pass so I translated it into C++ which did.
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N,-1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (nums[(i+j)%N] > nums[i]) {
                    ans[i]=nums[(i+j)%N];
                    break;
                }
            }
        }
        return ans;
    }
};