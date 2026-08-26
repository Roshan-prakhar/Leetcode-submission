class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        // the boundary elements will always come in the partition
        // instead of checking for i+j, try to see elements opposite of a division
        // The entire problem is about consecutive nos pairs sum.
        // Do Dry run and find out
        // maximum = sum of k-1 maximum pairs sum
        // minimum = sum of k-1 minimum pairs sum
        int sze=w.size();
        vector<int>v;
        for(int i=0;i<w.size()-1;++i)
        {
             v.push_back(w[i]+w[i+1]);
        }
        sort(v.begin(),v.end());
        long long max_sum=w[0]+w[w.size()-1];
        long long min_sum=w[0]+w[w.size()-1];
        int cnt=0;
        for(int i=0;i<v.size() && cnt<k-1;++i)
       {
          min_sum+=v[i];
          cnt++;
       }
       cnt=0;
        for(int i=v.size()-1;i>=0 && cnt<k-1;--i)
       {
          max_sum+=v[i];
          cnt++;
       }
    
       return (max_sum-min_sum);

      
   
    }
};