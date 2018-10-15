#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;



string getStringID(string& str)
{
    string id;
    int primary = 0;
    for(char c : str)
    {
        int n = c-'a';
        int t = 1<<n;
        if ((primary & t) != 0)
        {
            //has duplicate key
            id.append("#"+to_string(t));
        }
        else
        {
            primary |= 1<<n;
        }
    }
    id.append("#"+to_string(primary));
    return id;

}
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string,int> idRec;
    vector<vector<string>> res;
    for(string str : strs)
    {
        string id = getStringID(str);
        if (idRec.find(id) != idRec.end())
        {
            res[idRec[id]-1].push_back(str);
        }
        else
        {
            idRec[id] = res.size()+1;
            vector<string> vec{str};
            res.push_back(vec);
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<string> strs
    {
        "boo","bob","eat","tea"
    };
    auto res = groupAnagrams(strs);
    return a.exec();
}
