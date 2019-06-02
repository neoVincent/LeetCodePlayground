912 Sort_Array.cpp

class Solution {
public:
    
    int partition(vector<int>& nums, int p,int q)
    {
        int x = nums[q];
        int i = p-1;
        for(int j = p; j < q; j++)
        {
            if (nums[j] < x)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
        i++;
        swap(nums[i],nums[q]);
        return i;
    }
    
    void quickSort(vector<int>& nums, int p,int r)
    {
        if (p < r)
        {
            int q = partition(nums,p,r);
            quickSort(nums,p,q-1);
            quickSort(nums,q+1,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // in place fast sort
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};