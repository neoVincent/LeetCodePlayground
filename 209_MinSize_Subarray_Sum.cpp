209_MinSize_Subarray_Sum.cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(l < nums.size())
        {
            while(sum < s && r < nums.size()) 
                sum += nums[r++];
            if(sum < s)
                break;
            ans = min(ans, r-l); // pay attention after sum r is incremented
            sum -= nums[l++];
        }
        return ans == INT_MAX? 0 : ans;
    }
};
