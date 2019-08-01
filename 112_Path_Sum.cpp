112_Path_Sum.cpp

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // recursion, brute force
        // root to leaf
        if (!root) return false;
        if (!root->left && !root->right && sum == root->val) return true;
        
        sum -= root->val;
        return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
        
    }
};