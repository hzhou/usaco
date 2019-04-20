class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int arr[amount + 1];
        for(int i = 0; i < amount + 1; i++)
        {
            arr[i] = -1;
        }
        arr[0] = 0;
        int min;
        for(int i = 1; i < amount + 1; i++)
        {
            min = 99999;
            for(int j = 0; j < coins.size(); j++)
            {
                if(i - coins[j] >= 0)
                {
                    if(arr[i-coins[j]] + 1 < min and arr[i-coins[j]] != -1)
                    {
                        min = arr[i-coins[j]] + 1;
                    }
                }
            }
            if(min != 99999)
            {
                arr[i] = min;
            }
        }
        return arr[amount];
    }
};

