110_Balanced_Binary_Tree.cpp
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // recursion
        if (!root) return true;
        
        int heightDiff = treeHeight(root->left) - treeHeight(root->right);
        if (abs(heightDiff) > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);

        
    }
    
    int treeHeight(TreeNode* root)
    {
        if (!root) return 0;
        return max(treeHeight(root->left),treeHeight(root->right))+1;
    }
};


bool isBalanced(TreeNode* root) {
        return treeHeight(root) != -1;
    }
    
    int treeHeight(TreeNode* node)
    {
        if (!node) return 0;
        
        int left = treeHeight(node->left);
        if (left == -1)
            return -1;
        
        int right = treeHeight(node->right);
        if (right == -1)
            return -1;
        
        return abs(right - left) <= 1? max(left,right)+1 : -1;
    }
