#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

vector<int> partitionLabels(string S)
{
    vector<int> res;
    int lastPos[26];
    int i = 0;
    for(char c : S)
    {
        lastPos[c - 'a'] = i++;
    }

    int radius = 0;
    i = 0;
    int startPos = 0;
    for(char c : S)
    {
        radius = max(radius,lastPos[c-'a']);
        if (radius == i++)
        {
            res.push_back(radius+1 - startPos);
            startPos = radius + 1;
        }
    }


    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string S = "ababcbacadefegdehijhklij";
    auto res = partitionLabels(S);
    for(auto index : res)
        cout << index<<endl;
    return a.exec();
}
