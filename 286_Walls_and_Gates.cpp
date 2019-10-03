286_Walls_and_Gates.cpp
class Solution {
private:
    int m = 0;
    int n = 0;
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // no needs for visited 
        // reuse the rooms for visited
        if (rooms.size() == 0) return;
        
        m = rooms.size();
        n = rooms[0].size();
        
        // push gate as the initial seeds
        queue<pair<int,int>> q;
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (rooms[i][j] == 0)
                    q.push({i,j});
            }
        }
        
        int dir[5] = {0,1,0,-1,0};
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            
            // add unvisited neighbor
            for(int i = 0; i < 4; i++)
            {
                int xp = x + dir[i];
                int yp = y + dir[i+1];
                
                if (isValid(xp,yp) && rooms[xp][yp] == INT_MAX)
                {
                    rooms[xp][yp] = rooms[x][y] + 1; // save the value for depth
                    q.push({xp,yp});
                }
            }
        }
    }
    bool isValid(int x, int y)
    {
        return !(x < 0 || x >= m || y < 0 || y >= n);
    }
};
