654_Max_Binary_Tree.cpp

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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>::iterator left, vector<int>::iterator right)
    {
        if (left == right)
            return nullptr;
        
        auto iter = max_element(left,right);
        TreeNode* root = new TreeNode(*iter);
        root->left = constructMaximumBinaryTree(left,iter);
        root->right = constructMaximumBinaryTree(next(iter),right);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // recrusive
        return constructMaximumBinaryTree(nums.begin(),nums.end());
    }
};

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
public:
    
    TreeNode* constructMaximumBinaryTree(vector<int>& A) {
        vector<TreeNode*> stk;
        
        for(auto a : A)
        {
            TreeNode* cur = new TreeNode(a);
            while(!stk.empty() && a > stk.back()->val)
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



