#include <QCoreApplication>
#include <string>
#include <iostream>

using namespace std;

bool validPalindrome(string& s, int lo, int hi, int count)
{
    if (count > 1) return false;
    while (lo < hi)
    {
        if (s[lo] != s[hi])
        {
            return validPalindrome(s,lo+1,hi,1) || validPalindrome(s,lo,hi-1,1);
        }
        lo++;
        hi--;
    }
    return true;
}
bool validPalindrome(string s)
{
        int lo = 0, hi = s.size() - 1;
        return validPalindrome(s, lo, hi, 0);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}


