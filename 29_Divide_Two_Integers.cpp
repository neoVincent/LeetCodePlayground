29_Divide_Two_Integers.cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) 
            return INT_MAX;
        
        // overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        // overflow
        if(dividend == INT_MIN && divisor == 1 )
            return INT_MIN;
        
        bool isNegative = (dividend < 0 && divisor > 0) ||
                          (dividend > 0 && divisor < 0);
        
        long a = abs((long)dividend);
        long b = abs((long)divisor);
        int res = 0;
        while(a>=b)
        {
            int shift = 0;
            while(a>=(b << shift))
            {
                shift++;
            }
            
            a -= b << (shift-1);
            res += 1<<(shift-1);
        }
        return isNegative? -res : res;
        
    }
};
