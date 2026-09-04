class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sze=nums.size();
        int BP=-1;
        for(int j=sze-2;j>=0;--j)
        {
            if(nums[j]<nums[j+1])
            {
                BP=j;
                break;
            }
        }
        if(BP==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int pos=-1;
        for(int i=nums.size()-1;i>BP;--i)
        {
            if(nums[i]>nums[BP])
            {
                pos=i;
                break;
            }
        }
        swap(nums[BP],nums[pos]);
        reverse(nums.begin()+BP+1,nums.end());
     

    }
};