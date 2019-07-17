32_Longest_Valid_Parentheses.cpp

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        stk.push(-1);
        
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                stk.push(i);
            else
            {
                stk.pop();
                if (stk.empty())
                    stk.push(i);
                else
                {
                    res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0;
        int r = 0;
        int res = 0;
        // scan from left to right
        for(auto ch : s)
        {
            if (ch == '(')
                l++;
            else
            {
                if (l > r)
                    r++;
                else
                {
                    l = 0;
                    r = 0;
                }
            }
            if (l == r)
                res = max(res,l*2);
        }
        
        // scan from right to left
        l = 0;
        r = 0;
        for(int i = s.size() -1; i >= 0; i--)
        {
            if (s[i] == ')')
                r++;
            else
            {
                if (r > l)
                {
                    l++;
                }
                else
                {
                    r = 0;
                    l = 0;
                }
            }
            if (r == l)
                res = max(res, r*2);
        }
        
        return res;
        
    }
};