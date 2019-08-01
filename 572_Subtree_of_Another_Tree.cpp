572_Subtree_of_Another_Tree.cpp

class Solution {
public:
    // 1. Locate the root 
    // 2. check identity 
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;

        if (s->val == t->val && isSame(s,t)) return true;
        
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    
    bool isSame(TreeNode* s, TreeNode* t )
    {
        if (!s && !t ) return true;
        
        if (s && t)
        {
            if (s->val == t->val)
                return isSame(s->left,t->left) && isSame(s->right,t->right);
            return false;
        }
        return false;
    }
};

class Solution {
public:
    // pre-order, transoform to substring problem
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string s1,s2;
        preOrder(s,s1);
        preOrder(t,s2);
        return s1.find(s2) != string::npos;
    }
    
    void preOrder(TreeNode* t, string& str)
    {
        if (!t)
        {
            str.push_back('x');
            return;
        }
        
        str.push_back(t->val);
        
        preOrder(t->left,str);
        preOrder(t->right,str);
    }
};
