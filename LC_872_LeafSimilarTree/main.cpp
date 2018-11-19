#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void leafValueSeq(TreeNode* node, vector<int>& sequence)
{
    if (node)
    {
        if (!node->left && !node->right)
        {
            sequence.push_back(node->val);
        }
        leafValueSeq(node->left,sequence);
        leafValueSeq(node->right,sequence);
    }
}
bool leafSimilar(TreeNode* root1, TreeNode* root2)
{
    vector<int> seq1,seq2;
    leafValueSeq(root1, seq1);
    leafValueSeq(root2, seq2);
    return equal(seq1.begin(),seq1.end(),seq2.begin());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    cout << leafSimilar(node1,node2);
    return a.exec();
}
