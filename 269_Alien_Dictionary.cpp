269_Alien_Dictionary.cpp
class Solution {
public:
    string alienOrder(vector<string>& words) {
        // build graph
        int visited[26];
        for(int i = 0 ; i< 26; i++) visited[i] = -1;
        unordered_map<char,unordered_set<char>> dict;
        for(int i = 0; i < words.size(); i++)
        {
            for(auto w : words[i]) visited[w -'a'] = 0;
            if (i > 0)
            {
                int len = min<size_t>(words[i-1].size(),words[i].size());
                for(int j = 0; j < len; j++)
                {
                    if (words[i-1][j] != words[i][j])
                    {
                        dict[words[i-1][j]].insert(words[i][j]);
                        break;
                    }
                        
                }
            }
            
        }
        
        // topological sort
        string res;
        for(int i = 0; i < 26; i++)
        {
            if (visited[i] == 0)
            {
                if (!topologicalSort(i+'a',dict,visited,res))
                {
                    return "";
                }
            }
        }
        return {res.rbegin(),res.rend()};
    }
    
    bool topologicalSort(char c, unordered_map<char,unordered_set<char>>& dict, int visited[], string& res)
    {
        visited[c-'a'] = 1;
        for(auto iter = dict[c].begin(); iter != dict[c].end(); iter++)
        {
            if (visited[*iter-'a'] == 0)
            {
                if (!topologicalSort(*iter,dict,visited,res))
                {
                    return false;
                }
            }
            else if (visited[*iter-'a'] == 1) // loop detected, invalid order
            {
                return false;
            }   
        }
        visited[c-'a'] = 2;
        res.push_back(c);
        return true;
    }
};