#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> countBits(int num)
{
    vector<int> bits(num+1);
    bits[0] = 0;
    for (int i = 1; i < num + 1; i++)
    {
        if (i&(i-1) == 0)
        {
            bits[i] = 1;
        }
        else
        {
            bits[i] = bits[i&(i-1)] + 1;
        }
    }
    return bits;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
