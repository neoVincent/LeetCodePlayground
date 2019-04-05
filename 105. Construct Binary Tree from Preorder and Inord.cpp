
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
private:
    TreeNode* helper(vector<int>& preorder, int prei, int prej, vector<int>& inorder, int ini,int inj){
        if(prei==prej){
            return NULL;
        }
        int dis = find(inorder.begin()+ini,inorder.begin()+inj,preorder[prei])-inorder.begin()-ini;
        TreeNode* root = new TreeNode(preorder[prei]);
        root->left = helper(preorder,prei+1,prei+dis+1,inorder,ini,ini+dis);
        root->right = helper(preorder,prei+1+dis,prej,inorder,ini+dis+1,inj);
        return root;
        
    }
};
