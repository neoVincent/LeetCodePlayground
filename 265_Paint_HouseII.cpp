265_Paint_HouseII.cpp
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        
        int m = costs.size();
        int n = costs[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        
        //initialize 
        for(int i = 0; i < n; i++)
            dp[0][i] = costs[0][i];
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if (k != j)
                    {
                        dp[i][j] = min(dp[i-1][k]+costs[i][j],dp[i][j]);
                    }
                }
            }
        }
        
        int res = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            res = min(res, dp[m-1][i]);
        }
        
        return res;
    }
};
