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
void inorderTreeWalkNonRecursive(TreeNode* tree);
void preoderTreeWalk(TreeNode* tree);
void postorderTreeWalk(TreeNode* tree);
TreeNode* treeSuccessor(TreeNode* tree, TreeNode* node);
TreeNode* treePredecessor(TreeNode* tree, TreeNode* node);
TreeNode* maximum(TreeNode* node);
void treeInsert(TreeNode* tree, TreeNode* node);
void treeDelete(TreeNode* tree, TreeNode* node);
void transplant(TreeNode*tree, TreeNode* from, TreeNode* to);

} // TreeNode

} // CLRS


#endif // TREENODE_H
