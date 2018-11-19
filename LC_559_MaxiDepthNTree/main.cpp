#include <QCoreApplication>
#include <vector>
#include <iostream>

using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Given a n-ary tree, find its maximum depth.
int maxDepth(Node* root)
{
    if (!root) return 0;
    int res = 1;
    for(auto node : root->children)
    {
        int depth = maxDepth(node) + 1;
        res = max(depth,res);
    }
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
