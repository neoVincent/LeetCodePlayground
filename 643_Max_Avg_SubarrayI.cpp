643_Max_Avg_SubarrayI.cpp
class Solution {
public:
    // sliding window
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0)
            return 0;
        
        int left = 0;
        double sum = 0.0;
        int right = left+k;
        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        double res = sum/k;
        
        for(int i = k; i < nums.size(); i++)
        {
            sum -= nums[left++];
            sum += nums[i];
            res = max(sum/k,res);
        }
        return res;
        
    }
};
