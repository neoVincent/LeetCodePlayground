#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int count = 0;
    vector<int>::iterator giter = g.begin();
    vector<int>::iterator siter = s.begin();
    while(giter != g.end() && siter != s.end())
    {
        if (*giter <= *siter)
        {
            count++;
            giter++;
            siter++;
        }
        else
        {
            siter++;
        }
    }
    return count;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
