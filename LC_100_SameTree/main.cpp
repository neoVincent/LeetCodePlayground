#include <QCoreApplication>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p && q)
    {
        if (p->val == q->val)
        {
            if (isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
                return  true;
        }
    }
    else if (!p && !q)
    {
        return true;
    }

    return false;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
