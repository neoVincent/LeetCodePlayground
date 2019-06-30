Lint_394_Coins_in_Line.cpp
class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        if (n == 0) return false;
        
        // dp 记入的是任何人的局面如果是n他的胜算
        vector<bool> dp(n+1,false);
        dp[0] = false;
        dp[1] = true;
        dp[2] = true;
        
        for(int i = 3; i <= n ; i++)
        {
            // 当前的选手的结果，取决于对手的结果取非
            dp[i] = !dp[i-1] || !dp[i-2];
        }
        
        return dp[n];
    }
};
