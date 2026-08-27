class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        int sze=s.size();
        set<string>st;
        for(int i=0;i<wd.size();++i) st.insert(wd[i]);
        // leetcode
        // DP[i] -> means starting from (0.....i-1) could be matched or not
        // ans = DP[n]==true;
        vector<int>dp(sze+1,0);
        dp[0]=1;
        for(int i=1;i<=sze;++i)
        {
            for(int j=0;j<i;++j)
            {
                string temp=s.substr(j,i-j);
                if(dp[j]==1 && st.count(temp)!=0)
                {
                    dp[i]=true;
                }
            }
        }

        return dp[sze];

                
    }
};