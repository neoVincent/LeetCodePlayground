912 Sort_Array.cpp

// quick sort
class Solution {
public:
    int partition(vector<int>& nums, int i, int j)
    {
        if (i < j)
        {
            int p = nums[j];
            int m = i - 1;
            int n = i;
            while(n <  j)
            {
                if (nums[n] > p)
                    n++;
                else
                {
                    m++;
                    swap(nums[m],nums[n]);
                    n++;
                }
            }
            m++;
            swap(nums[j],nums[m]);
            return m;
        }
        return -1;
    }
    void quickSort(vector<int>& nums, int i, int j)
    {
        if (i < j)
        {
            int p = partition(nums,i,j);
            cout<<p<<endl;
            quickSort(nums,i,p-1);
            quickSort(nums,p+1,j);  
        }
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        // in place fast sort
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};