class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int sze=coins.size();
        vector<int>dp(amt+1,1e9);
        dp[0]=0;
        for(int i=1;i<=amt;++i)
        {
            for(int j=0;j<sze;++j)
            {
                if(coins[j]<=i)
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }

    return dp[amt]==1e9? -1:dp[amt];
        
    }
};