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

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>> res;
    queue<TreeNode*> treeQueue;

    if(!root) return res;

    TreeNode* node = root;
    treeQueue.push(node);
    while(!treeQueue.empty())
    {
        int sizeLevel = treeQueue.size();
        vector<int> value;
        for(int i = 0 ; i < sizeLevel ; i++)
        {
            TreeNode* tmp = treeQueue.front();
            treeQueue.pop();
            value.push_back(tmp->val);

            if(tmp->left) treeQueue.push(tmp->left);
            if(tmp->right) treeQueue.push(tmp->right);
        }

        res.insert(res.begin(),value);
    }
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
