139_Word_Break.cpp

class Solution {
public:
    // dp
    // def: dp[i] (1->i) whether it can be separated
    // dp[i] = dp[j] && wordDict.find(s.substr(j+1,i+1)) [0<=j<=i]
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || wordDict.empty()) return false;
        
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        
        for(int i = 1; i < dp.size(); i++)
        {
            for(int j = i-1; j>=0; j--)
            {
                if (dp[j])
                {
                    string str = s.substr(j,i-j);
                    if (dict.count(str)) 
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()];
        
    }
};