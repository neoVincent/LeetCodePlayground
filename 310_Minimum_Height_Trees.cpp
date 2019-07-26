310_Minimum_Height_Trees.cpp

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // BFS
        if (edges.size() == 0) return {0};
        // build adj graph
        unordered_map<int,unordered_set<int>> graph;
        for(auto edge : edges)
        {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        // BFS trim layer by layer
        // find the leaf first
        vector<int> curLayer;
        vector<int> nextLayer;
        
        for(auto iter = graph.begin(); iter != graph.end(); iter++)
        {
            if (iter->second.size() == 1)
                curLayer.push_back(iter->first);
        }
        
        while(true)
        {
            // trim the leaf layer
            for(auto u : curLayer)
            {
                for(auto iter = graph[u].begin(); iter != graph[u].end(); iter++)
                {
                    int v = *iter;
                    graph[v].erase(u);
                    if (graph[v].size() == 1)
                        nextLayer.push_back(v);
                }
            }
            
            if (nextLayer.size() == 0)
                return curLayer;
            curLayer.clear();
            swap(curLayer,nextLayer);
        }
    }
};
