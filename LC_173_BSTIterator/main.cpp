#include <QCoreApplication>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
    public:
        stack<TreeNode*> stSmall;

        //put all the left child into the stack
        //Space complexity O(h)
        BSTIterator(TreeNode *root) {
            //initial check
            TreeNode* cur = root;
            while(cur)
            {
                stSmall.push(cur);
                cur = cur->left;
            }
            //initialzie the stack

        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            //check the stack size
            return !stSmall.empty();
        }

        //pop up the stack
        //put the current node's right child into the stack(if it has)
        //including all the son's of this right child.
        /** @return the next smallest number */
        int next() {
           TreeNode* cur = stSmall.top();
           stSmall.pop();
           int res = cur->val;
           cur = cur->right;
           while(cur)
           {
               stSmall.push(cur);
               cur = cur->left;
           }
           return res;
        }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
