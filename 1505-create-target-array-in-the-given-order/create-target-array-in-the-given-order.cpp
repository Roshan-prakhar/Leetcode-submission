class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int sze=nums.size();
        vector<int>ans;
        for(int i=0;i<sze;++i)
        {
            ans.push_back(0);
            //adding a zero will simply increase vector space by one 
            // and i can start from the end and shift values to the right.
            for(int j=ans.size()-1;j>index[i];--j)
            {
                ans[j]=ans[j-1];
            }
            ans[index[i]]=nums[i];
        }
        return ans;
        
        return ans;
    }
};