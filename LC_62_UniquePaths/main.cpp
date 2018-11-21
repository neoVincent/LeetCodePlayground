#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int uniquePaths(int m, int n)
{
    //https://leetcode.com/problems/unique-paths/discuss/184248/8-lines-Java-DP-solution-0ms-beats-100-explained-with-graph
    // bottom up
    vector<vector<int>> matrics(m,vector<int>(n,0));
    for(int i = 0 ; i < m ; i++) matrics[i][0] = 1;
    for(int i = 0 ; i < n ; i++) matrics[0][i] = 1;

    for(int r = 1 ; r < m ; r++)
    {
        for(int c = 1 ; c < n; c++)
        {
            matrics[r][c] = matrics[r-1][c] + matrics[r][c-1];
        }
    }
    return matrics[m-1][n-1];
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
