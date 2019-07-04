Lint_402_Continuous_Subarray_Sum.cpp
class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
        
        vector<int> res{0,0};
        int maxi = INT_MIN;
        int preSum = 0;
        int left = 0;
        
        for(int i = 0 ; i < A.size(); i++)
        {
            if (preSum < 0)
            {
                left = i;
                preSum = A[i];
            }
            else
            {
                preSum += A[i];
            }
            
            if (preSum > maxi)
            {
                maxi = preSum;
                res = {left,i};
            }
            
        }
        return res;
    }
};

 