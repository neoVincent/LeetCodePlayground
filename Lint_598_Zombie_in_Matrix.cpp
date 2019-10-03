Lint_598_Zombie_in_Matrix.cpp
class Solution {
private:
    int m = 0;
    int n = 0;
    
public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    int zombie(vector<vector<int>> &grid) {
        // BFS, zoombie 2 is source
        m = grid.size();
        n = grid[0].size();
        
        queue<pair<int,int>> q;
        int num = 0;
        
        // find all zombie and people
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    q.push({i,j});
                if (grid[i][j] == 0)
                    num++;
            }
        }
        
        // BFS
        int dir[5] = {0,1,0,-1,0};
        int day = 1;
        int transform = 0;
        // printM(grid);
        // cout << endl;
        while(!q.empty())
        {
            int size = q.size();
            while(size-- > 0)
            {
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                
                for(int i = 0; i < 4; i++)
                {
                    int xp = x + dir[i];
                    int yp = y + dir[i+1];
                    if (isValid(xp,yp) && grid[xp][yp] == 0)
                    {
                        grid[xp][yp] = 1;
                        transform++;
                        q.push({xp,yp});
                        
                    }
                }
            }
            // cout << "After day " <<day<<endl;
            // printM(grid);
            day++;
        }
        
        if (transform == num)
            return day-2;
        return -1;
    }
    bool isValid(int x, int y)
    {
        return x >=0 && x < m && y >= 0 && y < n;
    }
    
    void printM(vector<vector<int>> &grid)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << grid[i][j] <<" ";
            }
            cout <<endl;
        }
    }
};
