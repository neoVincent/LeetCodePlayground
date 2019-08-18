325_Maximum_Size_Subarray_Sum_Equals_k.cpp
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        unordered_map<int,int> dict{{0,-1}};
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (dict.find(sum-k) != dict.end())
                res = max(res,i - dict[sum-k]);
            if (dict.find(sum) == dict.end())
                dict[sum] = i;
        }
        return res;
    }
};