261_Valid_Tree.cpp
class Solution {
public:
    // Union Find:
    // Only one set in the end
    
    int find(vector<int>& sets, int x)
    {
       if (sets[x] == -1)
           return x;
        return sets[x] = find(sets,sets[x]);
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> sets(n,-1);
        
        for(auto edge: edges)
        {
            int lRoot = find(sets,edge[0]);
            int rRoot = find(sets, edge[1]);
            
            if (lRoot == rRoot )
            {
                return false;
            }
            else
                sets[lRoot] = rRoot;
        }
        
        return edges.size() == n-1;
    }
    
    
};

