Lint_437_CopyBooks.cpp

class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        if (pages.size() == 0)
            return 0;
        
        int left = *max_element(pages.begin(),pages.end());
        int right = accumulate(pages.begin(),pages.end(),0);
        while(left < right)
        {
            int mid = (right - left) / 2 + left;
            int n = copiers(pages,mid);
            
            if (n <= k ) // fewer people than needed, decrease time
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    
    int copiers(vector<int>& pages, int t)
    {
        int n = 1;
        int timeSpent = 0;
        for(int i = 0 ; i < pages.size(); i++)
        {
            if (timeSpent + pages[i] > t)
            {
                n++;
                timeSpent = 0;
            }
            timeSpent += pages[i];
        }
        return n;
    }
};
