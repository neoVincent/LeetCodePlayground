1021_Remove_Outermost_Parentheses.cpp

class Solution {
    
public:
    // recursion
    string removeOuterParentheses(string S) {
        if (S.size() == 0) return "";
        int left = 0;
        int right = 0;
        for(auto ch: S)
        {
            if (ch =='(')
                left++;
            if (ch ==')')
                right++;
            if (left == right)
                break;
        }
        return S.substr(1,right+left-2) + removeOuterParentheses(S.substr(right+left));
    }
};

class Solution {
    
public:
    string removeOuterParentheses(string S) {
        string res;
        int left = 0;
        for(const auto& c : S)
        {
            if (c =='(')
            {
                left++;
                if (left > 1)
                    res.push_back(c);
            }
            if (c == ')')
            {
                left--;
                if (left >=1)
                    res.push_back(c);
            }
        }
        return res;
    }
};


