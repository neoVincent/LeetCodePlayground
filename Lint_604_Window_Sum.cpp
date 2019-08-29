Lint_604_Window_Sum.cpp

class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        if (nums.size() < k || nums.size() == 0) return {};
        
        vector<int> res;
        int i = 0;
        int sum = 0;
        
        for(;i < k && i < nums.size(); i++)
        {
            sum += nums[i];
        }
            
        res.push_back(sum);
        
        while( i < nums.size())
        {
            sum -= nums[i-k];
            sum += nums[i];
            res.push_back(sum);
            i++;
        }
        return res;
    }
};
