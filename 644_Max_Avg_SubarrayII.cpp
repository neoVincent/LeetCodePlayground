644_Max_Avg_SubarrayII.cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() < k) return 0.0;
        
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        
        while (right - left >= 1e-5) {
            double mid = left + (right - left) / 2;
            
            if (isLarger(nums, k, mid)) left = mid; //average > mid
            else right = mid;
        }
        
        return left;
    } 
    
    // x is average we assume
    bool isLarger(vector<int>& nums, int k, double x) { //true: if average > x
        double sum = 0.0; //{nums[0] - x, ..., nums[i] - x}
        double pre = 0.0; //{nums[0] - x, ..., nums[i - k] - x}
        
        // double min_pre = numeric_limits<double>::max();  //BUG: 
        double min_pre = 0.0; //minimum pre sum at some index j {nums[0] - x, ..., nums[j] - x} where 0 <= j <= i - k
        
        for (int i = 0; i < k; i++) sum += nums[i] - x;
        
        if (sum > 0) return true; //NOTE: bug without this line
        
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - x;
            pre += nums[i - k] - x;
            min_pre = min(pre, min_pre);
            
            if (sum - min_pre > 0) return true;
        }
        
        return false;
    }
};