721_Accounts_Merge.cpp


struct Node
{
    Node* parent;
    int rank;
    string name;
    string email;
    Node(string name, string email): name(name), email(email)
    {
        parent = this;
        rank = 0;
    }
};

class Solution {
public:
    
    Node* find(Node* x)
    {
        if (x->parent != x)
        {
            x->parent = find(x->parent);
        }
        return x->parent;
    }
    
    void Union(Node* x, Node* y)
    {
        Node* xp = find(x);
        Node* yp = find(y);
        
        if(xp == yp) return;
        
        if (xp->rank > yp->rank)
        {
            yp->parent = xp;
        }
        else
        {
            xp->parent = yp;
            if (xp->rank == yp->rank)
                yp->rank++;
        }
    }
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        if (accounts.size() == 0) return {};
        
        unordered_map<string,Node*> sets;
        
        for(auto account : accounts)
        {
            string usrname = account[0];
            for(int i = 1; i < account.size(); i++)
            {
                if (sets.find(account[i]) == sets.end())
                {
                    // make set
                    Node* n = new Node(usrname,account[i]);
                    sets[account[i]] = n;
                }
            }
            
            for(int i = 1; i < account.size()-1; i++)
            {
                Node* n1 = sets[account[i]];
                Node* n2 = sets[account[i+1]];
                Union(n1,n2);
            }
        }
        
        // 整理出每个component
        unordered_map<Node*, vector<string>> info;
        for(auto iter = sets.begin(); iter != sets.end(); iter++)
        {
            // cout <<"Email parent " << iter->second->parent->email << endl;
            // cout <<"Email child " <<iter->first<<endl;
            info[find(iter->second)].push_back(iter->first); 
        }
        
        // 将每个component进行排序
        vector<vector<string>> res;
        for(auto iter = info.begin(); iter != info.end(); iter++)
        {
            vector<string> emails = iter->second;
            
            // cout << "Email groups"<<endl;
            // for(auto s: emails)
            //     cout << s << " ";
            // cout << endl;
            
            // sort(iter->second->begin(), iter->second->end());
            sort(emails.begin(), emails.end());
            // res.push_back({iter->first->name,iter->second});
            emails.insert(emails.begin(),iter->first->name);
            res.push_back(emails);
        }
        return res;
    }
};