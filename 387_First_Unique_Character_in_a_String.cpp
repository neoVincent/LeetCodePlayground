387_First_Unique_Character_in_a_String.cpp

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> dict(26,0);
        for(const auto& ch: s)
            dict[ch-'a']++;
        
        for(int i = 0; i < s.size(); i++)
        {
            if (dict[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};
