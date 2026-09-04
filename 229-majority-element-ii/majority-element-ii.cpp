class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        int cand1=INT_MIN;
        int cand2=INT_MIN;
        for(int j=0;j<nums.size();++j)
        {
            if(nums[j]==cand1)
            {
                cnt1++;
            }
            else if (nums[j]==cand2)
            {
                cnt2++;
            }
            else if(cnt1==0)
            {
                cand1=nums[j];
                cnt1=1;
            }
            else if(cnt2==0)
            {
                cand2=nums[j];
                cnt2=1;

            }
            else
            {
                cnt1--;
                cnt2--;
            }

        }

        cnt1=0;
        cnt2=0;
        for(int num:nums)
        {
            if(num==cand1 && num!=cand2)
            {
                cnt1++;
            }
            else if(num==cand2 && num!=cand1)
            {
                cnt2++;
            }
        }
        vector<int>ans;
        if(cnt1>(n/3)) ans.push_back(cand1);
        if(cnt2>(n/3)) ans.push_back(cand2);

        return ans;
    }
};