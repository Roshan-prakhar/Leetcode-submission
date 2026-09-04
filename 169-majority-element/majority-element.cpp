class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sze=nums.size();
        int cand=0;
        int cnt=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==cand)
            {
                cnt++;
            }
            else if(cnt==0)
            {
                cand=nums[i];
                cnt=1;
            }
            else{
                cnt--;
            }
        }

        cnt=0;
        for(int i=0;i<sze;++i)
        {
            if(cand==nums[i])
            {
                cnt++;
            }
        }
        return cnt>sze/2 ? cand:-1;
        
    }
};