49_Group_Anagrams.cpp

// previous solution
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return {};
        
        vector<pair<string,int>> dict;
        for(int i = 0 ; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(),str.end());
            dict.push_back(make_pair(str,i));
        }
        
        sort(dict.begin(),dict.end());
        
        //push a dummy record
        dict.push_back(make_pair("-1",-1));
        
        vector<vector<string>> res;
        vector<string> t;
        for(int i = 0 ; i < dict.size()-1; i++)
        {
            t.push_back(strs[dict[i].second]);
            if (dict[i].first != dict[i+1].first)
            {
                res.push_back(t);
                t = {};
            }
        }
        return res;
    }
};

// sort algorithm can replace the sort part above
sort(strs.begin(),strs.end(),[](string lhs, string rhs)
             {
                 sort(lhs.begin(),lhs.end());
                 sort(rhs.begin(),rhs.end());
                 return lhs < rhs;
});

// use hash table 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<int>> dict;
        for(int i = 0 ; i < strs.size(); i++)
        {
            string t = strs[i];
            sort(t.begin(),t.end());
            dict[t].push_back(i);
        }
        
        vector<vector<string>> res;
        for(auto iter = dict.begin(); iter != dict.end(); iter++)
        {
            auto index = iter->second;
            vector<string> anagrams;
            for(int i : index)
            {
                anagrams.push_back(strs[i]);
            }
            res.push_back(anagrams);
        }
        
        return res;
    }
    
};