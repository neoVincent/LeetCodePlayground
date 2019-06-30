lint_438_Copy_BooksII.cpp
class Solution {
public:
    /**
     * @param n: An integer
     * @param times: an array of integers
     * @return: an integer
     */
    int copyBooksII(int n, vector<int> &times) {
        
        int left = 0;
        int right = times[0]*n;
        
        while(left < right)
        {
            int mid = (right - left)/2 +left;
            if (canWrite(n,times,mid))
            {
                // right 指向的是下界
                right = mid;
            }
            else
            {
                // need more time
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool canWrite(int n, vector<int> &times, int midTime)
    {
        int num = 0;
        for(int i: times)
        {
            num += midTime/i;
        }
        return n<=num;
    }
};
