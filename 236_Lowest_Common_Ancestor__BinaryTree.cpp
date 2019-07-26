236_Lowest_Common_Ancestor__BinaryTree.cpp

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if (left && right) return root;
        return left?left : right;
    }
};


class Solution {
public:
    // straightforward
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // keep all the parent of the node
        unordered_map<TreeNode*, TreeNode*> parents; // child, parent
        deque<TreeNode*> que;
        
        parents[root] = nullptr;
        que.push_back(root);
        
        while(parents.find(p) == parents.end() || parents.find(q) == parents.end())
        {
            TreeNode* node = que.front();
            que.pop_front();
            
            if (node->left)
            {
                parents[node->left] = node;
                que.push_back(node->left);
            }
            
            if (node->right)
            {
                parents[node->right] = node;
                que.push_back(node->right);
            }
        }
        
        unordered_set<TreeNode*> pParents;
        while(p)
        {
            pParents.insert(p);
            p = parents[p];
        }
        
        while(pParents.find(q) == pParents.end())
        {
            q = parents[q];
        }
        return q;
    }
};