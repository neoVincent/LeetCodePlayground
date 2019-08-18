974_Subarray_Sums_Divisible_by_K.cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        // prefix sum
        vector<int> count(K,0);
        count[0] = 1;
        int res = 0;
        int sum = 0;
        for(auto const a: A)
        {
            sum = (sum + a ) % K;
            if (sum < 0)
                sum += K;
            res += count[sum]++;
        }
        return res;
        
    }
};
