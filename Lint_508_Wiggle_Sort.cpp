Lint_508_Wiggle_Sort.cpp

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        
        if (n == 0 || n == 1) return ;
        
        int mid = n / 2 + 1;
        int midVal = kthLargestValue(nums,0,nums.size()-1, mid);
        if (n%2 == 0)
            merge(nums,0,mid-1);
        else
            merge(nums,0,mid);
    }
    
    int kthLargestValue(vector<int> &nums, int left, int right, int k)
    {
        if (left == right) return nums[left];
        
        if(left < right)
        {
            int i = partition(nums,left,right);
            
            if (i == k-1) return nums[i];
            
            if (i > k-1)
                return kthLargestValue(nums,left,i-1,k);
            else
                return kthLargestValue(nums,i+1,right,k);
        }
        return INT_MAX;
    }
    
    int partition(vector<int>& nums, int left, int right)
    {
        int x = left -1;
        int pivot = nums[right];
        for(int y = left; y < right ; y++)
        {
            if(nums[y] < pivot)
            {
                x++;
                swap(nums[x],nums[y]);
            }
        }
        x++;   
        swap(nums[x],nums[right]);
        return x;
    }
    
    void merge(vector<int>& nums, int left, int right)
    {
        vector<int> res(nums.size());
        int k = 0;
        int i = left;
        int j = right;
        while(k < nums.size())
        {
            if (i < right)
                res[k++] = nums[i++];
            if (j < nums.size())
                res[k++] = nums[j++];
        }
        nums = res;
    }
};
