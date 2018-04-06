#include <QCoreApplication>
#include <vector>
#include <QDebug>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    int size = digits.size();
    while(!digits.empty())
    {
        if(digits.back() == 9)
        {
            digits.pop_back();
        }
        else
        {
            int t = digits.back();
            digits.pop_back();
            digits.push_back(t+1);
            break;
        }
    }
   int diffSize = size - digits.size();
   if (diffSize == size) digits.push_back(1);
   for(int i = 0; i< diffSize ; i++) digits.push_back(0);
   return digits;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
