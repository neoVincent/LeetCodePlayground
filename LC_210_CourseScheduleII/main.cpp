#include <QCoreApplication>
#include <vector>
#include <iostream>

using namespace std;

bool dfs(int v, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& res)
{
    // 1: is visiting; -1 unvisited; 2 visited
    visited[v] = 1;
    for(int u : adjList[v])
    {
        // ( visited[u] == -1 && !dfs(u, adjList, visited, res) )|| visited[u] == 1
        if ( visited[u] == -1 )
        {
            if (!dfs(u, adjList, visited, res) )
                return false;
        }
        else if (visited[u] == 1)
        {
            return false;
        }
    }
    visited[v] = 2;
    res.insert(res.begin(),v);
    return true;
}
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<int> res(numCourses);

    //convert to adjancy list
    vector<vector<int>> adjList(numCourses);
    for(auto edge : prerequisites)
    {
        adjList[edge.second].push_back(edge.first);
    }

    //traverse DFS
    vector<int> visited(numCourses,-1);
    for(int i = 0 ; i < numCourses; i++)
    {
        if (visited[i] == -1)
        {
            if (!dfs(i, adjList, visited, res))
            {
                return {};
            };
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int numberCourses = 2;
    vector<pair<int, int>> prerequisites
    {
        {0,1},
    };
    auto res = findOrder(numberCourses,prerequisites);
    for (auto val : res) cout << val << endl;
    return a.exec();
}
