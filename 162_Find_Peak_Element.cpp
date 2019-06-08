162_Find_Peak_Element.cpp
class Solution {
public:
   
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int left = 0; 
        int right = nums.size()-1;
        while (left < right)
        {
            int mid = (left + right)/2;
            if (nums[mid] > nums[mid+1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
