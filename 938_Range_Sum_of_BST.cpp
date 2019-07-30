938_Range_Sum_of_BST.cpp

class Solution {
private:
    int res = 0;
    bool foundLeft;
    bool foundRight;
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        // in order 
        if (!root)  return res;
        
        rangeSumBST(root->left,L,R);
        
        if (foundLeft || root->val == L)
        {
            res += root->val;
            foundLeft = true;
        }
        
        if (root->val == R)
        {
            foundLeft = false;
            return res;
        }
        else
        {
            rangeSumBST(root->right,L,R);
        }
        
        return res;
    }
};



class Solution {
private:
    int res;
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        res = 0;
        dfs(root,L,R);
        return res;
    }
    
    void dfs(TreeNode* node, int L, int R)
    {
        if(node)
        {
            if (node->val >= L && node->val <= R)
                res += node->val;
            if (node->val > L)
                dfs(node->left,L,R);
            if (node->val < R)
                dfs(node->right,L,R);
        }
    }
};

class Solution {
public:
    // iternation stack
    int rangeSumBST(TreeNode* root, int L, int R) {
        stack<TreeNode*> stk;
        int res = 0;
        stk.push(root);
        
        while(!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop();
            if (node)
            {
                if (node->val <= R && node->val >= L)
                {
                    res+= node->val;
                }
                if (node->val > L)
                    stk.push(node->left);
                if (node->val < R)
                    stk.push(node->right);
            }
        }
        
        return res;      
    }
};
