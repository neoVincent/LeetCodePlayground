Lint_125_BackpackII.cpp
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int mass, vector<int> &A, vector<int> &V) {
        int m = A.size();
        int n = mass;
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        vector<vector<int>> record(m+1,vector<int>(n+1,-1));
        dp[0][0] = 0;
        
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                dp[i][j] = dp[i-1][j];
                if (A[i-1] <= j && dp[i-1][j-A[i-1]] != -1)
                {
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-A[i-1]] + V[i-1]);
                    if (dp[i][j] == dp[i-1][j-A[i-1]] + V[i-1])
                    {
                        record[i][j] = 1;
                    }
                }
            }
        }
        
        int res = 0;
        int maxMass = 0;
        for(int i = n; i>=0;i--)
        {
            if (dp[m][i] != -1)
            {
                res = max(res,dp[m][i]);
                if (res == dp[m][i])
                {
                    maxMass = i;
                }
            }
                
        }
        
        for(int i = m; i >= 0; i--)
        {
            if (record[i][maxMass] == 1)
            {
                cout <<"Select item " << A[i-1] << " its value " << V[i-1] << endl;
                maxMass -= A[i-1];
            }
        }
        return res;
    }
};