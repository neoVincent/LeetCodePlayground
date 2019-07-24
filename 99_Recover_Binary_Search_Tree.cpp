99_Recover_Binary_Search_Tree.cpp
class Solution {
private:
    TreeNode* preNode = nullptr;
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;
    
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        while(!stk.empty() || root)
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            
            if (preNode && preNode->val > root->val)
            {
                if (!x)
                    x = preNode;
                y = root;
            }
            preNode = root;
            root = root->right;
        }
        swap(x->val,y->val);
    }
    
};