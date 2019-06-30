Lint_395_Coins_in_LineII.cpp

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // bottom up
        int n = values.size();
        if (n == 0) return false;
        
        vector<int> dp(n+1,0);
        
        dp[0] = 0;
        dp[1] = values[n-1];
        dp[2] = values[n-1] + values[n-2];
        dp[3] = values[n-3] + values[n-2];
        
        for(int i = 4; i <= n ; i++)
        {
            dp[i] = max(values[n-i]+min(dp[i-2],dp[i-3]),values[n-i]+values[n-i+1]+min(dp[i-3],dp[i-4]));
        }
        
        int sum = 0;
        for(auto v : values)
            sum+=v;
        
        return dp[n] > sum/2;
    }
};
