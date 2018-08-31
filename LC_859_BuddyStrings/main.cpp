#include <QCoreApplication>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

bool buddyString( string A, string B)
{
    if(A.length() != B.length() || A.empty() || B.empty()) return false;
    unordered_set<char> record;
    //indicate swap happened
    bool checked = false;
    //check for repeated alphabet when A == B
    bool repeated = false;
    //keep the index of the different alphabet, if more than 2 different chars index = -1
    int index = 0;
    for(int i = 0 ; i < A.length(); i++)
    {
        if (!repeated && !record.insert(A[i]).second) repeated = true;
        if (A[i] == B[i]) continue;
        if (index < 0) return false;
        if (checked)
        {
            if (A[index] == B[i] && B[index] == A[i])
            {
                index = -1;
                continue;
            }
            else
            {
                return false;
            }
        }
        else
        {
            checked = true;
            index = i;
        }

    }
    if (checked || repeated)
        return true;
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string A = "abcaa";
    string B = "abcbb";
    cout << buddyString(A,B) << endl;
    return a.exec();
}

