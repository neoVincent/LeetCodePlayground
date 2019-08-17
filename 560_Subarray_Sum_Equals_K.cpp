560_Subarray_Sum_Equals_K.cpp

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force O(n^2) --> time limited
        // expected nlgn or n
        // prefix sum
        vector<int> sums(nums.size()+1,0);
        multiset<int> dict{0};
        int res = 0;
        for(int i = 1; i < sums.size(); i++)
        {
            sums[i] = sums[i-1]+nums[i-1];
            if (dict.count(sums[i] - k))
                res+= dict.count(sums[i]-k);
            dict.insert(sums[i]);            
        }
        return res;
        
    }
};

