288_Unique_Word_Abbreviation.cpp
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(auto& str: dictionary)
        {
            dict[str]++;
            dict[getAbbr(str)]++;
        }
    }
    
    bool isUnique(string word) {
        string abbr = getAbbr(word);
        return dict[word] == dict[abbr];
    }
    
    string getAbbr(string& word)
    {
        if(word.size() == 2)
            return word;
        
        int abbrSize = word.size() - 2;
        return word[0]+to_string(abbrSize)+word.back();
    }
private:
    unordered_map<string,int> dict;
    unordered_map<string,int> abbrDict;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
