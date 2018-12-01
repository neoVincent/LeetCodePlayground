#include <QCoreApplication>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void matrixChainOrder()
{
    vector<vector<int>> m(7,vector<int>(7,INT_MAX));
    vector<vector<int>> s(7,vector<int>(7,-1));
    for(int i = 0 ; i < 7 ; i++)
    {
        m[i][i] = 0;
    }
    int p[7] = {15,3,7,27,10,5,60};
    //inclusive
    for(int l = 2; l <= 6; ++l)
    {
        //start from 1 to
        for(int i = 1; i <= 6 - l + 1; ++i)
        {
            int j = i + l -1;
            for (int k = i ; k <= j - 1; ++k)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    for (auto row : m)
    {
        for(auto ele : row)
        {
            if(ele == INT_MAX) cout << -1 <<"\t";
            else    cout << ele<<"\t";
        }
        cout << endl;
    }
    cout << endl;
    for (auto row : s)
    {
        for(auto ele : row)
        {
            cout << ele<<"\t";
        }
        cout << endl;
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    matrixChainOrder();
    return a.exec();
}
