103_Binary_Tree_Zigzag_Level_Order_Traversal.cpp

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // BFS
        if (!root) return {};
        
        vector<vector<int>> res;
        deque<TreeNode*> que;
        vector<int> level;
        int size = 0;
        int order = 1;
        que.push_back(root);
        
        while(!que.empty())
        {
            size = que.size();
            while(size--)
            {
                TreeNode* node = que.front();
                que.pop_front();
                level.push_back(node->val);
                
                if (node->left)
                    que.push_back(node->left);
                if(node->right)
                    que.push_back(node->right);
            }
            
            // left to right
            if (order % 2 == 1)
                res.push_back(level);
            else
                res.push_back(vector<int>(level.rbegin(),level.rend()));
            
            order++;
            level.clear();
        }
        return res;
    }
};

class Solution {
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        visit(res,root,0);
        return res;
    }
    
    void visit(vector<vector<int>>& res, TreeNode* node, int level)
    {
        if (!node) return;
        
        if (res.size() == level)
            res.push_back({});
        
        if (level%2 == 0)
            res[level].push_back(node->val);
        else
            res[level].insert(res[level].begin(),node->val);
        
        visit(res,node->left,level+1);
        visit(res,node->right,level+1);
    }
};