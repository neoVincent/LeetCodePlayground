407_Trapping_Rain_Water_II.cpp
class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int>> &heights) {
        int m = heights.size();
        int n = (m == 0)? 0: heights[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        priority_queue<pair<int,pair<int,int>>, 
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>> pq;
                        
        
        // add border
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (!(i == 0 || j == 0 || j == n-1 || i == m-1))
                    continue;
                pq.push({heights[i][j],{i,j}});
                visited[i][j] = 1;
            }
        }
        
        // add border gradually
        int res = 0, H = INT_MIN;
        vector<int> dir = {0,1,0,-1,0};
        while(!pq.empty())
        {
            auto minBar = pq.top();
            pq.pop();
            int height = minBar.first, x = minBar.second.first, y = minBar.second.second;
            
            H = max(H,height);
            
            for(int d = 0; d < 4; d++)
            {
                int i = x + dir[d];
                int j = y + dir[d+1];
                
                if (i < 0 || i >= m-1 || j < 0 || j >= n-1 || visited[i][j])
                    continue;
                
                int diff = H - heights[i][j];
                if (diff > 0)
                    res += diff;
                
                visited[i][j] = 1;
                
                pq.push({heights[i][j],{i,j}});
            }
            
        }
        
        return res;
    }
};