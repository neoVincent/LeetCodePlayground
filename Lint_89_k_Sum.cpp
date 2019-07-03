Lint_89_k_Sum.cpp
class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int K, int target) {
        int m = A.size();
        int n = target;
        
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(K+1,vector<int>(n+1,0)));
        
        for(int i = 0; i < m+1; i++)
            dp[i][0][0] = 1;
        
       
        for(int i = 1; i < m+1; i++)
        {
            for(int k = 1; k < K+1 && k <= i ; k++)
            {
                for(int j = 1; j < n+1; j++)
                {
                    dp[i][k][j] = 0;
                    if (A[i-1] <= j)
                    {
                        dp[i][k][j] = dp[i-1][k-1][j-A[i-1]];
                    }
                    dp[i][k][j] += dp[i-1][k][j];
                }
            }
        }
        return dp[m][K][n];
    }
};