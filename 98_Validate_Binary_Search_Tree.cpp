98_Validate_Binary_Search_Tree.cpp
class Solution {
private:
    long preVal = LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        // in-order traverse
        if (!root) return true;
        
        if(!isValidBST(root->left)) return false;
        
        if (preVal!= LONG_MIN && (!left || preVal >= root->val))
            return false;
        
        preVal = root->val;
        
        if (!isValidBST(root->right)) return false;
        
        return true;
    }
};