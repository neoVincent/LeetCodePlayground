Lint_92_Backpack.cpp
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        int n = A.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        dp[0][0] = true;
        
        for(int i = 1; i<n+1; i++)
        {
            for(int j = 0; j < m+1; j++)
            {
                dp[i][j] = dp[i-1][j];
                if (j >= A[i-1] && dp[i-1][j-A[i-1]])
                {
                    dp[i][j] = true;
                }
            }
        }
        

        for(int i = m; i >= 0; i--)
        {
            if (dp[n][i])
            {
                return i;  
            }
        }
        return 0;
    }
};
