Lint_138_Subarray_Sum.cpp
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // prefix sum 
        unordered_map<int,int> hash;
        int sum = 0;
        hash[0] = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (hash.find(sum) != hash.end())
            {
                return {hash[sum]+1, i};
            }
            hash[sum] = i;
        }
        return {-1,-1};
    }
};
