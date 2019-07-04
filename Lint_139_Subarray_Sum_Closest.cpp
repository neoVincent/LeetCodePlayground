Lint_139_Subarray_Sum_Closest.cpp

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // prefix sum
        vector<pair<int,int>> preSum;
        int sum = 0;
        preSum.push_back({0,-1});
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            preSum.push_back({sum,i});
        }
        
        sort(preSum.begin(), preSum.end(), greater<pair<int,int>>());
        
        int start = -1;
        int delt = INT_MAX;
        for(int i = 0; i < preSum.size()-1; i++)
        {
            if (preSum[i].first - preSum[i+1].first < delt)
            {
                delt = preSum[i].first - preSum[i+1].first;
                start = i;
            }
        }
        
        if(start != -1)
        {
            int left = min(preSum[start].second, preSum[start+1].second);
            int right = max(preSum[start].second, preSum[start+1].second);
            return {left+1, right};
        }
        return {0,0};
        
    }
};