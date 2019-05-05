/*
40 mins
Runtime: 12 ms, faster than 88.33% of C++ online submissions for Two Sum.
Memory Usage: 10.7 MB, less than 10.87% of C++ online submissions for Two Sum.

Had some experiences trying to figure out how C++ maps and vectors worked.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]=i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target-nums[i])!=map.end()) {
                   if (map[target-nums[i]] != i) {
                      vector<int> ans{i,map[target-nums[i]]};
                      return ans;
                }
            }
        }
        return {1};
    }
};