20_Valid_Parentheses.cpp
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> hash{{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> stk;
        
        for(const char ch:s)
        {
            if (hash.find(ch) == hash.end())
                stk.push(ch);
            else 
            {
                if (stk.empty() || stk.top() != hash[ch])
                    return false;
                else
                    stk.pop();
            }
        }
        
        return stk.empty();
        
    }
    

};
