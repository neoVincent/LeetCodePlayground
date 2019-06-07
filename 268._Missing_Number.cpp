268._Missing_Number.cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // XOR
        int res =0 ;
        for(int i = 0; i <= nums.size(); i++)
        {
            res ^= i;
        }
        
        for(auto n:nums) res ^=n;
        
        return res;
    }
};