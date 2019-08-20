953_Verifying_an_Alien_Dictionary.cpp
class Solution {
private:
    unordered_map<char,int> dict;
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() == 1 or words.size() == 0) return true;
        
        // build dict
        dict.clear();
        dict['*'] = -1;
        for(int i = 0; i < order.size()953_Verifying_an_Alien_Dictionary.cpp; i++)
            dict[order[i]] = i+1;
        
        int maxLen = 0;
        for(auto& w : words)
        {
            maxLen = max(maxLen, static_cast<int>(w.size()));
        }
        
        for(int i = 1; i < words.size(); i++)
        {
            if (!isCorrectOrder(words[i-1],words[i],dict))
                return false;
        }
        return true;
    }
    
    bool isCorrectOrder(string& s1, string& s2, unordered_map<char,int>& dict)
    {
        for(int i = 0, j = 0; i < s1.size() && j < s2.size(); i++,j++)
        {
            if (dict[s1[i]] < dict[s2[j]])
                return true;
            else if (dict[s1[i]] > dict[s2[j]])
                return false;
        }
        return s1.size() <= s2.size();
    }
};