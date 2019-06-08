34_Find_First_Last_Ele_Pos_Sorted_Array.cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // initial check
        if (nums.size() == 0 ) return {-1,-1};
        
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(left < right)
        {
            mid = (right-left)/2+left;
            if (nums[mid] == target) break;
            
            if (nums[mid] > target)
                right = mid -1;
            else 
                left = mid + 1;
        }
        
        if (left == right)
        {
            if (nums[left] == target)
                return {left,left};
            else
                return {-1,-1};
        }
        else if (nums[mid] == target)
        {
            int leftPos = mid;
            int rightPos = mid;
            for(;leftPos >=0; leftPos--)
            {
                if (nums[leftPos] != target)
                    break;
            }
            
            for(;rightPos < nums.size(); rightPos++)
            {
                if (nums[rightPos] != target)
                    break;
            }
            return {leftPos+1,rightPos-1};
        }
        return {-1,-1};        
        
    }
};


class Solution {
public:
    int findIndex(vector<int>& nums, int target, bool leftSide)
    {
        int left = 0;
        int right = nums.size();
        
        while(left < right) // different from binary search 
        {
            int mid = (right-left)/2 + left;
            if (nums[mid] > target || (leftSide && nums[mid] == target))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        
        int leftIndex = findIndex(nums,target,true);
        
        if (leftIndex == nums.size() || nums[leftIndex] != target)
            return res;
        
        res[0] = leftIndex;
        res[1] = findIndex(nums,target,false)-1;
        return res;
    }
};
