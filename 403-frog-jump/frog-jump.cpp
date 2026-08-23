class Solution {
public:
    bool canCross(vector<int>& s) {
        int sze=s.size();
        if(sze==1) return 0;

        //dp[i][j] -> I can reach i stone with j jumps
        unordered_map<int,unordered_set<int>>dp;
        for(int i=0;i<sze;++i)
        {
            dp[s[i]]={};
        }
        dp[0].insert(0);
        for(int i=0;i<sze;++i)
        {
            int pos=s[i];
            for(int jump : dp[pos])
            {
                for(int j=jump-1;j<=jump+1;++j)
               {
            
                 if(j<=0) continue;
                 int next=j+pos;
                 if(next==s[sze-1]) return true;
                 if(dp.find(next)!=dp.end())
                 dp[next].insert(j);

               }
            }
        }
          

          return false;
    

        
    }
};