class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
            int sze=nums.size();
        set<int>st;
        for(int i=0;i<nums.size();++i)
        {
            st.insert(nums[i]);
        }
        int cnt=0;
        int ans=0;
        for(auto num : st)
        {
            int prev=num-1;
            if(st.count(prev)!=0) continue;
            int cnt=1;
            while(true)
            {
                int x=num+1;
                if(st.count(x)!=0)
                {
                    cnt++;
                    num=x;
                }
                else
                {
                    ans=max(ans,cnt);
                    break;
                } 
            }
        }
        
        return ans;

    }
};