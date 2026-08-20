class Solution {
public:
const int mod=1e9;
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<vector<long long>>> dp(
            m + 1, vector<vector<long long>>(n + 1, vector<long long>(2, 0))
        );
     //dp[i][j][0] -> no of ways till i-1 th and j-1th chars are processed and a match
     //dp[i][j][1] -> match

        dp[0][0][0] = 1;

        for (long long i = 0; i < m; ++i) {
            for (long long j = 0; j <= n; ++j) {
         
                dp[i + 1][j][0] += (dp[i][j][0] + dp[i][j][1])%mod;

                if (j < n && s[i] == t[j]) {
                    dp[i + 1][j + 1][1] += (dp[i][j][0] + dp[i][j][1])%mod;
                }
            }
        }

        long long ans = dp[m][n][0] + dp[m][n][1];

        return ans;
    }
};