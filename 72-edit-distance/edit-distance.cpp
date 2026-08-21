class Solution {
public:
    int minDistance(string w1, string w2) {
        int m=w1.size();
        int n=w2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        //dp[i][j][1] -> match -> no need to do anything
        /// dp[i][j][0] -> NO match -> we have three options
        dp[0][0]=0;
        for(int i = 0; i < m; i++)
         dp[i+1][0] = i+1;

      for(int j = 0; j < n; j++)
        dp[0][j+1] = j+1;
        //edge case : if one is finished , talk about other one
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(w1[i]==w2[j])
                {
                    dp[i+1][j+1]=dp[i][j];
                }
                else
                {
                    dp[i+1][j+1]=min({dp[i+1][j]+1,dp[i][j+1]+1,dp[i][j]+1});
                }
            }
        }

       return dp[m][n];
        
    }
};