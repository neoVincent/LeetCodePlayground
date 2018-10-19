#include <QCoreApplication>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int longestUnivaluePath(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = longestUnivaluePath(root->left);
    int right = longestUnivaluePath(root->right);

    if (root->left && root->left->val == root->val)
    {
        return left + 1;
    }


    if (root->right && root->right->val == root->val)
    {
        return right + 1;
    }

    return max(left,right);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
