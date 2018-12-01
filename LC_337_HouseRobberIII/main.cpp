#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>

using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
class Solution {
public:

    pair<int,int> thief(TreeNode *node) {
        if (node == nullptr) return {0,0};
        auto lval = thief(node->left);
        auto rval = thief(node->right);
        int with = rval.second + lval.second + node->val;
        int without = max(rval.second, rval.first) + max(lval.second,lval.first);
        return {with, without};
    }

    int rob(TreeNode* root) {
        pair<int,int> p = thief(root);
        return max(p.first, p.second);
    }
};
