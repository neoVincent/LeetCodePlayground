#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* convertion(int p, int q, vector<int>& nums)
{
    if (p < q)
    {
        int mid = p+ (q-p)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = convertion(p,mid,nums);
        node->right = convertion(mid+1, q, nums);
        return node;
    }
    return nullptr;



}
TreeNode* sortedArrayToBST(vector<int>& nums)
{
    TreeNode* node = convertion(0,nums.size(),nums);
    return node;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
