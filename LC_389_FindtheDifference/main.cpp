#include <QCoreApplication>
#include <string>

using namespace std;


char findTheDifference(string s, string t)
{
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    for(auto iterS = s.begin(), iterT = t.begin(); iterS != s.end(); iterS++, iterT++)
    {
        if(*iterS != *iterT) return *iterT;
    }
    return t[s.size()-1];

//    vector<int>v(26,0);
//    for(int i=0;i<s.size();++i){
//        v[t[i]-'a']++;
//        v[s[i]-'a']--;
//    }
//    v[t[t.size()-1]-'a']++;
//    for(int i=0;i<v.size();i++)
//        if(v[i]==1)
//            return 'a'+i;
//    return '\0';
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
