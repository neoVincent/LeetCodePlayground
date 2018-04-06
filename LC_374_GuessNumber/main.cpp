#include <QCoreApplication>

int guess(int num);

int guessNumber(int n)
{
    int begin = 1;
    int end = n;
    int mid = begin + (end - begin) / 2;
    while(begin < end)
    {
        switch(guess(mid))
        {
        case 1 : begin = mid + 1;break;
        case -1 : end = mid - 1;break;
        case 0: return mid;
        }

        mid = begin + (end - begin) / 2;
    }

    if (guess(begin) == 0 ) return begin;
    return -1;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
