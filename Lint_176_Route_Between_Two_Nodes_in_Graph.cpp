Lint_176_Route_Between_Two_Nodes_in_Graph.cpp


class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
        // BFS
        if (s == t) return true;
        
        deque<DirectedGraphNode*> que;
        unordered_set<DirectedGraphNode*> visited;
        
        que.push_back(s);
        visited.insert(s);
        
        while(!que.empty())
        {
            auto node = que.front();
            que.pop_front();
            
            for(auto nb: node->neighbors)
            {
                if (nb == t)
                    return true;
                    
                if (visited.find(nb) == visited.end())
                {
                    visited.insert(nb);
                    que.push_back(nb);
                }
            }
        }
        
        return false;
    }
};