Lint_637_Valid_Word_Abbreviation.cpp
class Solution {
public:
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        // two pointers
        int i = 0, j = 0;
        while(i < word.size() && j < abbr.size())
        {
            if (word[i] == abbr[j])
            {
                i++;
                j++;
            }
            else if (abbr[j] > '0' && abbr[j] <='9')
            {
                int steps = 0;
                while(j < abbr.size() && isdigit(abbr[j]))
                {
                    steps = steps*10 + abbr[j]-'0';
                    j++;
                }
                i += steps;
            }
            else
                return false;
        }
        
        return i == word.size() && j == abbr.size();
    }
};
