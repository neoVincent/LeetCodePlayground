#include <QCoreApplication>
#include <vector>
#include <unordered_map>

using namespace std;

int dp(const vector<vector<int>>& grid, int r, int c, unordered_map<int,int> mem)
{
    if (r == 0 && c == 0) return grid[r][c];
    if (c < 0 || r < 0) return INT_MAX;
    if (mem.find(r*c+c) != mem.end()) return mem[r*c+c];
    int pathValue = min(dp(grid,r-1,c,mem), dp(grid,r,c-1,mem)) + grid[r][c];
    mem[r*c+c] = pathValue;
    return pathValue;
}
int minPathSum(vector<vector<int>>& grid)
{
    // top down
    unordered_map<int,int> mem(grid.size());
    return dp(grid,grid.size()-1,grid[0].size()-1,mem);

    //bottom up
    for (int row = 1; row < grid.size(); row++)
        grid[row][0] = grid[row-1][0] + grid[row][0];
    for(int col = 1; col < grid[0].size(); col++)
        grid[0][col] = grid[0][col]+grid[0][col-1];
    for(int row = 1; row < grid.size() ; row++)
    {
        for(int col = 1; col < grid[0].size(); col++)
        {
            grid[row][col] = min(grid[row-1][col], grid[row][col-1]) + grid[row][col];
        }
    }
    return grid[grid.size()-1][grid[0].size()-1];
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
