class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int sze=intervals.size();
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int i=0;
        int j=1;
        while(j<sze)
        {
           int l=intervals[i][1];
           int r=intervals[j][0];
           if(r<l)
           {
               cnt++;
               intervals[j][0]=max(intervals[i][0],intervals[j][0]);
               intervals[j][1]=min(intervals[i][1],intervals[j][1]);
               
           }
            i=j;
            j++;
        }
        return cnt;
    }
};
// [1,2] [2,3] [3,4] [1,3]
// [1,2] [1,3] [2,3] [3,4] 
// [1,2] [2,3] [3,4]
// [1,100] [11,22] [1,11] [2,12] 
// ->[1,11] [1,100] [2,12] [11,22] -> [1,11] [2,12] [11,22]
// -> [2,11] [11,22] ->