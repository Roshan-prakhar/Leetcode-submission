class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sze=nums.size();
        int i=0;
        int cand=-1;
        int cnt=0;
        while(i<sze)
      {
         if(cnt==0)
         {
            cand=nums[i];
            cnt=1;
            i++;
         }
         else if(cand==nums[i])
         {
             cnt++;
             i++;
         }
         else{
            cnt--;
            if(cnt==0)
            {
                cand=nums[i];
                cnt=1;
              
            }
            i++;
         }
      }

      cnt=0;
      for(int i=0;i<sze;++i)
      {
        if(nums[i]==cand) {
            cnt++;
        }
      }
        return cnt>sze/2 ? cand:-1;
    }
};