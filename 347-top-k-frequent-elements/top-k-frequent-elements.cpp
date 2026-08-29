class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int K) {
     int sze=nums.size();

 priority_queue<pair<int,int>>pq;
 unordered_map<int,int>hash;
 for(int i=0;i<nums.size();++i)
 {
    hash[nums[i]]++;
 }
 for(auto it:hash)
 {
    int num=it.first;  int f=hash[it.first];
  
    pq.push({f,num});
 }
 vector<int>ans;
 int k=0;

 while(!pq.empty() && k<K)
 {
    auto it=pq.top();
    int x=it.second;
    pq.pop();
    k++;
    ans.push_back(x);
 }

return ans;


        
    }
};