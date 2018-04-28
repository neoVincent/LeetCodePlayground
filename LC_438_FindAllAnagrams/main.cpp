#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool sameMapValue(unordered_map<char,int> &pmap, unordered_map<char,int> &smap)
{
    for(auto iter : smap )
    {
        if (pmap[iter.first] != iter.second) return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    unordered_map<char,int> pmap;
    unordered_map<char,int> smap;

    for(int i = 0 ; i < p.size(); i++)
    {
        pmap[p[i]]++;
        smap[s[i]]++;
    }

    if (sameMapValue(pmap,smap)) res.push_back(0);

    int pSize = p.size();
    for(int i = pSize; i < s.size(); ++i)
    {
        // Remove the past effect
        char si = s[i];
        char siminus = s[i-pSize];
        smap[s[i-pSize]]--;

        smap[s[i]]++;

        if (sameMapValue(pmap,smap)) res.push_back(i-pSize+1);
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
