713_Subarray_Product_Less_Than_K.cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // 2 pointers, sliding windows
        if ( k<= 1) return 0;
        int l = 0;
        int r = 0;
        long p = 1;
        int res = 0;
        while(r < nums.size())
        {
            p *= nums[r];
            while(p >= k)
            {
                p /= nums[l];
                l++;
            }
            res += (r-l) + 1;
            r++;
        }
        return res;
    }
    
};