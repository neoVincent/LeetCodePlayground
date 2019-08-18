10_Regular_Expression_Matching.cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        // dp
        // dp(i,j): is mathch? s[0:i-1] and p[0:j-1]
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i = 0; i < n+1; i++)
        {
            for(int j = 1; j < m+1;j++)
            {
                // current element
                if (p[j-1] != '*' )
                    dp[i][j] = i && dp[i-1][j-1] && (p[j-1] == '.' || s[i-1] == p[j-1] );
                else 
                    dp[i][j] = (i && dp[i-1][j]  && (s[i-1] == p[j-2] || p[j-2] =='.')) || dp[i][j-2];
            }
        }
        
        // for(int i = 0; i < n+1; i++)
        // {
        //     for(int j =0; j < m+1; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n][m];
    }
};