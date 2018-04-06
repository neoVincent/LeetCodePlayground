#include <QCoreApplication>
#include <QDebug>

using namespace std;

bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int begin = 1;
    int end = n;
    int mid = begin + (end - begin) / 2;

    while(begin < end)
    {
        if (isBadVersion(mid))
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
        // mid = (begin + end) / 2 causes overflow!!!
        mid = begin + (end - begin) / 2;
    }

    if (isBadVersion(begin)) return begin;
    else return begin + 1;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
