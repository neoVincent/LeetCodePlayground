Lint_77_Longest_Common_Subsequence.cpp
class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        int m = A.size();
        int n = B.size();
        if (!m || !n) return 0;
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if (A[i-1] == B[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

