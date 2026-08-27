class Solution {
public:
    bool solve(string s,int idx,set<string>&st,vector<int>&dp)
    {
         if(idx>=s.size()) return 1;
        if(dp[idx]!=-1) return dp[idx];
         string temp;
         for(int i=idx;i<s.size();++i)
         {
            temp.push_back(s[i]);
            if(st.count(temp)!=0)
            if(solve(s,i+1,st,dp)) return dp[idx]=true;
         }
         return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wd) {
        int sze=s.size();
       set<string>st;
       for(string x : wd) st.insert(x);
       vector<int>dp(sze+1,-1);
       return solve(s,0,st,dp);



        
    }
};