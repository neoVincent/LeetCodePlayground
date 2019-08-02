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

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        // prefix Sum
        if (!root) return 0;
        
        unordered_map<int,int> map;
        return pathSum(root,sum,0,map);
        
    }
    
    int pathSum(TreeNode* root, int target, int sum, unordered_map<int,int>& map)
    {
        if(!root) return 0;
       
        int path = 0;
        sum += root->val;
        path = map[sum - target];
        
        if (sum == target)
            path++;
        
        map[sum]++;
        path += pathSum(root->left,target,sum,map);
        path += pathSum(root->right,target,sum,map);
        map[sum]--;
        
        return path;
    }
};