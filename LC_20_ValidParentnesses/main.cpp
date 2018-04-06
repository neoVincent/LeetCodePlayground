#include <QCoreApplication>
#include <stack>
#include <QDebug>
#include <string>
#include <iostream>

using namespace std;

bool isValid(string s) {
    stack<string> st;
    map<string,string> rule;
    rule["}"] = "{";
    rule[")"] = "(";
    rule["]"] = "[";

    for(int i = 0 ; i< s.length() ; i++)
    {
        string bracket;
        bracket = s[i];
        if(rule[bracket] == "")
        {
            st.push(bracket);
        }
        else
        {
            if (!st.empty() && st.top() == rule[bracket])
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<isValid("()]{}");
    qDebug()<<isValid("()[]{}");
    qDebug()<<isValid("([]{}");
    qDebug()<<isValid("()[]{");
    qDebug()<<isValid("()[]}");
    return a.exec();
}


//rule['{'] = '}';
//rule['('] = ')';
//rule['['] = ']';

//for(char c : s)
//{
//    if(strcmp(rule[c], ''))
//    {
//        st.push(c);
//    }
//    else
//    {
//        if (strcmp(st.top() , rule[c]))
//        {
//            st.pop();
//        }
//        else
//        {
//            return false;
//        }
//    }
//}
