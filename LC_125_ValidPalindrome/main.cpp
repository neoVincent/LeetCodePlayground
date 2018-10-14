#include <QCoreApplication>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

bool isPalindrome(string s)
{
    if (s.length() == 0) return true;
    char* begin = &s[0];
    char* end = &s[s.length()-1];
    while(end - begin > 0)
    {
        if (isalnum(*begin) && isalnum(*end))
        {
            if (tolower(*begin) != tolower(*end))
            {
                return false;
            }
            end--;
            begin++;
        }
        else if (!isalnum(*begin))
        {
            begin++;
        }
        else
        {
            end--;
        }

    }
//    cout << tolower(*begin)<<endl;
//    cout << tolower(*end)<<endl;
    return true;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << isPalindrome("abb") << endl;
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
    return a.exec();
}
