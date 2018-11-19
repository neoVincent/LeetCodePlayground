#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <stack>
#include <iostream>

using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    stack<pair<int,int>> stackTrace;
    stackTrace.push({sr,sc});
    while(!stackTrace.empty())
    {
        auto ele = stackTrace.top();
        int srA = ele.first;
        int scB = ele.second;

        stackTrace.pop();

        if ((srA - 1) >= 0 && image[srA-1][scB] == image[srA][scB] )
        {
            stackTrace.push({srA-1,scB});
        }

        if ((srA + 1) < image.size() && image[srA+1][scB] == image[srA][scB])
        {
            stackTrace.push({srA + 1,scB});
        }


        if ((scB + 1) < image.size() && image[srA][scB + 1] == image[srA][scB])
        {
            stackTrace.push({srA,scB + 1});
        }

        if ((scB - 1) >= 0 && image[srA][scB - 1] == image[srA][scB])
        {
            stackTrace.push({srA,scB - 1});
        }

        image[srA][scB] = newColor;
    }

    return image;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    auto res = floodFill(image,1,1,2);
    for (auto rows : res)
    {
        for(auto ele : rows)
            cout << ele << " ";
        cout << endl;
    }
    return a.exec();
}
