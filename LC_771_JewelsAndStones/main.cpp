#include <QCoreApplication>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int numJewelsInStones(string J, string S)
{
/*
    //replace string
    int pos = S.find(J);
    while(pos != string::npos)
    {
        S.replace(pos,pos+J.length(),"#");
        //find_first_index_of Finds the first character equal
        //to one of the characters in the first count characters
        //of the character string
        //str = "#A" str.find_first_index_of(str,"aA") return 1.
        pos = S.find(J);
    }
*/
    unordered_map<char,int> record;

    for(char c : J)
    {
        record[c]++;
    }

    int res = 0;
    for(char c : S)
    {
        if (record[c] > 0)
        {
            res++;
        }
    }
    return res;

//    int count = 0;
//    string::const_iterator s_it = S.begin();
//    string::const_iterator s_end = S.end();
//    while (s_it != s_end) {
//        std::size_t pos = J.find(*s_it);
//        if (pos != string::npos) count++;
//        s_it++;
//    }
//    return count;

}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    string J = "z";
    string S = "ZZ";
    cout << numJewelsInStones(J,S) << endl;

    return app.exec();
}
