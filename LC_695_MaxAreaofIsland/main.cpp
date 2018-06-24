#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <utility>
#include <stack>

using namespace std;

typedef pair<int,int> Point;

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int area = 0;
    stack<Point> tracker;
    vector<vector<int>> seen(grid.size(),vector<int>(grid[0].size(),0));

    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] != 0 && seen[i][j] == 0)
            {
                Point p{i,j};
                tracker.push(p);
                seen[p.first][p.second] = 1;
                int size = 0;
                while(!tracker.empty())
                {
                    Point p = tracker.top();
                    tracker.pop();
                    size++;

                    //up,down,righ,left
                    vector<Point> direction;
                    direction.push_back({p.first-1,p.second});
                    direction.push_back({p.first+1,p.second});
                    direction.push_back({p.first,p.second+1});
                    direction.push_back({p.first,p.second-1});

                    for(Point subP : direction)
                    {
                        if (subP.first >= grid.size() || subP.second < 0
                                || subP.second >= grid[0].size()
                                || grid[subP.first][subP.second] == 0
                                || seen[subP.first][subP.second] == 1
                                )
                        {
                            continue;
                        }
                        else
                        {
                            tracker.push(subP);
                            seen[subP.first][subP.second] = 1;
                        }
                    }

                }

                if (area < size) area = size;
            }
        }
    }

    return area;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
   vector<vector<int>> grid = {
       {0,0,1,0,0,0,0,1,0,0,0,0,0},
     {0,0,0,0,0,0,0,1,1,1,0,0,0},
     {0,1,1,0,1,0,0,0,0,0,0,0,0},
     {0,1,0,0,1,1,0,0,1,0,1,0,0},
     {0,1,0,0,1,1,0,0,1,1,1,0,0},
     {0,0,0,0,0,0,0,0,0,0,1,0,0},
     {0,0,0,0,0,0,0,1,1,1,0,0,0},
     {0,0,0,0,0,0,0,1,1,0,0,0,0}};

   vector<vector<int>> grid2 =
   {
       {1,1,0,0,0},
       {1,1,0,0,0},
       {0,0,0,1,1},
       {0,0,0,1,1}
   };

   vector<vector<int>> grid3 =
   {
     {1,0,1},
     {1,1,1}
   };
   cout << "Result: " << maxAreaOfIsland(grid3)<<endl;
    return a.exec();
}
