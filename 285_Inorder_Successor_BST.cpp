285_Inorder_Successor_BST.cpp

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // locate the node
        stack<TreeNode*> parents;
        TreeNode* cur = root;
                
        while(cur != p)
        {
            parents.push(cur);
            if (cur->val > p->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        
        // find successor 
        if (cur->right)
        {
            cur = cur->right;
            while(cur->left)
                cur = cur->left;
            return cur;
        }
        else if (!parents.empty())
        {
            TreeNode* p = parents.top();
            parents.pop();
            
            if (cur == p->left)
                return p;
            
            while(!parents.empty() && cur == p->right)
            {
                cur = p;
                p = parents.top();
                parents.pop();
            }
            return cur == p->right? nullptr : p;
        }
        else
            return nullptr;
            
    }
};

class Solution {
public:
    // recursion, divide and conquer
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
         // base case
        if (!root) return nullptr;
        
        if (root->val <= p->val)
            return inorderSuccessor(root->right,p);
        else
        {
            TreeNode* left = inorderSuccessor(root->left,p);
            return !left ? root : left;
        }
    }
};


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        if (p->right)
        {
            p = p->right;
            while(p->left)
                p = p->left;
            return p;
        }
        
        TreeNode* succ = nullptr;
        TreeNode* ancestor = root;
        while(ancestor != p)
        {
            if (ancestor->val > p->val)
            {
                succ = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return succ;
    }
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* candidate = NULL;
    while (root)
        root = (root->val > p->val) ? (candidate = root)->left : root->right;
    return candidate;
}