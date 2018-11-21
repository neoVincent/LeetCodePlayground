#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int dp(vector<vector<int>>& obstacleGrid, pair<int,int> end, vector<vector<int>>& record)
{
    int counter = 0;

    if (record[end.first][end.second] != 0) return record[end.first][end.second];

    if (end.first == 0 && end.second == 0 && obstacleGrid[0][0] != 1) return 1;

    if (end.first > 0 && obstacleGrid[end.first-1][end.second] != 1)
    {
        counter += dp(obstacleGrid,{end.first-1, end.second}, record);
    }

    if (end.second > 0 && obstacleGrid[end.first][end.second-1] != 1)
    {
        counter += dp(obstacleGrid,{end.first, end.second-1}, record);
    }

    record[end.first][end.second] = counter;

    return counter;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    if (obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1] == 1) return 0;
    vector<vector<int>> record(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
    return dp(obstacleGrid,{obstacleGrid.size()-1,obstacleGrid[0].size()-1}, record);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
