#include <QCoreApplication>
#include <math.h>
#include <QDebug>

bool isPalindrome(int x) {
    if(x < 0) return false;
    int tmp  = x;
    int mirror = 0;
    do
    {
        int r = tmp%10;
        mirror = mirror*10 + r;
        tmp = tmp/10;
    }while(tmp>0);

    return mirror == x ;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << isPalindrome(-2147447412) <<endl;
    return a.exec();
}
