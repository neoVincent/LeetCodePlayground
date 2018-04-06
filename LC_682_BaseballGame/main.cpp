#include <QCoreApplication>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int calPoints(vector<string>& ops)
{
    stack<int> val;
    for(string elem : ops)
    {
        switch(*elem.c_str())
        {
        case'+':
            if (val.size() >=2 )
            {
                int a = val.top();
                val.pop();
                int b = val.top();
                val.push(a);
                val.push(a+b);
            }
            break;
        case 'D':
            val.push(val.top()*2);
            break;
        case 'C':
            val.pop();
            break;
        default:
            val.push(stoi(elem));
        }
    }
    int res = 0;
    while(!val.empty())
    {
        res += val.top();
        val.pop();
    }
    return res;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
