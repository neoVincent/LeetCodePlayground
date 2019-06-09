153_Find_Min_in_Rotated_Array.cpp

class Solution {
public:
    int findMin(vector<int>& nums) {
        // initial check 
        if (nums.size() == 0) return -1;
        
        int left = 0;
        int right = nums.size()-1;
        int mini = INT_MAX;
        
        while(left <= right)
        {
            int mid = (right-left)/2 + left;
            mini = min(mini,nums[mid]);
            
            if (nums[mid] >= nums[left])
            {
                mini = min(mini,nums[left]);
                left = mid+1;
            }
            
            if (nums[mid] <= nums[right])
            {
                right = mid-1;
            }
            
        }
        return mini;
    }
};