797_All_Paths_From_Source_to_Target.cpp

class Solution {
private:
    vector<vector<int>> res;
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // Backtracking
        vector<int> route{0};
        vector<bool> visited(graph.size(),false);
        findRoutes(graph,route,visited,0);
        return res;
    }
    
    void findRoutes(vector<vector<int>>& graph, vector<int> route, vector<bool> visited, int node)
    {
        visited[node] = true;

        // base case
        if (node == graph.size()-1)
        {
            res.push_back(route);
            return;
        }
        
        // common
        for(auto next : graph[node])
        {
            if (!visited[next])
            {
                route.push_back(next);
                findRoutes(graph,route,visited,next);
                route.pop_back();
            }
        }
    }
};