451_Sort_Characters_By_Frequency.cpp
class Solution {
public:
    string frequencySort(string s) {
        vector<int> dict(128,0);
        for(const auto& ch : s) dict[ch]++;
        vector<pair<int,char>> chars;
        for(int i = 0; i < dict.size(); i++)
        {
            if (dict[i] > 0)
                chars.push_back({dict[i],i});
        }
        sort(chars.rbegin(),chars.rend());
        string res="";
        for(const auto& c : chars)
            res.append(c.first,c.second);
        return res;
    }
};
