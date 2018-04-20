#include <QCoreApplication>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};


int res = __INT_MAX__, preVal = __INT_MAX__;

int getMinimumDifference(TreeNode* root)
{
    if(root->left)
    {
        getMinimumDifference(root->left);
    }
    if (preVal != __INT_MAX__)
    {

        int diff = abs(root->val - preVal);
        res = min(res,diff);
    }
    preVal = root->val;
    if  (root->right) getMinimumDifference(root->right);

    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
