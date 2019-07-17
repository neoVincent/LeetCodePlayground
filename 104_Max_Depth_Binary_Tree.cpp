104_Max_Depth_Binary_Tree.cpp

class Solution {
public:
    
    int maxDepth(TreeNode* root) 
    {
        if(!root) return 0;
        return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};

class Solution {
public:
    // BFS
    
    int maxDepth(TreeNode* root) 
    {
        if (!root) return 0;
        
        deque<TreeNode*> que;
        int path = 0;
        que.push_back(root);
        
        while(!que.empty())
        {
            int size = que.size();
            while(size-- > 0)
            {
                TreeNode* node = que.front();
                que.pop_front();
                
                if (node->left)
                    que.push_back(node->left);
                if (node->right)
                    que.push_back(node->right);
            }
            path++;
        }
        
        return path;
    }
};
