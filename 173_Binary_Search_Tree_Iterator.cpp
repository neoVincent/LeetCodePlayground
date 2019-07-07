173_Binary_Search_Tree_Iterator.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stk;
    
public:
    BSTIterator(TreeNode* root) {
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        if (hasNext())
        {
            TreeNode* node = stk.top();
            stk.pop();
            TreeNode* rightSon = node->right;
            while(rightSon)
            {
                stk.push(rightSon);
                rightSon = rightSon->left;
            }
            return node->val;
        }
        
        return INT_MIN;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */