Lint_396_Coins_in_LineIII.cpp

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        if (n == 0) return false;
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        // initial
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = values[i];
        }
        
        for(int i = 0; i < n-1; i++)
        {
            dp[i][i+1] = max(values[i],values[i+1]);
        }
        
        // calcualte
        for(int i = n-3; i >= 0; i--)
        {
            for(int j = i+1; j < n; j++)
            {
                dp[i][j] = max(values[i] + min(dp[i+2][j],dp[i+1][j-1]),
                            values[j] + min(dp[i+1][j-1],dp[i][j-2]));
            }
        }
        
        int sum = 0;
        for(auto v : values)
            sum += v;
        
        // for(int i = 0; i < n-1; i++)
        // {
        //     for(int j = 1; j < n;j++)
        //     {
        //         if (i <= j)
        //         {
        //             cout <<i <<" "<<j <<" : "<< dp[i][j] << "; ";
        //         }
        //     }
        //     cout << endl;
        // }
        return dp[0][n-1] >= sum/2;
    }
};