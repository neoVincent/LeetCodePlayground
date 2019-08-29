Lint_627_Longest_Palindrome.cpp
class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        // count the elements
        vector<int> dict(128,0);
        for(auto& ch: s)
            dict[ch]++;
        
        int res=0;
        for(auto& n : dict)
        {
            res += n/2*2;
            if (res %2 == 0 && n%2 ==1)
                res +=1;
        }
        return res;
        
    }
};
