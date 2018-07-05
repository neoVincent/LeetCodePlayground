#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool compare(TreeNode* nodeA, TreeNode* nodeB)
{
    if (!nodeA && !nodeB) return true;
    if (!nodeA && nodeB || nodeA && !nodeB) return false;

    if (nodeA->val == nodeB->val)
    {
        return compare(nodeA->left,nodeB->right) && compare(nodeA->right, nodeB->left);
    }
    else
    {
        return false;
    }

}

bool isSymmetric(TreeNode* root)
{
    if (!root) return true;
    return compare(root->left,root->right);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
