#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> findAnagrams(string s, string p)
{


    int x = 0, y = 0;
    vector<int> res;

    while(x < s.size() - p.size()+1)
    {
        unordered_map<char,int> dict;
        for (char c : p)
        {
            dict[c]++;
        }

        y = x;
        int wordSize = p.size();
        cout << "iteration start";
        while(wordSize > 0 && y < s.size())
        {
            cout << s[y] << " ";
            if ((--dict[s[y]]) < 0  )
            {
                break;
            }
            y++;
            wordSize--;
        }
        cout << "iteration end" << endl;
        if (wordSize == 0)
        {
            res.push_back(x);
            cout <<"match index " <<x<<endl;

        }
        x++;
    }
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string s = "cbaebabacd";
    string p = "abc";
    auto res = findAnagrams(s,p);
    cout << "Kick the result"<<endl;
    for(auto ele : res)
        cout << ele<<endl;

    return a.exec();
}
