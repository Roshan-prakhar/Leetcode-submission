class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sze=nums.size();
        unordered_map<int,int>hash;
        for(int i:nums) hash[i]++;
        int num=-1;
        for(auto it : hash)
        {
            if(hash[it.first]==1) {
                num=it.first;
                break;
            }
        }
        return num;

    }
};