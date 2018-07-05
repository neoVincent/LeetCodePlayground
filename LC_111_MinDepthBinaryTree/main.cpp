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


int minDepth(TreeNode* root)
{
    if(!root) return 1;

    int leftDepth = minDepth(root->left) + 1;
    int rightDepth = minDepth(root->right) + 1;
    return leftDepth > rightDepth ? rightDepth : leftDepth;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
