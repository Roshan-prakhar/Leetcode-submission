class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      int n=nums.size();
      //rato mat
      // muje koi number mila maine usko uski shi jagah pr rak diya. 
      int j=0;
      int cnt=0;
      while(j<n)
      {
         int num=nums[j];
         int idx=num-1;
     if(nums[j]!=nums[idx]) // agr already no waha hai toh swap kyu krna 
     {
        swap(nums[j],nums[idx]);
     }
     else j++;
      } 

    vector<int>ans;
  for(int j=0;j<nums.size();++j)
  {
    int num=j+1;
    if(nums[j]!=num)
    ans.push_back(nums[j]);
  }
  return ans;
    }
};

