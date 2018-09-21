#include <QCoreApplication>
#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

void pathToLeaf(vector<string>& res, string path, TreeNode* node)
{
   if (!node)
   {
       return;
   }
   path.append("->" + to_string(node->val));
   if (node->left || node->right)
   {
       pathToLeaf(res,path,node->left);
       pathToLeaf(res,path,node->right);
   }
   else
   {
       res.push_back(path);
       return;
   }
}
vector<string> binaryTreePaths(TreeNode* root)
{

   vector<string> res;
   if (root)
   {
       string path = to_string(root->val);
       pathToLeaf(res,path,root->left);
       pathToLeaf(res,path,root->right);
       if (!root->left && !root->right)
       {
           res.push_back(path);
       }
       return res;
   }
   return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
