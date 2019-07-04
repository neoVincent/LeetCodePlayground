Lint_404_Subarray_SumII.cpp

class Solution {
public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        if (end == 0) return 0;
        
        // prefix sum 
        
        int n = A.size();
        vector<int> preSum(n+1,0);
        for(int i = i; i < n+1; i++)
        {
            preSum[i] = preSum[i-1] + A[i-1];
        }
        
        
        // two pointer get the number ensure the O(n)
        int res = 0;
        // right... ... left ..... i... (all the elemnts is positive) 
        int left = 0; // means the left index bound, a[left] + ... + a[i] == start
        int right = 0; // means the right index bound, a[right] + ... + a[i] == end
        
        // As the i goes to the end, left, right moves moves in the same direction to the end
        // therefore, we can use 2 pointers
        for(int i = 1 ; i < n+1; i++)
        {
            // pay attention to the logic here (preSum[i] - preSum[left]) > start
            while(left <= i && (preSum[i] - preSum[left]) >= start)
            {
                left++;
            }
            
            // pay attention to the logic here preSum[i] - preSum[right] < end
            while(right <= i && (preSum[i] - preSum[right] > end))
            {
                right++;
            }
            
            res += (left - right);
        }
        return res;
    }
};