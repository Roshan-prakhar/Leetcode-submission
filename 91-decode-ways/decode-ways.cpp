class Solution {
public:
    int numDecodings(string s) {
        int sze=s.size();
      // DP[j] -> means how many after processing j-1 elements
      // ans = DP[sze];
    vector<int>dp(sze+1,0);
    dp[0]=1;
    for(int j=0;j<s.size();++j)
    {
        // one char string 
       if(s[j]=='0') continue;

        dp[j+1]+=dp[j];
        if(j+2<=sze && ( s[j]=='1'|| (s[j]=='2' && s[j+1]<='6')))
        {
            dp[j+2]+=dp[j];
        }
    }

   return dp[sze];

        
    }
};