#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int compress(vector<char>& chars)
{
    int N = chars.size();
    int idx = 0, cnt = 0;

     for(int i = 0; i < N; ++i) {
         cnt++;
         if (i == N-1 || chars[i] != chars[i+1]) {
             chars[idx++] = chars[i];
             if (cnt > 1) {
                 for(auto c : to_string(cnt))
                     chars[idx++] = c;
              }
             cnt = 0;
         }
     }
     return idx;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<char> chars
    {
        'a','a','b','b','c','c','c'
    };
    cout << compress(chars) << endl;
    for(auto c : chars) cout << c << endl;
    return a.exec();
}
