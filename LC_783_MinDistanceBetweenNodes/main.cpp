#include <QCoreApplication>

#include <stack>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

int res = __INT_MAX__, preVal = -__INT_MAX__;

int minDiffInBST(TreeNode* root)
{

    if (root->left) minDiffInBST(root->left);

    if (preVal != -__INT_MAX__ )
    {
        res = min(res,root->val - preVal);
    }
    preVal = root->val;

    if (root->right) minDiffInBST(root->right);
    return res;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
