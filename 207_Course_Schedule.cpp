207_Course_Schedule.cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // circle dectection, DFS
        
        // build map
        unordered_map<int,vector<int>> map;
        for(const auto& pair: prerequisites)
        {
            map[pair[0]].push_back(pair[1]);
        }
        
        vector<int> state(numCourses,0); // 0 white unvisisted, 1 grey visiting, 2 black visited
        // DFS traverse
        for(auto iter = map.begin(); iter != map.end(); iter++)
        {
            cout << iter->first << endl;
            if (state[iter->first] == 0)
                if (!dfs(map,iter->first,state))
                    return false;
        }
        return true;
    }
    
private:
    bool dfs(const unordered_map<int,vector<int>>& map, 
             int s, 
             vector<int>& state)
    {
        state[s] = 1; // visiting
        
        const auto iter = map.find(s);
        if (iter == map.end()) 
        {
            state[s] = 2;
            return true;
        }
        for(const int& next: iter->second)
        {
            if (state[next] == 1)
                return false;
            if (state[next] == 0)
                if (!dfs(map,next,state))
                    return false;
        }
        state[s] = 2;
        
        return true;
    }
};