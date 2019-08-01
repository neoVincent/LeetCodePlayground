437_Path_Sum_III.cpp

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        // recursion
        if (!root) return 0;
        
        int path = 0;
        int pathRoot = pathSum(root,0,sum,path);
        int pathLeft = pathSum(root->left,sum);
        int pathRight = pathSum(root->right,sum);
        
        return pathRoot+pathLeft+pathRight;
    }
    
    int pathSum(TreeNode* node,int sum, int target, int& path)
    {
        if (!node) return 0;
        
        sum += node->val;
        if (target == sum)
            path++;
        
        pathSum(node->left,sum,target,path);
        pathSum(node->right,sum,target,path);
        
        return path;
        
    }
};