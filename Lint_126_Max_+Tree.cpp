Lint_126_Max_+Tree.cpp
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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode * maxTree(vector<int> &A) {
        vector<TreeNode*> stk;
        
        for(auto a: A)
        {
            TreeNode* cur = new TreeNode(a);
            while(!stk.empty() && stk.back()->val < cur->val)
            {
                cur->left = stk.back();
                stk.pop_back();
            }
            
            if (!stk.empty())
            {
                stk.back()->right = cur;
            }
            
            stk.push_back(cur);
        }
        return stk.front();
    }
};



