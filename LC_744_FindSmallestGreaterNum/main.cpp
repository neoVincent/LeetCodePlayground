#include <QCoreApplication>
#include <vector>
#include <QDebug>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target)
{
    int begin = 0;
    int end = letters.size()-1;
    int mid = begin + (end - begin) / 2;
    while(begin < end)
    {
        if (letters[mid]- target <= 0)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = begin + (end - begin) / 2;
    }

    if (letters[begin] - target > 0 )
        return letters[begin];
    else
        return letters[(begin+1)%letters.size()];
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<char> vec{'c','f','j'};
    char* c1 = new char('c');
    char* c2 = new char('c');
    qDebug() << strcmp(c1,c2)<<endl;
    qDebug() << nextGreatestLetter(vec,'a') << endl;
    return a.exec();
}
