300_Longest_Increasing_Subsequence.cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        vector<int> dp(nums.size());
        int res = 1;
        dp[0] = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            int maxVal = 0; // the initial must be zero, for the case nums[i] <= nums[j]
            for(int j = 0; j < i; j++ )
            {
                if (nums[i] > nums[j])
                    maxVal = max(maxVal,dp[j]);
            }
            dp[i] = maxVal+1;
            res = max(res,dp[i]);
        }
        return dp[nums.size()-1];
    }
};