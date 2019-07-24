785_Is_Graphx_Bipartite.cpp
class Solution {
public:
    // dfs
    // assign different color to each child
    // if find same color in the child, return false
    bool isBipartite(vector<vector<int>>& graph) {
        // initialize 
        vector<bool> visited(graph.size(),false);
        vector<int> color(graph.size(),-1);
        
        for(int i = 0; i < graph.size(); i++)
        {
            if (!visited[i])
            {
                color[i] = 1;
                if (!dfs(graph,i,visited,color))
                    return false;
            }
                
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, int v, vector<bool>& visited, vector<int>& color)
    {
        visited[v] = true;
        for(int i = 0; i < graph[v].size(); i++)
        {
            int u = graph[v][i];
            
            if (!visited[u])
            {
                color[u] = (color[v] + 1)%2;
                if (!dfs(graph,u,visited,color))
                    return false;
            }
            else if (color[u] == color[v])
            {
                return false;
            }
                
        }
        return true;
    }
};

