#ifndef TREENODE_H
#define TREENODE_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

namespace CLRS {
namespace BST {

void inorderTreeWalk(TreeNode* tree);



} // TreeNode

} // CLRS


#endif // TREENODE_H
