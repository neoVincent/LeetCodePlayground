510_Inorder_Successor_BST_II.cpp

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return nullptr;
        
        if (node->right)
        {
            node = node->right;
            while(node->left)
                node = node->left;
            return node;
        }
        
        Node* p = node->parent;
        
        while(p && p->right == node)
        {
            node = p;
            p = node->parent;
        }
        return p;
    }
};
