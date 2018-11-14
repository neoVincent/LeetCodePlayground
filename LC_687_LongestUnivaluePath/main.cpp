#include <QCoreApplication>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxlen = 0;

int longestUnivaluePathUtil(TreeNode* root)
{
    if (root == nullptr) return  0;
    int leftPath = longestUnivaluePathUtil(root->left);
    int rightPath = longestUnivaluePathUtil(root->right);
    int left = 0, right = 0;
    if (root->left && root->left->val == root->val)
    {
        left = leftPath + 1 + left;
    }
    if (root->right && root->right->val == root->val)
    {
        right = rightPath + 1 + right;
    }
    maxlen = max(maxlen,right+left);
    return max(right,left);
}

int longestUnivaluePath(TreeNode* root)
{
    longestUnivaluePathUtil(root);
    return maxlen;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
