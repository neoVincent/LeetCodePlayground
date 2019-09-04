1790_Rotate_String_II.cpp
class Solution {
public:
    /**
     * @param str: An array of char
     * @param left: a left offset
     * @param right: a right offset
     * @return: return a rotate string
     */
    string RotateString2(string &str, int left, int right) {
        // left, append end 
        // right, append front 
        left %= str.size();
        right %= str.size();
        
        if (left == right) return str;
        
        int diff = 0;
        if (left > right)
        {
            diff = left - right;
            return str.substr(diff) + str.substr(0,diff);
        }
        else
        {
            diff = right - left;
            return str.substr(str.size()-diff) + str.substr(0,str.size()-diff);
        }
    }
};