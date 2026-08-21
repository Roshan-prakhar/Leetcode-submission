class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int>dp(n+1,1);
        for(int i=0;i<nums.size();++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
    int ans=0;
    for(int i=0;i<dp.size();++i)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
        
    }
};