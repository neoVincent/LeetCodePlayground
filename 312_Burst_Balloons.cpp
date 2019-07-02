312_Burst_Balloons.cpp

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        if (nums.size() == 0) return 0;
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        
        // initialize not necessary
        // for range (i,j) is not inclusive
        // for(int i = 0; i < n; i++)
        //     dp[i][i] = nums[i];
        
        // calculate
        for(int i = n-2; i >=0 ; i--)
        {
            for(int j = i+2; j < n; j++)
            {
                for(int k = i+1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};