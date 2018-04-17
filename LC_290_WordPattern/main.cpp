#include <QCoreApplication>
#include <QDebug>
#include <string>
#include <unordered_map>

using namespace std;

string findNextPhrase(string& str)
{
    int index = str.find_first_of(" ");
    string res = str.substr(0,index);
    str = str.substr(index+1);
    return res;
}

bool wordPattern(string pattern, string str)
{
    unordered_map<char, string> mapper;
    unordered_map<string, char> remapper;
    int comparedSize = 0;
    int fullSize = str.size();
    for(int i = 0 ; i < pattern.size(); i++)
    {
        string phrase = findNextPhrase(str);
        if (mapper.find(pattern[i]) == mapper.end() && remapper.find(phrase) == remapper.end())
        {
            mapper[pattern[i]] = phrase;
            remapper[phrase] = pattern[i];
            comparedSize += phrase.size();
        }
        else if (mapper[pattern[i]] == phrase && (remapper[phrase] == pattern[i]) )
        {
            comparedSize += phrase.size();
            continue;
        }
        else return false;

    }
    if ((comparedSize + pattern.size() -1 ) != fullSize) return false;
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string patter = "abba";
    string str = "dog cat cat dog";
    qDebug() << wordPattern(patter,str) << endl;
    return a.exec();
}
