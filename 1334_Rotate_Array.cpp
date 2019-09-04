1334_Rotate_Array.cpp

class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: rotate the array to the right by k steps
     */
    vector<int> rotate(vector<int> &nums, int k) {
        
        k %= nums.size();
        
        if (k == 0) return nums;
        
        vector<int> res;
        res.insert(res.begin(),prev(nums.end(),k),nums.end());
        
        res.insert(res.end(),nums.begin(),next(nums.begin(),nums.size()-k));
        
        return res;
    }
};