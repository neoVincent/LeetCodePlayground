124_Binary_Tree_Maximum_Path_Sum.cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int max_sum = INT_MIN;
    
public:
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
    
    int max_gain(TreeNode* node)
    {
        if (node == nullptr) return 0;
        
        int left_gain = max(0,max_gain(node->left));
        int right_gain = max(0,max_gain(node->right));
        
        max_sum = max(max_sum, left_gain+right_gain+node->val);
        
        return max(left_gain,right_gain) + node->val;
                            
    }
};