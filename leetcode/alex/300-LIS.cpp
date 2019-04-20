class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        int answer = 0;
        int arr[nums.size()];
        arr[0] = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            arr[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    arr[i] = max(arr[i], arr[j] + 1);
                }
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if (arr[i] > answer)
            {
                answer = arr[i];
            }
        }
        return answer;
    }
};

