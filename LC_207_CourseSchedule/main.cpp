#include <QCoreApplication>
#include <vector>
#include <iostream>

using namespace std;

bool dfs(int v, vector<vector<int>>& adjList, vector<int>& visited)
{
    bool res = true;
    visited[v] = 1;
    for(auto u : adjList[v])
    {
        if (visited[u] == -1)
        {
            res = dfs(u,adjList,visited);
            if (!res) break;
        }
        else if(visited[u] == 1)
        {
            res = false;
            break;
        }
    }
    visited[v] = 2;
    return res;

}
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
    //pre check
    if(prerequisites.size() == 0) return true;

    //convert to a adjancy list
    vector<vector<int>> adjList(numCourses);
    for(auto edge : prerequisites)
    {
        adjList[edge.second].push_back(edge.first);
    }

    //-1 unvisited, 1 is visiting, visited 2
    vector<int> visited(numCourses, -1);
    for(int i = 0 ; i < numCourses; i++)
    {
        bool loop;
        if (visited[i] == -1)
        {
            loop = dfs(i,adjList,visited);
        }
        if (!loop)
        {
            return false;
        }
    }
    return true;

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int numberCourses = 3;
    vector<pair<int, int>> prerequisites
    {
        {0,1},
        {1,2},
        {0,2}
    };
    cout << canFinish(numberCourses,prerequisites)<<endl;
    return a.exec();
}
