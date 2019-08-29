Lint_1380_Log_Sorting.cpp
class Node
{
public:
    string val;
    string id;
    string content;
    bool isAlpha;
    
    Node(string logs)
    {
        content = logs;
        int pos = logs.find(" ");
        id = logs.substr(0,pos);
        val = logs.substr(pos+1);
        isAlpha = false;
        for(auto& ch : val)
        {
            if(isalpha(ch) && ch !=' ')
            {
                isAlpha = true;
                break;
            }
        }
    }
    
    bool operator < (const Node& rhs)
    {
        if (rhs.val == val)
        {
            return id < rhs.id;
        }
        
        return val < rhs.val;
    }
};

class Solution {
public:
    /**
     * @param logs: the logs
     * @return: the log after sorting
     */
    vector<string> logSort(vector<string> &logs) {
        vector<string> numbers;
        vector<Node> nodes;

        for(auto& l : logs)
        {
            Node n(l);
            if (!n.isAlpha)
                numbers.push_back(l);
            else
                nodes.push_back(n);
        }
        
        std::sort(nodes.begin(),nodes.end());
        vector<string> res;
        for(auto& n: nodes)
        {
            res.push_back(n.content);
        }
        
        res.insert(res.end(),numbers.begin(),numbers.end());
        return res;
    }
};

