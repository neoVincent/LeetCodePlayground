Lint_440_BackpackIII.cpp
class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int mass) {
        int m = A.size();
        int n = mass;
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                dp[i][j] = dp[i-1][j];
                if (j >= A[i-1])
                {
                   dp[i][j] = max(dp[i][j],dp[i][j-A[i-1]]+V[i-1]);
                }
            }
        }
        
        return dp[m][n];        
    }
};

class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int mass) {
        int m = A.size();
        int n = mass;
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        dp[0][0] = 0;
        
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                dp[i][j] = dp[i-1][j];
                if (j >= A[i-1])
                {
                    for(int k = 0 ; k <= j/A[i-1]; k++)
                    {
                        if (dp[i-1][j-k*A[i-1]] != -1)
                        {
                            dp[i][j] = max(dp[i][j],dp[i-1][j-k*A[i-1]]+k*V[i-1]);
                        }
                    }
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < m+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                if (dp[i][j] != -1)
                    res = max(res,dp[i][j]);
            }
        }
        return res;
    }
};