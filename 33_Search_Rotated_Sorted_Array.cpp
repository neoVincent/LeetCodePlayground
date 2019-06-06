33_Search_Rotated_Sorted_Array.cpp

class Solution {
public:
    int binSearch(vector<int>& nums, int left, int right, int target)
    {
        if (left > right) return -1;
        
        int mid = (right-left)/2 + left;
        
        cout <<"Mid "<< nums[mid];
        cout <<" Left " << nums[left];
        cout <<" Right " << nums[right];
        cout << endl;
        
        if (nums[mid] == target) return mid;
        
        if (nums[left] < nums[mid])
        {
            // left part is in correct order
            if (target < nums[mid] && target >= nums[left])
                return binSearch(nums,left,mid-1,target);
            else
                return binSearch(nums,mid+1,right,target);
        }else if (nums[mid] < nums[right])
        {
            // right part is in correct order
            if (target > nums[mid] && target <= nums[right])
                return binSearch(nums,mid+1,right,target);
            else
                return binSearch(nums,left,mid-1,target);
        }
        else if (nums[left] == nums[mid])
        {
            if (nums[mid] != nums[right])
                return binSearch(nums,mid+1,right,target);
            else 
            {
                // search both side
                int res = binSearch(nums,mid+1,right,target);
                if (res == -1)
                    res = binSearch(nums,left,mid-1,target);
                return res;
            }
        }
        
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        return binSearch(nums,0, nums.size()-1, target);
        
    }
};