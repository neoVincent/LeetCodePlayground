#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool dfs(TreeNode* node, int& sum, const int& target)
{
    if (node)
    {
        sum += node->val;
        if (dfs(node->left,sum,target)) return true;
        if (!node->left && !node->right && sum == target) return true;
        if (dfs(node->right,sum,target)) return true;
        sum -= node->val;
    }

    return false;
}


bool hasPathSum(TreeNode* root, int sum)
{
    int pathSum = 0;
    return dfs(root,pathSum,sum);
}

bool hasPathSum2(TreeNode* root, int sum) {
        if(root==NULL)
        {

            return false;
        }
        if(root->left ==NULL && root->right==NULL && root->val==sum)
            return true;
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

