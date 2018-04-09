#include <QCoreApplication>
#include <string>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length()) return false;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
