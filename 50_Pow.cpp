50_Pow.cpp

class Solution {
public:
    double fastPow(double x, long long n)
    {
        // base case
        if (n == 0)
            return 1;
        
        double half = fastPow(x,n/2);
        if (n%2 == 0)
        {
            return half*half;
        }
        else
        {
            return half*half*x;
        }
    }
    double myPow(double x, int n) {
        // Fast Power Algorithm Recursive
        long long N = n;
        if (N < 0)
        {
            x = 1/x;
            N = -N;
        }
        
        return fastPow(x,N);
    }
};


class Solution {
public:

    double myPow(double x, int n) {
        // Fast Power Algorithm iterative
        long long N = n;
        if (N < 0)
        {
            x = 1/x;
            N = -N;
        }
        
        double ans = 1;
        double current_product = x;
        for(long long i = N; i; i /=2)
        {
            if (i%2 == 1)
            {
                ans = current_product*ans;
            }
            
            current_product = current_product*current_product;
        }
        return ans;
       
    }
};