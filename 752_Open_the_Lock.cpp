752_Open_the_Lock.cpp
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // BFS : 最短路径
        if (target == "0000") return 0;
        
        unordered_set<string> dict(deadends.begin(),deadends.end());
        
        if (dict.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        
        int depth = 0;
        while(!q.empty())
        {
            int size = q.size();
            depth++;
            while(size-- > 0)
            {
                string s = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++)
                {
                    int num = s[i]-'0';
                    int next = (num+1)%10;
                    int prev = (num-1+10)%10;
                    string str1 = s.substr(0,i) + to_string(next)+s.substr(i+1);
                    string str2 = s.substr(0,i) + to_string(prev)+s.substr(i+1);
                    
                    if (str1 == target || str2 == target) 
                    {
                        return depth;
                    }
                    if (dict.count(str1) == 0)
                    {
                        dict.insert(str1);
                        q.push(str1);
                    }
                    if (dict.count(str2) == 0)
                    {
                        dict.insert(str2);
                        q.push(str2);
                    }

                }
                
            }
            
        }
        
        return -1;
    }
};
