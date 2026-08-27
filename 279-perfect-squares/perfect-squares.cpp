class Solution {
public:
    // vector<int>primes;
    // vector<int>spf(1e4,-1);
    // spf[0]=0;
    // spf[1]=0;
    // for(int i=2;i<1e4;++i)
    // {
    //     if(spf[i]==-1)
    //     {
    //         for(int j=i*i;j<1e4;j+=i)
    //         {
    //            spf[j]=i;
    //         }
    //     }
    // }
    // for(int i=2;i<spf.size();++i) 
    // {
    //     if(spf[i]==-1) primes.push_back(i);
    // }
    int numSquares(int n) {
        vector<int>dp(n+1,1e9);
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j*j<=i;++j)
            {
                  dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        
        return dp[n];
    }
};