#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<int>& visited, vector<int>& dist)
{
    visited[node] = 1;
    for(int i = 0 ; i < graph[node].size(); i++)
    {
        if (graph[node][i] == -1) continue;
       if(visited[i] == 0)
       {
           // cout << "(u,v) "<< node <<", "<< i << endl;
           dist[i] = dist[node] + graph[node][i];
           // cout <<"dist " << i << " " << dist[i]<<endl;
           dfs(graph,i,visited,dist);
       }
       else if (visited[i] == 2 && (dist[node] + graph[node][i]) < dist[i])
       {
           dist[i] = dist[node] + graph[node][i];
           // cout <<"Update from u= " << node << " to v = " << i << endl;
           // cout <<"Update dist " << i << " " << dist[i]<<endl;
           dfs(graph,i,visited,dist);
       }
    }
    visited[node] = 2;
}

int networkDelayTime(vector<vector<int>>& times, int N, int K)
{
    //store visited distance
    vector<int> visited(N,0);
    vector<int> dist(N,INT_MIN);
    // adjacency matrix
    vector<vector<int>> graph(N,vector<int>(N,-1));
    for(auto time: times)
    {
        graph[time[0]-1][time[1]-1] = time[2];
    }
    // define the source distance is zero
    dist[K-1] = 0;
    dfs(graph, K-1, visited, dist);

    int res = 0;
    for(auto d : dist)
    {
        if(d == INT_MIN) return -1;
        res = max(res, d);
    }
    return res;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    struct Edge {
        int start;
        int end;
        int cost;
        Edge(int s, int e, int c) : start(s), end(e), cost(c) {}
    };
    using P = pair<int, int>;	//first: minimum cost, second: end vertex
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> d(N + 1);
    fill(d.begin(), d.end(), numeric_limits<int>::max());
    d[K] = 0;
    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < times.size(); ++i) {
        graph[times[i][0]].push_back(Edge(times[i][0], times[i][1], times[i][2]));
    }
    que.push(make_pair(0, K));
    while (!que.empty()) {
        P node = que.top();
        que.pop();
        //if (d[node.second] < node.first)	//same as check if visited[X] == true
            //continue;
        for (int i = 0; i < graph[node.second].size(); ++i) {
            Edge edge = graph[node.second][i];
            if (d[edge.end] > d[node.second] + edge.cost) {
                d[edge.end] = d[node.second] + edge.cost;
                que.push(make_pair(d[edge.end], edge.end));
            }
        }
    }
    int ret = 0;
    for (int i = 1; i < d.size(); ++i) {
        if (d[i] == numeric_limits<int>::max())
            return -1;
        ret = max(ret, d[i]);
    }

    return ret;
}

};
