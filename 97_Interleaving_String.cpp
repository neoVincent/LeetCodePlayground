97_Interleaving_String.cpp

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        
        if ( (m+n) != s3.size()) return false;
        
        vector<vector<bool>>dp(m+1, vector<bool>(n+1,false));
        dp[0][0] = true;
        
        for(int i = 0; i < m; i++)
        {
            dp[i+1][0] = (s1[i] == s3[i]) && dp[i][0];
        }
        
        for(int i = 0; i < n; i++)
        {
            dp[0][i+1] = (s2[i] == s3[i]) && dp[0][i];
        }
        
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                int index = i+j-1;
                dp[i][j] = (dp[i-1][j] && s3[index] == s1[i-1]) || (dp[i][j-1] && s3[index] == s2[j-1]);
            }
        }
        
        return dp[m][n];
    }
};
