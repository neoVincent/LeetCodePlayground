3_Longest_Substring_Without_Repeating_Characters.cpp

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        vector<int> index(128,INT_MIN);
        int ans = 0;
        
        for(; r < s.length(); r++)
        {
            if(s[r] != INT_MIN)
                l = max(l,index[s[r]]+1); //不用删除已经重复的index，在这里只需要取最大的index就可以了 总的T(N) = O(n)
            ans = max(ans, r-l+1);
            index[s[r]] = r;
        }
        return ans;
    }
};
