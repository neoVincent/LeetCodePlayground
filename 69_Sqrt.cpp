69_Sqrt.cpp

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int left = 1;
        int right = x/2+1;
        int res = 0;
        while(left <= right)
        {
            
            int mid = (right-left)/2+left;
            int divide = x/mid;
            if (mid == divide ) return mid;
            if (mid > divide) 
                right = mid - 1;
            else 
            {
                left = mid+1;
                res = mid;
            }
                
        }
        return res;            
    }
};
