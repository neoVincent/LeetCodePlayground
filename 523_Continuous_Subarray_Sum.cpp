523_Continuous_Subarray_Sum.cpp

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // prefix sum + map
        int sum = 0;
        unordered_map<int,int> dict{{0,-1}};
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int target = (k == 0) ? sum : sum%k;
            if (dict.find(target) != dict.end())
            {
                if(i - dict[target] > 1) return true;
            }
            else
                dict[target] = i;
                
        }
        return false;
    }
};