#include <QCoreApplication>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* cur = nullptr;

void dfs(TreeNode* node)
{
    if (node != nullptr)
    {
        dfs(node->left);
        cur->right = node;
        cur->left = nullptr;
        cur = cur->right;
        dfs(node->right);
    }
}
TreeNode* increasingBST(TreeNode* root)
{
    if (!root)  return root;
    TreeNode* res = new TreeNode(INT_MIN);
    cur = res;
    dfs(root);
    return res->right;
}

void dfs(TreeNode* node, vector<int>& values)
{
    if (node != nullptr)
    {
        dfs(node->left,values);
        values.push_back(node->val);
        dfs(node->right,values);
    }
}
TreeNode* increasingBST2(TreeNode* root)
{
    if (!root)  return root;
    vector<int> values;
    dfs(root, values);
    TreeNode* node = new TreeNode(0);
    TreeNode* res = node;
    for(auto val : values)
    {
        TreeNode* t = new TreeNode(val);
        node->right = t;
        node = node->right;
    }
    return res->right;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TreeNode* second = new TreeNode(826);
    TreeNode* first = new TreeNode(379);
    first->left = second;
    auto res = increasingBST(first);
    while(res)
    {
        cout << res->val << endl;
        res = res->right;
    }

    return a.exec();
}
