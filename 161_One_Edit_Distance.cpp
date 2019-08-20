161_One_Edit_Distance.cpp
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // scan the string
        // use the size condition to decide the option
        if (s.size() == 0 && t.size() == 0 || s == t) return false;
        
        int diff = s.size() - t.size();
        if (abs(diff) > 1 ) return false;
        
        int l1 = s.size();
        int l2 = t.size();
        
        int i = 0, j = 0;
        bool isEdited = false;
        while(i < l1 && j < l2)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else if (!isEdited)
            {
                if (l1 == l2)
                {
                    i++;
                    j++;
                }
                else if (l1 > l2)
                {
                    i++;
                }
                else
                    j++;
                
                isEdited = true;
            }
            else
                return false;
        }
        return true;
    }
};