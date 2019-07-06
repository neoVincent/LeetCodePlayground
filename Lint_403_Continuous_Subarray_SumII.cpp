Lint_403_Continuous_Subarray_SumII.cpp
class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
     
    vector<int> continuousSubarraySumII(vector<int> &A) {
        if(A.size() == 0 || A.size() == 1) return {0,0};
        int n = A.size();
        auto sum1 = continuousSubarraySum(A);
        int totalSum = 0;
        for(auto& a: A)
        {
            totalSum += a;
            a = -a;
        }
            
        
        auto sum2 = continuousSubarraySum(A);
        if (sum1[0] >= totalSum + sum2[0])
            return {sum1[1],sum1[2]};
        else
            return {(sum2[2]+1)%n,  sum2[1]-1};
    }
    
    vector<int> continuousSubarraySum(vector<int> &A)
    {
        int left = 0;
        int preSum = INT_MIN;
        int maxi = INT_MIN;
        vector<int> res{0,0,0};
        for(int i = 0; i < A.size() -1 ;i++)
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
                res = {maxi,left,i};
            }
        }
        return res;
    }
};

