#include <QCoreApplication>

bool isValidBSTUtil(TreeNode* node, long min, long max)
{
    if (node == nullptr ) return true;
    return ((min < node->val) && (node->val < max) && isValidBSTUtil(node->left, min, node->val) && isValidBSTUtil(node->right,node->val,max)  );
}
bool isValidBST(TreeNode* root) {
    return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return bst(root, NULL, NULL);
    }
    bool bst(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == NULL)    return true;
        if(min && root->val <= min->val || max && root->val >= max->val)
            return false;
        return bst(root->left, min, root) && bst(root->right, root, max);
    }
};
