#include <QCoreApplication>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int subTreelength(TreeNode* node)
{
    if (!node) return 0;
    int left = subTreelength(node->left)+1;
    int right = subTreelength(node->right)+1;
    return max(left,right);
}

int treenodelength(TreeNode* node)
{
    if (!node) return 0;
    return subTreelength(node->left) + subTreelength(node->right);
}
int treeDiameter(TreeNode* root, int& maxLen)
{
    if (!root) return maxLen;
    if (root->left)
    {
        maxLen = treeDiameter(root->left,maxLen);
    }
    maxLen = max(maxLen,treenodelength(root));
    if (root->right)
    {
        maxLen = treeDiameter(root->right,maxLen);
    }
    return maxLen;
}
int diameterOfBinaryTree(TreeNode* root)
{
    int maxLen = 0;
    return treeDiameter(root,maxLen);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
