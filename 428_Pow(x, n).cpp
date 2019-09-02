428_Pow(x, n).cpp

class Solution {
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, long n) {
    
        // double 特判不能用 == 0
        if (-1e-10 < x && x < 1e-10) return 0;
        
        if (n < 0) 
        {
            x = 1/x;
            // int overflow 
            //input 2.00000 -2147483648
            n = -n; 
        }
        
        double ans = 1, tmp = x; //x^1,x^2, x^4,x^8
        
        while(n != 0)
        {
            if (n%2 == 1)
            {
                ans *= tmp;
            }
            tmp *=tmp;
            n /=2;
        }
        return ans;
    }
};