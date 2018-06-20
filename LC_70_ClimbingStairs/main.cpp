#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>

using namespace std;

int climb(int n, unordered_map<int,int>& stairMap)
{
    if (stairMap[n] != 0) return stairMap[n];
    if (n - 2 > 0) stairMap[n]+= climb(n-2,stairMap);
    if (n -1 > 0) stairMap[n] += climb(n-1,stairMap);
    return stairMap[n];
}

int climbStairs(int n)
{
    unordered_map<int,int> stairMap;
    stairMap[1] = 1;
    stairMap[2] = 2;
    climb(n,stairMap);
    return stairMap[n];
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Result:  "<< climbStairs(3)<<endl;
    return a.exec();
}
