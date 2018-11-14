#include <QCoreApplication>
#include <string>
#include <iostream>

using namespace std;

int repeatedStringMatch(string A, string B) {
    if (A.find(B) != string::npos) return 1;

    //concate A with itself til A.size >= B.size
    int counter = 1;
    string a = A;
    while(a.size() < B.size())
    {
       a.append(A);
       counter++;
    }
    if(a.find(B) != string::npos)
    {
       cout << a.size() << endl;
       return counter;
    }
    if (a.append(A).find(B) != string::npos) return counter +1;
    return -1;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string a1 ="abc";
    string a2 ="cabcabca";
    string a3 = "abcabcabc";
    cout << a3.find(a2)<<endl;
    repeatedStringMatch(a1,a2);
    return a.exec();
}
