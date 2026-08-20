class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // a b a c 
        // c a b 
        // c a b a c 
        int m=str1.size();
        int n=str2.size();
        // dp[i][j][1] -> from the first i-1 chars of str1, and first j-1 chars of str2, I got the match
        // dp[i][j][0] -> from the first i-1 chars of str1, and first j-1 chars of str2, I got No match
         vector<vector<int>>dp(m+1,vector<int>(n+1,0));
         dp[0][0]=0;
         for(int i=0;i<str1.size();++i)
         {
            for(int j=0;j<str2.size();++j)
            {
                if(str1[i]==str2[j])
                {
                    dp[i+1][j+1]=1+dp[i][j];
                }
                else
                {
                   dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
         }
         // During Backtrack, jo bada tha usko include kr liya 
         int i=m;
         int j=n;
         string ans="";
         while(i>0 && j>0)
         {
              if(str1[i-1]==str2[j-1])
              {
                ans+=str1[i-1];
                i--;
                j--;
              }
              else
              {
                 if(dp[i-1][j]>dp[i][j-1])
                 {
                    ans+=str1[i-1];
                    i--;
                 }
                 else{
                    ans+=str2[j-1];
                    j--;
                 }
              }
         }
       // remaining parts of strings 
         while(i>0)
         {
            ans+=str1[i-1];
            i--;
         }
         while(j>0)
         {
            ans+=str2[j-1];
            j--;
         }


  reverse(ans.begin(),ans.end());
  return ans;


        
    }
};