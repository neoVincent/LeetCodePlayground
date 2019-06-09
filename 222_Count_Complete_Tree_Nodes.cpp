222_Count_Complete_Tree_Nodes.cpp

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
    
    bool checkNode(TreeNode* root,int code,int h){
        int mask = 1 << (h-1);
        cout <<"Mask " << mask << endl;
        cout <<"Code " << code << endl;
        for(int i = 0; i < h;i++){
            if((code & mask) == mask){
                cout <<"Move right"<<endl;
                root = root->right;
            }else{
                cout <<"Move left" << endl;
                root = root->left;
            }
            mask >>= 1;
        }
        return root != NULL;
    }
    
    int countNodes(TreeNode* root) {
        // initial check
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        
        int h = 0;
        TreeNode* p = root;
        while(p)
        {
            p = p->left;
            h++;
        }
        h = h-1;
        cout <<"Height " << h << endl;
        
        int sum = pow(2,h)-1;
        cout <<"Nodes - last " << sum << endl;
        
        // binary search to check the last layer
        int left = 0;
        int right = pow(2,h)-1; // the full size of the last layer
        int n = 0;
        
        cout << "last layer range " << right << endl;
        
        while(left <= right)
        {
            int mid = (right - left) /2 + left;
            cout << "Mid " << mid << endl;
            if (checkNode(root,mid,h))
            {
                cout <<"Find the node" << endl;
                n = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            
            cout <<"Left " << left <<"  Right " << right << endl;
            cout <<"N " << n << endl;
        }
        
        return (n+1)+sum;
        
    }
};