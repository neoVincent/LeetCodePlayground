#include "tree_node.h"
#include <iostream>
#include <stack>

using namespace CLRS::BST;
using namespace std;


void printNode(TreeNode* node)
{
    cout << "  " << node->val << "  ";
}

TreeNode* findParent(TreeNode* root, TreeNode* node)
{
    TreeNode* parent = nullptr;
    while(root && root->val != node->val)
    {
        parent = root;
        if (root->val > node->val) root = root->left;
        else if (root->val < node->val) root = root->right;
    }
    return parent;
}

void inorderTreeWalk(TreeNode *tree)
{
    if (tree != nullptr)
    {
        inorderTreeWalk(tree->left);
        printNode(tree);
        inorderTreeWalk(tree->right);
    }
}


void inorderTreeWalkNonRecursive(TreeNode *tree)
{
    stack<TreeNode*> tnStack;
    TreeNode* node = tree;

    while(node != null || !tnStack.empty())
    {
        while(node)
        {
            tnStack.push(node);
            node = node->left;
        }
        printNode(node);

        node = tnStack.top();
        tnStack.pop();

        node = node->right;
    }
}

void preoderTreeWalk(TreeNode *tree)
{
    if (tree)
    {
        printNode(tree);
        preoderTreeWalk(tree->left);
        preoderTreeWalk(tree->right);
    }
}

void postorderTreeWalk(TreeNode *tree)
{
    if (tree)
    {
        postorderTreeWalk(tree->left);
        postorderTreeWalk(tree->right);
        printNode(node);
    }
}


TreeNode *treeSuccessor(TreeNode* tree , TreeNode *node)
{
    if (node == nullptr ) return nullptr;
    TreeNode* successor = nullptr;
    if (node->right != nullptr)
    {
        successor = node->right;
        while(successor->left) successor = successor->left;
        return successor;
    }
    else
    {
       //collect its ancester
        stack<TreeNode*> parents;
        TreeNode* root = tree;
        while(root && root->val != node->val)
        {
            if (root->val > node->val)
            {
                root = root->left;
                parents.push(root);
            }
            else if (root->val < node->val)
            {
                root = root->right;
                parents.push(root);
            }
        }
        TreeNode* parent = nullptr;
        TreeNode* grand = nullptr;
        do
        {
            parent = parents.top();
            parents.pop();
            grand = parents.top();
            parents.pop();
        }while(grand->left = parent);

        return grand;
    }
}

TreeNode *treePredecessor(TreeNode *tree, TreeNode *node)
{
    if (node == nullptr ) return nullptr;
    if (node->left) return maximum(node);
    else
    {
        //collect its ancester
         stack<TreeNode*> parents;
         TreeNode* root = tree;
         while(root && root->val != node->val)
         {
             if (root->val > node->val)
             {
                 root = root->left;
                 parents.push(root);
             }
             else if (root->val < node->val)
             {
                 root = root->right;
                 parents.push(root);
             }
         }
         TreeNode* parent = nullptr;
         TreeNode* grand = nullptr;
         do
         {
             parent = parents.top();
             parents.pop();
             grand = parents.top();
             parents.pop();
         }while(grand->right = parent);
         return grand;
    }
}

TreeNode *maximum(TreeNode *tree)
{
    TreeNode* node = tree;
    while(node && node->right) node = node->right;
    return node;
}

void treeInsert(TreeNode *tree, TreeNode *node)
{
    //Tree and node should not be null
    if (!node || !tree) return;

    TreeNode* parent = nullptr;
    while(tree)
    {
        parent = root;
        if (tree->val > node->val)
        {
            tree = tree->left;
        }
        else if(tree->val < node->val)
        {
            tree = tree->right;
        }
    }

    //parent should not be null becase tree is not null
    if (parent->val > node->val) parent->left = node;
    else parent->right = node;
}

void treeDelete(TreeNode *tree, TreeNode *node)
{
    if (!node->left)
    {
        transplant(tree,node->right,node);
    }
    else if (!node->right)
    {
        transplant(tree,node->left,node);
    }
    else
    {
        TreeNode* successor = treeSuccessor(tree,node);
        if (successor != node->left && successor != node->right)
        {
            transplant(tree,successor->right,successor);
            successor->right = node->right;
        }

        transplant(tree,successor,node);
        successor->left = node->left;
    }
}

void transplant(TreeNode *tree, TreeNode *from, TreeNode *to)
{
    TreeNode* p = findParent(tree,to);
    if (!p) return;
    if (p->left == to)
    {
        p->left = from;
    }
    else
    {
        p->right = to;
    }
}
