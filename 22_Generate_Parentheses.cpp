22_Generate_Parentheses.cpp

class Solution {
public:
    void backTracking(string& s, int l, int r, vector<string>& res)
    {
        if (l == 0 && r == 0)
        {
            res.push_back(s);
            return;
        }
        
        
        if (l > 0)
        {
            string cur = s;    
            cur.push_back('(');
            backTracking(cur,l-1,r,res);
        }
        
        if (l < r)
        {
            string cur = s;
            cur.push_back(')');
            backTracking(cur,l,r-1,res);
        }
            
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str="";
        backTracking(str,n,n,res);
        return res;
    }
};
