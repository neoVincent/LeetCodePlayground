609_Find_Duplicate_File_in_System.cpp

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> files; // content --> path
        
        
        for(const auto& p: paths)
        {
            string filePath;
            int i = 0;
            while(p[i] != ' ') filePath += p[i++];
            while(i < p.size())
            {
                string fileName;
                string content;
                i++; // ' '
                while(p[i] != '(') fileName += p[i++];
                i++; // '('
                while(p[i] != ')') content += p[i++];
                i++; // ')'
                files[content].push_back(filePath+"/"+fileName);
            }
        }
        
        vector<vector<string>> res;
        for(auto& file: files)
        {
            if (file.second.size() > 1)
                res.push_back(std::move(file.second));
        }
        return res;
    }
};

