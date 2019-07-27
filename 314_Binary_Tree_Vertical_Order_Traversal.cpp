314_Binary_Tree_Vertical_Order_Traversal.cpp

class Solution {
private:
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // BFS
        if (!root) return {};
        
        map<int,vector<int>> dict;
        deque<pair<TreeNode*,int>> que;
        int depth = 0;
        dict[depth].push_back(root->val);
        que.push_back({root,depth});
        
        while(!que.empty())
        {
            auto node = que.front();
            que.pop_front();
            depth = node.second;
            if (node.first->left)
            {
                dict[depth-1].push_back(node.first->left->val);
                que.push_back({node.first->left,depth-1});
            }
            
            if (node.first->right)
            {
                dict[depth+1].push_back(node.first->right->val);
                que.push_back({node.first->right,depth+1});
            }
        }
        
        vector<vector<int>> res;
        for(auto iter = dict.begin(); iter != dict.end(); iter++)
        {
            res.push_back(iter->second);
        }
        return res;
    }
};