100_Same_Tree.cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string str1,str2;
        preOrder(p,str1);
        preOrder(q,str2);
        return str1 == str2;
    }
    
    void preOrder(TreeNode* p, string& str)
    {
        if (!p)
        {
            str.push_back('X');
            return;
        }
        str.append(to_string(p->val));
        preOrder(p->left,str);
        preOrder(p->right, str);
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string str1,str2;
        preOrder(p,str1);
        preOrder(q,str2);
        cout <<"str1 " << str1<<endl;
        cout <<"str2 " << str2<<endl;
        return str1 == str2;
    }
    
    void preOrder(TreeNode* p, string& str)
    {
        if (!p)
        {
            str.push_back('X');
            return;
        }
        preOrder(p->left,str);
        preOrder(p->right, str);
        str.append(to_string(p->val));
    }
};