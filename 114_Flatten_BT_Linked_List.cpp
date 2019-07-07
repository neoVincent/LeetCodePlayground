114_Flatten_BT_Linked_List.cpp

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        if(!root) return;
        if(lastNode)
        {
            lastNode->left = nullptr;
            lastNode->right = root;
        }
        lastNode = root;
        TreeNode* right = root->right; // it will be updated in the following traverse
        flatten(root->left);
        flatten(right);
    }
    TreeNode* lastNode = nullptr;
};