
class Solution {
public:
    vector<vector<int>> answer;
    vector<vector<int>> permute(vector<int>& nums) {
        permute1(nums, 0, nums.size() - 1);
        return answer;
    }
    void permute1(vector<int>& nums, int start, int end) {
        if(start == end)
        {
            answer.push_back(nums);
        }
        int temp1, temp2;
        for(int i = start; i < end + 1; i++)
        {
            temp1 = nums[i];
            temp2 = nums[start];
            nums[i] = temp2;
            nums[start] = temp1;
            permute1(nums, start + 1, end);
            nums[i] = temp1;
            nums[start] = temp2;
        }
    }
};
