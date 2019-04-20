class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Canonicalize Parameters
        int N=coins.size();
        // Deal with corner case first
        if(N==0){
            if(amount==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        // DP
        int dp[N][amount+1];
        // One way to make 0 amount
        dp[0][0]=1;
        // Deal with first row
        for(int j=1; j<=amount; j++){
            if (j % coins[0]==0){
                dp[0][j]=1;
            }
            else {
                dp[0][j]=0;
            }
        }
        // Recurrence
        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j <= amount; j++)
            {
                dp[i][j]=0;
                for(int k=0; j-k*coins[i]>=0; k++){
                    if (dp[i-1][j-k*coins[i]]>0){
                        dp[i][j]+=dp[i-1][j-k*coins[i]];
                    }
                }
            }
        }
        return dp[N-1][amount];
    }
};
