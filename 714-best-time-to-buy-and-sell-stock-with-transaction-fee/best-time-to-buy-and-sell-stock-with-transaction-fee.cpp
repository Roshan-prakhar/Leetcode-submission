class Solution {
public:
const int NEG=-1e9;
    int maxProfit(vector<int>& p, int fee) {
        int sze=p.size();
        if(sze==0) return 0;
        // dp[i][0] ->  maximum profit after processing i-1 th day. and not holding any stock
        // dp[i][1]-> max profit after processing i-1 th day, holding a stock;
        vector<vector<int>>dp(sze+1,vector<int>(3,NEG));
        dp[0][0]=0;
        for(int i=0;i<sze;++i)
        {
            dp[i+1][0]=max(dp[i][0],dp[i][1]+p[i]);
            dp[i+1][1]=max(dp[i][0]-p[i]-fee,dp[i][1]);
        }
        return max(dp[sze][0],dp[sze][1]);
        
    }
};