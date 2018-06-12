#include <QCoreApplication>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <utility>
using namespace std;

typedef pair<int,int> Point;


Point findStartPoint(vector<vector<int>>& grid)
{
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0 ; j<grid[i].size(); j++)
        {
            if (grid[i][j] != 0)
            {
                return Point{i,j};
            }
        }
    }
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};

int islandPerimeter(vector<vector<int>>& grid)
{
    //findTheStartPoint

    //do while queue ! empty
    //check neighbour,add sides
    //add to queue

    Point start {0,0};
    start = findStartPoint(grid);

    queue<Point> island;
    int perimeter = 0;
    unordered_map<Point,int,pair_hash> record;
    island.push(start);
    record[start] = 1;

    while(!island.empty())
    {
        Point cur = island.front();
        island.pop();


        Point up {cur.first-1,cur.second};
        Point right{cur.first,cur.second+1};
        Point left{cur.first,cur.second-1};
        Point down{cur.first+1,cur.second};
        vector<Point> sides {left,up,down,right};
        for(Point p: sides)
        {
            if (p.first < 0 || p.second < 0 || p.first > grid.size()-1 || p.second > grid[0].size()-1 || grid[p.first][p.second] == 0)
            {
                perimeter++;
            }
            else if (record[p] == 0 )
            {
                record[p] = 1;
                island.push(p);
            }
        }
    }
    return perimeter;
}


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << "result: " << islandPerimeter(grid) <<endl;
    return app.exec();
}
