128_Longest_Consecutive_Sequence.cpp
class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> dict(num.begin(), num.end());
        
        int res = INT_MIN;
        for(auto& n: num)
        {
            if (dict.count(n) != 0)
            {
                int l = n, r = n;
                while(dict.count(l-1) != 0)
                {
                    l--;
                    dict.erase(l);
                }
                while(dict.count(r+1) != 0)
                {
                    r++;
                    dict.erase(r);
                }
                
                res = max(res,r - l + 1);
            }
            
        }
        return res;
    }
};
