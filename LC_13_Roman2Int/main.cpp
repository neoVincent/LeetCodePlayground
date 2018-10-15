#include <QCoreApplication>
#include <iostream>
#include <unordered_map>
#include <stdexcept>

using namespace std;

unordered_map<char,int> buildMap()
{
    unordered_map<char, int> charMap;
    charMap['I'] = 1;
    charMap['V'] = 5;
    charMap['X'] = 10;
    charMap['L'] = 50;
    charMap['C'] = 100;
    charMap['D'] = 500;
    charMap['M'] = 1000;
    return charMap;
}
int romanToInt(string s)
{
    unordered_map<char, int> charMap;
    charMap = buildMap();
    if (s.size() == 1) return charMap[s[0]];

    int sum = 0;
    int previous = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        int n = charMap[s[i]];
        if (previous == 0 || previous >= n)
        {
            sum = sum + n;
        }
        else if (previous < n )
        {
            sum = sum - 2*previous + n;
        }
        previous = n;
    }

    return sum;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
