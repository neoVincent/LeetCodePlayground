Lint_5_Kth_Largest_Element.cpp
class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // quick select
        // k: nums.size() - n 在[0,nums.size()-1]范围内的数组索引
        return kthLargestElement(nums,nums.size()-n,0,nums.size()-1);
    }
    
    // k: 是在[left,right]中的相对索引    
    int kthLargestElement(vector<int> &nums, int k, int left, int right)
    {
        if (left == right) return nums[left];
        
        if(left < right)
        {
            // partition
            int pivot = nums[right];
            int i = left-1;
            for(int j = left; j < right; j++)
            {
                if (nums[j] < pivot)
                {
                    i++;
                    swap(nums[j],nums[i]);
                }
            }
            i++;
            swap(nums[i],nums[right]);

            // divide and conquer
            // i: 是在[0,nums.size()-1]中的全局索引
            // i-left: 在[left,right]中的相对索引
            
            if (i-left == k) return nums[i];
                        
            if (i-left > k)
                return kthLargestElement(nums,k,left, i-1);
            else
                // ... i1 i2 i3 i4 i5 i6 i7 i8...
                // ... l     i         k 
                // 在这个情选择右半边，之前说了，k是相对所以，所以在做计算之前，需要将k转换为全局索引，这样才能和i进行比较
                return kthLargestElement(nums,k + left -i-1 ,i+1,right);
        }
        
        return INT_MAX;
        
    }
};
