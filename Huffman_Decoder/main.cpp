#include <QCoreApplication>
#include <string>
#include <unordered_map>
#include <stack>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <iomanip>
#include <limits>
#include <array>

using namespace std;

struct TreeNode
{
    char c;
    bool leaf;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c1): c(c1) {left = nullptr; right = nullptr; leaf = false;}
};

/**
 * @brief build a binary tree for the code. Each char code is in the leaf
 * 0 is left, 1 is right
 * @param codes
 * @return
 */
TreeNode* buildTree(vector<string> codes)
{
    TreeNode* root = new TreeNode('#');
    for(string c : codes)
    {
        //parse code
//        istringstream record(c);
//        string alpha;
//        string code;
//        record >> alpha;
//        record >> code;

        istringstream record(c);
        string token[2];
        string alpha;
        string code;

        for(int i = 0; i<2; i++)
        {
            getline(record,token[i],'\t');
        }
        alpha = token[0];
        code = token[1];


        TreeNode* n = root;
        for(int i = 0 ; i< code.size() ; i++)
        {
            int digital = code[i] - '0';
            // 0 is left, 1 is right
            if (digital == 0 && n->left == nullptr)
            {
                TreeNode* t = new TreeNode('#');
                n->left = t;
                n = n->left;
                continue;
            }
            if (digital == 0 && n->left != nullptr)
            {
                n = n->left;
                continue;
            }
            if (digital == 1 && n->right == nullptr)
            {
                TreeNode* t = new TreeNode('#');
                n->right = t;
                n = n->right;
                continue;
            }
            if (digital == 1 && n->right != nullptr)
            {
                n = n->right;
                continue;
            }
        }
        n->leaf = true;
        if (alpha == "[newline]")
        {
            n->c = '\n';
            cout << "New line"<<endl;
        }
        else
        {
            n->c = alpha[0];
            cout << "Char: " <<c <<endl;
        }

    }
    return root;
}
string decode(vector<string> codes, string encoded)
{
    TreeNode* root = buildTree(codes);
    if (!root) return "";
    string res = "";
    TreeNode* cur = root;
    for(char c : encoded)
    {
        if (cur && cur->leaf)
        {
            string t(1,cur->c);
            res.append(t);
            cout<<"Found: "<<cur->c<<endl;
            cur = root;
        }
        int digital = c-'0';
        if (cur && digital == 1)
        {
            cur = cur->right;
        }
        else if (cur)
        {
            cur = cur->left;
        }
    }
    if (cur && cur->leaf)
    {
        cout << "Found: " << cur->c<< endl;
        res.append(string(1,cur->c));
    }

    return res;
}

/**
 * @brief use a hashmap to build the code for char.
 * @param codes
 * @param minSize: the minimum length for the code in the map
 * @return
 */
unordered_map<string,char> buildMap(vector<string> codes, int& minSize)
{
    unordered_map<string,char> codeMap;
    for(string c : codes)
    {
//        istringstream record(c);
//        string alpha;
//        string code;
//        record >> alpha;
//        record >> code;

        istringstream record(c);
        string token[2];
        string alpha;
        string code;

        for(int i = 0; i<2; i++)
        {
            getline(record,token[i],'\t');
        }
        alpha = token[0];
        code = token[1];
        cout << "Alpha: "<<alpha <<"Code: " << code<<endl;
        if (code.size() < minSize)
        {
            minSize = code.size();
        }

        if (alpha == "[newline]")
        {

            codeMap[code] = '\n';
        }
        else
        {
            codeMap[code] = alpha[0];
        }

    }
    return codeMap;
}
string decode2(vector<string> codes, string encoded)
{
    if (codes.size() == 0 || encoded == "") return "";
    int minSize = INT_MAX;
    unordered_map<string,char> codeMap = buildMap(codes,minSize);
    string tmp="";
    string res="";
    for(char c : encoded)
    {
        tmp.append(string(1,c));
        //Avoid the unecessary comparions time
        //we can compare current tmp length with minimum size of code
        if (tmp.size() >= minSize && codeMap.find(tmp) != codeMap.end())
        {
            res.append(string(1,codeMap[tmp]));
            tmp = "";
        }
    }
    if (tmp != "" && codeMap.find(tmp) != codeMap.end())
    {
        res.append(string(1,codeMap[tmp]));
    }
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    vector<string> codes =
    {
        "a\t001",
        "b	100101",
        "c	110001",
        "d	100000",
        "[newline]	111111",
        "p	111110",
        "q	000001",
        "m\t101"
    };
    vector<string> codes2 =
    {
        "a  100",
        "b 111"
    };
    string encoded2 = "100111";
    string encoded = "111110000001001001111111100101110001111110101";
    cout << decode2(codes, encoded) << endl;
//    decode(codes, encoded);

    return app.exec();
}
