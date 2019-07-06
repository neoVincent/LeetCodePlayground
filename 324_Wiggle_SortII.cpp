324_Wiggle_SortII.cpp
void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        
        if (n == 0 || n == 1) return ;
        
        int mid = n / 2 + 1;
        int midVal = kthLargestValue(nums,0,nums.size()-1, mid);
        
        cout <<"Mid " << mid << endl;
        for(auto n : nums)
            cout << n <<" ";
        cout << endl;
        
         #define A(i) nums[(1+2*(i)) % (n|1)]
       int i = 0, j = 0, k = n - 1;
        while (j <= k) 
        {
            if (A(j) > midVal)
                swap(A(i++), A(j++));
            else if (A(j) < midVal)
                swap(A(j), A(k--));
            else
                j++;
        }
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