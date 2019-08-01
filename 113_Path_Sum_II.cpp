113_Path_Sum_II.cpp
class Solution {

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // recursion
        // back tracking
        if (!root) return {};
        
        vector<vector<int>> res;
        vector<int> path{root->val};
        pathSum(root,sum,path,res);
        return res;
    }
    
    void pathSum(TreeNode* node, int sum, vector<int>&path, vector<vector<int>>& res)
    {
        if (!node) return;
        if (!node->left && !node->right && node->val == sum)
        {
            res.push_back(path);
            return;
        }
        
        sum -= node->val;
        if (node->left)
        {
            path.push_back(node->left->val);
            pathSum(node->left,sum,path,res);
            path.pop_back();
        }
        
        if(node->right)
        {
            path.push_back(node->right->val);
            pathSum(node->right,sum,path,res);
            path.pop_back();
        }
        
        
        
    }
};