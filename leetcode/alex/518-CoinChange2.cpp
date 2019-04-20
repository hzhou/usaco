class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[coins.size()+1][amount+1];
        dp[0][0] = 1;

        for(int i = 1; i < coins.size() + 1; i++)
        {
            dp[i][0] = 1;
            for(int j = 1; j < amount + 1; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(coins[i-1] <= j)
                {
                    dp[i][j] = dp[i][j] + dp[i][j - coins[i-1]];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};
