Lint_628_Maximum_Subtree.cpp
class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the maximum weight node
     */
    pair<int,TreeNode*> res{INT_MIN,nullptr};
    
    TreeNode * findSubtree(TreeNode * root) {
        findMaxSubtree(root);
        return res.second;
    }
    
    int findMaxSubtree(TreeNode* node)
    {
        if (!node) return INT_MIN;
        
        int left = findMaxSubtree(node->left);
        int right = findMaxSubtree(node->right);
        
        left = left == INT_MIN? 0: left;
        right = right == INT_MIN? 0: right;
        
        int sum = left + right + node->val;
        
        if (sum > res.first)
        {
            res.first = sum;
            res.second = node;
        }
        
        return sum;
    }
};